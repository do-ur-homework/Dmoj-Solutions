#include <iostream>
#include <vector>
using namespace std;
int main() {
    int initialNumberOfStreams;
    cin >> initialNumberOfStreams;
    vector<double> v;
    for (int i = 0; i < initialNumberOfStreams; ++i) {
        int initialStreamFlow;
        cin >> initialStreamFlow;
        v.push_back(initialStreamFlow);
    }

    int action;
    cin >> action;
    while (action != 77) {
        if (action == 99) {
            int p;
            cin >> p;
            p -= 1;
            double o = v[p];
            int left;
            cin >> left;
            v[p] = o * (left / 100.0);
            v.insert(v.begin() + p + 1, o * (1 - (left / 100.0)));
        } else {
            int n;
            cin >> n;
            n -= 1;
            v[n] += v[n + 1];
            v.erase(v.begin() + n + 1);
        }
        cin >> action;
    }

    for (size_t i = 0; i < v.size(); ++i) {
        cout << static_cast<int>(v[i]);
        if (i != v.size() - 1) {
            cout << " ";
        }
    }
    cout << endl;

    return 0;
}