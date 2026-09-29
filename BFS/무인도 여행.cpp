#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
vector<int> solution(vector<string> maps) {
    vector<int> answer;
    int R = maps.size();
    int C = maps[0].size();
    vector<vector<bool>> visited(R, vector<bool>(C, false));
    for (int c = 0; c < R; c++) {
        for (int v = 0; v < C; v++) {
            if (maps[c][v] != 'X' && !visited[c][v]) {
                queue<pair<int, int>> q;
                q.push({ c, v });
                visited[c][v] = true;
                int foodsum = maps[c][v] - '0';
                while (!q.empty()) {
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();
                    for (int dir = 0; dir < 4; dir++) {
                        int nx = x + dx[dir];
                        int ny = y + dy[dir];
                        if (nx >= 0 && nx < R && ny >= 0 && ny < C) {
                            if (maps[nx][ny] != 'X' && !visited[nx][ny]) {
                                visited[nx][ny] = true;
                                foodsum += maps[nx][ny] - '0';
                                q.push({ nx,ny });
                            }
                        }
                    }
                }
                answer.push_back(foodsum);
            }
        }
    }
    if (answer.empty()) answer.push_back(-1);
    else sort(answer.begin(), answer.end());
    return answer;
}
