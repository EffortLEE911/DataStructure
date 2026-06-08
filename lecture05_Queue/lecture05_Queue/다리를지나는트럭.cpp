#include <string>
#include <vector>
#include <iostream>
#include <deque>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int total_weight = 0; //다리위에 모든 트럭들의 무게

    deque<int> on_bridge;
    deque<int> dq_truck; // 트럭들을 deque에 옮기기 위한 deque

    for (int i = 0; i < bridge_length; i++) //다리 위에 0kg 트럭들로 가득 채워놓는다.
    {
        on_bridge.push_back(0);
    }
    for (int i = 0; i < truck_weights.size(); i++) //트럭들의 무게를 deque에 복사하기
    {
        dq_truck.push_back(truck_weights[i]);
    }

    while (!on_bridge.empty()) 
    {
        answer++;

        total_weight = total_weight - on_bridge.front(); //한칸 이동할때마다 다리에서 가장 앞에 무게를 삭제하기.
        on_bridge.pop_front();

        if (!dq_truck.empty())
        {
            if (total_weight + dq_truck.front() <= weight) //트럭을 한대 올릴 수 있는지 없는지 체크
            {
                total_weight = total_weight + dq_truck.front(); //올릴수 있다면, 올리고 다리위의 총 트럭들의 무게를 늘리고

                on_bridge.push_back(dq_truck.front()); //다리 위 가장뒤에 트럭을 한대 추가.
                dq_truck.pop_front(); //트럭 deque에서 가장 앞 트럭을 한대 제거
            }
            else
            {
                on_bridge.push_back(0);
            }
        }

    }

    return answer;
}



int main() {

    int bridege_length = 2;

    int weight = 10;

    //vector<int> truck_weights = { 7,6,5,2,12 };
    vector<int> truck_weights = { 7,4,5,6 };

    int answer = 0;
    answer = solution(bridege_length, weight, truck_weights);

    cout << answer << endl;
}