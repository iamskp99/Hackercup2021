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
int n;
vector<string> mat;
unordered_map<int, int> graph;

void solve(int now) {
	cin >> n;
	string s;
	int ans, i, j, cnt, flag, e1, e2, rom, cnt1;
	i = 0;
	while (i < n) {
		cin >> s;
		mat.pb(s);
		i = i + 1;
	}
	ans = 1000000000000000000;
	i = 0;
	while (i < n) {
		j = 0;
		cnt = 0;
		flag = 0;
		while (j < n) {
			if (mat[i][j] == 'O') {
				flag = 1;
				break;
			}
			if (mat[i][j] == '.') {
				cnt += 1;
			}
			j = j + 1;
		}
		if (flag == 0) {
			ans = min(ans, cnt);
			graph[cnt] += 1;
		}
		i = i + 1;
	}
	// cout << ans << " " << graph[ans] << nline;
	i = 0;
	while (i < n) {
		j = 0;
		cnt = 0;
		flag = 0;
		while (j < n) {
			if (mat[j][i] == 'O') {
				flag = 1;
				break;
			}
			if (mat[j][i] == '.') {
				cnt += 1;
			}
			j = j + 1;
		}
		if (flag == 0) {
			ans = min(ans, cnt);
			graph[cnt] += 1;
		}
		i = i + 1;
	}
	if (ans == 1) {
		i = 0;
		while (i < n) {
			j = 0;
			while (j < n) {
				if (mat[i][j] == '.') {
					rom = 0;
					e1 = 0;
					cnt1 = 0;
					flag = 0;
					while (e1 < n) {
						if (mat[i][e1] == 'O') {
							flag = 1;
							break;
						}
						if (mat[i][e1] == '.') {
							cnt1 += 1;
						}
						e1 = e1 + 1;
					}
					if (flag == 0) {
						if (cnt1 == 1) {
							rom += 1;
						}
					}
					// rom = 0;
					e1 = 0;
					cnt1 = 0;
					flag = 0;
					while (e1 < n) {
						if (mat[e1][j] == 'O') {
							flag = 1;
							break;
						}
						if (mat[e1][j] == '.') {
							cnt1 += 1;
						}
						e1 = e1 + 1;
					}
					if (flag == 0) {
						if (cnt1 == 1) {
							rom += 1;
						}
					}
					if (rom == 2) {
						graph[ans] -= 1;
					}
				}
				j = j + 1;
			}
			i = i + 1;
		}
	}
	if (ans == 1000000000000000000) {
		cout << "Case #" << now + 1 << ": " << "Impossible" << nline;
		return;
	}
	cout << "Case #" << now + 1 << ": " << ans << " " << graph[ans] << nline;
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