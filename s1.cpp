#include <vector> 
#include <algorithm>
#include <functional>
#include <iostream>

using namespace std;

int main (int argc, char** argv) {

	int ia[6] = {27, 210, 12, 35, 109, 85};

	vector<int, allocator<int>> vi(ia, ia+6);

	cout << count_if(vi.begin(), vi.end(), 
		not1(bind2nd(less<int>(), 40))) << endl;

	auto foo = not2(less<int>());
	if (foo(5,4))
		cout << "A" << endl;

	auto itr = vi.begin();

	return 0;
}
