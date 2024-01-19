#include <fstream>


int main() {
	short int n;
	long int number{}, maximal_element{ -2147483648 };
	std::ifstream in("input.txt");
	in >> n;
	for (int i = 0; i < n; i++) {
		in >> number;
		if (maximal_element < number) maximal_element = number;
	}

	std::ofstream out("output.txt");
	out << maximal_element;
}