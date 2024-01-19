#include <fstream>
#include <math.h>
struct point {
    long long int x, y;
};


point get_coords(long long int x) {
    point result;
    long long int n_left, n, x_left, t;
    n_left = ((sqrt(8 * x + 1) - 3) / 2);
    n = floor(n_left);
    n++;
    x_left = (n * (n + 1)) / 2;
    t = x - x_left;

    result.x = n - t;
    result.y = t;
    return result;
}


int main() {
    std::ifstream in("input.txt");
    std::ofstream out("output.txt");
    point result;

    long long int n, x;
    in >> n;
    while (n--) {
        in >> x;
        result = get_coords(x);
        out << result.x << " " << result.y << '\n';
    }
    return 0;
}