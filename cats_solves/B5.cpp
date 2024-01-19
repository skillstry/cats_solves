#include <fstream>

int main() {
	std::ifstream in("input.txt");

	long unsigned int n;
	in >> n;

	double a{ 0 }, summ{ 0 };
	while (in >> a) { summ += a; }
	in.close();

	double result = (summ) / (float(n));
	std::ofstream out("output.txt");
	out << result;
	out.close();
}