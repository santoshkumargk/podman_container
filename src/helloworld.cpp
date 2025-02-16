#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <config_file_path>" << std::endl;
        return 1;
    }

    std::string config_file_path = argv[1];
    std::string config_value;
    std::ifstream config_file(config_file_path);
    std::ofstream log_file("/app/logs/log.txt", std::ios::app); // Open log file in append mode

    if (!log_file.is_open()) {
        std::cerr << "Unable to open log file" << std::endl;
        return 1;
    }

    if (config_file.is_open()) {
        std::getline(config_file, config_value);
        config_file.close();
        log_file << "Configuration file read successfully: " << config_file_path << std::endl;
    } else {
        std::cerr << "Unable to open configuration file: " << config_file_path << std::endl;
        log_file << "Unable to open configuration file: " << config_file_path << std::endl;
        log_file.close();
        return 1;
    }

    std::cout << "Hello, World!" << std::endl;
    std::cout << "Configuration Value: " << config_value << std::endl;
    log_file << "Hello, World!" << std::endl;
    log_file << "Configuration Value: " << config_value << std::endl;

    log_file.close();
    return 0;
}