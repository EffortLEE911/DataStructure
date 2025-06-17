#include <iostream>
#include <vector>
#include <string>

using namespace std;

int function(vector<int> vec);

int main()
{
	vector<int>vec = { 5,4,3,2,1 };
	vector<int>arr = { 100,150,200,250,300 };

	string s = "900";

	// 문자열끼리 더하기 
	cout << s + to_string(arr[function(vec)]) << endl;



}

int function(vector<int> vec)
{
	int min = -1;

	if (!vec.empty())
	{
		min = vec[0];
		for (int i = 0; i < vec.size(); i++)
		{
			if (vec[i] < min)
			{
				min = vec[i];
			}

		}
	}

	return min;
}