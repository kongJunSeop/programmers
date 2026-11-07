#include <vector>
#include <algorithm>
using namespace std;
vector<int> solution(vector<vector<int>> edges) {
    vector<int> in(1000001);
    vector<int> out(1000001);
    int start = 0, tot = 0, stk = 0, eig = 0, maxN = 0;
    for (int i = 0; i < edges.size(); i++) {
        out[edges[i][0]]++;
        in[edges[i][1]]++;
        maxN = max(maxN, max(edges[i][0], edges[i][1]));
    }
    for (int i = 1; i <= maxN; i++) {
        if (in[i] == 0 && out[i] >= 2) {
            start = i;
            tot = out[i];
        }
        if (in[i] >= 1 && out[i] == 0) stk++;
        if (in[i] >= 2 && out[i] == 2) eig++;
    }
    return { start,tot - (stk + eig),stk,eig };
}
