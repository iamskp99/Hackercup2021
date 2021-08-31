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
unordered_map<char, vector<char>> graph;
unordered_set<char> ele;
unordered_set<char> visited;
string s;
int k;
int val;

void bfs(char node, char x) {
	unordered_map<char, int> level;
	queue<char> q;
	q.push(node);
	level[node] = 0;
	visited.insert(node);
	while (q.size() > 0) {
		node = q.front();
		q.pop();
		// visited.insert(node);
		if (graph.find(node) == graph.end()) {
			continue;
		}
		for (auto child : graph[node]) {
			if (visited.find(child) == visited.end()) {
				level[child] = level[node] + 1;
				visited.insert(child);
				q.push(child);
			}
		}
	}
	if (level.find(x) != level.end()) {
		val = level[x];
	}
	return;
}

void solve(int now) {
	cin >> s;
	cin >> k;
	int ans = 1000000000000000000;
	int i, cnt, n, res, flag;
	char node;
	string aux;
	n = s.length();
	i = 0;
	while (i < n) {
		ele.insert(s[i]);
		i = i + 1;
	}
	i = 0;
	while (i < k) {
		cin >> aux;
		graph[aux[0]].pb(aux[1]);
		// graph[aux[1]].pb(aux[0]);
		i = i + 1;
	}
	for (auto x : ele) {
		cnt = 0;
		flag = 0;
		i = 0;
		while (i < n) {
			visited.clear();
			node = s[i];
			// cout << node << " s " << nline;
			if (node == x) {
				res = 0;
			}
			else {
				val = -1;
				bfs(node, x);
				if (val == -1) {
					flag = 1;
				}
				res = val;
			}
			if (flag == 1) {
				break;
			}
			cnt += res;
			i = i + 1;
		}

		if (flag == 0) {
			ans = min(ans, cnt);
		}
	}
	if (ans == 1000000000000000000) {
		cout << "Case " << "#" << now + 1 << ": " << -1 << nline;
	}
	else {
		cout << "Case " << "#" << now + 1 << ": " << ans << nline;
	}
}
int32_t main() {
	fastIO
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int tests, now;
	// t = 1;
	cin >> tests;
	now = 0;
	int uu = 65;
	// cout << char(uu) << nline;
	while (uu <= 90) {
		ele.insert(char(uu));
		uu += 1;
	}
	while (now < tests) {
		graph.clear();
		visited.clear();
		// ele.clear();
		solve(now);
		now += 1;
	}

	cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}