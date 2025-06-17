#include <iostream>
#include <vector>
#include <string>

using namespace std;


int function(int a, int b);

int main() {

	// 2. 형변환 문제
	int k = 0;

	string s = "130";

	s = to_string(123);
	k = stoi(s);
	
	//3. 함수 문제
	int spaceX = 1;
	int tesla = 3;

	cout << function(spaceX, tesla) << endl;
	

	//3.1 함수의 매개변수
	cout << function(stoi(s), tesla) << endl;


	//3.2 함수의 반환값을 변수에 넣을 수 있는가?
	k = function(spaceX, tesla);
	cout << "k의 값은 : " << k << endl;


	//3.3 함수의 반환값을 형변환 할 수 있는가?
	s = to_string( function(spaceX, tesla) );
	cout << "string으로 형변환 하였습니다. s의 값은 : " << s << endl;


	//3.4 함수의 반환값을 배열에 넣을 수 있는가?
	vector<int>vec = { 5,4,3,2,1 };

	cout << vec[function(spaceX, tesla)] << endl;


}
//3. 함수 문제
int function(int a, int b) {

	int c = a + b;
	return c;
}