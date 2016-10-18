#include <queue>
#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;


static class Solution {
public:
	static string str(int x) {
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
	static vector<string> fizzBuzz(int n) {
		vector<string> out;
		for (size_t i = 1; i <= n; i++) {
			out.push_back(str(i));
		}
		return out;

	}
};


int main()
{
	vector<string> o = Solution::fizzBuzz(1);
	return 0;
}