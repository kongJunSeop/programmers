#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int solution(vector<int> menu, vector<int> order, int k) {
	int time = 0, maxpeople = 0;
	queue<int> q;
	for (int i = 0; i < order.size(); i++) {
		int arrival = i * k;
		time = max(time, arrival);
		int leave = time + menu[order[i]];
		q.push(leave);
		time = leave;
		while (!q.empty() && q.front() <= arrival) q.pop();
		if (q.size() > maxpeople) maxpeople = q.size();
	}
	return maxpeople;
}
