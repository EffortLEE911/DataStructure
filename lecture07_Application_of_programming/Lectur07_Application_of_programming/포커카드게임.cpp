
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	vector<int> card = { 5,5,5,3,2 };//5트리플

	int count = 0;
	bool is_straight = false;

	sort(card.begin(), card.end()); // 정렬방법

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
		cout << "스트레이트 입니다." << endl;
	}

	else if (count == 6)
	{
		cout << "포카드 입니다." << endl;
	}
	else if (count == 4)
	{
		cout << "풀하우스 입니다." << endl;
	}
	else if (count == 3)
	{
		cout << "트리플 입니다." << endl;
	}
	else if (count == 2)
	{
		cout << "투페어 입니다." << endl;
	}
	else if (count == 1)
	{
		cout << "원페어 입니다." << endl;
	}
	else {
		cout << "탑카드 입니다." << endl;
	}
	

	
	






}