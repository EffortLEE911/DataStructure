#include <iostream>
#include <vector>

using namespace std;

int main() {

	vector<int> vec;

	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	
	vec = { 10,20,30,40,50,60,70,80,90,100 }; // vector도 배열처럼 초기화 가능하다.
	
	cout << "int arr[10] = ";

	//배열과 vector 안에 값 확인하기
	for (int i = 0; i < vec.size(); i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	
	cout << "vector<int> vec = ";
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << " ";
	}
	cout <<endl<<endl;


	//배열의 크기 구하기
	int arr_size = sizeof(arr) / sizeof(arr[0]); // 배열의 총 byte 크기 / 인덱스 하나의 byte 크기, 여기서는 40 / 4 = 10
	int vec_size = vec.size();

	cout << "배열의 크기는? " << arr_size << endl;
	cout << "vector의 크기는? " << vec_size << endl;


	//vector.push_back() 뒤에서 데이터 넣기.

	vec.push_back(200);
	vec.push_back(300);

	cout << "vector<int> vec = ";
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << " ";
	}
	cout << endl << endl;

	//vector.pop_back()으로 뒤에서 데이터 빼기.
	vec.pop_back();
	cout << "pop_back()으로 뒤에서 숫자를 뺐습니다." << endl;

	cout << "vector<int> vec = ";
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << " ";
	}
	cout << endl << endl;

	//vector.empty() vecotor가 비어있으면 true, 비어있지않다면 false

	cout << "현재 vector가 비어있나요? " << vec.empty() << endl;
	cout << "vector의 크기 만큼 vector를 pop_back() 하겠습니다."<<endl;

	//while문 대신 vector.clear() 사용 가능.
	while (!vec.empty()) {

		vec.pop_back();

	}
		
	cout << "현재 vector가 비어있나요? " << vec.empty() << endl;
	
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << endl;
	}
	cout << endl << endl;



}