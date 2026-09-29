#include <iostream>
#include <string>
#include <vector>
using namespace std;
int solution(int m, int n, vector<vector<int>> puddles) {
    vector<vector<int>> table(m + 1, vector<int>(n + 1, 0));
    for (auto p : puddles) table[p[0]][p[1]] = -1;
    table[1][1] = 1;
    for (int y = 1; y <= n; y++) {
        for (int x = 1; x <= m; x++) {
            if (table[x][y] == -1) table[x][y] = 0;
            else table[x][y] += (table[x - 1][y] + table[x][y - 1]) % 1000000007;
        }
    }
    return table[m][n];
}
