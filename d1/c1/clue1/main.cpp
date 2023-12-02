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

	while (getline(input, line))
	{
		if (line.length() < 1) continue;

		std::vector<int> ascii_nums = every_num(line);

		if (ascii_nums.size() == 1)
		{
			int first = ascii_nums[0] - 48;
			int result = concatenate(first, first);
		}
		else
		{
			int first = ascii_nums[0] - 48;
			int second = ascii_nums[1] - 48;
			int result = concatenate(first, second);
		}
		int total = total + result;
	}
}