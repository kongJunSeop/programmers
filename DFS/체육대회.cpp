#include <algorithm>
#include <vector>
using namespace std;
void dfs(int idx, int sum, const vector<vector<int>>& ability, vector<bool>& visited, int& cmax) {
    if (idx == ability[0].size()) {
        cmax = max(sum, cmax);
        return;
    }
    for (int i = 0; i < ability.size(); i++) {
        if (!visited[i]) {
            visited[i] = 1;
            dfs(idx + 1, sum + ability[i][idx], ability, visited, cmax);
            visited[i] = 0;
        }
    }
}
int solution(vector<vector<int>> ability) {
    int cmax = 0;
    vector<bool> visited(ability.size(), false);
    dfs(0, 0, ability, visited, cmax);
    return cmax;
}
