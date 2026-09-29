#include <vector>
#include <queue>
using namespace std;
int solution(vector<vector<int>> maps) {
    int n = maps.size(), m = maps[0].size();
    int dx[] = { -1, 1, 0, 0 };
    int dy[] = { 0, 0, -1, 1 };
    queue<pair<int, int>> q;
    q.push({ 0,0 });
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if (x == n - 1 && y == m - 1) return maps[x][y];
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
                if (maps[nx][ny] == 1) {
                    maps[nx][ny] = maps[x][y] + 1;
                    q.push({ nx,ny });
                }
            }
        }
    }
    return -1;
}
