//Christian Martinez CS 251 Data Structures Project 4
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;  
void ssort(string &s) {

	std::sort(s.begin(), s.end());
}

int main(int argc, char *argv[]) {

	unordered_map<string, vector<string>> word2pos;
	ifstream file;
	string word;
	string key;
	int wordCount = 0;
	int numClasses = 0;
	int counter = 0;
	string largestClassKey = " ";
	if (argc != 2) {
		cout << "usage:  ./freq <filename>\n";
		cout << "goodbye\n";
		return 1;
	}
	file.open(argv[1],ios::in);

	if (!file.is_open()) {
		cout << "Error: could not open file '" <<
			argv[1] << "'\n";
		cout << "goodbye\n";
		return 1;
	}

	std::cout << "reading input file...\n";

	counter = 0;
	while (file >> word) {
		wordCount++;
		key = word;
		ssort(key);
		word2pos[key].push_back(word);

		if (counter < word2pos[key].size()) {
			largestClassKey = key;
			counter = word2pos[key].size();
		}

	}

	cout << "enter a word and I will tell you what I know about it\n";
	cout <<	"  when you are done, type ctrl-d (ctrl-z on windows)\n\n";
	cout << "> ";

	
	int fact = word2pos.size();
	while(cin >> word) {
		key = word;
		ssort(key);
	  if(word2pos.count(key)==0) {
		cout << "sorry, '" << word << "' does not appear in the input file '" << argv[1] << "'\n";
	  }
	  else {
		  cout << "English Anagrams Found:" << endl;
		  for (int i = 0; i < word2pos[key].size(); i++) 
			  cout << word2pos[key].at(i) << endl;
		}
	  
	  cout << "> ";
	}
	// user has quit.  Let's dump the map contents

	cout << "Report:\n\n";
	cout << "num_words: " << wordCount <<endl; 
	cout << "num_classes : " << word2pos.size() <<endl;
	cout << "size - of - largest - class : " << counter <<endl;
	cout << "largest - class key : " << largestClassKey << endl;
	cout << "members of largest class : "  <<endl << endl; 

	for (int i = 0; i < counter; i++)
		cout << word2pos[largestClassKey].at(i) << endl;
	
	return 0;
}