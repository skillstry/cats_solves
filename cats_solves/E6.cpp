#include <iostream>

int main() {
	double a, b, c, lambda;
	std::cin >> a >> b >> c;
	char X;
	std::cin >> X;
	std::cin >> lambda;
	if ((a - lambda == 0) && (b * c == 0)) {
		std::cout << "INF";
	}
	else if (a - lambda == 0) { std::cout << "NO"; }
	else {
		std::cout << "YES" << std::endl;
		std::cout << std::fixed << ((b * c) / (a - lambda)) + lambda;
	}
	return 0;
}