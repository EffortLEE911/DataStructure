#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {

	vector<int> stack;

	string s = "300 100 3 1 - * + 100 2 / +";

	vector<string> input = { "300", "100", "3", "1", "-", "*", "+", "100", "2", "/", "+"};
	string answer = "";

	vector<string> oper = { "+", "-", "*", "/" };

	bool is_oper = false;
	int a = -1;
	int b = -1;
	int tmp = -1;

	for (int i = 0; i < input.size(); i++)
	{
		is_oper = false;
		for (int j = 0; j < oper.size(); j++)
		{
			if ( input[i]== oper[j])
			{
				is_oper = true;
				break;
			}
		}

		if (is_oper) 
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
			
		}
		else
		{
			stack.push_back(stoi(input[i]));
			
		}
		

	}
	
	cout << stack[0] << endl;

	
}