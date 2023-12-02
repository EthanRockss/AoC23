#include <iostream>
#include <fstream>
#include <string>
#include <vector>


std::vector<int> every_num(const std::string text)
{
	std::vector<int> nums;
	for (int i = 0; i < text.length(); i++)
	{
		int ascii = text[i];
		if (ascii > 57) continue;
		nums.push_back(text[i]);
	}
	return nums;
}

int concatenate(int i, int j) {
	std::string s1 = std::to_string(i);
	std::string s2 = std::to_string(j);
	std::string s = s1 + s2;
	int c = stoi(s);
	return c;
}

int main()
{
	std::ifstream input("input.txt");
	std::string line;

	int result, total;
	total = 0;

	while (getline(input, line))
	{
		if (line.length() < 1) continue;

		std::vector<int> ascii_nums = every_num(line);
		std::size_t ascii_size = ascii_nums.size();

		if (ascii_size == 0) continue;
		
		int first, last;
		first = last = ascii_nums[0] - 48;

		if (ascii_nums.size() > 1) last = ascii_nums[ascii_nums.size() - 1] - 48;

		result = concatenate(first, last);

		total = total + result;
		std::cout << "First: " << first << '\n';
		std::cout << "Second: " << last << '\n';
		std::cout << "Result: " << result << '\n';
		std::cout << "Total: " << total << '\n' << '\n';
	}
	
}