#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n;
	while(cin >> n){
		if(n%2 == 1) cout << 0 << endl;
		else{
			n = n/2;

			vector<long long int> cat_n (n+1, 0);
			cat_n[0] = 1;

			
			for(int i = 0; i < n; ++i){
				for(int j = 0; j <= i; ++j){
					int k = i -j;
					cat_n[i+1] += cat_n[j]*cat_n[k];
				}
			}

			cout << cat_n[n] << endl;
		}
	}
}