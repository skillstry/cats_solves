#include <iostream>
#include <set>

int main() {
	unsigned long int n, a;
	std::cin >> n;

	std::set<int> numbers;
	for (int i = 0; i < n; i++) {
		std::cin >> a;
		numbers.insert(a);
	}

	std::set<int>::iterator it = numbers.begin();
	unsigned long int anwser = *it;
	for (it; it != numbers.end(); it++) {
		if (*it % anwser != 0) { goto link; }
	}

	std::cout << anwser;
	return 0;

link:
	std::cout << "-1";
	return 0;
}