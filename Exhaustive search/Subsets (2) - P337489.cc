#include <iostream>
#include <vector>
using namespace std;

int n;
vector<string> v;

void gen(int k, vector<string>& s, int m)
{
	if(int(s.size()) > m) return;
	if(int(s.size()) +n -k < m) return;

	if(k == n){
		cout << "{";
		for(int i = 0; i < m; ++i){
			if(i != 0) cout << ",";
			cout << s[i];
		}
		cout << "}" << endl;
	}
	else{
		s.push_back(v[k]);
		gen(k+1, s, m);
		s.pop_back();

		gen(k+1, s, m);
	}
}

int main()
{
	int m; cin >> m;

	cin >> n;
	v = vector<string> (n);
	for (int i = 0; i < n; ++i) cin >> v[i];

	vector<string> s;
	gen(0, s, m);
}