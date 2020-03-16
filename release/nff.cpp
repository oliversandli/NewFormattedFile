#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

std::string readFile(std::string fileName) {
    std::ifstream inFile;
    inFile.open(fileName);
    std::stringstream strStream;
    strStream << inFile.rdbuf();
    return strStream.str();
}

void writeFile(std::string fileName, std::string fileContents) {
    std::ofstream out(fileName);
    out << fileContents;
    out.close();
}

int main(int argc, char** argv) {
    if (argc == 2) {
        std::string newFileName(argv[1]);
        if ((newFileName == "--help") or (newFileName == "-h")) {
            std::cout << "New Formatted File v1.0.1\nCreate new file with the format assigned to the file extension.\nSee https://github.com/oliversandli/NewFormattedFile for help/documentation." << std::endl;
        } else {
            std::string confPath("~/.config/nff/templates/" + newFileName.substr(newFileName.find(std::string(".")) + 1).append(".conf"));
            std::string confContents(readFile(confPath));
            if (confContents == "") {
                std::cout << "Error: no such config: " << confPath << std::endl;
                return 1;
            } else {
                writeFile(newFileName, confContents);
            }
        }
    } else {
        std::cout << "Error: nff takes 1 argument but " << (argc - 1) << " were given" << std::endl;
        return 1;
    }
    return 0;
}
