#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	vector<vector<int>> inp;
	string line;
	while(cin >> line){
		vector<int> r_inp;
		for(char c : line) r_inp.push_back(int(c - 'A' +1)*(int(c - 'A' +1) +1)/2);
		inp.push_back(r_inp); 
	}

	int r = int(inp.size());
	int c = int(inp[0].size());
	vector<vector<int>> R (r+1, vector<int> (c+1, 0));

	for(int i = 1; i <= r; ++i){
		for(int j = 1; j<= c; ++j){
			R[i][j] = R[i-1][j] + R[i][j-1] - R[i-1][j-1] + inp[i-1][j-1];

			if(j != 1) cout << " ";
			cout << R[i][j];
		}
		cout << endl;
	}
}