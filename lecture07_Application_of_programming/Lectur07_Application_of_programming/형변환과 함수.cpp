#include <iostream>
#include <vector>
#include <string>

using namespace std;


int function(int a, int b);

int main() {

	// 2. ����ȯ ����
	int k = 0;

	string s = "130";

	s = to_string(123);
	k = stoi(s);
	
	//3. �Լ� ����
	int spaceX = 1;
	int tesla = 3;

	cout << function(spaceX, tesla) << endl;
	

	//3.1 �Լ��� �Ű�����
	cout << function(stoi(s), tesla) << endl;


	//3.2 �Լ��� ��ȯ���� ������ ���� �� �ִ°�?
	k = function(spaceX, tesla);
	cout << "k�� ���� : " << k << endl;


	//3.3 �Լ��� ��ȯ���� ����ȯ �� �� �ִ°�?
	s = to_string( function(spaceX, tesla) );
	cout << "string���� ����ȯ �Ͽ����ϴ�. s�� ���� : " << s << endl;


	//3.4 �Լ��� ��ȯ���� �迭�� ���� �� �ִ°�?
	vector<int>vec = { 5,4,3,2,1 };

	cout << vec[function(spaceX, tesla)] << endl;


}
//3. �Լ� ����
int function(int a, int b) {

	int c = a + b;
	return c;
}