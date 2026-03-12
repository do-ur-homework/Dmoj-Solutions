#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string s; cin >> s;
	int k; cin >> k;

	vector<pair<char, pair<int, int>>> charRanges;
	int n = s.size(), start = 0, end = 0, len = 0;

	for (int i = 0; i < n;) {
		char ch = s[i++];
		string num = "";

		while (i < n && isdigit(s[i])) {
			num += s[i++];
		}
		int x = stoll(num);
		end += x;
		len += x;
		charRanges.push_back({ch, {start, end - 1}});
		start = end;
	}

	int to_Find = k % len;

	for (const auto &p : charRanges) {
		if (to_Find >= p.second.first && to_Find <= p.second.second) {
			cout << p.first;
			break;
		}
	}

	return 0;
}