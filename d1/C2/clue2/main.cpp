#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <regex>
#include <tuple>
#include <algorithm>

std::string reverse_string(std::string str)
{
	int n = str.length();

	for (int i = 0; i < n / 2; i++)
		std::swap(str[i], str[n - i - 1]);

	return str;
}

int word_num_matcher(std::string text)
{
	int num = 0;
	if (text == "one")
		num = 1;
	else if (text == "two")
		num = 2;
	else if (text == "three")
		num = 3;
	else if (text == "four")
		num = 4;
	else if (text == "five")
		num = 5;
	else if (text == "six")
		num = 6;
	else if (text == "seven")
		num = 7;
	else if (text == "eight")
		num = 8;
	else if (text == "nine")
		num = 9;
	else if (text == "zero")
		num = 0;
	return num;
}

std::tuple<int, int> first_of_num_int(const std::string text)
{
	std::tuple<int, int> tup{ -1,-1 };
	for (int i = 0; i < text.length(); i++)
	{
		int ascii = text[i];
		if (ascii > 57) continue;
		tup = { ascii - 48, i };
		break;
	}
	return tup;
}

std::tuple<int, int> first_of_word_int(const std::string text)
{
	std::smatch sm;
	std::tuple<int, int> tup{-1,-1};
	if (std::regex_search(text, sm, std::regex("(one)|(two)|(three)|(four)|(five)|(six)|(seven)|(eight)|(nine)|(zero)")))
	{
		std::string match = sm[0];
		int num = word_num_matcher(match);
		tup = {num, sm.position(0)};
	}
	return tup;
}

std::tuple<int, int> last_of_word_int(const std::string text)
{
	std::smatch sm;
	std::tuple<int, int> tup{ -1,-1 };
	if (std::regex_search(text, sm, std::regex("(eno)|(owt)|(eerht)|(ruof)|(evif)|(xis)|(neves)|(thgie)|(enin)|(orez)")))
	{
		std::string match = sm[0];
		int num = word_num_matcher(reverse_string(match));
		tup = { num, sm.position(0)};
	}
	return tup;
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
	int total = 0;

	while (getline(input, line))
	{
		if (line.length() < 1) continue;

		int first, last;

		std::tuple<int, int> first_word = first_of_word_int(line);
		std::tuple<int, int> first_num = first_of_num_int(line);

		if (std::get<1>(first_word) > std::get<1>(first_num) || std::get<1>(first_word) == -1)
		{
			first = std::get<0>(first_num);
		}
		else
		{
			first = std::get<0>(first_word);
		}

		std::string reverse_line = reverse_string(line);

		std::tuple<int, int> last_word = last_of_word_int(reverse_line);
		std::tuple<int, int> last_num = first_of_num_int(reverse_line);

		if (std::get<1>(last_word) > std::get<1>(last_num) || std::get<1>(first_word) == -1)
		{
			last = std::get<0>(last_num);
		}
		else
		{
			last = std::get<0>(last_word);
		}

		int result = concatenate(first, last);
		total = total + result;
		std::cout << "Line: " << line << '\n';
		std::cout << "First: " << first << '\n';
		std::cout << "Second: " << last << '\n';
		std::cout << "Result: " << result << '\n';
		std::cout << "Total: " << total << '\n' << '\n';
	}
}