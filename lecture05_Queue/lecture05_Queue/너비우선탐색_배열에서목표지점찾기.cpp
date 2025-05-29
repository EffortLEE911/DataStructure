
#include <iostream>
#include <deque>
#include <vector>

using namespace std;

//방문표시
bool visited[9];

int main()
{
    vector<int> arr = { 0, 1, 1, 1, 1, 1, 1, 1, 1 }; //맵 정의

    deque<int> dq;

    // -1은 좌로 이동, +1은 우로 이동
    vector<int> dir = { -1, 1 };

    int cur_pos = 0;
    int next_pos = 0;

    int start_pos = 3; // 시작 위치

    //시작위치를 deque에 넣고, 방문위치를 true로 바꿔준다.
    dq.push_back(start_pos);
    visited[start_pos] = true;

    while (!dq.empty())
    {
        cur_pos = dq.front();
        dq.pop_front();

        cout << "현재 내 위치는: " << cur_pos << endl;

        for (int i = 0; i < dir.size(); i++)
        {
            next_pos = cur_pos + dir[i];

            //내가 이동할 위치가 배열안의 위치인지 체크
            if (next_pos >= 0 && next_pos < arr.size())
            {
                if (!visited[next_pos] && arr[next_pos] == 1)  //내가 방문할 위치가 한번도 방문하지 않았고, 지도에서 1이라고 표시되어있는 길인지 체크
                {
                    dq.push_back(next_pos);    //방문이 가능하다면 deque에 넣고 visited에 true표시
                    visited[next_pos] = true;  //방문이 가능하면 deque가 계속 늘어나 while문의 반복문의 조건이 충족되어 계속 탐색
                }

            }

        }
        cout << "현재 deque의 값은? ";
        for (int i = 0; i < dq.size(); i++) {
            cout << dq[i] << " ";
        }
        cout << endl << endl;

    }
    





}

