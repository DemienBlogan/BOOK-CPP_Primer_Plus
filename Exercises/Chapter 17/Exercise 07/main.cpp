/*
7. Here is part of a program that reads keyboard input into a vector of string objects,
stores the string contents (not the objects) in a file, and then copies the file contents
back into a vector of string objects:

int main()
{
using namespace std;
vector<string> vostr;
string temp;
// acquire strings
cout << "Enter strings (empty line to quit):\n";
while (getline(cin,temp) && temp[0] != '\0')
vostr.push_back(temp);
cout << "Here is your input.\n";
for_each(vostr.begin(), vostr.end(), ShowStr);
// store in a file
ofstream fout("strings.dat", ios_base::out | ios_base::binary);
for_each(vostr.begin(), vostr.end(), Store(fout));
fout.close();
// recover file contents
vector<string> vistr;
ifstream fin("strings.dat", ios_base::in | ios_base::binary);
if (!fin.is_open())
{
cerr << "Could not open file for input.\n";
exit(EXIT_FAILURE);
}
GetStrs(fin, vistr);
cout << "\nHere are the strings read from the file:\n";
for_each(vistr.begin(), vistr.end(), ShowStr);
return 0;
}

Note that the file is opened in binary format and that the intention is that I/O be
accomplished with read() and write(). Quite a bit remains to be done:
- Write a void ShowStr(const string &) function that displays a string
object followed by a newline character.
- Write a Store functor that writes string information to a file.The Store
constructor should specify an ifstream object, and the overloaded
operator()(const string &) should indicate the string to write.A workable
plan is to first write the string’s size to the file and then write the string
contents. For example, if len holds the string size, you could use this:
os.write((char *)&len, sizeof(std::size_t)); // store length
os.write(s.data(), len); // store characters
The data() member returns a pointer to an array that holds the characters in
the string. It’s similar to the c_str() member except that the latter appends a
null character.

- Write a GetStrs() function that recovers information from the file. It can
use read() to obtain the size of a string and then use a loop to read that
many characters from the file, appending them to an initially empty temporary
string. Because a string’s data is private, you have to use a class method to
get data into the string rather than read directly into it.
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void GetStrs(ifstream& file, vector<string>& strings);
void ShowStr(const string& str);

class Store
{
private:
	ofstream& file;

public:
	Store(ofstream& file)
		: file(file)
	{ }

	void operator()(const string& str)
	{
		size_t length = str.length();
		file.write(reinterpret_cast<char*>(&length), sizeof(size_t));
		file.write(str.data(), sizeof(char) * length);
	}
};

int main()
{
	vector<string> vostr;
	string temp;

	// acquire strings
	cout << "Enter strings (empty line to quit):\n";
	while (getline(cin, temp) && temp[0] != '\0')
		vostr.push_back(temp);

	cout << "Here is your input.\n";
	for_each(vostr.begin(), vostr.end(), ShowStr);

	// store in a file
	ofstream fout("strings.dat", ios_base::out | ios_base::binary);
	for_each(vostr.begin(), vostr.end(), Store(fout));

	fout.close();

	// recover file contents
	vector<string> vistr;
	ifstream fin("strings.dat", ios_base::in | ios_base::binary);

	if (!fin.is_open())
	{
		cerr << "Could not open file for input.\n";
		exit(EXIT_FAILURE);
	}

	GetStrs(fin, vistr);

	cout << "\nHere are the strings read from the file:\n";
	for_each(vistr.begin(), vistr.end(), ShowStr);

	return 0;
}

void GetStrs(ifstream& file, vector<string>& strings)
{
	size_t len;
	string str;

	while (!file.eof())
	{
		file.read(reinterpret_cast<char*>(&len), sizeof(size_t));

		if (file.eof())
			break;

		for (size_t i = 0; i < len; i++)
		{
			char ch;
			file.read(reinterpret_cast<char*>(&ch), sizeof(char));
			str.push_back(ch);
		}

		strings.push_back(str);

		str.clear();
	}
}

void ShowStr(const string& str)
{
	cout << str << endl;
}