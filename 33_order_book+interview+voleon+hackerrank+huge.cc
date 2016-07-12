// Problem is to write an order book, which has four types of orders.
// 1) limit 2) market 3) stop 4) cancel.
// Have to print all the matching trades that happen.
#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

enum OrderType { LIMIT, MARKET, STOP, CANCEL };

// CONSTANTS.
static constexpr char BUY[] = "buy";
static constexpr char MATCH[] = "match";
static constexpr char SELL[] = "sell";
static constexpr char SPACE[] = " ";

static unordered_map<string, OrderType> order_type_map = {
    {"limit", LIMIT}, {"market", MARKET}, {"stop", STOP}, {"cancel", CANCEL}};

///////////////////////
// UTILITY FUNCTIONS //
///////////////////////
void printMatchString(int64_t taker, int64_t maker, int64_t volume,
                      double price) {
  ostringstream oss;
  oss << std::setprecision(2) << std::fixed << MATCH << SPACE << taker << SPACE
      << maker << SPACE << volume << SPACE << price;
  cout << oss.str() << endl;
}

///////////////////////
// BASE ORDER CLASS. //
///////////////////////

class Order;
class OrderProcessor;

class Order {
 public:
  int64_t getOrderNumber() const { return no_; }
  OrderType getOrderType() const { return type_; }
  int64_t getCount() const { return count_; }
  double getPrice() const { return price_; }

  void decrementCount(int64_t count) { count_ -= count; }

  virtual string getOrderSide() const = 0;
  virtual void AddStopOrder(OrderProcessor& processor) = 0;
  virtual void EraseOrderFromProcessor(OrderProcessor& processor) = 0;
  virtual void ProcessOrder(OrderProcessor& processor) = 0;

 protected:  // Using protected for the ease of use in child classes.
  Order(int64_t no, OrderType type, int64_t count, double price)
      : no_(no), type_(type), count_(count), price_(price) {}

  int64_t no_;
  OrderType type_;
  int64_t count_;
  double price_;
};

struct OrderComparator {
  bool operator()(const Order* lhs, const Order* rhs) {
    if (lhs->getPrice() < rhs->getPrice()) {
      return true;
    } else if (lhs->getPrice() > rhs->getPrice()) {
      return false;
    } else {
      return (lhs->getOrderNumber() < rhs->getOrderNumber());
    }
  }
};

struct ReverseOrderComparator {
  bool operator()(const Order* lhs, const Order* rhs) {
    if (lhs->getPrice() > rhs->getPrice()) {
      return true;
    } else if (lhs->getPrice() < rhs->getPrice()) {
      return false;
    } else {
      return (lhs->getOrderNumber() < rhs->getOrderNumber());
    }
  }
};

struct StopOrderComparator {
  bool operator()(const Order* lhs, const Order* rhs) {
    if (lhs->getOrderNumber() < rhs->getOrderNumber()) {
      return true;
    } else {
      return false;
    }
  }
};

// Overload for printing orders. This is for debugging purposes.
ostream& operator<<(ostream& os, const Order& order) {
  cout << order.getOrderNumber() << SPACE << order.getOrderType() << SPACE
       << order.getOrderSide() << SPACE << order.getCount() << SPACE
       << order.getPrice() << endl;
  return cout;
}

//////////////////////////
// MAIN ORDER PROCESSOR //
//////////////////////////
/*
 * Responsible for handling all the calculations
 * for processing an order.
 */
class OrderProcessor {
 public:
  // TODO: Returning a reference here is probably not very safe.
  set<Order*, ReverseOrderComparator>& GetPendingBuyOrders() {
    return pending_buy_orders;
  }
  set<Order*, OrderComparator>& GetPendingSellOrders() {
    return pending_sell_orders;
  }
  set<Order*, OrderComparator>& GetStopBuyOrders() { return stop_buy_orders; }
  set<Order*, ReverseOrderComparator>& GetStopSellOrders() {
    return stop_sell_orders;
  }

