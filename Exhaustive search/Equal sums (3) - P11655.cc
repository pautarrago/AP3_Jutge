#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> v;

void genstrip(int t_s, int k, vector<int>& s, int p_s, int r_s)
{
	if(p_s > t_s or p_s + r_s < t_s) return;
	if(k == n){
		cout << "{";
		for(int i = 0; i < int(s.size()); ++i){
			if(i != 0) cout << ",";
			cout << s[i];
		}
		cout << "}" << endl;
	}
	else{
		s.push_back(v[k]);
		genstrip(t_s, k+1, s, p_s + v[k], r_s - v[k]);
		s.pop_back();

		genstrip(t_s, k+1, s, p_s, r_s - v[k]);
	}
}

int main(){
	int t_s;
	cin >> t_s >> n;
	v = vector<int> (n);

	int r_s = 0;
	for(int& i : v){
		cin >> i;
		r_s += i;
	}

	vector<int> s;
	genstrip(t_s, 0, s, 0, r_s);
}