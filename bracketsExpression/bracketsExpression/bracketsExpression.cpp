#include "stdafx.h"
#include <iostream>
#include <string>
#include <stack>
#include <set>

using namespace std;

bool relation(char s1, char s2)
{
	if (s1 == '(') return (s2 == ')');
	if (s1 == '{') return (s2 == '}');
	if (s1 == '<') return (s2 == '>');
	if (s1 == '[') return (s2 == ']');
	return false;
}
bool valid(string source)
{
	stack<char> brackets;
	for (unsigned int i = 0; i < source.size(); ++i)
	{
		char sym;
		sym = source[i];
		if (sym == '(' || sym == '<' || sym == '{' || sym == '[') brackets.push(sym);
		else if (sym == ')' || sym == '>' || sym == '}' || sym == ']')
		{
			if (!(brackets.size() && relation(brackets.top(), sym))) return false;
			brackets.pop();
		}
	}
	if (brackets.size()) return false;
	return true;
}

void variables(string source)
{
	char sym_prev1 = '1';
	for (unsigned int i = 0; i < source.size(); ++i)
	{
		char sym = source[i];
		if (i > 1) sym_prev1 = source[i - 1];
		if (isalpha(sym) == 0 && !(isalpha(sym_prev1) && isdigit(sym))) source.replace(i, 1, " "); //replace when sym's not alpha or digit after alpha
	}
	char sym_prev = ' ';
	char sym_next = ' ';
	source += " ";													//to check the last symbol
	for (unsigned int i = 0; i < source.size(); ++i)				//replacing spaces with a tilde
	{
		if (i > 0) sym_prev = source[i - 1];

		if ((source[i] == ' ') && (isalnum(sym_prev)))
		{
			source.replace(i, 1, "~");
		}
	}
	for (; source.find(' ') != -1;)			//erase spaces
	{
		source.erase(source.find(' '), 1);
	}

	set<string> variables;			//set w/variables
	int i = 0;
	for (; source.size() > 0; ++i)
	{
		int pos = source.find_first_of('~', 0);
		string sub;
		sub = source.substr(0, pos);
		variables.insert(sub);
		source.erase(0, pos + 1);

	}
	cout << endl << "Variables:" << endl;
	for (auto i = variables.begin(); i != variables.end(); ++i)	//output
	{
		cout << *i << endl;
	}
}

int main()
{
	cout << "Enter the string" << endl;
	string source;
	cin >> source;
	if (valid(source)) cout << "valid" << endl;
	else cout << "invalid" << endl;
	variables(source);
	return 0;
}

