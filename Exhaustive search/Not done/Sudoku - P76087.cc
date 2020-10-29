#include <iostream>
#include <vector>
using namespace std;

bool done;

bool legal(int k, int i, const vector<vector<int>>& sudoku)
{
	int x = k/9;
	int y = k%9;
	for(int j = 0; j < 9; ++j){
		if(sudoku[x][j] == i or sudoku[j][y] == i or sudoku[3*(x/3) + j/3][3*(y/3) + j%3] == i) return false;
	}
	return true;
}

void solve(int k, vector<vector<int>>& sudoku)
{
	if(done) return;
	if(k == 81){
		for(int i = 0; i < 9; ++i){
			for(int j = 0; j < 9; ++j){
				if(j != 0) cout << " ";
				cout << sudoku[i][j];

			}
			cout << endl;
		}
		done = true;
	}
	else if(sudoku[k/9][k%9] == -1){
		for(int i = 1; i < 10; ++i){
			if(legal(k, i, sudoku)){
				int x = k/9;
				int y = k%9;
				sudoku[x][y] = i;
				solve(k+1, sudoku);
				sudoku[x][y] = -1;
			}
		}
	}
	else solve(k+1, sudoku);
}

int main()
{
	int n; cin >> n;
	for(int i = 0; i < n; ++i){
		vector<vector<int>> sudoku(9, vector<int> (9));
		for(auto& r : sudoku){
			for(auto& e : r){
				char x; cin >> x;
				e = (x == '.' ? -1 : x - '0');
			}
		}
		done = false;
		solve(0, sudoku);
	}
}