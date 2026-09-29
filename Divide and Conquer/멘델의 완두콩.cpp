#include <string>
#include <vector>
using namespace std;
string getT(int g, int p) {
    if (g == 1) return "Rr";
    int pp = (p - 1) / 4 + 1;
    int myp = (p - 1) % 4;
    string pT = getT(g - 1, pp);
    if (pT == "RR") return"RR";
    else if (pT == "rr") return"rr";
    else {
        if (myp == 0) return "RR";
        else if (myp == 3) return "rr";
        else return "Rr";
    }
}
vector<string> solution(vector<vector<int>> queries) {
    vector<string> answer;
    for (int i = 0; i < queries.size(); i++) {
        answer.push_back(getT(queries[i][0], queries[i][1]));
    }
    return answer;
}
