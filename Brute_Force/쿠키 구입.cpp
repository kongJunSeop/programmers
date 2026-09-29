#include <vector>
#include <algorithm>
using namespace std;
int solution(vector<int> cookie) {
    int max = 0;
    int n = cookie.size();
    int sum = 0;
    for (int i : cookie) sum += i;
    for (int criteria = 1; criteria < n; criteria++) {
        int left = 0;
        for (int j = 0; j < criteria; j++) left += cookie[j];
        int right = sum - left;
        int idxf = 0, idxb = n - 1;
        while (idxf < criteria && idxb >= criteria) {
            if (left == right) {
                if (max < left) max = left;
                break;
            }
            else if (left < right) {
                right -= cookie[idxb];
                idxb--;
            }
            else {
                left -= cookie[idxf];
                idxf++;
            }
        }
    }
    return max;
}
