#include <string>
#include <vector>
#include <algorithm>
using namespace std;
void dfs(int k, int count, int &answer, vector<bool>& visited, vector<vector<int>>& dungeons){
    answer = max(answer, count);
    for (int i = 0; i < dungeons.size(); i++) {
        if (!visited[i] && dungeons[i][0] <= k) {
            visited[i] = true;
            dfs(k - dungeons[i][1], count + 1, answer, visited, dungeons);
            visited[i] = false;
        }
    }
}
int solution(int k, vector<vector<int>> dungeons) {
    vector<bool> visited(dungeons.size(), 0);
    int answer = -1;
    dfs(k , 0, answer, visited, dungeons);
    return answer;
}
