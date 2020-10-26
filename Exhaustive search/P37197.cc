#include <iostream>
#include <vector>
using namespace std;

void gen_comp(vector<char>& s, const vector<char>& species, vector<bool>& b, const vector<vector<bool>>& incomp)
{
	if(int(s.size()) == int(species.size())){
		for(auto c : s) cout << c;
		cout << endl;
	}
	else{
		for(int i = 0; i < int(species.size()); ++i){
			if(not b[i] and (int(s.size()) == 0 or not incomp[s.back() - 'A'][species[i] - 'A'])){
				s.push_back(species[i]);
				b[i] = true;
				gen_comp(s, species, b, incomp);
				s.pop_back();
				b[i] = false;
			}
		}
	}
}

int main()
{
	int n; cin >> n;
	vector<char> species(n);
	for(auto& c : species) cin >> c;

	int n_letters = 'z' - 'A' +1;
	vector<vector<bool>> incomp(n_letters, vector<bool> (n_letters, false));
	int m; cin >> m;
	for(int i = 0; i < m; ++i){
		char species1, species2;
		cin >> species1;
		cin >> species2;

		incomp[species1 - 'A'][species2 - 'A'] = true;
		incomp[species2 - 'A'][species1 - 'A'] = true;
	}

	vector<bool> b(n, false);
	vector<char> s;
	gen_comp(s, species, b, incomp);
}

