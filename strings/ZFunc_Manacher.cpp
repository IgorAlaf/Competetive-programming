
#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <algorithm>
#include <map>
#include <deque>
#include <cstring>
#include <sstream>
#include <string>
#include <cmath>
#include <queue>
#include <math.h>
#include <iomanip>
#include <fstream>
#include <iostream>
#include <unordered_map>
using namespace std;
typedef long long ll;
#define INF 1000000000
#define  MOD 9113823233
#define K 2017
#define EPS 10e-16
#define rep(i,a,b) for (int i=a; i<b; ++i)
#define seea(a,x,y) for(int i=x;i<y;i++){scanf("%d",&a[i]);}
#define vi vector<int>
#define vvi vector<vector<int>>
#define pii pair<int,int>
#define vii vector<pii>


vi z_function(string s) {
	int n =s.size();
	vi z(n, 0);
	int l = 0;
	int r = 0;
	for (int i = 1; i < n; i++) {
		if (i <= r) {
			z[i] = min(r - i + 1, z[i - 1]);
		}
		while (i + z[i] < n && s[z[i]] == s[i + z[i]])z[i]++;
		if (i + z[i] - 1 > r) {
			r = i + z[i] - 1;
			l = i;
		}
	}
	return z;
}
/// include 'a' - as subpalindrome
vi manacher(string s) {
	int n = s.size();
	vi d(n, 1);
	int l = 0, r = 0;
	for (int i = 1; i < n; i++) {
		if (i < r) {
			d[i] = min(r - i + 1, d[l + r - i]);
		}
		while (i - d[i] >= 0 && i + d[i] < n && s[i - d[i]] == s[i + d[i]])d[i]++;
		if (i + d[i] - 1 > r) {
			l = i - d[i] + 1, r = i + d[i] - 1;
		}
	}
	return d;
}

int main(void){}
