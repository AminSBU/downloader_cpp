#include <iostream>
#include <stdlib.h>

using namespace std;

string dl_link;

int main()
{
    std::string url = "http://example.com/file.txt";
    std::string output = "downloaded_file.txt";

    // Use the Windows command prompt to download the file
    std::string command = "curl -o " + output + " " + url;

    // Execute the command using system call
    int result = system(command.c_str());

    if (result == 0) {
        std::cout << "File downloaded successfully." << std::endl;
    }
    else {
        std::cout << "Error downloading file." << std::endl;
    }

    return 0;
}