#include <vector>
#include <queue>
using namespace std;
int solution(vector<int>  scoville, int k) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    int f, s;
    for (int i : scoville) pq.push(i);
    while (pq.size() >= 2 && pq.top() < k) {
        f = pq.top(); pq.pop();
        s = pq.top(); pq.pop();
        pq.push(f + s * 2);
        answer++;
    }
    if (pq.top() < k) return -1;
    return answer;
}
