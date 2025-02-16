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

    if (config_file.is_open()) {
        std::getline(config_file, config_value);
        config_file.close();
    } else {
        std::cerr << "Unable to open configuration file: " << config_file_path << std::endl;
        return 1;
    }

    std::cout << "Hello, World!" << std::endl;
    std::cout << "Configuration Value: " << config_value << std::endl;

    return 0;
}