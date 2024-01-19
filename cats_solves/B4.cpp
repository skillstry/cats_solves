#include <iostream>

int main() {
	long int Fizz;
	std::cin >> Fizz;

	if (((Fizz % 3) == 0) && ((Fizz % 5) == 0)) {
		std::cout << "FizzBuzz";
	}
	else if ((Fizz % 3) == 0) {
		std::cout << "Fizz";
	}
	else if ((Fizz % 5) == 0) {
		std::cout << "Buzz";
	}
	else {
		std::cout << std::endl;
	}
	return 0;
}