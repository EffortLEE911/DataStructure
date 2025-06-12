#include <string>
#include <vector>
#include <queue>
#include <functional>
#include <iostream>

using namespace std;

int solution(vector<int> scoville, int K);

int main() {

    vector<int> vec = { 1,2,3,9,10,12 };

    int K = 7;

    cout<< solution(vec, K)<< endl;


}


int solution(vector<int> scoville, int K) {
    int answer = 0;

    int s1 = -1;
    int s2 = -2;
    int mix = -99;

    priority_queue<int, vector<int>, greater<int>> pq; // greater�� �̿��Ͽ� ������ ���� ������ �ϱ�.

    for (int i = 0; i < scoville.size(); i++)
    {
        pq.push(scoville[i]);                           // scoville �� ���� �켱���� ť�� ����
    }

    while (true)
    {
        if (pq.top() >= K || pq.size() == 1) {          //���ǿ� ���Ͽ� scoville�� ���̴� 2���� �����ϴϱ�
            break;                                      //���� ���̰� 1�� �ǰų� pq�� �ּڰ��� K���� ũ�ٸ� ����
        }

        s1 = pq.top();
        pq.pop();
        s2 = pq.top();
        pq.pop();

        mix = s1 + s2 * 2;

        pq.push(mix);

        answer++;                                       // �����ٸ� answer ++;

    }

    if (pq.top() < K) {
        answer = -1;
    }

    return answer;
}