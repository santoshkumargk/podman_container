#include <iostream>
#include <fstream>
#include <string>

void log_message(const std::string& message, std::ofstream& log_file) {
    log_file << message << std::endl;
    std::cout << message << std::endl;
}

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
        log_message("Configuration file read successfully: " + config_file_path, log_file);
    } else {
        log_message("Unable to open configuration file: " + config_file_path, log_file);
        return 1;
    }

    log_message("Hello, World!", log_file);
    log_message("Configuration Value: " + config_value, log_file);

    log_file.close();
    return 0;
}