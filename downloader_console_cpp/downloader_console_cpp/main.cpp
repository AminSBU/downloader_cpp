#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

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
        std::cout << "checking your internet connection ..." << std::endl;
        std::cout << "please wait ..." << std::endl;

        // Create a connection to www.google.com
        std::string url = "www.google.com";
        std::string command = "curl -s -o webpage.html " + url;

        // Execute the command using system call
        int result = system(command.c_str());

        if (result == 0) {
            std::ifstream file("webpage.html");
            std::string line;
            bool connectionLost = true;

            while (std::getline(file, line)) {
                if (line.find("HTML") != std::string::npos) {
                    connectionLost = false;
                    break;
                }
            }

            file.close();

            if (!connectionLost) {
                std::cout << "Connection is ok." << std::endl;

                num_menu = 2;
            }
            else {
                std::cout << "Connection is lost." << std::endl;
            }
        }
        else {
            std::cout << "Error checking internet connection." << std::endl;
        }
    }
    break;

    case 2:
    {
        std::cout << "paste your download link: " << std::endl;
        std::cin >> dl_link;

        std::string url = dl_link;
        fileType = extractFileType(url);
        // Get the current user's profile directory
        char* userProfile = nullptr;
        size_t len = 0;
        if (_dupenv_s(&userProfile, &len, "USERPROFILE") == 0 && userProfile != nullptr) {
            std::string output = std::string(userProfile) + "\\Downloads\\downloaded_file." + fileType; // Specify the folder path

            // Use the Windows command prompt to download the file
            std::string command = "curl -o \"" + output + "\" " + url;

            // Execute the command using system call
            int result = system(command.c_str());

            if (result == 0) {
                std::cout << "File downloaded successfully." << std::endl;
            }
            else {
                std::cout << "Error downloading file." << std::endl;
            }

            free(userProfile); // Free the memory allocated by _dupenv_s
        }
        else {
            std::cout << "Error: Cannot retrieve user profile directory." << std::endl;
        }
    }
    break;

    default:
        break;
    }
    

    return 0;
}