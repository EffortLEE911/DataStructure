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
		// ���ĺ� A ~ Z �ϰ�� �ٷ� ����غ� ���ش�.
		if (s[i] >= 'A' && s[i] <= 'Z') {
			answer = answer + s[i];
			continue;
		}
		//������ ����ְų�, ( ���� ��ȣ�� ������ ���ÿ� �ֱ�
		else if (s[i] == '(' || stack.empty())
		{
			stack.push_back(s[i]);
		}
		else if (s[i] == ')')
		{
			//stack�� �ֻ��� ��忡��  '(' ���� �� ���� stack �ȿ� ������ ����.
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
			//ǥ��Ŀ��� ������ �������� �켱������ ���þȿ� ����ִ� �������� �켱�������� ���ٸ� ���ÿ� push()
			if (dict[s[i]] > dict[stack.back()])
			{
				stack.push_back(s[i]);
			}
			else
			{  //ǥ��Ŀ��� ������ �������� �켱������ ���þȿ� ����ִ� �������� �켱�������� �۰ų� ������,
				//���þ��� ���� ���� ���� ��� �� pop()�� �ݺ�
				//�Ʒ� ���ǽ��� �ߺ��� and �����ڸ� ����ϴµ�, ������ ��ų�(false�� �Ǹ�) ������ �����ڰ� �켱������ ��������(false) 
				//��, �� �� �ϳ��� false�� �Ǹ� �ݺ� ����
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