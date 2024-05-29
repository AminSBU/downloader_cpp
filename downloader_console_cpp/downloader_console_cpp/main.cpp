#include <iostream>
#include <stdlib.h>

using namespace std;

string dl_link;

int num_menu;

std::string extractFileType(const std::string& url) {
    size_t pos = url.find_last_of(".");
    if (pos != std::string::npos) {
        return url.substr(pos + 1);
    }
    else {
        return "Unknown";
    }
}

int main()
{
    std::string fileType;

    std::cout << "Welcome to CPP Downloader!" << std::endl;
    std::cout << "1. Download Files ..." << std::endl;
    std::cout << "2. About Application ...\n" << std::endl;
    std::cout << "*************************\n";
    std::cout << "enter Your choose: ";
    std::cin >> num_menu;

    switch (num_menu)
    {
    case 1:
    {
        std::cout << "paste your download link: " << std::endl;
        std::cin >> dl_link;

        std::string url = dl_link;
        fileType = extractFileType(url);
        std::string output = "downloaded_file." + fileType;

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
    }
    break;

    default:
        break;
    }
    

    return 0;
}