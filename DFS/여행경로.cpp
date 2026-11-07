#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool dfs(string cur, int used, vector<string>& answer, vector<bool>& visited, vector<vector<string>>& tickets) {
    if (used == tickets.size()) return true;
    for (int i = 0; i < tickets.size(); i++) {
        if (!visited[i] && tickets[i][0] == cur) {
            visited[i] = true;
            answer.push_back(tickets[i][1]);
            if (dfs(tickets[i][1], used + 1, answer, visited, tickets)) return true;
            visited[i] = false;
            answer.pop_back();
        }
    }
    return false;
}
vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    sort(tickets.begin(), tickets.end());
    vector<bool> visited(tickets.size(), 0);
    answer.push_back("ICN");
    dfs("ICN", 0, answer, visited, tickets);
    return answer;
}
