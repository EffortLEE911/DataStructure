#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

int main() {

	unordered_map<char, int> dict;
	vector<char> stack;

	string s = "A+B*(C-D)+B/E";
	string answer = "";

	/*cin >> s;*/
	 
	dict.insert({ '+',1 });
	dict.insert(make_pair( '-',1 ));

	dict.insert({ '*',2 });
	dict.insert(make_pair('/', 2));

	
	dict.insert({ '(',0 });

	for (int i = 0; i < s.size(); i++)
	{	
		// 알파벳 A ~ Z 일경우 바로 출력준비를 해준다.
		if (s[i] >= 'A' && s[i] <= 'Z') {
			answer = answer + s[i];
			continue;
		}
		//스택이 비어있거나, ( 여는 괄호가 나오면 스택에 넣기
		else if (s[i] == '(' || stack.empty())
		{
			stack.push_back(s[i]);
		}
		else if (s[i] == ')')
		{
			//stack의 최상위 노드에서  '(' 나올 때 까지 stack 안에 수식을 뺀다.
			while (true)
			{
				if (stack.back() == '(')
				{
					stack.pop_back();
					break;
				}
				answer = answer + stack.back();
				stack.pop_back();
			}
		}
		else if (dict.find(s[i]) != dict.end())
		{
			//표기식에서 가져온 연산자의 우선순위가 스택안에 들어있는 연산자의 우선순위보다 높다면 스택에 push()
			if (dict[s[i]] > dict[stack.back()])
			{
				stack.push_back(s[i]);
			}
			else
			{  //표기식에서 가져온 연산자의 우선순위가 스택안에 들어있는 연산자의 우선순위보다 작거나 같으면,
				//스택안의 값이 빌때 까지 출력 후 pop()을 반복
				//아래 조건식을 잘보면 and 연산자를 사용하는데, 스택이 비거나(false가 되면) 가져온 연산자가 우선순위가 높아지면(false) 
				//즉, 둘 중 하나라도 false가 되면 반복 종료
				while (!stack.empty() && dict[s[i]] <= dict[stack.back()])
				{
					answer = answer + stack.back();
					stack.pop_back();
				}
				stack.push_back(s[i]);
			}

		}

	

	}

	while (!stack.empty()) {
		answer = answer + stack.back();
		stack.pop_back();
	}

	cout << answer << endl;

	


}