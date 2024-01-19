#include <fstream>
#include <string>

void find(int x, int y, std::string* res, int a = 0, int b = 1, int c = 1, int d = 0) {
	int m = a + c, n = b + d;
	if (x == m && y == n)
		return;
	if (x * n < y * m) {
		*res += "L";
		find(x, y, res, a, b, m, n);
	}
	else {
		*res += "R";
		find(x, y, res, m, n, c, d);
	}
}
int main() {
	int m, n;
	std::ifstream in("input.txt");
	in >> n >> m;
	std::string result = "";
	std::string* res = &result;
	find(n, m, res);
	std::ofstream out("output.txt");
	out << result << std::endl;
	return 0;
}