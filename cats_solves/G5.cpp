#include <iostream>
#include <fstream>
#include <set>

int main() {
    std::ifstream input("input.txt");
    std::ofstream output("output.txt");
    int N;
    input >> N;
    std::string initialString(1000000, 'Z');

    for (int i = 0; i < N; ++i) {
        char alpha;
        int start, end;
        input >> alpha >> start >> end;

        for (int j = start - 1; j < end; ++j) {
            initialString[j] = alpha;
        }
    }
    std::set<char> uniqueLetters(initialString.begin(), initialString.end());
    output << uniqueLetters.size() << std::endl;
    return 0;
}