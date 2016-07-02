// There are three jugs, each of them when filled would have water in range of [X, Y]. There is another beaker to be filled which is to be filled using these three beakers, making sure water in beaker is in range of [R1, R2].
// e.g: J1(230, 240), J2(290, 310), J3(500, 515). Final beaker should be (2100, 2300).
// Return sequence of J1, J2 and J3 that can be used to fill the final beaker.

#include <iostream>
#include <vector>

using namespace std;

struct jug { int l; int r; jug(int l, int r) {this->l = l; this->r = r;}};
jug j2(230, 240);
jug j3(290, 310);
jug j1(500, 515);

vector<int> seq;
jug jugs[3] = {j1, j2, j3};
int cl = 0, cr = 0, r1 = 2100, r2 = 2300;

bool PopulateSeq() {
	if (cl >= r1 && cr <= r2) { return true; }
  if (cr >= r2) { return false; }
	for (int i=0; i < 3; ++i) {
		cl += jugs[i].l; cr += jugs[i].r; seq.push_back(i);
		if(PopulateSeq()) { return true; }
		cl -= jugs[i].l; cr -= jugs[i].r; seq.pop_back();
	}
	return false;
}

int main() {
	PopulateSeq();
	for (int i : seq) {
		cout << "(" << jugs[i].l << ", " << jugs[i].r << ") "<< "==";
	}
}
