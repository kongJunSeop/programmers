#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int solution(vector<int> diffs, vector<int> times, long long limit) {
    int min = 1, max = *max_element(diffs.begin(), diffs.end());
    int ans = 0;
    while (min <= max) {
        int mid = (min + max) / 2;
        long long sec = 0;
        for (int j = 0; j < diffs.size(); j++) {
            if (j == 0)sec += times[0];
            else if (mid >= diffs[j]) sec += times[j];
            else sec += (times[j - 1] + times[j]) * (diffs[j] - mid) + times[j];
        }
        if (sec <= limit) {
            ans = mid;
            max = mid - 1;
        }
        else min = mid + 1;
    }
    return ans;
}
