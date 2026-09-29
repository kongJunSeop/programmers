#include <vector>
#include <algorithm>
using namespace std;
int getParent(vector<int>& parent, int x) {
    if (parent[x] == x) return x;
    else return parent[x] = getParent(parent, parent[x]);
}
void unionParent(vector<int>& parent, int a, int b) {
    a = getParent(parent, a);
    b = getParent(parent, b);
    if (a < b) parent[b] = a;
    else parent[a] = b;
}
int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    vector<int> parent(n);
    for (int i = 0; i < n; i++) parent[i] = i;
    sort(costs.begin(), costs.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[2] < b[2];
        });
    for (int i = 0; i < costs.size(); i++) {
        int nodeA = costs[i][0];
        int nodeB = costs[i][1];
        int cost = costs[i][2];
        if (getParent(parent, nodeA) != getParent(parent, nodeB)) {
            unionParent(parent, nodeA, nodeB);
            answer += cost;
        }
    }
    return answer;
}
