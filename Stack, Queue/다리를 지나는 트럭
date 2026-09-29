#include <vector>
#include <queue>
using namespace std;
int solution(int bridge_length, int weight, vector<int> truck_weights) {
    queue<int> bridge;
    int sec = 0;
    int current_weight = 0;
    for (int i = 0; i < truck_weights.size(); i++) {
        int truck = truck_weights[i];
        while (true) {
            if (bridge.size() == bridge_length) {
                current_weight -= bridge.front();
                bridge.pop();
            }
            if (current_weight + truck <= weight) {
                bridge.push(truck);
                current_weight += truck;
                sec++;
                break;
            }
            else {
                bridge.push(0);
                sec++;
            }
        }
    }
    return sec + bridge_length;
}
