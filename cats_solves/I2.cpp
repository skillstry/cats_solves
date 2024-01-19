#include <iostream>
#include <list>

int main() {
	std::list<int> queue;
	int count_people;
	int time;
	std::cin >> count_people >> time;
	long long max_len = 0;
	int* people = new int[count_people];
	for (int i = 0; i < count_people; i++) {
		std::cin >> people[i];
	}
	for (int i = 0; i < count_people; i++) {
		while ((!queue.empty()) && (queue.front() <= people[i]))
		{
			queue.pop_front();
		}
		if (queue.empty()) {
			queue.push_back(people[i] + time);
		}
		else
		{
			queue.push_back(queue.back() + time);
		}
		long long len = queue.size();
		max_len = (max_len > len) ? max_len : len;
	}
	std::cout << max_len - 1;
	return 0;
}





