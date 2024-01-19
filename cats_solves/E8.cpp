#include <fstream> 
using namespace std;

#define min(a, b) ((a<b)?(a):(b)) 
#define max(a, b) ((a>b)?(a):(b)) 

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");

    int n, nn;
    long long now, next;
    long long a, b, c;
    long long la, lb, lc;
    in >> n;

    in >> nn;
    if (nn == 1) {
        in >> a;
        now = a;
        next = a;
    }
    else if (nn == 2) {
        in >> a >> b;
        la = a;
        lb = b;
        a = min(la, lb);
        b = max(la, lb);
        now = a;
        next = b;
    }
    else {
        while (1) now++;
    }
    out << now << ' ';

    for (int i = 1; i < n; i++) {
        in >> nn;
        if (nn == 1) {
            in >> a;
            now = a;
            next = a;
        }
        else if (nn == 2) {
            in >> a >> b;
            la = a;
            lb = b;
            a = min(la, lb);
            b = max(la, lb);
            now = next;
            next = b;
        }
        else {
            in >> a >> b >> c;
            la = a;
            lb = b;
            lc = c;
            c = max(lc, max(la, lb));
            a = min(lc, min(la, lb));
            now = next;
            next = c;
        }
        out << now << ' ';
    }
    return 0;
}