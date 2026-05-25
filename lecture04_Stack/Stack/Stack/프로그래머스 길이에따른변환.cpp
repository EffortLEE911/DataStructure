#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> num_list) {
    int answer = 0;

    if (num_list.size() < 11)
    {
        answer = 1;
        for (int i = 0; i < num_list.size(); i++)
        {
            answer = answer * num_list[i];
        }
    }
    else
    {
        for (int i = 0; i < num_list.size(); i++)
        {
            answer = answer + num_list[i];
        }
    }

    return answer;
}

int main()
{

    vector<int> num_list = { 3, 4, 5, 2, 5, 4, 6, 7, 3, 7, 2, 2, 1 };
    
    cout << solution(num_list) << endl;;


}