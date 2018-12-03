#include"WordDecisionMaking.h"

int main()
{
	set<string> wordSet;
	wordSet.insert("arshi");
	wordSet.insert("khan");
	wordSet.insert("khan1");
	wordSet.insert("khan2");
	wordSet.insert("hello");
	wordSet.insert("world");

	CWordSuggestionProcessor wordProcessorObj;
	string sInput;
	cout << "Enter the word : ";
	cin>>sInput;
	wordProcessorObj.checkIfWordExistAndAdd(wordSet,sInput);

	return 0;
}