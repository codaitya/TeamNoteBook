class SparseTable {
	vector < vector < ll > > ST;
	int N;

	public :SparseTable ( ) { };
	public : SparseTable ( int n, ll  * ar ) {
		N = n;
		int sz = ceil ( log2(n) )+  1;
		ST.resize ( n + 1);
		for ( int i = 0; i < N; i ++ ) {
			ST[i].resize(sz);
		}
		for ( int i = 0; i < n;  i++ ) {
			ST[i][0] = ar[i];
		}
		cal();
	}
	void cal()
	{
		int i, j;
		//compute values from smaller to bigger intervals
		for (j = 1; 1 << j <= N; j++)
			for (i = 0; i + (1 << j) - 1 < N; i++)
				ST[i][j] = hcf ( ST[i][j - 1], ST[i + (1 << (j - 1))][j - 1] );
	}
	ll query (int i, int j ) {
		int k = log2 ( j - i + 1 );
		ll y = ST[i][k];
		ll z = ST[j - (1 << k ) + 1][k];
		return hcf ( y, z ); //Replace it by any required function
	}
	
};

