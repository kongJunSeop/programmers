#include <string>
#include <vector>
#include <unordered_set>
using namespace std;
int solution(int N, int number) {
    vector<unordered_set<int>>dp(9);
    int base = 0;
    for (int c = 1; c <= 8; c++) {
        base = base * 10 + N;
        dp[c].insert(base);
        for (int v = 1; v < c; v++) {
            int x = c - v;
            for (int a : dp[v]) {
                for (int b : dp[x]) {
                    if (b != 0)dp[c].insert(a / b);
                    dp[c].insert(a + b);
                    dp[c].insert(a - b);
                    dp[c].insert(a * b);
                }
            }
        }
        if (dp[c].find(number) != dp[c].end())return c;
    }
    return -1;
}
