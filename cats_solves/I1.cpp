#include <stack>
#include <string>
#include <iostream>
#include <set>
bool isValid(std::string s) {
    std::stack<char> stack;
    std::stack<char> prev;
    for (char c : s) {
        if (c == '(' || c == '[' || c == '{')
            stack.push(c);
        else if (c == ')' && !stack.empty() && stack.top() == '(')
            stack.pop();

        else if (c == ']' && !stack.empty() && stack.top() == '[')
            stack.pop();
        else if (c == '}' && !stack.empty() && stack.top() == '{')
            stack.pop();
        else
            return false;
    }
    return stack.empty();
}
int main() {
    std::string dan;
    std::cin >> dan;
    if (!isValid(dan)) {
        std::cout << -1;
        return 0;
    }
    std::set<char> cont;
    for (char c : dan) {
        if (c == '(' || c == '{' || c == '[')
        {
            cont.insert(c);
        }
    }
    int maxlen{ -1 };
    int len = 0;
    for (char c : dan) {
        if (cont.count(c) == 0) {
            maxlen = (len > maxlen) ? len : maxlen;
            len--;
        }
        else
        {
            len++;
        }
    }
    maxlen = (len > maxlen) ? len : maxlen;
    std::cout << maxlen;
}