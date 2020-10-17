#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

void gen(int k, vector<string>& w, map<int, vector<string>>& M)
{
	if(k == int(w.size())){
		for(auto it = M.begin(); it != M.end(); ++it){
			cout << "subset " << it->first << ": {";
			if(int(it->second.size()) != 0){
				cout << it->second[0];
				for(int i = 1; i < int(it->second.size()); ++i){
					cout << "," << it->second[i];
				}
			}
			cout << "}" << endl;
		}
		cout << endl;
	}
	else{
		for(int j = 1; j <=int(M.size()); ++j){
			M[j].push_back(w[k]);
			gen(k+1, w, M);
			M[j].pop_back();
		}
	}
}

int main()
{
	int n; cin >> n;
	vector<string> w(n);
	for(int i = 0; i < n; ++i) cin >> w[i];

	int p; cin >> p;
	map<int, vector<string>> M;
	for(int i = 1; i <= p; ++i) M[i] = {};

	gen(0, w, M); 
}