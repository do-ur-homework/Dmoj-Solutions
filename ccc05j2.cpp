#include <bits/stdc++.h>

using namespace std;

int main() {
    int m, n;
    cin >> m >> n;
    int total = 0;
    int in_total = 0;
    for (int i = m; i <= n; i++) { // 5 to 6
        for (int j = 1; j <= i; j++) {
            if (i % j == 0) {
                in_total++;
            }
        }
        if (in_total == 4) {
                total++;
            }
            in_total = 0;
    }
    cout << "The number of RSA numbers between " << m << " and " << n << " is " << total << endl;
    return 0;
}