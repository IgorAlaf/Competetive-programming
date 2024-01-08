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
struct Fenwick {
	int n;
	vl s;
	Fenwick(int n) {
		this->n = n;
		s.resize(n + 1);
	}
	void add(int k, int x) {
		while (k <= n) {
			s[k] += x;
			k += k & -k;
		}
	}
	int64_t sum(int k) {
		int64_t res = 0;
		while (k >= 1) {
			res += s[k];
			k -= k & -k;
		}
		return res;
	}
	int64_t sum(int l, int r) {
		return sum(r) - sum(l - 1);
	}
	int lower_bound(int left_p, int k) {
		int left = left_p, right = n + 1;
		while (right - left > 1) {
			int mid = (right + left) / 2;
			if (sum(mid) >= k)right = mid;
			else left = mid;
		}
		return right;
	}
	int lower_bound(int k) {
		return lower_bound(0, k);
	}
};
int main(void){
