#ifndef _WORDPROCESSOR_H_
#define _WORDPROCESSOR_H_
#pragma once

#include<iostream>
#include<set>
#include<string>
#include<map>
#include<set>
using namespace std;

void checkIfWordExistAndAdd(set<string> wordSet, string sInput);
bool matchesSubString(string strExistingWord, string sInput);
bool isSubString(string subStr, string sInput);
int getUserChoice();
void addToList(int iUserChoice, string sInput, map<int, string>mapOfSuggestedWords, set<string>& wordSet);
void addToList(string sInput, set<string>& wordSet);
void createMapOfSuggestedWords(map<int, string>& mapOfSuggestedWords, set<string> wordSet, string sInput);


class CWordSuggestionProcessor
{
public :
	void checkIfWordExistAndAdd(set<string>& wordSet, string sInput);
	bool matchesSubString(string strExistingWord, string sInput);
	bool isSubString(string subStr, string sInput);
	int getUserChoice();
	void addToList(int iUserChoice, string sInput, map<int, string>mapOfSuggestedWords, set<string>& wordSet);
	void addToList(string sInput, set<string>& wordSet);
	void createMapOfSuggestedWords(map<int, string>& mapOfSuggestedWords, set<string> wordSet, string sInput);
};



#endif // !defined(_WORDPROCESSOR_H_)