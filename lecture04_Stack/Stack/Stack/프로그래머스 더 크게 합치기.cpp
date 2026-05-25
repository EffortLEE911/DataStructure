#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int a, int b) {
    int answer = 0;

    string s1 = "";
    string s2 = "";

    int ab = 0;
    int ba = 0;

    //형변환 to_string() : 
    s1 = to_string(a);
    s2 = to_string(b);

    // 형변환 stoi() : string을 int형으로 변환
    ab = stoi(s1 + s2);
    ba = stoi(s2 + s1);

    if (ab >= ba)
    {
        answer = ab;
    }
    else
    {
        answer = ba;
    }


    return answer;
}

int main()
{
    int a = 9;
    int b = 91;

    cout << solution(a, b) << endl;

}