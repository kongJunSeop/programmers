#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm> 
using namespace std;
vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    unordered_map<string, int> stream;
    for (int i = 0; i < genres.size(); i++) 
        stream[genres[i]] += plays[i];
    vector<pair<string, int>> sorted(stream.begin(), stream.end());
    sort(sorted.begin(), sorted.end(), [](const auto& a, const auto& b)
        {return a.second > b.second;
        });
    for (int i = 0; i < sorted.size(); i++) {
        int fir = -1, sec = -1;
        for (int j = 0; j < genres.size(); j++) {
            if (genres[j] == sorted[i].first) {
                if (fir == -1 || plays[fir] < plays[j]) {
                    sec = fir;
                    fir = j;
                }
                else if (sec == -1|| plays[j] > plays[sec]) sec = j;
            }
        }
        answer.push_back(fir);
        if (sec != -1) answer.push_back(sec);
    }
    return answer;
}
