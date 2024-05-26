#include <iostream>

using namespace std;

string dl_link;

int main()
{
	std::cout << "Hello! Welcome to File Downloader. \n" << endl;
	std::cout << "Please Copy your File Here: ";
	std::cin >> dl_link;
	std::cout << "\n";
	std::cout << "Your Link is: " << dl_link;
	return 0;
}