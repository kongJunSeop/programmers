#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
long long solution(int n, vector<int> works) {
    long long answer = 0;
    int time = 0;
    for (int work : works) time += work;
    if (time < n) return 0;
    priority_queue<int> pq;
    for (int work : works) pq.push(work);
    while (n > 0) {
        int max = pq.top();
        pq.pop();
        max--;
        n--;
        pq.push(max);
    }
    while (!pq.empty()) {
        long long val = pq.top();
        pq.pop();
        answer += val * val;
    }
    return answer;
}
