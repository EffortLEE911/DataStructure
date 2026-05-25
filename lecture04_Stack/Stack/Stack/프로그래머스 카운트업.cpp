#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int start_num, int end_num) {
    vector<int> answer;

    for (int i = start_num; i <= end_num; i++)
    {
        answer.push_back(i);
    }
    return answer;
}

/////위에가 프로그래머스 정답..
///////////////////////////
////////////////////////////




int main()
{

    int s = 3;
    int e = 10;

    vector<int> vec = solution(s, e);

    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl;
    
}