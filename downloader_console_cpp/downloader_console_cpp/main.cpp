#include <iostream>
#include <string>
#include <chrono>
#include <thread>

void printProgressBar(int progress, int total) {
    float percentage = static_cast<float>(progress) / total;
    int barWidth = 70;

    std::cout << "[";
    int pos = barWidth * percentage;
    for (int i = 0; i < barWidth; ++i) {
        if (i < pos)
            std::cout << "=";
        else if (i == pos)
            std::cout << ">";
        else
            std::cout << " ";
    }

    std::cout << "] " << int(percentage * 100.0) << " %\r";
    std::cout.flush();
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
            // Perform internet connection check (You can put your implementation here)
            std::cout << "Connection is ok.\n";
            num_menu = 0;
        }
        break;

        case 2:
        {
            std::cin.ignore(); // Clear the input buffer
            std::cout << "Paste your download link: ";
            std::getline(std::cin, dl_link);

            // Download file simulation (replace with actual download code)
            int totalFileSize = 1000; // Simulated total file size
            int downloaded = 0;
            const int downloadRate = 50; // Simulated download rate (bytes/sec)

            std::cout << "\nDownloading...";

            while (downloaded < totalFileSize) {
                downloaded += downloadRate;
                printProgressBar(downloaded, totalFileSize);
                std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Simulate download delay
            }

            std::cout << "\nFile downloaded successfully!\n";

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