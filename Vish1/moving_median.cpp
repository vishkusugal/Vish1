#include <queue>
#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
template<class _Ty = void>
struct greater
{	// functor for operator<
	typedef _Ty first_argument_type;
	typedef _Ty second_argument_type;
	typedef bool result_type;

	constexpr bool operator()(const _Ty& _Left, const _Ty& _Right) const
	{	// apply operator< to operands
		return (_Left > _Right);
	}
};
class min_hp :public priority_queue<int,vector<int>,greater<int>> {
public:
	void remove(int x) {
		auto it = find(c.begin(), c.end(), x);
		if (it != c.end()) {
			c.erase(it);
			make_heap(c.begin(), c.end(), comp);
		}

	}
};
class max_hp :public priority_queue<int, vector<int>, less<int>> {
public:
	void remove(int x) {
		auto it = find(c.begin(),c.end(),x);
		if (it != c.end()) {
			c.erase(it);
			//make_heap(c.begin(), c.end(), comp);
		}

	}
};
class moving_median {
public:
	min_hp minH;
	max_hp maxH;

	void push(int x) {
		if (minH.size()>0 && x < minH.top()) {
			maxH.push(x);
		}
		else {
			minH.push(x);
		}
		bal();
	}
	void bal() {
		//balance the sie of the heap by moving top element 
		while (abs((int)maxH.size() - (int)minH.size()) > 1) {
			if (maxH.size() > minH.size()) {
				int e = maxH.top();
				maxH.pop();
				minH.push(e);
			}
			else {
				int e = minH.top();
				minH.pop();
				maxH.push(e);
			}
		}
	}
	void remove(int x) {
		if (minH.top()>0 && x >= minH.top()) {
			minH.remove(x);
		} else if(maxH.top()>0) {
			maxH.remove(x);
		}
	}
	int median() { 
		cout << "max sz: "<<maxH.size() << endl;
		cout << "min sz: " << minH.size() << endl;
		int avg = 0;
		if (maxH.size() > minH.size()) {
			avg = 2*maxH.top();
		}
		else if (maxH.size() < minH.size()) {
			avg = 2*minH.top();
		} else {
			if (maxH.size() > 0) {
				avg += maxH.top();
			}
			if (minH.size() > 0) {
				avg += minH.top();
			}
		}
		return avg;
	}

};

int main()
{
	moving_median mm = moving_median();
	vector<int> a = { 13434,223,334,43434,53434,634,734,834,923,10,11,12,12,13,14,14,353,232,2312,23,4,3,2,2,3535,43545,234324234,234234,234234,23234,234324 };
	int n = a.size();
	int d = n / 2;
	for (int i = 0; i < d; i++) {
		mm.push(a[i]);
	}
	for (int i = d; i <n; i++) {
		mm.remove(a[i - d]);
		mm.push(a[i]);
		cout << mm.median() << endl;
	}
	int x;
	cin >> x;
	return 0;
}
class Solution {
public:
	string str(int x) {
		string ostr = "";
		if (x % 3 == 0) {
			ostr += "Fizz";
		}
		if (x % 5 == 0) {
			ostr += "Buzz";
		}
		if (ostr.size() == 0) {
			ostr = to_string(x);
		}
		return ostr;
	}
	vector<string> fizzBuzz(int n) {
		vector<string> out;
		if (int i = 1; i <= n; i++) {
			out.push_back(str(i));
		}
		return out;

	}
};