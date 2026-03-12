#include <iostream>
#include <string>

int main() {
	int D, E;
	std::cin >> D >> E;

	for (int i = 0; i < E; ++i) {
		std::string e;
		int Q;
		std::cin >> e >> Q;

		if (e == "+") {
			D += Q;
		} else if (e == "-") {
			D -= Q;
		}
	}

	std::cout << D << std::endl;
	return 0;
}