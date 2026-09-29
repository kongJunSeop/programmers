#include <algorithm>
#include <vector>
using namespace std;
int solution(vector<int> A, vector<int> B) {
    int answer = 0, j = 0;
    sort(A.rbegin(), A.rend());
    sort(B.rbegin(), B.rend());
    for (int i = 0; i < A.size(); i++) {
        if (A[i]<B[j]) {
            answer++;
            j++;
        }
    }
    return answer;
}
