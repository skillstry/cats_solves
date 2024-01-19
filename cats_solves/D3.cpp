#include <fstream>
#include <map>

int main() {
	unsigned int n;
	std::ifstream in("input.txt");
	in >> n;
	int a;
	std::map<int, int> numbers;
	for (unsigned int i = 0; i < n; i++) {
		in >> a;
		if (numbers.count(a)) { numbers[a]++; }
		else {
			numbers.insert(std::pair<int, int>(a, 1));
		}
	}
	in.close();
	std::ofstream out("output.txt");
	for (const auto& [number, count] : numbers)
		out << number << " " << count << std::endl;
}