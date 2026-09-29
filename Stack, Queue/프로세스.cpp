#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<pair<int, int>> q;
    for (int c = 0; c < priorities.size(); c++) q.push({ priorities[c], c });
    sort(priorities.begin(), priorities.end(), greater<int>());
    int maxidx = 0;
    while (!q.empty()) {
        int curpri = q.front().first;
        int curidx = q.front().second;
        q.pop();
        if (curpri == priorities[maxidx]) {
            answer++;
            maxidx++;
            if (curidx == location) return answer;
        }
        else q.push({ curpri,curidx });
    }
    return answer;
}
