#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
#include <cstring>
#include <math.h>
#include <fstream>
#include <string>
#include <iomanip>
#include <bitset>
#include <functional>
typedef long long ll;
using namespace std;
#define vi vector<int>
#define vii vector<pair<int,int>>
#define vvi vector<vector<int>>
#define vvpi vector<vector<pair<int,int>>>
#define pii pair<int,int>
#define MOD 1000000007
#define vl vector<int64_t>
#define vll vector<vector<int64_t>>


// index start with 0
// ----- SegmentTree for minimum
struct SegmentTree {
	int n;
	vi t;
	SegmentTree(int n) {
		this->n = n;
		t.assign(2 * n, 0);
	}
	void add(int k, int x) {
		k += n;
		t[k] += x;
		//t[k] =x;
		for (k /= 2; k >= 1; k /= 2) {
			t[k] = t[2 * k] + t[2 * k + 1];
			//t[k] = min(t[2*k] ,t[2*k+1]);
		}
	}
	int get(int a) {
		return t[a + n];
	}
	int sum(int l, int r) {
		l += n; r += n;
		int s = 0;
		while (l <= r) {
			if (l &1) s += t[l++];
			if (~r&1)s += t[r--];
			l >>= 1, r >>= 1;
		}
		return s;
	}
	int get_min(int l, int r) {
		l += n; r += n;
		int min_val = MOD;
		while (l <= r) {
			if (l & 1) min_val = min(min_val, t[l++]);
			if (~r & 1)min_val = min(min_val, t[r--]);
			l >>= 1, r >>= 1;
		}
		return min_val;
	}
};
int main(){}
