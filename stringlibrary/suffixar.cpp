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
string str; //lowercase characters
int n;
int sa[100005]; 
int rnk[100005]; //rnk[i] is the rnk of the suffix at ith position in suffix array
int lcp[100005];
int tmp[100005];
int cnt;
bool mycmp(int x, int y) {
	if (rnk[x] != rnk[y])
		return rnk[x] < rnk[y];
	x += cnt;
	y += cnt;
	if (x < n and y < n)
		return rnk[x] < rnk[y];
	return (x > y);
}
//time n*((logn)^2)
void buildsa()
{
	rep(i,0,n-1) {
		rnk[i] = str[i] - 'A';
		sa[i] = i;
	}
	for (cnt = 1; cnt < n; cnt *= 2) {
		sort(sa,sa+n,mycmp);
		rep(i,1,n-1) 
			tmp[i] = tmp[i-1]+mycmp(sa[i-1],sa[i]);
		rep(i,0,n-1)
			rnk[sa[i]] = tmp[i];
		if (rnk[sa[n-1]] == n-1)
			break;
	}
}
//Kasai builds lcp in o(n)
void kasai()
{
	int k = 0;
	rep(i,0,n-1) {
		if (rnk[i] == n-1) {
			k = 0;
			continue;
		}
		int j = sa[rnk[i]+1]; 
		while(i+k < n and j+k < n and str[i+k] == str[j+k])
			k++;
		lcp[rnk[i]] = k;
		if (k > 0)
			k--;
	}
}
