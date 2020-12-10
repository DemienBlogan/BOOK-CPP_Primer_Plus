/*
2. Do the same problem as given in Programming Exercise 1 but do worry about
complications such as capitalization, spaces, and punctuation.That is,“Madam, I’m
Adam” should test as a palindrome. For example, the testing function could reduce
the string to “madamimadam” and then test whether the reverse is the same. Don’t
forget the useful cctype library.You might find an STL function or two useful
although not necessary.
*/

#include <iostream>
#include <string>
#include <cctype>

std::string EnterString();
std::string GetOnlyLowerLetters(const std::string& str);
bool IsPalindrom(const std::string& str);

int main()
{
	std::string str = EnterString();
	std::string onlyLowerLettersStr = GetOnlyLowerLetters(str);
	std::cout << "Your string " << (IsPalindrom(onlyLowerLettersStr) ? "is" : "isn't") << " a palindrom.\n";

	return 0;
}

std::string EnterString()
{
	std::cout << "Enter a string: ";
	std::string str;
	std::getline(std::cin, str);

	return str;
}

std::string GetOnlyLowerLetters(const std::string& str)
{
	std::string onlyLowerLettersStr;

	size_t length = str.length();
	for (size_t i = 0; i < length; i++)
		if (std::isalpha(str[i]))
			onlyLowerLettersStr.push_back(std::tolower(str[i]));

	return onlyLowerLettersStr;
}

bool IsPalindrom(const std::string& str)
{
	size_t length = str.length();
	for (size_t i = 0; i < length; i++)
		if (str[i] != str[length - i - 1])
			return false;

	return true;
}