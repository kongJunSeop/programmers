#include <vector>
#include <string>
using namespace std;
string tobin(int n) {
    string answer = "";
    while (n > 0) {
        answer += to_string(n % 2);
        n /= 2;
    }
    return answer;
}
int todec(string n) {
    int pow = 1, answer = 0;
    for (int i = n.length() - 1; i > 0; i--) {
        answer += (n[i] - '0') * pow;
        pow *= 2;
    }
    return answer;
}
int countOne(string n) {
    int count = 0;
    for (auto i : n) if (i == '1') count++;
    return count;
}
int solution(int n) {
    int one = countOne(tobin(n));
    while (true) {
        n++;
        if (one == countOne(tobin(n)))
            return n;
    }
}
