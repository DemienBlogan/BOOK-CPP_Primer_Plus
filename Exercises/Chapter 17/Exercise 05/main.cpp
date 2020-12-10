/*
5. Mat and Pat want to invite their friends to a party, much as they did in Programming
Exercise 8 in Chapter 16, except now they want a program that uses files.
They have asked you to write a program that does the following:

- Reads a list of Mat’s friends’ names from a text file called mat.dat, which lists
one friend per line.The names are stored in a container and then displayed in
sorted order.

- Reads a list of Pat’s friends’ names from a text file called pat.dat, which lists
one friend per line.The names are stored in a container and then displayed in
sorted order.

- Merges the two lists, eliminating duplicates and stores the result in the file
matnpat.dat, one friend per line.
*/


#include <iostream>
#include <fstream>
#include <list>

void ShowFriends(const std::list<std::string> friends);

int main()
{
	std::string MatFriendsFilename{ "MatFriends.dat" };
	std::string PatFriendsFilename{ "PatFriends.dat" };

	std::ifstream MatFriendsFile{ MatFriendsFilename };
	std::ifstream PatFriendsFile{ PatFriendsFilename };

	if (!MatFriendsFile.is_open())
	{
		std::cerr << "Cannot open file '" << MatFriendsFilename << "'\n";
		return 2;
	}

	if (!PatFriendsFile.is_open())
	{
		std::cerr << "Cannot open file '" << PatFriendsFilename << "'\n";
		return 3;
	}

	std::list<std::string> MatFriends;
	std::list<std::string> PatFriends;

	std::string newFriend;

	while (MatFriendsFile >> newFriend)
		MatFriends.push_back(newFriend);

	while (PatFriendsFile >> newFriend)
		PatFriends.push_back(newFriend);

	PatFriendsFile.close();
	MatFriendsFile.close();

	MatFriends.sort();
	PatFriends.sort();

	std::list<std::string> friends(MatFriends);
	friends.merge(PatFriends);
	friends.unique();

	std::string allFriendsFilename{ "matnpat.dat" };
	std::ofstream allFriendsFile{ allFriendsFilename };

	if (!allFriendsFile.is_open())
	{
		std::cerr << "Cannot open/create file '" << allFriendsFilename << "'\n";
		return 4;
	}

	for (const std::string& nextFriend : friends)
		allFriendsFile << nextFriend << std::endl;

	allFriendsFile.close();

	return 0;
}

void ShowFriends(const std::list<std::string> friends)
{
	for (const std::string& fr : friends)
		std::cout << fr << " ";
	std::cout << std::endl;
}