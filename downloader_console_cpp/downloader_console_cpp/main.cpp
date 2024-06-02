#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

std::string extractFileType(const std::string& url) {
    size_t dotIndex = url.find_last_of('.');
    if (dotIndex != std::string::npos) {
        return url.substr(dotIndex + 1);
    }
    return "Unknown";
}

int main() {
    int num_menu = 0;
    std::string dl_link;
    bool should_exit = false;

    while (!should_exit) {
        switch (num_menu) {
        case 0:
        {
            std::cout << "****************************\n";
            std::cout << "Welcome to CPP Downloader!\n";
            std::cout << "1. Check Internet Connection\n";
            std::cout << "2. Download Files\n";
            std::cout << "3. Exit\n";
            std::cout << "****************************\n";
            std::cout << "Enter your choice: ";
            std::cin >> num_menu;
        }
        break;

        case 1:
        {
            std::cout << "Checking your internet connection...\n";
            system("curl -s -o webpage.html www.google.com");
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
                std::cout << "Connection is ok.\n";
            }
            else {
                std::cout << "Connection is lost.\n";
            }

            num_menu = 0;
        }
        break;

        case 2:
        {
            std::cin.ignore(); // Clear the input buffer
            std::cout << "Paste your download link: ";
            std::getline(std::cin, dl_link);

            // Download file code

            std::cout << "Downloading file from link: " << dl_link << std::endl;

            num_menu = 0;
        }
        break;

        case 3:
        {
            std::cout << "Exiting the program. Goodbye!\n";
            should_exit = true;
        }
        break;

        default:
        {
            std::cout << "Invalid choice. Please select a valid option.\n";
            num_menu = 0;
        }
        break;
        }
    }

    return 0;
}