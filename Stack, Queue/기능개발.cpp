#include <iostream>
#include <string>
#include <vector>
using namespace std;
int leftday(int pro, int spd) {
    return (99 - pro) / spd + 1;
}
vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int release = 1;
    int day = leftday(progresses[0], speeds[0]);
    for (int c = 1; c < progresses.size(); c++) {
        if (leftday(progresses[c], speeds[c]) <= day) {
            release += 1;
        }
        else {
            answer.push_back(release);
            release = 1;
            day = leftday(progresses[c], speeds[c]);
        }
    }
    answer.push_back(release);
    return answer;
}
