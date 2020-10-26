#include <iostream>
#include <vector>
#include <string>
using namespace std;

void gen(int k, vector<string>& s, vector<bool>& b, const vector<string>& v, int strt)
{
	if(k == int(s.size())){
		if(k != 0){
			cout << "{" << s[0];
			for(int i = 1; i < int(s.size()); ++i){
				cout << "," << s[i];
			}
			cout << "}" << endl;
		}
	}
	else{
		for(int i = strt; i < int(v.size()); ++i){
			if(not b[i]){
				b[i] = true;
				s[k] = v[i];
				gen(k+1, s, b, v, i);
				b[i] = false;
			}
		}
	}
}

int main()
{
	int n; cin >> n;
	
	int m; cin >> m;
	vector<string> v(m);
	for(int i = 0; i < m; ++i) cin >> v[i];

	vector<bool> b(m, false);
	vector<string> s(n);
	gen(0, s, b, v, 0);
}