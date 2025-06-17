#include <iostream>
#include <vector>

using namespace std;

int main()
{

    // 1. 배열에서 값을 순환하는 방법
    vector<int> vec = { 3,5,10,2,20,4,6 };

    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl;

    //2. 배열에서 특정 값이 존재하는지 확인하시오.
    
    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i] == 20)
        {
            cout << "20이 존재합니다" << endl;
        }
    }
    cout << endl;
    
    //3.최댓값을 구하는 방법

    int max = vec[0];

    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i] > max)
        {
            max = vec[i];
            cout << "최댓값이 변경되었습니다. 변경값 : " << max << endl;
        }
    }
    cout << "최종 최댓값은 : " << max << endl << endl;

    //4. 최솟값을 구하는 방법

    int min = vec[0];

    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i] < min)
        {
            min = vec[i];
            cout << "최솟값이 변경되었습니다. 변경값 : " << min << endl;
        }
    }
    cout << "최종 최솟값은 : " << min << endl << endl;

}

class student {

    string name;
    int age;


};

