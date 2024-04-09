#include <iostream>
#include <fstream>
#include <chrono>
#include <thread>
#include <filesystem>

namespace fs = std::filesystem;

int main() {
    std::string dir = "frames-ascii";

    for (const auto& entry : fs::directory_iterator(dir)) {
        if (entry.is_regular_file()) {
            std::ifstream file(entry.path());
            if (file.is_open()) {
                std::cout << file.rdbuf();
                file.close();
            }
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(1000 / 30));
    }

    return 0;
}
