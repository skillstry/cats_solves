#include <iostream>

bool be(unsigned long long int m) {
    if (m % 47806 == 0) { return true; }
}
int main() {
    unsigned long long int n;
    std::cin >> n;
    if (n < 47806 || n > 18446744073709551615) {
        std::cout << "NO"; return 0;
    }

    if ((n & 0xBABE) == 0xBABE) { goto link; }//1
    if ((n & 0xBABE0) == 0xBABE0) { goto link; }//2
    if ((n & 0xBABE00) == 0xBABE00) { goto link; }//3
    if ((n & 0xBABE000) == 0xBABE000) { goto link; }//4
    if ((n & 0xBABE0000) == 0xBABE0000) { goto link; }//5
    if ((n & 0xBABE00000) == 0xBABE00000) { goto link; }//6
    if ((n & 0xBABE000000) == 0xBABE000000) { goto link; }//7
    if ((n & 0xBABE0000000) == 0xBABE0000000) { goto link; }//8
    if ((n & 0xBABE00000000) == 0xBABE00000000) { goto link; }//9
    if ((n & 0xBABE000000000) == 0xBABE000000000) { goto link; }//10
    if ((n & 0xBABE0000000000) == 0xBABE0000000000) { goto link; }//11
    if ((n & 0xBABE00000000000) == 0xBABE00000000000) { goto link; }//12
    if ((n & 0xBABE000000000000) == 0xBABE000000000000 && be(n)) { goto link; }//13



    std::cout << "NO";
    return 0;
link:
    std::cout << "YES";
    return 0;
}