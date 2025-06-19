
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	vector<int> card = { 5,5,5,3,2 };//5Ʈ����

	int count = 0;
	bool is_straight = false;

	sort(card.begin(), card.end()); // ���Ĺ��

	for (int i = 0; i < card.size()-1; i++)
	{
		for (int j = i+1; j < card.size(); j++)
		{
			if (card[i] == card[j])
			{
				count++;
			}
		}
	}

	for (int i = 0; i < card.size() - 1; i++)
	{
		if (card[i + 1] - card[i] == 1)
		{
			is_straight = true;
		}
		else 
		{
			is_straight = false;
			break;
		}

	}

	if (is_straight)
	{
		cout << "��Ʈ����Ʈ �Դϴ�." << endl;
	}

	else if (count == 6)
	{
		cout << "��ī�� �Դϴ�." << endl;
	}
	else if (count == 4)
	{
		cout << "Ǯ�Ͽ콺 �Դϴ�." << endl;
	}
	else if (count == 3)
	{
		cout << "Ʈ���� �Դϴ�." << endl;
	}
	else if (count == 2)
	{
		cout << "����� �Դϴ�." << endl;
	}
	else if (count == 1)
	{
		cout << "����� �Դϴ�." << endl;
	}
	else {
		cout << "žī�� �Դϴ�." << endl;
	}
	

	
	






}