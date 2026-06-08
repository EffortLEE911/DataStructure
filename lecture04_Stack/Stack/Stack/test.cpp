#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{

	string s = "A*B+(A*C+B*D)";
	string answer = "";

	vector<char> stack;

	unordered_map<char, int> dict = { {'+',1}, {'-',1} };


	dict['*'] = 2;

	dict.insert({ '/',2 });

	//for (unordered_map<char, int>::iterator it = dict.begin(); it != dict.end(); it++)
	//{
	//	cout << it->first << endl;
	//}

	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] >= 'A' && s[i] <= 'Z')
		{
			answer = answer + s[i];
		}
		else if(stack.empty() || s[i] == '(')
		{
			stack.push_back(s[i]);
		}
		else if (s[i] == ')')
		{
			while (stack.back() != '(')
			{
				answer = answer + stack.back();
				stack.pop_back();
			}
			stack.pop_back();
				
		}
		else if (dict.find(s[i]) != dict.end())
		{

			if (dict[s[i]] > dict[stack.back()])
			{
				stack.push_back(s[i]);
			}
			else
			{
				while (!stack.empty() && dict[s[i]]<=dict[stack.back()])
				{
					answer = answer + stack.back();
					stack.pop_back();
				}
				stack.push_back(s[i]);
			}



		}

	}

	while (!stack.empty())
	{
		answer = answer + stack.back();
		stack.pop_back();

	}
	cout << answer << endl;

}