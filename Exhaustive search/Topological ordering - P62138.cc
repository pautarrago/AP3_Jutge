#include <iostream>
#include <vector>
using namespace std;

vector<vector<bool>> map;

bool legal(int i, int n)
{
	for(int j = 0; j < n; ++j){
		if(not map[i][j]) return false;
	}
	return true;
}

void genstrip(vector<int>& s, int n, vector<bool>& b)
{
	if(int(s.size()) == n){
		for(int i = 0; i < n; ++i){
			if(i != 0) cout << " ";
			cout << s[i];
		}
		cout << endl;
	}
	else{
		for(int i = 0; i < n; ++i){
			if(not b[i] and legal(i, n)){
				s.push_back(i);
				b[i] = true;
				vector<bool> j_col;
				for(int j = 0; j < n; ++j){
					j_col.push_back(map[j][i]);
					map[j][i] = true;
				}
				genstrip(s, n, b);
				s.pop_back();
				b[i] = false;
				for(int j = 0; j < n; ++j) map[j][i] = j_col[j];
			}
		}
	}
}

int main()
{
	int n; cin >> n;
	map = vector<vector<bool>> (n, vector<bool> (n, true));
	int m; cin >> m;
	for(int i = 0; i < m; ++i){
		int a, b;
		cin >> a >> b;
		map[b][a] = false;
	}

	vector<bool> b(n, false);
	vector<int> s;
	genstrip(s, n, b);
}