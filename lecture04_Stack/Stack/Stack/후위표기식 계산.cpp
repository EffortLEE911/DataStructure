#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {

	vector<int> stack;

	string s = "300 100 3 1 - * + 100 2 / +";

	vector<string> input = { "300", "100", "3", "1", "-", "*", "+", "100", "2", "/", "+" };
	//vector<string> input = { "50", "100", "*", "30", "20", "-","+"};
	//vector<string> input = { "50", "2", "*" , "50", "10", "*", "2", "3", "*", "+", "+" };
	string answer = "";

	int a = -1;
	int b = -1;
	int tmp = -1;

	for (int i = 0; i < input.size(); i++)
	{

		if (input[i] == "+")
		{
			b = stack.back();
			stack.pop_back();

			a = stack.back();
			stack.pop_back();

			tmp = a + b;
			stack.push_back(tmp);

		}
		else if (input[i] == "-")
		{
			b = stack.back();
			stack.pop_back();

			a = stack.back();
			stack.pop_back();

			tmp = a - b;
			stack.push_back(tmp);
		}
		else if (input[i] == "*")
		{
			b = stack.back();
			stack.pop_back();

			a = stack.back();
			stack.pop_back();

			tmp = a * b;
			stack.push_back(tmp);
		}
		else if (input[i] == "/")
		{
			b = stack.back();
			stack.pop_back();

			a = stack.back();
			stack.pop_back();

			tmp = a / b;
			stack.push_back(tmp);
		}
		else
		{
			stack.push_back(stoi(input[i]));
		}

	}

	for (int i = 0; i < stack.size(); i++)
	{
		cout << stack[i] << endl;
	}



}