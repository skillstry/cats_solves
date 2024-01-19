#include <fstream>

int main() {
	int n;
	std::ifstream in("input.txt");
	in >> n;
	unsigned long long int t1{ 0 }, t2{ 1 }, res{};
	int i = 1;
	in.close();

	std::ofstream out("output.txt");
	while (i <= n)
	{
		if (i == n) { out << t1; }
		else { out << t1 << " "; }
		res = t1 + t2;
		t1 = t2;
		t2 = res;
		i++;
	}
}