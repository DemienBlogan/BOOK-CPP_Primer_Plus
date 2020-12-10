/*
8. Mat and Pat want to invite their friends to a party.They ask you to write a program
that does the following:

- Allows Mat to enter a list of his friends’ names.The names are stored in a
container and then displayed in sorted order.

- Allows Pat to enter a list of her friends’ names.The names are stored in a second
container and then displayed in sorted order.

- Creates a third container that merges the two lists, eliminates duplicates, and
displays the contents of this container.
*/

#include <iostream>
#include <list>

void ShowFriends(const std::list<std::string> friends);

int main()
{
	std::list<std::string> MatFriends;
	std::list<std::string> PatFriends;

	std::string newFriend;

	std::cout << "Mat, enter your friends' names ('stop' to stop): ";
	while (std::cin >> newFriend && newFriend != "stop")
		MatFriends.push_back(newFriend);

	std::cout << "Pat, enter your friends' names ('stop' to stop): ";
	while (std::cin >> newFriend && newFriend != "stop")
		PatFriends.push_back(newFriend);

	std::cout << "Mat friends: ";
	ShowFriends(MatFriends);

	std::cout << "Pat friends: ";
	ShowFriends(PatFriends);

	MatFriends.sort();
	PatFriends.sort();

	std::list<std::string> friends(MatFriends);
	friends.merge(PatFriends);
	friends.unique();

	std::cout << "All friends: ";
	ShowFriends(friends);

	return 0;
}

void ShowFriends(const std::list<std::string> friends)
{
	for (const std::string& fr : friends)
		std::cout << fr << " ";
	std::cout << std::endl;
}