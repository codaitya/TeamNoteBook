#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <ll, ll> pll;
typedef pair <int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector < vector<int> > vvi;
typedef vector < vector<ll> > vvl;

#define sl(x) scanf("%lld", &x); //s(x) is for long long int.
#define si(x) scanf("%d", &x);

#define debug true
#define ok if(debug)
#define trace(x) ok cerr << #x << ": " << x << endl;
#define trace2(x, y) ok cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)    ok      cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)  ok cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | "  << #d << ": " << d << endl;
#define trace5(a, b, c, d, e) ok cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
#define trace6(a, b, c, d, e, f) ok cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;
#define rep(i, a, b) \
		for (int i = int(a); i <= int(b); i++)
#define nrep(i,a,b) \
		for (int i = int(a); i >= int(b); i--)
#define trv(it, c) \
		for (auto it = (c).begin(); it != (c).end(); it++)
#define mkp make_pair
#define pb push_back
#define X first
#define Y second

#define MOD 1000000007 //10^9 + 7

int vist[26][26];
int vis[26];
vector <int> g[30];
int dp[30];
int cyclepresent = 0;
int cyclenode = 0;
int parent[30];

vector <char> cycle;
void  dfs ( int u ,int par) {
	if ( vis[u] == 2 ) return;
	parent[u] = par;
	if ( vis[u] == 1 ) {
		cyclepresent = 1;
		cyclenode = u;
		throw u;
	}

	vis[u] = 1;
	for ( int i = 0; i < g[u].size(); i++ ) {
		int v = g[u][i];
		dfs ( g[u][i] , u);
		dp[u] = max ( dp[u], dp[v] + 1);
	}
	vis[u] = 2;
}
void printsquare ( string str) {
	for ( int i = 0; i < 20; i ++ ) {
		for ( int j = i; j < i + 20; j ++ )
			cout <<str[j];
		cout << endl;
	}
}
int main()
{
	int t;
	si (t);
	while ( t -- ) {
		int n;
		si(n);
		memset ( vist, 0, sizeof (vist) ) ;
		memset ( dp, 0, sizeof ( dp ) );
		memset (parent, 0, sizeof(parent) );
		cyclepresent = 0;

		for ( int i = 0; i < n; i ++ ) {
			char str[2];
			scanf ("%s", str);
			vist[str[0] - 'a'][str[1] - 'a'] = 1; 
		}
		rep ( i, 0, 25) g[i].clear();

		rep ( i, 0, 25)
			rep ( j, 0, 25 ) {
				if ( !vist[i][j] ) {
					g[i].pb(j);
				}
			}
		memset ( vis, 0, sizeof (vis) ) ;

		for  (int i = 0; i <= 25; i ++ ) {
			try { 
			dfs ( i , - 1);
			}
			catch ( int x ) { 
			if ( cyclepresent == 1 )  {
					//trace ( cyclenode);
					//trace (cyclepresent);
					string ss = "";
					for ( int i = 0; i <= 39;  i++ ) {
						ss =  char ( 'a' + cyclenode ) + ss;
						cyclenode = parent[cyclenode];
					}
				printsquare(ss);
				break;
			} }
		}

		if ( cyclepresent == 1 ) continue;

		int mx = 0;
		for ( int i = 0; i < 26; i++ ) {
			if ( dp[i] >= dp[mx] ) mx = i;
		}
		string str = "";
		int cur = mx;
		for ( int i = dp[mx]; i > 0; i -- ) {
			str = str + char ('a' + cur );
			int j;
			for ( j = 0; j < 26; j++ ) {
				if ( dp[j] == dp[cur] - 1 and vist[cur][j] == 0 ) {
					cur = j;
					break;
				}
			}
		}
		str = str + char ('a' + cur );
		
		for ( int i = 0; i < (str.size() + 1) / 2; i ++ ) {
			for ( int j = 0; j < (str.size() + 1) / 2; j ++ ) 
				cout << str[i+j];
			cout << endl;
		}
	}
	return 0;
}

