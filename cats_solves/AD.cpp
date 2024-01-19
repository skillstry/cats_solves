#include <iostream>
#include <set>

int main() {
    std::set<int> numbers; std::set<int> numbers2; int last = 0, m; std::cin >> m; for (int i = 1; last + i <= m; i++) {
        last += i;
        numbers.insert(last);
        numbers2.insert(m - last);
        if (numbers.count(m - last)) {
            std::cout << 2;
            return 0;
        }
    }

    if (numbers.count(m)) {
        std::cout << 1;
        return 0;
    }

    std::cout << 3;
    return 0;
}