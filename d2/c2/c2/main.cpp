#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <regex>

int concatenate(int i, int j) {
	std::string s1 = std::to_string(i);
	std::string s2 = std::to_string(j);
	std::string s = s1 + s2;
	int c = stoi(s);
	return c;
}

int num_string_to_int(std::string text)
{
	int num = 0;
	if (text.length() == 1)
		num = text[0] - 48;
	else if (text.length() == 2)
		num = concatenate(text[0] - 48, text[1] - 48);
	else if (text.length() == 3)
		num = concatenate(concatenate(text[0] - 48, text[1] - 48), text[2] - 48);
	return num;
}

int get_game_id(std::string text)
{
	std::smatch sm;
	int num = 0;

	if (std::regex_search(text, sm, std::regex("([0-9]+):")))
	{
		num = num_string_to_int(sm[1]);
	}
	return num;
}

std::vector<int> get_highest_values(std::string text)
{
	std::smatch sm;
	std::vector<int> vect{ 0, 0, 0 };
	std::vector<std::regex> regex{ std::regex("([0-9]+) red"),std::regex("([0-9]+) green"),std::regex("([0-9]+) blue") };

	for (int j = 0; j < regex.size(); j++)
	{
		auto words_begin = std::sregex_iterator(text.begin(), text.end(), regex[j]);
		auto words_end = std::sregex_iterator();


		for (std::sregex_iterator i = words_begin; i != words_end; i++)
		{
			std::smatch match = *i;
			int current = vect[j];
			int working = num_string_to_int(match[1]);

			if (working < current) continue;
			vect.at(j) = working;
		}
	}
	return vect;
}

int main()
{
	std::ifstream input("input.txt");
	std::string line;
	int total = 0;

	while (getline(input, line))
	{
		int maxred = 12;
		int maxgreen = 13;
		int maxblue = 14;

		int gameid = get_game_id(line);
		std::vector<int> highest_nums = get_highest_values(line);

		total = total + (highest_nums[0] * highest_nums[1] * highest_nums[2]);
	}
	std::cout << "Total: " << total << std::endl;
	return 0;
}