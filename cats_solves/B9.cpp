#include <vector>;
#include <fstream>
int main() {
	long int n;
	std::ifstream in("input.txt");
	in >> n;

	std::vector<long int> numbers;
	long int a;
	for (long int i = 0; i < n; i++) { in >> a; numbers.push_back(a); }
	in.close();
	std::ofstream out("output.txt");
	for (long int i = 0; i < n; i++) {
		if (((n - 1) - i) != 0) {
			out << numbers[(n - 1) - i] << ' ';
		}
		else
		{
			out << numbers[(n - 1) - i] << '\n';
		}

	}
	out.close();
}