#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void help(int x, int y, vector<vector<int>>& board) {
    if (x > 0 && y > 0 && board[x][y] != 0) {
        board[x][y] = min({ board[x - 1][y], board[x][y - 1], board[x - 1][y - 1] }) + 1;
    }
}
int solution(vector<vector<int>> board) {
    int answer = board[0][0];
    for (int x = 0; x < board.size(); x++) {
        for (int y = 0; y < board[0].size(); y++) {
            help(x, y, board);
            if (board[x][y] > answer) answer = board[x][y];
        }
    }
    return answer * answer;
}
