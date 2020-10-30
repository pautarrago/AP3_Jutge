#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	int n;
	while(cin >> n){
		vector<long long int> cost(n);
		for(auto& i : cost) cin >> i;
		vector<int> count(n, 0);

		string w1, w2;
		cin >> w1;
		cin >> w2;
		int s_w1 = int(w1.size()), s_w2 = int(w2.size());

		string w3;
		for(int i = 0; i < (s_w1 > s_w2 ? s_w1 : s_w2); ++i){
			if(i < s_w1){
				w3 += w1[i];
			}
			if(i < s_w2){
				w3 += w2[i];
			}
		}
		cout << w3 << endl;
	}
}