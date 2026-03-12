#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<set<int>> levels(N);
    vector<tuple<int, int, int>> tunnels;

    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        tunnels.emplace_back(a, b, c);
        levels[a].insert(c);
        levels[b].insert(c);
    }

    levels[0].insert(0);

    vector<vector<int>> sorted_levels(N);
    for (int i = 0; i < N; i++) {
        sorted_levels[i].assign(levels[i].begin(), levels[i].end());
        sort(sorted_levels[i].begin(), sorted_levels[i].end());
    }

    vector<int> offset(N + 1, 0);
    int total_nodes = 0;
    for (int i = 0; i < N; i++) {
        offset[i] = total_nodes;
        total_nodes += (int)sorted_levels[i].size();
    }
    offset[N] = total_nodes;

    vector<unordered_map<int, int>> maps(N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < (int)sorted_levels[i].size(); j++) {
            maps[i][sorted_levels[i][j]] = j;
        }
    }

    vector<vector<pair<int, long long>>> graph(total_nodes);

    // Add intra-room edges
    for (int i = 0; i < N; i++) {
        int base = offset[i];
        auto &L = sorted_levels[i];
        for (int j = 0; j + 1 < (int)L.size(); j++) {
            int u = base + j;
            int v = base + j + 1;
            long long diff = (long long)(L[j + 1] - L[j]);
            graph[u].emplace_back(v, diff);
            graph[v].emplace_back(u, diff);
        }
    }

    // Add tunnel edges with zero cost
    for (auto &[a, b, c] : tunnels) {
        int u = offset[a] + maps[a][c];
        int v = offset[b] + maps[b][c];
        graph[u].emplace_back(v, 0);
        graph[v].emplace_back(u, 0);
    }

    const long long INF = 1000000000000000000LL;
    vector<long long> dist(total_nodes, INF);

    int start_node = offset[0] + maps[0][0];
    dist[start_node] = 0;

    using pli = pair<long long, int>;
    priority_queue<pli, vector<pli>, greater<pli>> pq;
    pq.emplace(0, start_node);

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (d != dist[u]) continue;

        for (auto &[v, cost] : graph[u]) {
            long long nd = d + cost;
            if (nd < dist[v]) {
                dist[v] = nd;
                pq.emplace(nd, v);
            }
        }
    }

    long long ans = INF;
    int base = offset[N - 1];
    for (int j = 0; j < (int)sorted_levels[N - 1].size(); j++) {
        int node = base + j;
        if (dist[node] < ans) {
            ans = dist[node];
        }
    }

    cout << ans << "\n";

    return 0;
}