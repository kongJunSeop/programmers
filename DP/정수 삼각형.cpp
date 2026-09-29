#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int solution(vector<vector<int>> triangle) {
    vector<int> can;
    int answer = 0;
    for (int c = 1; c < triangle.size(); c++) {
        for (int i = 0; i < triangle[c].size(); i++) {
            if (i == 0)  triangle[c][i] += triangle[c - 1][i];
            else if (i == c) triangle[c][i] += triangle[c - 1][i - 1];
            else triangle[c][i] += max(triangle[c - 1][i], triangle[c - 1][i - 1]);
        }
    }
    for (int i = 0; i < triangle.size(); i++) {
        answer = max(answer, triangle[triangle.size() - 1][i]);
    }
    return answer;
}
