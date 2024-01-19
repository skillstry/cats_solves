#include <fstream>

int sign(int one, int two) {
	if ((one - two) >= 0) {
		return 1;
	}
	return -1;
}

int main() {
	int x1, y1, x2, y2;
	std::ifstream in("input.txt");
	in >> x1 >> y1 >> x2 >> y2;

	in.close();
	for (int i = 1; i < 9; i++) {
		for (int j = 1; j < 9; j++) {
			if ((i != x1) && (i != x2) && (j != y1) && (j != y2))
			{
				if (((abs(i - x1) == abs(j - y1)) && (abs(i - x2) == abs(j - y2)))) {
					if ((sign(i, x1) != sign(i, x2)) || (sign(j, y1) != sign(j, y2))) {
						std::ofstream out("output.txt");
						out << i << " " << j;
						return 0;
					}
				}
			}
		}
	}
	std::ofstream out("output.txt");
	out << "0";
}