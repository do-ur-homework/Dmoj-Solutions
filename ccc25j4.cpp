#include <stdio.h>
#define max(a, b) (a>b)?a:b

int main() {
	int days, prev = 0, current = 0, max = 0;
	char w, not_all_sunny = 0;
	scanf("%d", &days);
	for (int i = 0; i < days; i++) {
		getchar(); w = getchar();
		if (w == 'P') {
			max = max(prev + current + 1, max);
			prev = current;
			current = 0;
			not_all_sunny = 1;
		} else {
			current++;
		}
	}
	printf("%i\n", ((not_all_sunny)? max(prev + current + 1, max) : (days - 1)));
}