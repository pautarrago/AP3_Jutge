#include <iostream>
#include <vector>
using namespace std;

const int oo = 1000000;

int main()
{
	int x, y;
	cin >> x >> y;
	while(x != 0 or y != 0){
		vector<vector<long long int>> grid(x+1, vector<long long int> (y+1, 0));
		grid[1][1] = 1;

		for(int i = 1; i <= x; ++i){
			for(int j = 1; j <= y; ++j){
				char c; cin >> c;
				if(c != 'X'){
					grid[i][j] += grid[i-1][j] + grid[i][j-1];
					if (grid[i][j] >= +oo) grid[i][j] = +oo;
				}
			}
		}
		cout << (grid[x][y] < 1000000 ? to_string(grid[x][y]) :  "!!!") << endl;

		cin >> x >> y;
	}
}