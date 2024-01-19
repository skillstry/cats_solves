#include <fstream>
#include <vector>
#include <string>
int main() {
	int n;
	std::vector<int> numbers;
	std::string anwsers;

	std::ifstream in("input.txt");
	in >> n;
	for (int i = 0; i < n; i++) {
		int a;
		in >> a;
		numbers.push_back(a);
	}
	in >> anwsers;
	in.close();


	unsigned int total{};
	for (int i = 0; i < n; i++) {
		if (anwsers[i] == '+') { total += numbers[i]; }
	}

	std::ofstream out("output.txt");
	out << total;
	out.close();
}