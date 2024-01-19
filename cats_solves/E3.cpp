#include <iostream>
#include <vector>
#include <map>
int main() {
	int n, m;
	std::cin >> n >> m;
	int max{ -1 };
	std::vector<std::map<int, int>> numbers;
	numbers.resize(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int a;
			std::cin >> a;
			max = std::max(max, a);
			if (numbers[i].count(a)) {
				numbers[i][a]++;
			}
			else { numbers[i].insert(std::pair<int, int>(a, 1)); }
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= max; j++) {
			if (numbers[i].count(j)) { continue; }
			else { numbers[i].insert(std::pair<int, int>(j, 0)); }
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= max; j++) {
			std::cout << numbers[i][j] << " ";
		}
		std::cout << std::endl;
	}
}