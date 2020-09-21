#include <iostream>
#include <vector>
#include <set>
#include <string>
using namespace std;

void subset(int m, set<string> S, vector<string>& subS)
{
	if(int(subS.size()) == m)
	{

		cout << "{";
		if(m != 0){
			cout << subS[0];
			for(int i = 1; i < int(subS.size()); ++i){
				cout << "," << subS[i];
			}
		}
		cout << "}" << endl;
	}

	while(not S.empty())
	{
		auto it = S.begin();
		string curr_s = *it;
		S.erase(it);

		subS.push_back(curr_s);
		subset(m, S, subS);
		subS.pop_back();
	}
}

int main()
{
	int m; cin >> m;
	int n; cin >> n;
	set<string> S;
	for(int i = 0; i < n; ++i){
		string s; cin >> s;
		S.insert(s);
	}

	vector<string> subS;
	subset(m, S, subS);
}