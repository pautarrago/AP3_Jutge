#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int a, b;
	while(cin >> a >> b)
	{
		vector<int> A(a);
		vector<int> B(b);
		for(int& c : A) cin >> c;
		for(int& c : B) cin >> c;

		vector<vector<int>> s(a, vector<int> (b, 0));

		for(int i = 0; i < a; ++i){
			for(int j = 0; j < b; ++j){
				if(A[i] == B[j]) s[i][j] = 1;
			}
		}

		for(auto i : s){
			for(auto j : i){
				cout << j << " ";
			}
			cout << endl;
		}
	}
}