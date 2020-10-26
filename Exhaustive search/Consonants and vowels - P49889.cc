#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void genwords(vector<char>& s, int n, const vector<char>& csts, vector<bool>& b_csts, const vector<char>& vwls, vector<bool>& b_vwls)
{
	if(int(s.size()) == 2*n){
		for(auto c : s) cout << c;
		cout << endl;
	}
	else{
		if(int(s.size())%2 == 0){
			for(int i = 0; i < n; ++i){
				if(not b_csts[i]){
					s.push_back(csts[i]);
					b_csts[i] = true;
					genwords(s, n, csts, b_csts, vwls, b_vwls);
					s.pop_back();
					b_csts[i] = false;
				}
			}
		}
		else{
			for(int i = 0; i < n; ++i){
				if(not b_vwls[i]){
					s.push_back(vwls[i]);
					b_vwls[i] = true;
					genwords(s, n, csts, b_csts, vwls, b_vwls);
					s.pop_back();
					b_vwls[i] = false;
				}
			}
		}
	}
}

int main()
{
	int n; cin >> n;
	vector<char> csts(n);
	for(auto& c : csts) cin >> c;
	vector<char> vwls(n);
	for(auto& c : vwls) cin >> c;

	sort(csts.begin(), csts.end());
	sort(vwls.begin(), vwls.end());
	vector<bool> b_csts(n, false);
	vector<bool> b_vwls(n, false);

	vector<char> s;
	genwords(s, n, csts, b_csts, vwls, b_vwls);
}