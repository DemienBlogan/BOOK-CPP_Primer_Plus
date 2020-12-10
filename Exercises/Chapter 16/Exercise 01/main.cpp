/*
1. A palindrome is a string that is the same backward as it is forward. For example,“tot”
and “otto” are rather short palindromes.Write a program that lets a user enter a
string and that passes to a bool function a reference to the string.The function
should return true if the string is a palindrome and false otherwise. At this point,
don’t worry about complications such as capitalization, spaces, and punctuation.
That is, this simple version should reject “Otto” and “Madam, I’m Adam.” Feel free
to scan the list of string methods in Appendix F for methods to simplify the task.
*/

#include <iostream>
#include <string>

std::string EnterString();
bool IsPalindrom(const std::string& str);

int main()
{
	std::string str = EnterString();
	std::cout << "Your string " << (IsPalindrom(str) ? "is" : "isn't") << " a palindrom.\n";

	return 0;
}

std::string EnterString()
{
	std::cout << "Enter a string: ";
	std::string str;
	std::getline(std::cin, str);

	return str;
}

bool IsPalindrom(const std::string& str)
{
	size_t length = str.length();

	for (size_t i = 0; i < length; i++)
		if (str[i] != str[length - i - 1])
			return false;

	return true;
}