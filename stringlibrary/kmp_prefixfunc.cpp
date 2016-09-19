#include <bits/stdc++.h>
using namespace std;

int h[100007];
void compute_func(char * pattern) {
	long long  plen = strlen(pattern);
	plen --;
	h[0] = -1;
	long long int k  = -1;   // here h[i] means that the suffix matches till ar[i] of string
	for (long  long int q  = 1; q <= plen; q++){
		while ( k >  -1 && pattern[k + 1] != pattern[q])
			k = h[k];
		if (pattern[k+1] == pattern[q])
			k = k + 1;
		h[q] = k;
	}
}



void kmpi (char * text, char * pattern) {
	//compute_func();
	long long tlen = strlen(text);
	long long plen = strlen(pattern);
	plen --;
	long long int q = -1;
	//long long int count = 0;


	for (long long int i = 0; i < tlen; i++){
		while (q > -1 && pattern[q + 1] != text[i])
			q = h[q];

		if (pattern [q + 1] == text [i])
			q  = q + 1;
		if (q == plen ){
			// match found here 
			//printf ("%lld\n",i - plen);
			q = h[q];
		}
	}

}
int main (){
	return 0;
}
