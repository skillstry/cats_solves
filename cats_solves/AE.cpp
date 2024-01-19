#include <iostream>

int main()
{
	unsigned long int value_color;
	char name_color;
	std::cin >> value_color >> name_color;
	switch (name_color)
	{
	case 'g':
		std::cout << (value_color & 65280);
		break;
	case 'r':
		std::cout << (value_color & 16711680);
		break;
	case 'b':
		std::cout << (value_color & 255);
		break;
	default:
		break;
	}
	return 0;
}