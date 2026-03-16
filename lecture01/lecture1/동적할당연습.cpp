#include <iostream>

using namespace std;

int main()
{

	int size = 5;
	int next_size = 0;


	int* arr = (int*)malloc(sizeof(int) * 5);

	free(arr);


	int* tmp;


	cout << "현재 동적배열 arr에 저장되어있는 값은? " << endl;
	for (int i = 0; i < size; i++) 
	{
		arr[i] = i;
		cout << arr[i]<<" ";
	}
	cout << endl << endl;

	while (true)
	{
		cout << endl;
		cin >> next_size;

		if (next_size == -1)
		{
			break;
		}
		tmp = (int*)malloc(sizeof(int) * next_size);

		for (int i = 0; i < next_size; i++)
		{
			tmp[i] = arr[i];
			cout << tmp[i] << " ";
		}
		cout << endl << endl;

		free(arr);

		arr = tmp;

		for (int i = 0; i < next_size; i++)
		{
			cout << arr[i] << " ";
		}
	}


	free(arr);

	



}

