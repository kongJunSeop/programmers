#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
vector<int> solution(int n, vector<string> words) {
    vector<int> answer(2, 0);
    unordered_map<string, int> word;
    char last = 'a';
    for (int i = 0; i < words.size(); i++) {
        word[words[i]]++;
        if (i == 0) {
            last = words[i].back();
            continue;
        }
        if (last != words[i].front()|| word[words[i]] > 1) {
            answer[0] = (i % n) + 1;
            answer[1] = (i / n) + 1;
            return answer;
        }
        last = words[i].back();
    }
    return answer;
}
