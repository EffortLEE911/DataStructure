#include <string>
#include <vector>
#include <iostream>
#include <deque>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int total_weight = 0; //�ٸ����� ��� Ʈ������ ����
    deque<int> dq;
    deque<int> dq_truck;

    for (int i = 0; i < bridge_length; i++) //�ٸ��� ���̸� deque�� �����ϱ�
    {
        dq.push_back(0);
    }
    for (int i = 0; i < truck_weights.size(); i++) //Ʈ������ ���Ը� deque�� �����ϱ�
    {
        dq_truck.push_back(truck_weights[i]);
    }

    while (!dq.empty()) 
    {
        answer++;

        total_weight = total_weight - dq.front(); //��ĭ �̵��Ҷ����� �ٸ����� ���� �տ� ���Ը� �����ϱ�.
        dq.pop_front();

        if (!dq_truck.empty())
        {
            if (total_weight + dq_truck.front() <= weight) //Ʈ���� �Ѵ� �ø� �� �ִ��� ������ üũ
            {
                total_weight = total_weight + dq_truck.front(); //�ø��� �ִٸ�, �ø��� �ٸ����� �� Ʈ������ ���Ը� �ø���

                dq.push_back(dq_truck.front()); //�ٸ� �� ����ڿ� Ʈ���� �Ѵ� �߰�.
                dq_truck.pop_front(); //Ʈ�� deque���� ���� �� Ʈ���� �Ѵ� ����
            }
            else
            {
                dq.push_back(0);
            }
        }

    }

    return answer;
}

int main() {

    int bridege_length = 5;

    int weight = 13;

    vector<int> truck_weights = { 7,6,5,2,12 };

    int answer = 0;
    answer = solution(bridege_length, weight, truck_weights);

    cout << answer << endl;
}