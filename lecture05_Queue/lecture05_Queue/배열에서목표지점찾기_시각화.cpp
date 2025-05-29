
#include <iostream>
#include <deque>
#include <vector>

using namespace std;

//방문표시
bool visited[9];

void show_maps(int size, int pos,int target);
int main()
{
    int size = 9;
    int start_pos = 3; // 시작 위치
    int target = 8; // 타겟 위치

    int dump = 0;

    vector<int> arr; //맵 정의를 할 vector
    deque<int> dq;

    vector<int> dir = { -1, 1 }; // -1은 좌로 이동, +1은 우로 이동

    int cur_pos = 0;
    int next_pos = 0;
    int last_pos = 0;

    arr.push_back(0);//맵정의
    for (int i = 1; i < size; i++)
    {
        arr.push_back(1);
    }


    //시작위치를 deque에 넣고, 방문위치를 true로 바꿔준다.
    dq.push_back(start_pos);
    visited[start_pos] = true;
    last_pos = start_pos;
    int ve = 0;

    while (!dq.empty())
    {
        cur_pos = dq.front();
        dq.pop_front();


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
        while (true)
        {
            show_maps(size, last_pos, target);

            std::cout << "현재 이동해야할 목표는?: " << cur_pos << endl;

            cout << "앞으로 탐색해야할 위치는? ";
            for (int i = 0; i < dq.size(); i++) {
                cout << dq[i] << " ";
            }
            cout << endl << endl;

            std::cout << "아무값 입력시 다음으로 이동" << endl;
            std::cin >> dump;
            system("cls");
            ve = last_pos - cur_pos;
            if (ve == 0)
            {
                break;
            }
            else if (ve < 0)
            {
                last_pos++;
            }
            else if (ve > 0)
            {
                last_pos--;
            }
        }

    }


}

void show_maps(int size, int pos, int target)
{
    for (int i = 0; i < size; i++)
    {
        cout << "---" << " ";
    }
    cout << endl;

    for (int i = 0; i < size; i++)
    {
        if (i == pos)
        {
            cout << " C " << " ";
        }
        else if (i == target)
        {
            cout << " A " << " ";
        }
        else
        {
            cout << "   " << " ";
        }
        
    }
    cout << endl;

    for (int i = 0; i < size; i++)
    {
        cout << "---" << " ";
    }
    cout << endl;

}
