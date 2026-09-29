#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool compare(const string& a, const string& b) {
    return a + b > b + a;
}
string solution(vector<int> numbers) {
    string answer = "";
    vector<string>list;
    for (int c : numbers) list.push_back(to_string(c));
    sort(list.begin(), list.end(), compare);
    if (list[0] == "0") return "0";
    for (string& c : list)answer += c;
    return answer;
}
