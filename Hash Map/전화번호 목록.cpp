#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
bool solution(vector<string> phone_book) {
    unordered_map<string, int> hmap;
    for (int c = 0; c < phone_book.size(); c++) {
        hmap.insert({ phone_book[c],c });
    }
    for (int c = 0; c < phone_book.size(); c++) {
        string num = "";
        for (int v = 0; v < phone_book[c].size() - 1; v++) {
            num += phone_book[c][v];
            if (hmap.find(num) != hmap.end()) return false;
        }
    }
    return true;
}
