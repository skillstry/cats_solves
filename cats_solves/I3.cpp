#include <fstream>
#include <vector>
#include <stack>

std::vector<int> find_next_greater_elements(const std::vector<int>& sequence) {
    int n = sequence.size();
    std::vector<int> result(n, -1);

    std::stack<int> s;

    for (int i = 0; i < n; ++i) {
        while (!s.empty() && sequence[i] > sequence[s.top()]) {

            result[s.top()] = sequence[i];
            s.pop();
        }


        s.push(i);
    }


    while (!s.empty()) {
        result[s.top()] = sequence[s.top()];
        s.pop();
    }

    return result;
}

int main() {

    int n;
    std::ifstream in("input.txt");
    in >> n;
    std::vector<int> sequence(n, 0);
    for (int i = 0; i < n; i++) {
        in >> sequence[i];
    }
    std::vector<int> result = find_next_greater_elements(sequence);

    std::ofstream out("output.txt");
    for (int value : result) {
        out << value << " ";
    }

    return 0;
}