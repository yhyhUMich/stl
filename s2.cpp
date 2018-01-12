#include <iostream>
#include <string>
#include <array>
#include <ctime>
#include <cstdlib>

#define ASIZE 500000

using namespace std;

long get_a_target_long() {
	long target = 0;
	cin >> target;
	return target;
}

string get_a_target_string() {
	long target = 0;
	char buf[10];

	cin >> target;
	snprintf(buf, 10, "%d", target);
	return static_cast<string>(buf);
}

int compareLongs(const void* a, const void* b) {
	return *(reinterpret_cast<long*>(const_cast<void*> (a))) - *(reinterpret_cast<long*> (const_cast<void*>(b)));
}

int compareStrings(const void* a, const void* b) {
	if(*(reinterpret_cast<string*> (const_cast<void*>(a))) > *(reinterpret_cast<string*>(const_cast<void*>(b))))
		return 1;
	else if(*(reinterpret_cast<string*> (const_cast<void*>(a))) < *(reinterpret_cast<string*>(const_cast<void*>(b))))
		return -1;
	else
		return 0;
}
	
namespace s2 {

void test_array() {

	cout << "\ntest_array().....\n"	;
	array<long, ASIZE> c;
	
	clock_t timeStart = clock();

	for(long i = 0; i < ASIZE; ++i) {
		c[i] = rand();
	}
	
	cout << "milli-seconds " << (clock()-timeStart) << endl;
	cout << "array size " << c.size() << endl;
	cout << "array.front() " << c.front() << endl;
	cout << "array.back() " << c.back() << endl;
	cout << "array.data() " << c.data() << endl;

	long target = get_a_target_long();
	
	timeStart = clock();

	qsort(c.data(), ASIZE, sizeof(long), compareLongs);

	long* pItem = reinterpret_cast<long*> (bsearch(&target, (c.data()), ASIZE, sizeof(long), compareLongs));
	
	cout << "qsort()+bsearch(), milli-seconds : " << (clock()-timeStart) << endl;
	
	if(pItem != nullptr)
		cout << "found, " << *pItem << endl;
	else
		cout << "not found " << endl;


}
}

int main (int argc, char** argv) {
	s2::test_array();
	return 0;
}

