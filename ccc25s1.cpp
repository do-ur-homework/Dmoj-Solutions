#include <bits/stdc++.h>
using namespace std;
int main(){
	int a, b, x, y;
	cin>>a>>b>>x>>y;
	int p1 = 2*(a + x + max(b, y));
	int p2 = 2*(b + y + max(a, x));
	cout<<min(p1, p2);
}