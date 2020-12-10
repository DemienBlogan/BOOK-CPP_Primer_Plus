/*
1. Modify the Tv and Remote classes as follows:
	a. Make them mutual friends.
	b. Add a state variable member to the Remote class that describes whether the
	   remote control is in normal or interactive mode.
	c. Add a Remote method that displays the mode.
	d. Provide the Tv class with a method for toggling the new Remote member.
This method should work only if the TV is in the on state.
Write a short program that tests these new features.
*/

#include <iostream>
#include "Remote.h"
#include "Television.h"

int main()
{
	Remote myRemote;
	Television myTV;

	myRemote.TurnOnOff(myTV);
	std::cout << "Remote mode: " << (myRemote.IsNormal() ? "Normal" : "Interactive") << std::endl;
	myTV.ChangeRemoteNormalMode(myRemote);
	std::cout << "Remote mode: " << (myRemote.IsNormal() ? "Normal" : "Interactive") << std::endl;

	return 0;
}