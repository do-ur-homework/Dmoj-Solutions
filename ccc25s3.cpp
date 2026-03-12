#include <iostream>
#include <set>
#include <vector>
using namespace std;
vector<multiset<int, greater<int>>> v;
multiset<int, greater<int>> backset;
multiset<int, greater<int>> frontset;
int color[200005];
int pretiness[200005];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m, q;
	cin >> n >> m >> q;
	for (int i = 0; i <= m; i++) {
		v.push_back({});
	}
	for (int i = 0; i < n; i++) {
		int c, p;
		cin >> c >> p;
		color[i] = c;
		pretiness[i] = p;
		v[c].insert(p);
	}
	long long frontsum = 0;
	for (int i = 1; i <= m; i++) {
		if (v[i].size() > 0) {
			frontsum += *(v[i].begin());
			frontset.insert(*(v[i].begin()));
		}
		for (auto it = ++v[i].begin(); it != v[i].end(); it++) {
			backset.insert(*it);
		}
	}
	long long total = 0;
	total += frontsum + max(0,*(backset.begin())-(*(--frontset.end())));
	std::cout << total << "\n";
	for (int i = 0; i < q; i++) {
		int code, a, b;
		cin >> code >> a >> b;
		a -= 1;
			if (pretiness[a] == *(v[color[a]].begin())) {
				frontset.erase(frontset.find(pretiness[a]));
				frontsum -= pretiness[a];
				v[color[a]].erase(v[color[a]].find(pretiness[a]));
				if (v[color[a]].size() > 0) {
					frontset.insert(*(v[color[a]].begin()));
					frontsum += *(v[color[a]].begin());
					backset.erase(backset.find(*(v[color[a]].begin())));
				}
			}
			else {
				backset.erase(backset.find(pretiness[a]));
				v[color[a]].erase(v[color[a]].find(pretiness[a]));
			}
			if (code == 2) {
				pretiness[a] = b;
			}
			else {
				color[a] = b;
			}
			if (v[color[a]].size() == 0) {
				frontset.insert(pretiness[a]);
				frontsum += pretiness[a];
				v[color[a]].insert(pretiness[a]);
			}
			else if (pretiness[a] > *(v[color[a]].begin())) {
				frontset.erase(frontset.find(*(v[color[a]].begin())));
				frontsum -= *(v[color[a]].begin());
				frontset.insert(pretiness[a]);
				frontsum += pretiness[a];
				backset.insert(*(v[color[a]].begin()));
				v[color[a]].insert(pretiness[a]);

			}
			else {
				backset.insert(pretiness[a]);
				v[color[a]].insert(pretiness[a]);
			}

	std::cout << frontsum + max(0, *(backset.begin()) - (*(--frontset.end()))) <<"\n";
	}
}