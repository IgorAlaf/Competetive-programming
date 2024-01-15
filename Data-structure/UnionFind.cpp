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
using namespace std;
typedef long long ll;
#define vi vector<int> 
#define f first 
#define s second 
#define pb push_back 
#define vii vector<pair<int,int» 
#define vvi vector<vector<int» 
#define vvpi vector<vector<pair<int,int»> 
#define pii pair<int,int> 
#define MOD 1000000007 
#define vl vector<int64_t> 
#define vvl vector<vector<int64_t» 
#define vd vector<double> 
#define vvd vector<vector<double» 
#define isz(x) (x).size() 
const int N = 1e15 + 9;
void setmin(int& x, int y) {
	if (y < x)x = y;
}
void setmax(int& x, int y) {
	if (y > x)x = y;
}
void setminl(int64_t& x, int64_t y) {
	if (y < x)x = y;
}
void setmaxl(int64_t& x, int64_t y) {
	if (y > x)x = y;
}

struct UnionFind {
	vi parent;
	vi size;
	int n;
	UnionFind(int n) {
		parent.resize(n + 1);
		size.resize(n + 1);
		this->n = n;
	}
	void init(int cc) {
		for (int i = 0; i < cc; i++) {
			make_pair(i);
		}
	}
	void make_pair(int v) {
		size[v] = 1;
		parent[v] = v;
	}
	int find_set(int v) {
		if (parent[v] == v) {
			return v;
		}
		return parent[v] = find_set(parent[v]);
	}
	void union_sets(int a, int b) {
		int a = find_set(a);
		int b = find_set(b);
		if (a != b) {
			if (size[a] < size[b])swap(a, b);
			parent[b] = a;
			size[a] += size[b];
		}
	}
};


int main(void){}
