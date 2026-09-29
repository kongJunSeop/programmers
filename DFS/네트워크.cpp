#include <vector>
using namespace std;
void dfs(int index, vector<vector<int>>& computers, vector<bool>& visited){
    visited[index] = 1;
    for (int i = 0; i < computers.size(); i++) {
        if (computers[index][i] == 1 && visited[i] == 0) {
            visited[i] = 1;
            dfs(i, computers, visited);
        }
    }
}
int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<bool> visited(n, false);
    for (int i = 0; i < computers.size(); i++) {
        if (visited[i] == 0) {
            dfs(i, computers, visited);
            answer++;
        }
    }
    return answer;
}
