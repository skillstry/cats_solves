#include <fstream>


int main() {
	unsigned long int n, m, k;
	std::ifstream in("input.txt");
	in >> n >> m >> k;
	int counter{};
	in.close();


	if (k > 13) {
		counter = 2;
	}
	else if (k > 3) { counter = 1; };
	int etazh_counter{};

	k -= counter;
	std::ofstream out("output.txt");
	int anwser = (k + (k % m)) / m;


	if ((k + counter) == 4 || (k + counter) == 13) { goto link; }
	if (n * m < k) { goto link; }
	if (anwser >= 13) { anwser += 2; }
	else if (anwser >= 4) { anwser += 1; }
	out << anwser;



	return 0;
link:
	out << "-1";
	return 0;
}