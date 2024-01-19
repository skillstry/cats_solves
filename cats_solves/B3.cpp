#include <iostream>
#include <fstream>
#include <vector>
int main() {
	std::vector<int> numbers;

	std::ifstream in("input.txt");
	int a, b, c, d;
	while (in >> a >> b >> c >> d) {
		numbers = { a,b,c,d };
	}
	in.close();

	long int sum_vector{ 0 }, sign_mult{ 1 }, chet_sum_vector{ 0 };
	int max_element{ -10001 }, min_element{ 10001 };
	for (int i = 0; i < numbers.size(); i++) {
		sum_vector += numbers[i];
		sign_mult *= ((numbers[i] >= 0) ? (1) : (-1));
		if ((numbers[i] % 2) == 0) { chet_sum_vector += numbers[i]; }
		max_element = std::max(max_element, numbers[i]);
		min_element = std::min(min_element, numbers[i]);
	}
	bool chet_sum{ false }, proiz_neotr{ false };
	proiz_neotr = (sign_mult >= 0) ? 1 : 0;
	chet_sum = (((sum_vector % 2) == 0) ? 1 : 0);

	int anwser;
	if (proiz_neotr && chet_sum) {
		anwser = max_element;
	}
	else if (!chet_sum && proiz_neotr) {
		anwser = min_element;
	}
	else {
		anwser = chet_sum_vector;
	}

	std::ofstream out("output.txt");
	out << anwser;
	out.close();
}
