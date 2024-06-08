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

std::string getFileType(const std::string& dl_link) {
    size_t dotIndex = dl_link.find_last_of(".");
    if (dotIndex != std::string::npos) {
        return dl_link.substr(dotIndex);
    }
    return ""; // Return empty string if file type cannot be determined
}

void downloadFile(const std::string& dl_link, const std::string& filename) {
    std::string file_type = getFileType(dl_link);
    std::string command = "curl -k -o " + filename + file_type + " " + dl_link + " > NUL"; // Replace filename.ext with the desired file name and extension
    int result = system(command.c_str());

    if (result == 0) {
        std::cout << "\nFile downloaded successfully and saved as filename.ext in the project directory!\n";
    }
    else {
        std::cout << "\nFailed to download the file. Please try again.\n";
    }
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
            std::string filename;
            std::cout << "Enter the filename (without extension): ";
            std::cin >> filename;

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
            downloadFile(dl_link, filename);
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