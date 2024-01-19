#include <fstream>
#include <cmath>
using namespace std;

int main() {
    long double a, C, P, c;
    long long int V;
    short N;

    ifstream in("input.txt");
    ofstream out("output.txt");
    in >> N >> P >> C;

    a = 1 + P / 100;

    if (P == 0) {
        V = ceil(C / 12 / N);
        out << V;
        in.close();
        out.close();
        return 0;
    }
    c = C;
    if ((C <= 1000) or (P <= 1000)) {
        V = ceil((((C * pow(a, 12 * N - 1)) / (pow(a, 12 * N) - 1)) * (a - 1)));
        while (c > 0) {
            for (int i = 0; i < 12 * N; i++) {
                c -= V;
                c *= a;
                c = ceil(c);
            }
            if (c > 0) {
                V++;
                c = C;
            }

        }
    }
    else {
        V = ceil(C - C / a);
        out << V;
        return 0;
    }

    out << V;
    in.close();
    out.close();
    return 0;
}