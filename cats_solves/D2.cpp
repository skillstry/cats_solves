#include <fstream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
    int x1, y1, x2, y2, x0, y0;
    double x1n, x2n, y1n, y2n, alpha;
    double PI = 3.14159265, B;
    ifstream in("input.txt");
    in >> x1 >> y1 >> x2 >> y2 >> x0 >> y0 >> alpha;
    in.close();
    B = (alpha * PI / 180);

    ofstream out("output.txt");
    if (alpha == 360) {
        out << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2;
        out.close();
        return 0;
    }

    x1n = -sin(B) * (y1 - y0) + cos(B) * (x1 - x0) + x0;
    y1n = cos(B) * (y1 - y0) + sin(B) * (x1 - x0) + y0;
    x2n = -sin(B) * (y2 - y0) + cos(B) * (x2 - x0) + x0;
    y2n = cos(B) * (y2 - y0) + sin(B) * (x2 - x0) + y0;

    out << fixed << setprecision(9) << x1n << ' ' << y1n << ' ' << x2n << ' ' << y2n << '\n';
    out.close();
    return 0;
}