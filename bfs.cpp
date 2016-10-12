#include <bits/stdc++.h>
using namespace std;


#define MOD 1000000007 //10^9 + 7

#define inf 10000000
int dis[3700];
int vis[3700];
int ar[20];

int main()
{
	int t;
	scanf ("%d", &t);
	while ( t-- ) {
		int n; scanf ("%d", &n);
		int xx; scanf ("%d", &xx);
		memset (vis, 0, sizeof(vis) );
		queue <int> q;
		for ( int i = 0; i < n; i++)  scanf ("%d", &ar[i] );
		for ( int i = 0; i <= 3650; i ++ ) dis[i] = inf;
		q.push(0);
		dis[0] = 0;
		while ( ! q.empty () ) {
			int  tmp = q.front();
			q.pop();
			for ( int i = 0; i < n; i++ ) {
				int x = tmp + ar[i];
				if ( x > 3600) x = 3600;
				if ( x < 0 ) x = 0;
				if ( dis[x] >  dis[tmp] + 1 ) {
					q.push(x);
					dis[x] = dis[tmp] + 1;//equivalent to setting vis
				}
			}
		}
		for ( int i = xx; i <= 3600; i++ ){
			if ( dis[i] < inf ) {
				printf ("%d %d\n", dis[i], i - xx );
				break;
			}
		}
	}
	return 0;
}
