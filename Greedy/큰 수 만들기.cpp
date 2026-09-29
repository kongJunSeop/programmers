#include <string>
#include <vector>
using namespace std;
string solution(string number, int k) {
    string answer = "";
    int pos = 0;
    int left = number.size() - k;
    while (left > 0){
        int max = number[pos];
        int max_idx = pos;
        for (int i = pos; i < number.size() - left + 1; i++) {
            if(max <= number[i]){
                max = number[i];
                max_idx = i;
            }
        }
        pos = max_idx + 1;
        left--;
        k--;
        answer += max;
    }
    return answer;
}
