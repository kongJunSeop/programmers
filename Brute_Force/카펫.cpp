#include <string>
#include <vector>
using namespace std;
vector<int> solution(int brown, int yellow) {
    int size = brown + yellow;
    for (int x = 3; x <= size / 3; x++) {
        if (brown == 2 * (x + size / x) - 4 && size / x <= x) return { x, size / x };
    }
}
