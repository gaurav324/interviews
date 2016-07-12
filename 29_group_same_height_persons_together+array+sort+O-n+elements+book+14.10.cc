// Implement sorting such that elements with same value are together.
//
// Version-1: Mak sure all integers are placed together.

#include <iostream>
#include <unordered_map>

using namespace std;

template <size_t N>
void arrangellIntegersWithSameValueTogether(int (&arr)[N]) {
	unordered_map<int, int> key_count;
	for (auto v : arr) {
		if (key_count.find(v) == key_count.end()) {
			key_count[v] = 1;
		} else {
			key_count[v] += 1;
		}
	}
	int i = 0;
	while (key_count.size() > 0) {
		auto it = key_count.begin();
		int temp = it->second;
		while(temp-- > 0) {
			arr[i++] = it->first;
		}
		key_count.erase(it);
	}
}

struct People {
	int id;
	string name;
	
	People(int id, string name) { this->id = id; this->name = name; };
};

template <size_t N>
void arrangelPeopleWithSameIdTogether(People (&arr)[N]) {

}


int main() {
	int arr[10] = {4, 3, 3, 6, 6, 7, 3, 4, 1, 3};
	arrangellIntegersWithSameValueTogether(arr);

	People p[10]= {{4, "a"}, {3, "a"}, {3, "b"}, {6, "a"}, {6, "b"}, {7, "a"}, {3, "a"}, {4, "b"}, {1, "a"}, {3, "c"}};
	arrangelPeopleWithSameIdTogether(p);	
 	for (auto no : arr) { cout << no << endl; }
}
