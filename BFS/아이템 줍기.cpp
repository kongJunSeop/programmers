#include <string>
#include <vector>
#include <queue>
using namespace std;
int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 0;
    for (int i = 0; i < rectangle.size(); i++) {
        for (int j = 0; j < rectangle[0].size(); j++) rectangle[i][j] *= 2;
    }
    vector<vector<int>> board(102, vector<int>(102, 0));
    for (int i = 0; i < rectangle.size(); i++) {
        int x1 = rectangle[i][0];
        int y1 = rectangle[i][1];
        int x2 = rectangle[i][2];
        int y2 = rectangle[i][3];
        for (int y = y1; y <= y2; y++) {
            for (int x = x1; x <= x2; x++) {
                if (board[x][y] != 2 && (y == y1 || y == y2 || x == x1 || x == x2)) board[x][y] = 1;
                else board[x][y] = 2;
            }
        }
    }
    vector<vector<int>> dist(102, vector<int>(102, 0));
    queue<pair<int, int>>q;
    int dx[4] = { -1,1,0,0 };
    int dy[4] = { 0,0,-1,1 };
    q.push({ characterX * 2,characterY * 2 });
    dist[characterX * 2][characterY * 2] = 1;
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if (x == itemX * 2 && y == itemY * 2) return dist[x][y] / 2;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (board[nx][ny] == 1 && dist[nx][ny] == 0) {
                dist[nx][ny] = dist[x][y] + 1;
                q.push({ nx,ny });
            }
        }
    }
}
