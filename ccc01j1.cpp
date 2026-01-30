#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;
int main() {
    vector<int> v;
    for (string s; cin >> s;) v.push_back(stoi(s));
    int h = v[0];
    for (int i = 0, a = 1; i < h; ++i, a += i > h / 2 ? -2 : 2)
        cout << string(a, '*') + string(2 * (h - a), ' ') + string(a, '*') + '\n';
    return 0;
}