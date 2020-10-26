#include <iostream>
#include <vector>
using namespace std;

void generatestrip(vector<int>& v, int i, int n, int k, int o, int l){
	if(i == n){
		for(int j = 0; j < int(v.size()); ++j){
			if(j > 0) cout << " ";
			cout << v[j];
		}
		cout << endl;
	}
	else{
		if(l != n - o){
			v[i] = 0;
			generatestrip(v, i + 1, n, k, o, l + 1);
		}
		if(k != o){
			v[i] = 1;
			generatestrip(v, i + 1, n, k + 1, o, l);
		}
	}
}

int main(){
	int n, o;
	cin >> n >> o;
	vector<int> v(n);
	generatestrip(v, 0, n, 0, o, 0);
}