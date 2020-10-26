#include <iostream>
#include <vector>
using namespace std;

void generatestrip(vector<int>& v, int i, int n){
	if(i == n){
		for(int j = 0; j < int(v.size()); ++j){
			if(j > 0) cout << " ";
			cout << v[j];
		}
		cout << endl;
	}
	else{
		for(int j = 0; j < 2; ++j){
			v[i] = j;
			generatestrip(v, i + 1, n);
		}
	}
}

int main(){
	int n;
	cin >> n;
	vector<int> v(n);
	generatestrip(v, 0, n);
}