#include <bits/stdc++.h>
#define ll long long
#define int long long
#define pb(x) push_back(x)
#define gcd(x,y) __gcd(x,y)
#define tostr(x) to_string(x)
#define vi vector<int>
#define mii map<int,int>
#define umap unordered_map
#define ff first
#define ss second
#define INF 1e18
#define sastaINF 1e9
#define nline "\n"
#define PI 3.141592653589793238462
const ll MOD = 1000000007;
const ll MOD1 = 998244353;
#define fastIO  ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;

/////////////////////////// Functions /////////////////////////////
bool sortbysec(const pair<ll, ll> &a,
               const pair<ll, ll> &b)
{
	return (a.second < b.second);
}

string to_binary(int x) {
	//It will will give result in reverse (eg binary of 4 = 001).
	string w = "";
	string r;
	int e;
	while (x > 0) {
		e = x % 2;
		r = tostr(e);
		w = w + r;
		x = x / 2;
	}
	return w;
}

///////////////////////////////////////////////////////////////////

void solve(int now) {

}

int32_t main() {
	fastIO
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int tests;
	cin >> tests;
	int now = 0;
	while (now < tests) {
		mat.clear();
		graph.clear();
		solve(now);
		now = now + 1;
	}

	cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}