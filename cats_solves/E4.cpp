#include <iostream>

int main() {
	int n, m;
	std::cin >> n >> m;
	float a;
	int* arr_first = new int[n];
	int* arr_last = new int[n];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			std::cin >> a;
			if (j == 0) { arr_first[i] = a; }
			if (j == m - 1) { arr_last[i] = a; }
		}
	}
	long int summ{};
	for (int i = 0; i < n; i++) {
		summ += abs(arr_first[i] * arr_last[i]);
	}
	std::cout << summ;
}