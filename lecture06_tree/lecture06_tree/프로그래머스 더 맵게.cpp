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

    priority_queue<int, vector<int>, greater<int>> pq; // greater를 이용하여 낮은값 부터 나오게 하기.

    for (int i = 0; i < scoville.size(); i++)
    {
        pq.push(scoville[i]);                           // scoville 값 복사 우선순위 큐에 복사
    }

    while (true)
    {
        if (pq.top() >= K || pq.size() == 1) {          //조건에 의하여 scoville의 길이는 2부터 시작하니까
            break;                                      //만약 길이가 1이 되거나 pq의 최솟값이 K보다 크다면 종료
        }

        s1 = pq.top();
        pq.pop();
        s2 = pq.top();
        pq.pop();

        mix = s1 + s2 * 2;

        pq.push(mix);

        answer++;                                       // 섞었다면 answer ++;

    }

    if (pq.top() < K) {
        answer = -1;
    }

    return answer;
}