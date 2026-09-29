#include <string>
#include <vector>
#include <stack>
using namespace std;
vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size());
    stack<int> st;
    for (int v = 0; v < answer.size(); v++) {
        while (!st.empty() && prices[st.top()] > prices[v]) {
            answer[st.top()] = v - st.top();
            st.pop();
        }
        st.push(v);
    }
    while (!st.empty()) {
        answer[st.top()] = prices.size() - st.top() - 1;
        st.pop();
    }
    return answer;
}
