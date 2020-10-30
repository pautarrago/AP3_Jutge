#include <iostream>
#include <vector>
using namespace std;
typedef long long int lint;

int main()
{
	vector<vector<lint>> s(92, vector<lint> (92, 0));
	s[0][0] = s[1][0] = s[0][1] = s[0][2] = 1;

	int z, o;
	while(cin >> z >> o){

		for(int i = 2; i <= z; ++i){
			for(int j = 2; j <= o; ++j){
				s[i][j] = s[i-1][j] + s[i][j-1];
			}
		}

		cout << s[z+1][o+1] << endl;
	}
}