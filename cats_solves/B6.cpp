#include <fstream>
#include <cmath>

int main() {
	std::ifstream in("input.txt");
	float a, b, c;
	in >> a >> b >> c;
	float discr = b * b - 4 * a * c;
	if (a == 0 && b == 0) { goto link; };
	if (a == 0) {
		std::ofstream out("output.txt");
		out << (-1) * c / b << " " << (-1) * c / b;
		return 0;
	}
	if (discr == 0) {
		std::ofstream out("output.txt");
		out << static_cast<float>((-1) * b / (2 * a));
		return 0;
	}

	if (discr < 0) {
	link:
		std::ofstream out("output.txt");
		out << "-1";
		return 0;
	}
	float root_one = ((-1) * b + sqrt(discr)) / (2 * a);
	float root_two = ((-1) * b - sqrt(discr)) / (2 * a);
	std::ofstream out("output.txt");
	out << root_one << " " << root_two;
	return 0;
}
