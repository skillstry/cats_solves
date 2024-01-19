#include <fstream>


int main() {
	unsigned long int n;
	std::ifstream bebra("input.txt");
	bebra >> n;
	long long int* pref_summs = new long long int[n + 1];
	pref_summs[0] = 0;

	int* vvod = new int;
	for (unsigned long int i = 1; i <= n; i++) {
		bebra >> *vvod;
		pref_summs[i] = pref_summs[i - 1] + *vvod;
	}
	delete vvod;

	unsigned long int m;
	unsigned long int l, r;
	std::ofstream bruh("output.txt");

	bebra >> m;
	for (unsigned long int i = 0; i < m; i++) {
		bebra >> l >> r;
		bruh << pref_summs[r] - pref_summs[l - 1] << " ";
	}
	return 0;
}