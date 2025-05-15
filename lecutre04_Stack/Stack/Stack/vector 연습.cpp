#include <iostream>
#include <vector>

using namespace std;

int main() {

	vector<int> vec;

	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	
	vec = { 10,20,30,40,50,60,70,80,90,100 }; // vector�� �迭ó�� �ʱ�ȭ �����ϴ�.
	
	cout << "int arr[10] = ";

	//�迭�� vector �ȿ� �� Ȯ���ϱ�
	for (int i = 0; i < vec.size(); i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	
	cout << "vector<int> vec = ";
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << " ";
	}
	cout <<endl<<endl;


	//�迭�� ũ�� ���ϱ�
	int arr_size = sizeof(arr) / sizeof(arr[0]); // �迭�� �� byte ũ�� / �ε��� �ϳ��� byte ũ��, ���⼭�� 40 / 4 = 10
	int vec_size = vec.size();

	cout << "�迭�� ũ���? " << arr_size << endl;
	cout << "vector�� ũ���? " << vec_size << endl;


	//vector.push_back() �ڿ��� ������ �ֱ�.

	vec.push_back(200);
	vec.push_back(300);

	cout << "vector<int> vec = ";
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << " ";
	}
	cout << endl << endl;

	//vector.pop_back()���� �ڿ��� ������ ����.
	vec.pop_back();
	cout << "pop_back()���� �ڿ��� ���ڸ� �����ϴ�." << endl;

	cout << "vector<int> vec = ";
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << " ";
	}
	cout << endl << endl;

	//vector.empty() vecotor�� ��������� true, ��������ʴٸ� false

	cout << "���� vector�� ����ֳ���? " << vec.empty() << endl;
	cout << "vector�� ũ�� ��ŭ vector�� pop_back() �ϰڽ��ϴ�."<<endl;

	//while�� ��� vector.clear() ��� ����.
	while (!vec.empty()) {

		vec.pop_back();

	}
		
	cout << "���� vector�� ����ֳ���? " << vec.empty() << endl;
	
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << endl;
	}
	cout << endl << endl;



}