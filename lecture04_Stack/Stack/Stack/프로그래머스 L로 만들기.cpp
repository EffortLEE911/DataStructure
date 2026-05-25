#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string myString) {
    string answer = "";


    // char문자형과 ascii코드


    for (int i = 0; i < myString.size(); i++)
    {
        if (myString[i] >= 97 && myString[i] < 108)
        {
            answer = answer + 'l';
        }
        else
        {
            answer = answer + myString[i];
        }
    }


    return answer;
}

int main()
{

    string s = "abcdevwxyz";
    

    string an = solution(s);

    cout << an << endl;

    
    //cout << ('a' < 'b') << endl; // true 혹은 1
}