#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	string s = "300 100 3 1 - * + 100 2 / +";
	vector<string> input = { "300" , "100", "3", "1", "-", "*",
							"+", "100", "2", "/", "+" };

	vector<int> stack;

	for (int i = 0;i < input.size();i++)
	{
		if (input[i] == "+")
		{
			//+처리
		}
		else if (input[i] == "-") 
		{
			//- 처리
		}
		else if (input[i] == "*")
		{
			// *처리
		}
		else if (input[i] == "/")
		{
			//  /처리
		}
		else
		{
			stack.push_back(stoi(input[i]));
		}

	}

	for (int i = 0;i < stack.size();i++)
	{
		cout << stack[i] << " ";
	}
	cout << endl;



}