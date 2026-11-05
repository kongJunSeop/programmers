#include <string>
#include <vector>
#include <queue>
using namespace std;
bool oneDif(string a, string b) {
    int chance = 0;
    for (int i = 0; i < a.size(); i++) if (a[i] != b[i]) chance++;
    return chance == 1;
}
int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    queue<pair<string, int>> q;
    vector<bool>visited(words.size(), 0);
    q.push({ begin, 0 });
    while (!q.empty()) {
        string cur = q.front().first;
        int step = q.front().second;
        q.pop();
        if (cur == target) return step;
        for (int i = 0; i < words.size(); i++) {
            if (!visited[i] && oneDif(cur, words[i])) {
                visited[i] = true;
                q.push({ words[i],step + 1 });
            }
        }
    }
    return answer;
}
