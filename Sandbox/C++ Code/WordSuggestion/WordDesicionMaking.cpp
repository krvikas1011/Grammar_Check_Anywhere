#include<stack>
#include<vector>
#include"WordDecisionMaking.h"

/////////////////////////////////////////////////////////////////////////////
/// \Function name      void checkIfWordExistAndAdd
/// \Brief              Checks if the word exist in the set of words and then add the
///						user input string to the list based on the user choice
///
///
/// \Returns            void
///
/// \Parameter          set<string> wordSet - set of words to be populated
/// \Parameter          string sInput - users input string
/////////////////////////////////////////////////////////////////////////////
void CWordSuggestionProcessor::checkIfWordExistAndAdd(set<string>& wordSet, string sInput)
{
	set<string>::iterator it;
	map<int, string> mapOfSuggestedWords;
	int idx = 1;

	if (!wordSet.empty())
	{
		auto pos = wordSet.find(sInput);
		if (pos == wordSet.end())
		{
			createMapOfSuggestedWords(mapOfSuggestedWords, wordSet, sInput);

			cout << "\n****************************************\n";
			cout<<"\nFollowing are the suggestions? Do you want to select any of these?\n";
			for (map<int, string>::iterator it1 = mapOfSuggestedWords.begin(); it1 != mapOfSuggestedWords.end(); it1++)
			{
				cout << it1->second << "	Press :  " << it1->first << endl;
			}

			cout << "\nElse press 0 for adding typed word ";
			int iUserChoice = getUserChoice();
			addToList(iUserChoice, sInput, mapOfSuggestedWords, wordSet);

		}
		else
		{
			cout << "Element Exist in the set\n";
			system("pause");
			return;
		}
	}
	else
	{
		addToList(sInput, wordSet);
	}
}

/////////////////////////////////////////////////////////////////////////////
/// \Function name      void createMapOfSuggestedWords
/// \Brief              Creates a map of suggested words from the list
///
///
/// \Returns            void
///
/// \Parameter          map<int, string>& mapOfSuggestedWords - Updates the map
///	\Parameter			set<string> wordSet - set of words to be populated
/// \Parameter          string sInput - User input string for which suggestions should be generated
/////////////////////////////////////////////////////////////////////////////
void CWordSuggestionProcessor::createMapOfSuggestedWords(map<int, string>& mapOfSuggestedWords, set<string> wordSet, string sInput)
{
	int idx = 1;
	for (set<string>::iterator it = wordSet.begin(); it != wordSet.end(); it++)
	{
		string strExistingWord = *it;
		bool flag = matchesSubString(strExistingWord, sInput);
		if (flag)
		{
			mapOfSuggestedWords[idx] = *it;
			idx++;
		}

	}
}

/////////////////////////////////////////////////////////////////////////////
/// \Function name      bool matchesSubString
/// \Brief              Matches the user input string with the available string in the wordlist
///
///
/// \Returns            bool - return true is match is successful else returns false
///
/// \Parameter          string strExistingWord - available string
/// \Parameter          string strInput - user input string
/////////////////////////////////////////////////////////////////////////////
bool CWordSuggestionProcessor::matchesSubString(string strExistingWord, string strInput)
{
		int i = 0;
		for (int j = strExistingWord.length()-1; j >= 0; j--)
		{
			vector<string> v1;
			string subStr = strExistingWord.substr(i, j+1);
			if (subStr == "")
				break;

			if (isSubString(subStr, strInput))
			{
				return true;
			}
			else
			{
				continue;
			}
		}
	return false;
}


/////////////////////////////////////////////////////////////////////////////
/// \Function name      bool isSubString
/// \Brief              Checks if the input string matches the word in the wordList
///
/// \Returns            bool
///
/// \Parameter          string subStr - the word from wordlist
/// \Parameter          string strInput - User Input string
/////////////////////////////////////////////////////////////////////////////
bool CWordSuggestionProcessor::isSubString(string subStr, string strInput)
{
	string strBeginning = strInput.substr(0,subStr.length());

	size_t found = strBeginning.find(subStr);

	if (found != std::string::npos)
		return true;
	else
		return false;
}


/////////////////////////////////////////////////////////////////////////////
/// \Function name      int getUserChoice()
/// \Brief              Reads user input 
///
/// \Returns            int - index of user's input
///
/////////////////////////////////////////////////////////////////////////////
int CWordSuggestionProcessor::getUserChoice()
{
	int iUserChoice;
	cout << "\nEnter your choice : ";
	cin >> iUserChoice;

	return iUserChoice;
}


/////////////////////////////////////////////////////////////////////////////
/// \Function name      void addToList
/// \Brief              Add the user input to the wordList based on the user choice
///
/// \Returns            void
///
/// \Parameter          int iUserChoice - Users choice input
/// \Parameter          string strInput - User Input string
/// \Parameter          map<int, string> mapOfSuggestedWords - map containing the matched/suggested words
///						from the wordList
/// \Parameter          set<string>& wordSet - set of words 
/////////////////////////////////////////////////////////////////////////////
void CWordSuggestionProcessor::addToList(int iUserChoice, string sInput, map<int, string> mapOfSuggestedWords, set<string>& wordSet)
{
	if (iUserChoice == 0)
		addToList(sInput , wordSet);
	else
	{
		//do nothing
		cout << "\nNothing added to the list\n";
		system("pause");
	}
}

/////////////////////////////////////////////////////////////////////////////
/// \Function name      void addToList
/// \Brief              Add the user input string to the wordList directly
///
/// \Returns            void
///
/// \Parameter          string strInput - User Input string
/// \Parameter          set<string>& wordSet - wordList 
/////////////////////////////////////////////////////////////////////////////
void CWordSuggestionProcessor::addToList(string sInput, set<string>& wordSet)
{
	wordSet.insert(sInput);
	cout << "Added " << sInput << " to the list\n";
	system("pause");
}