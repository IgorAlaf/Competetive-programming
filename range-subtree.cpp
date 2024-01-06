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
int32_t n, q;
int64_t  fenvick[500500];

void add(int32_t k, int32_t x) {
	while (k <= n) {
		fenvick[k] += x;
		k += k & -k;
	}
}
int64_t sum(int32_t k) {
	int64_t res = 0;
	while (k >= 1) {
		res += fenvick[k];
		k -= k & -k;
	}
	return res;
}

int32_t main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	vvi adjList(n + 1);
	for (int i = 1; i < n; i++) {
		int32_t u, v;
		cin >> u >> v;
		adjList[u].push_back(v);
		adjList[v].push_back(u);
	}

	int32_t pos = 0;
	vi left(n + 1), right(n + 1);
	function<void(int, int)> euler_tour = [&](int32_t u, int32_t  p) {
		left[u] = ++pos;
		for (int v : adjList[u]) {
			if (v == p)continue;
			euler_tour(v, u);
		}
		right[u] = pos;
		};
	euler_tour(1, 0);
	for (int32_t i = 1; i <= n; i++) {	
		int32_t x;
		cin >> x;
		add(left[i], x);
	}
	cin >> q;
	while (q--) {
		int32_t u, x;
		cin >> u >> x;
		cout << sum(right[u]) - sum(left[u] - 1) << "\n";
		add(left[u], x - (sum(left[u]) - sum(left[u]-1)));
	}
	return 0;
}
