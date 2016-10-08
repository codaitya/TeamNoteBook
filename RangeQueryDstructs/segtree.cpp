#include <bits/stdc++.h>
using namespace std;

struct STree {
	struct node  {
		int sum;
		node () {} ; //default constructor
		node (int v): sum(v) {};
	};
	vector <node> ST;
	int N; // list size over which ST is built
	STree ( int n ) {
		N = n;
		ST.resize ( 4 * n );
	}
	node merge ( node u, node v ) {
		node t; t.sum = ( u.sum  + v.sum ) % P;
		return t;
	}
	void   update ( int sidx, int lo, int hi, int index, int val) {
		if ( lo == hi ) {
			ST[sidx] = node(val);
			return ;
		}
		int mid = (lo + hi ) / 2;
		if ( index <= mid )
			update ( 2*sidx, lo, mid, index, val);
		else
			update ( 2*sidx+1, mid+1, hi, index, val );
		ST[sidx] =  merge ( ST[sidx*2] ,  ST[sidx*2 + 1] ); 
	}
	node   query ( int sidx, int left, int right, int lo, int hi ) {
		//trace5(sidx,left,right,lo,hi);
		if ( left == lo and right == hi ) return ST[sidx];
		if ( left >= lo and right <= hi ) return ST[sidx];

		if ( lo > right or hi < left ) return 0;

		int mid = (left+right) / 2;
		if ( lo > mid )
			return query (2*sidx+1, mid + 1, right, lo, hi );
		if (hi <= mid )
			return query (2*sidx, left , mid , lo, hi );
		node x = query ( sidx * 2, left, mid, lo, mid);
		node  y = query ( sidx * 2 + 1, mid + 1, right, mid + 1, hi);
		return merge ( x, y ); 
	}	
	void update ( int idx, int val ) {
		update ( 1, 1, N, idx, val);
	}
	node query ( int L, int R ) {
		return query ( 1, 1 , N, L, R );
	}
};

