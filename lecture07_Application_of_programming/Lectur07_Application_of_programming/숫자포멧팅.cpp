#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {


	vector<pair<long long, string>> vec =
	{ 
		{1'000'000'000'000,  "��"},
		{100'000'000,"��"},
		{10'000, "��"},
		{1,""},
	};

	long long damage = 9'541'543'876'431;

	long long quotient = -1; //�������� remainder

	string s = "";
	for (int i = 0; i < vec.size(); i++)
	{
		if (vec[i].first <= damage)
		{
			quotient = damage / vec[i].first;
			damage = damage % vec[i].first;
			
			s = s + to_string(quotient)+vec[i].second;

		}
	}

	cout << s << endl;




}