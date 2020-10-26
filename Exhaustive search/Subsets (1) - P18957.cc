#include <iostream>
#include <vector>
#include <string>
using namespace std;

void subsets(vector<string> prev_words, vector<string> left_words)
{
	if(int(prev_words.size()) != 0 and prev_words[int(prev_words.size()) -1] == "")
	{
		cout << "{" << prev_words[0];
		for(int i = 1; i < int(prev_words.size()) -1; ++i) cout << "," << prev_words[i];
		cout << "}" << endl;
		return;
	}

	while(int(left_words.size()) != 0)
	{	
		string word = left_words[0];
		
		left_words = {left_words.begin() +1, left_words.end()};
		prev_words.push_back(word);

		subsets(prev_words, left_words);

		prev_words.pop_back();
	}
}

int main()
{
	int n; cin >> n;
	vector<string> words(n);
	for(int i = 0; i < n; ++i) cin >> words[i];
	words.push_back("");

	subsets({}, words);
}