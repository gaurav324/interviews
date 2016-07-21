// Version A: BUY once and SELL once.
//
// Given a list of stock prices, we have to maximize the 
// profit in that day. Like we buy at min price and sell at highest.
#include <iostream>
#include <vector>

using namespace std;

int maxStockPrice(std::vector<int> stockPrices) {
    int minValue = INT_MAX;
    int maxProfit = 0;
    for (int i=0; i < stockPrices.size(); ++i) {
        if(stockPrices[i] < minValue) {
            minValue = stockPrices[i];
        }
        int temp = stockPrices[i] - minValue;
        if (temp > maxProfit) {
            maxProfit = temp;
        }
    }
    return maxProfit;
}

// Version B: Keep BUYING and SELLING.
int maxStockPriceContinous(std::vector<int> stockPrices) {
  int totalProfit = 0;
  
  bool isNextBuy = true;
  int buyPrice = 0, i=0;
  for (i=0; i < stockPrices.size() - 1; ++i) {
    if (isNextBuy) {
        if (stockPrices[i+1] > stockPrices[i]) {
            buyPrice = stockPrices[i];
            isNextBuy = false;
        }
    } else {
      if (stockPrices[i+1] < stockPrices[i]) {
        totalProfit += stockPrices[i] - buyPrice;
        isNextBuy = true;
      }
    }  
  }
  
  if (!isNextBuy) {
    totalProfit += stockPrices[i] - buyPrice;
  }
  
  return totalProfit;
}

int main() {
	std::vector<int> stockPrices = {100, 180, 260, 310, 40, 535, 695};
	cout << "One time buy and sell: " << maxStockPrice(stockPrices) << endl;
	cout << "Multiple times buy and sell: " << maxStockPriceContinous(stockPrices) << endl;
}
