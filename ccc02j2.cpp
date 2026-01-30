#include <bits/stdc++.h>
using namespace std;
static string vowels = "aeiouy";
string convert(string s) {
    if (s.length() < 5) {
        return s;
    }
    if (s.substr(s.length() - 2, 2) == "or") {
        if (vowels.find(s[s.length() - 3]) == string::npos) {
            s.replace(s.length() - 2, 2, "our");
            return s;
        }
    }
    return s;

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    while (s != "quit!") {
        cout << convert(s) << "\n";
        cin >> s;
    }
    return 0;
}