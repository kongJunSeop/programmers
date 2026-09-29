#include <string>
#include <vector>
using namespace std;
void comp(int row, int col, int size, vector<vector<int>>& arr, vector<int>& answer) {
    int standard = arr[row][col];
    bool same = 1;
    for (int c = row; c < row + size; c++) {
        for (int i = col; i < col + size; i++) {
            if (arr[c][i] != standard) {
                same = 0;
                break;
            }
        }
        if (!same) break;
    }
    if (same) {
        answer[standard] += 1;
        return;
    }
    int half = size / 2;
    comp(row, col, half, arr, answer);
    comp(row + half, col, half, arr, answer);
    comp(row, col + half, half, arr, answer);
    comp(row + half, col + half, half, arr, answer);
}
vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer = { 0,0 };
    comp(0, 0, arr.size(), arr, answer);
    return answer;
}
