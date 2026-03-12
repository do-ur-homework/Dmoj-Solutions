#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

const ll MAXN = 1000005;
const ll INF = 1e18;
const ll MOD = 1e6 + 3;

struct Node {
    ll begin, time;

    static Node merge(const Node& l, const Node& r) {
        if (l.begin == INF) return r;
        if (r.begin == INF) return l;

        Node res;
        res.time = l.time + r.time;
        res.begin = max(l.begin + l.time, r.begin) - l.time;
        return res;
    }
};

Node tree[4 * MAXN];
ll current_durations[MAXN];
vector<pair<ll, ll>> history;

void update(ll node, ll left, ll right, ll index, ll value) {
    if (left == right) {
        if (value == 0) {
            tree[node] = {INF, 0};
        } else {
            tree[node] = {index, value};
        }
        return;
    }

    ll mid = left + (right - left) / 2;
    if (index <= mid) {
        update(2 * node + 1, left, mid, index, value);
    } else {
        update(2 * node + 2, mid + 1, right, index, value);
    }
    tree[node] = Node::merge(tree[2 * node + 1], tree[2 * node + 2]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;

    for (int i = 0; i < 4 * MAXN; ++i) {
        tree[i] = {INF, 0};
    }

    ll last_ans = 0;

    while (q--) {
        char type;
        cin >> type;

        if (type == 'A') {
            ll s, t;
            cin >> s >> t;
            s = (s + last_ans - 1 + MOD) % MOD;
            t = (t + last_ans) % MOD;

            current_durations[s] += t;
            history.push_back({s, t});
            update(0, 0, MAXN - 1, s, current_durations[s]);
        } else {
            int idx;
            cin >> idx;
            idx = (idx + last_ans - 1) % (ll)history.size();

            ll s = history[idx].first;
            ll t = history[idx].second;

            current_durations[s] -= t;
            update(0, 0, MAXN - 1, s, current_durations[s]);
        }

        if (tree[0].begin == INF) {
            last_ans = 0;
        } else {
            last_ans = tree[0].begin + tree[0].time;
        }

        cout << last_ans << "\n";
    }

    return 0;
}