  void AddSellOrder(Order* order) { pending_sell_orders.insert(order); }
  void EraseSellOrder(Order* order) {
    auto it = pending_sell_orders.find(order);
    if (it != pending_sell_orders.end()) {
      pending_sell_orders.erase(it);
      delete (order);
    }
  }

  void AddBuyOrder(Order* order) { pending_buy_orders.insert(order); }
  void EraseBuyOrder(Order* order) {
    auto it = pending_buy_orders.find(order);
    if (it != pending_buy_orders.end()) {
      pending_buy_orders.erase(it);
      delete (order);
    }
  }

  void AddStopBuyOrder(Order* order) { stop_buy_orders.insert(order); }
  void EraseStopBuyOrder(Order* order) { stop_buy_orders.erase(order); }

  void AddStopSellOrder(Order* order) { stop_sell_orders.insert(order); }
  void EraseStopSellOrder(Order* order) { stop_sell_orders.erase(order); }

  void CancelOrder(int64_t order_number) {
    cancelled_orders.insert(order_number);
  }

  void ProcessOrder(Order* order) {
    if (order == NULL) {
      return;
    }
    if (order->getOrderType() == STOP) {
      order->AddStopOrder(*this);
      return;
    }
    order->ProcessOrder(*this);

    while (pending_triggers.size() > 0) {
      double val = pending_triggers.front();
      TriggerStopOrderExecution(val);
      pending_triggers.pop_front();
    }
  }

  void TriggerStopOrderExecution(double price) {
    // This is probably not very neat solution.
    // Getting all the buy and sell stop orders, which can be triggered.
    // Sorting them by time of creation and then processing them one by one.
    // This could take more memory if there are a lot of stop orders.
    vector<Order*> orders_to_trigger;

    auto& stop_buy_orders = GetStopBuyOrders();
    while (stop_buy_orders.size() > 0) {
      auto it = stop_buy_orders.begin();
      if (cancelled_orders.find((*it)->getOrderNumber()) !=
          cancelled_orders.end()) {
        EraseStopBuyOrder(*it);
        continue;
      }

      if ((*it)->getPrice() > price) {
        break;
      }
      orders_to_trigger.push_back(*it);
      EraseStopBuyOrder(*it);
    }

    auto& stop_sell_orders = GetStopSellOrders();
    while (stop_sell_orders.size() > 0) {
      auto it = stop_sell_orders.begin();
      if (cancelled_orders.find((*it)->getOrderNumber()) !=
          cancelled_orders.end()) {
        EraseStopSellOrder(*it);
        continue;
      }

      if ((*it)->getPrice() < price) {
        break;
      }
      orders_to_trigger.push_back(*it);
      EraseStopSellOrder(*it);
    }

    StopOrderComparator comparator;
    std::sort(orders_to_trigger.begin(), orders_to_trigger.end(), comparator);

    for (auto it : orders_to_trigger) {
      it->ProcessOrder(*this);
      delete (it);
    }
  }

  void RecordTrade(Order* order, Order* match_order) {
    if (match_order == NULL) {
      return;
    }
    // If match order is cancelled, then just get rid of it.
    if (cancelled_orders.find(match_order->getOrderNumber()) !=
        cancelled_orders.end()) {
      match_order->EraseOrderFromProcessor(*this);
      return;
    }

    int64_t min_count = min(order->getCount(), match_order->getCount());
    order->decrementCount(min_count);
    match_order->decrementCount(min_count);

    printMatchString(order->getOrderNumber(), match_order->getOrderNumber(),
                     min_count, match_order->getPrice());
    pending_triggers.push_back(match_order->getPrice());
    if (match_order->getCount() == 0) {
      match_order->EraseOrderFromProcessor(*this);
    }
  }

 private:
  set<Order*, ReverseOrderComparator> pending_buy_orders;
  set<Order*, OrderComparator> pending_sell_orders;
  set<Order*, OrderComparator> stop_buy_orders;
  set<Order*, ReverseOrderComparator> stop_sell_orders;

  std::list<double> pending_triggers;
  std::unordered_set<int64_t> cancelled_orders;
};

