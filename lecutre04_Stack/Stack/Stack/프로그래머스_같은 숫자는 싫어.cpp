#include <vector>
#include <iostream>

using namespace std;

int main()
{
	//vector는 stack은 아니지만 우리는 마치 stack처럼 사용할 수 있다.

	vector<int> arr = { 1,1,3,3,0,1,1 };
	
	vector<int>answer;

	int arr_len = arr.size(); // vector의 크기를 반환하는 함수 vector.size(), 여기서 길이 7반환; 변수명 arr_len은 arr의 길이라는 뜻


	for (int i = 0; i < arr_len; i++) 
	{
		//vector.empty()는 vector container가 비어있는지 확인하는 함수, true false 반환
		if (answer.empty()) 
		{
			answer.push_back(arr[i]);

		}
		else if (answer.back() != arr[i]) {
			answer.push_back(arr[i]);
		}

	}

	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << " ";
	}
	cout << endl;

	


}

