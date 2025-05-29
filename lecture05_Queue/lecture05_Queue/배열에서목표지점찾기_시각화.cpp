
#include <iostream>
#include <deque>
#include <vector>

using namespace std;

//�湮ǥ��
bool visited[9];

void show_maps(int size, int pos,int target);
int main()
{
    int size = 9;
    int start_pos = 3; // ���� ��ġ
    int target = 8; // Ÿ�� ��ġ

    int dump = 0;

    vector<int> arr; //�� ���Ǹ� �� vector
    deque<int> dq;

    vector<int> dir = { -1, 1 }; // -1�� �·� �̵�, +1�� ��� �̵�

    int cur_pos = 0;
    int next_pos = 0;
    int last_pos = 0;

    arr.push_back(0);//������
    for (int i = 1; i < size; i++)
    {
        arr.push_back(1);
    }


    //������ġ�� deque�� �ְ�, �湮��ġ�� true�� �ٲ��ش�.
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

            //���� �̵��� ��ġ�� �迭���� ��ġ���� üũ
            if (next_pos >= 0 && next_pos < arr.size())
            {
                if (!visited[next_pos] && arr[next_pos] == 1)  //���� �湮�� ��ġ�� �ѹ��� �湮���� �ʾҰ�, �������� 1�̶�� ǥ�õǾ��ִ� ������ üũ
                {
                    dq.push_back(next_pos);    //�湮�� �����ϴٸ� deque�� �ְ� visited�� trueǥ��
                    visited[next_pos] = true;  //�湮�� �����ϸ� deque�� ��� �þ while���� �ݺ����� ������ �����Ǿ� ��� Ž��
                }

            }

        }
        while (true)
        {
            show_maps(size, last_pos, target);

            std::cout << "���� �̵��ؾ��� ��ǥ��?: " << cur_pos << endl;

            cout << "������ Ž���ؾ��� ��ġ��? ";
            for (int i = 0; i < dq.size(); i++) {
                cout << dq[i] << " ";
            }
            cout << endl << endl;

            std::cout << "�ƹ��� �Է½� �������� �̵�" << endl;
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