//////////////////////
// DERIVED CLASSES. //
//////////////////////
class SellOrder;
class BuyOrder : public Order {
 public:
  BuyOrder(int64_t no, OrderType type, int64_t count, double price)
      : Order(no, type, count, price) {}

  string getOrderSide() const { return BUY; }

  void AddStopOrder(OrderProcessor& processor) {
    processor.AddStopBuyOrder(this);
  }
  void EraseOrderFromProcessor(OrderProcessor& processor) {
    processor.EraseBuyOrder(this);
  }

  void ProcessOrder(OrderProcessor& processor);

 private:
  Order* getMatchingSellOrder(
      set<Order*, OrderComparator>& pending_sell_orders);
};

class SellOrder : public Order {
 public:
  SellOrder(int64_t no, OrderType type, int64_t count, double price)
      : Order(no, type, count, price) {}

  string getOrderSide() const { return SELL; }

  void AddStopOrder(OrderProcessor& processor) {
    processor.AddStopSellOrder(this);
  }
  void EraseOrderFromProcessor(OrderProcessor& processor) {
    processor.EraseSellOrder(this);
  }
  void ProcessOrder(OrderProcessor& processor);

 private:
  Order* getMatchingBuyOrder(
      set<Order*, ReverseOrderComparator>& pending_buy_orders);
};

Order* BuyOrder::getMatchingSellOrder(
    set<Order*, OrderComparator>& pending_sell_orders) {
  if (pending_sell_orders.size() == 0) {
    return NULL;
  }

  if (this->getOrderType() != LIMIT) {
    return *(pending_sell_orders.begin());
  }

  if ((*(pending_sell_orders.begin()))->getPrice() > this->getPrice()) {
    return NULL;
  } else {
    return *(pending_sell_orders.begin());
  }
}

void BuyOrder::ProcessOrder(OrderProcessor& processor) {
  Order* match_sell_order = NULL;
  auto& pending_sell_orders = processor.GetPendingSellOrders();
  while ((getCount() > 0 &&
          (match_sell_order = getMatchingSellOrder(pending_sell_orders)) !=
              NULL)) {
    processor.RecordTrade(this, match_sell_order);
  }
  // If order is not yet fullfilled and not a market order,
  // add it to the pending list of orders.
  if (getOrderType() == LIMIT && getCount() > 0) {
    processor.AddBuyOrder(this);
  }
}

Order* SellOrder::getMatchingBuyOrder(
    set<Order*, ReverseOrderComparator>& pending_buy_orders) {
  if (pending_buy_orders.size() == 0) {
    return NULL;
  }

  if (this->getOrderType() != LIMIT) {
    return *(pending_buy_orders.begin());
  }

  if ((*(pending_buy_orders.begin()))->getPrice() < this->getPrice()) {
    return NULL;
  } else {
    return *(pending_buy_orders.begin());
  }
}

void SellOrder::ProcessOrder(OrderProcessor& processor) {
  Order* match_buy_order = NULL;
  auto& pending_buy_orders = processor.GetPendingBuyOrders();
  while (
      (getCount() > 0 &&
       (match_buy_order = getMatchingBuyOrder(pending_buy_orders)) != NULL)) {
    processor.RecordTrade(this, match_buy_order);
  }
  // If order is not yet fullfilled and not a market order,
  // add it to the pending list of orders.
  if (getOrderType() == LIMIT && getCount() > 0) {
    processor.AddSellOrder(this);
  }
}

int main() {
  int lineno = 0;

  // Read lines into these variables.
  string type, side;
  int64_t value1;
  double value2;

  OrderProcessor* market_maker = new OrderProcessor();
  string line;
  while (std::getline(cin, line)) {
    ++lineno;

    istringstream iss(line);
    iss >> type >> side >> value1 >> value2;

    Order* order;
    if (side == "buy") {
      order = new BuyOrder(lineno, order_type_map[type], value1, value2);
    } else if (side == "sell") {
      order = new SellOrder(lineno, order_type_map[type], value1, value2);
    } else {
      order = NULL;
      market_maker->CancelOrder(value1);
    }
    market_maker->ProcessOrder(order);
  }
  return 0;
}
