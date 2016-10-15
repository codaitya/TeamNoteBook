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

#define debug false
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
#define inf 100000000

typedef pair <int, pii > piii;
vector < pii > G[1000];
int price[1007];
int dis[1007][110];
//implementation from nordic programming contest
int main()
{
	int n;
	si (n);
	int m;
	si (m);
	rep ( i, 0, n-1 ) si ( price[i] );
	rep ( i, 0, m - 1 ) {
		int u, v, w;
		si (u); si(v);si(w);
		G[u].pb ( mkp ( v, w ) );
		G[v].pb ( mkp ( u, w ) );
	}
	int q;
	si (q);
	while ( q -- ) {
		int cap;
		si (cap);
		int u, v; 
		si(u);si(v);
		priority_queue < piii  , vector <piii>, greater<piii>  > pq;
		for ( int i = 0; i <= n; i++ )
			for ( int  j = 0; j <= cap; j++)
				dis[i][j] = inf;
		pq.push(mkp ( 0,  mkp ( u, 0) ) ) ; //price  node fuel
		dis[u][0] = 0;
		while ( ! pq.empty () ) {
			auto tmp = pq.top();
			int cost = tmp.X;
			int node = tmp.Y.X;
			int frem = tmp.Y.Y;
			trace3(cost,node,frem);
			if ( node == v ) break;
			pq.pop();
			if ( dis[node][frem] < cost ) continue;
			//go to adjacent 
			for ( int i = 0; i < G[node].size(); i ++ ) {
				int neb = G[node][i].X;
				int ec = G[node][i].Y;
				if ( cap < ec ) continue;
				if ( frem >= ec  and dis[neb][frem - ec ] >  cost ) {
					dis[neb][frem - ec ] = cost;
					pq.push ( mkp ( cost, mkp (neb ,frem - ec ) ) );
				}
			}
			if ( frem + 1 <= cap) {
				if ( dis[node][frem+1] > cost + price[node]) {
					dis[node][frem+1] = cost + price[node];
					pq.push ( mkp ( cost + price[node] , mkp ( node, frem + 1) ) );
				}
			}
		}
		int ans = inf;
		for ( int i = 0; i <= cap; i ++ ) ans = min ( ans , dis[v][i] );
		if ( ans == inf ) cout <<"impossible"<<endl;
		else cout << ans<<endl;
	}
	return 0;
}

