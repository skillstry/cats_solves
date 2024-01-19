#include <iostream>
#include <string.h>
#include <stdint.h>

using namespace std;

int main() {
    float a;
    cin >> a;
    uint32_t a_int;
    static_assert(sizeof a_int == sizeof a);
    memcpy(&a_int, &a, sizeof a);

    if (-1 * (int)((a_int >> 23) & 0xFF) == 0) {
        if (a > 0) cout << -126;
        else cout << 0;
        return 0;
    }

    cout << (int)((a_int >> 23) & 0xFF) - 127 << endl;
}