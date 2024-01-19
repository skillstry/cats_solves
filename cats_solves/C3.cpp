#include <fstream>
#include <numeric>

int main() {
	std::ifstream in("input.txt");
	int a, b, c;
	in >> a >> b >> c;
	std::ofstream out("output.txt");
	out << std::gcd(a, b) << " " << std::gcd(a, c) << " " << std::gcd(b, c);
}