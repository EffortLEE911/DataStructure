#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr, int k) 
{
    
    vector<int> answer;
    //¦����� , ¦�� �Ǻ� �˰��� : 2�� ������ �� �������� 0�̸� ¦��
    if(k % 2 ==0)
    {
        for(int i=0;i<arr.size();i++)
        {
            answer.push_back(arr[i] + k);
            
        }
    }
    //Ȧ�����
    else if(k % 2 ==1)
    {
        for(int i=0;i<arr.size();i++)
        {
            answer.push_back(arr[i] * k);
            
        }
    }
    
    
    return answer;
    
    
}

int main()
{

    int k = 3;
    vector<int> arr = { 1, 2, 3, 100, 99, 98 };
    vector<int>answer;

    answer = solution(arr, k);

    for (int i = 0; i < answer.size(); i++) 
    {
        cout << answer[i] << " ";
    }
    
    
}