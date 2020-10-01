/*
author: Apoorv Singh
*/
 
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace std;
using namespace __gnu_pbds;
 
typedef vector <int> vi;
typedef pair <int, int> pii;
typedef vector <long long> vll;
typedef pair <long long, long long> pll;
#define pb push_back   
#define all(c) c.begin(), c.end()
#define For(i, a, b) for (long long i = a; i < b; ++i)
#define Forr(i, a, b) for (long long i = a; i > b; --i)
#define um unordered_map
#define F first
#define S second
#define ll long long 
#define endl "\n"
#define min(a,b) (a < b ? a : b)
#define max(a,b) (a > b ? a : b)
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

#define TRACE
#ifndef ONLINE_JUDGE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
	cout << name << " : " << arg1 << endl;  
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
	const char* comma = strchr(names + 1, ',');cout.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif

template <class X>
void printarr(X arr[], int n) 
{
	for (int i = 0; i < n; ++i)
		cout << arr[i] << ' ';
	cout << endl;
}
 
template <class T, class cmp = less<T>> using ordered_set = tree<T, null_type, cmp, rb_tree_tag, tree_order_statistics_node_update>;
 
ll modulo = 1e9 + 7;

ll fpow(ll a, ll n) 
{
	ll ans = 1;
	while (n) 
	{
		if (n&1) ans = (ans*a)%modulo;
		a = (a*a)%modulo; n = n >> 1;
	}
	return ans;
}

const int N = 2e5 + 10;
vector <int> graph[N];
bool visited[N];
ll a[N], b[N], val[N];
stack <ll> st;

void dfs(int source)
{
	visited[source] = 1;
	for (int a : graph[source])
	{
		if (!visited[a]) dfs(a);
	}
	st.push(source);
}

void solve() 
{
	int n;
	cin >> n;
	For(i,1,n+1) cin >> a[i];
	For(i,1,n+1) 
	{
		cin >> b[i];
		if (b[i] != -1) graph[i].pb(b[i]);
	}
	For(i,1,n+1) visited[i] = 0;				
	For(i,1,n+1)
	{
		if (!visited[i]) dfs(i);
	}
	For(i,1,n+1) val[i] = 0;
	ll ans = 0;
	vector <int> faulty;
	vector <int> proper;
	while (!st.empty())
	{
		int node = st.top();
		st.pop();
		ll x = val[node] + a[node];
		ans += x;
		if (x < 0) 
		{
			faulty.pb(node);
			continue;
		}
		if (graph[node].size() > 0)
		{
			val[graph[node][0]] += x;
		}
		proper.pb(node);
	}
	cout << ans << endl;
	reverse(all(faulty));
	for (int a : proper) cout << a << ' ';
	for (int a : faulty) cout << a << ' ';
	cout << endl;
}

int main() 
{
	fast_io();
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int t = 1;
	// cin >> t;
	while (t--) solve();
	return 0;
}
