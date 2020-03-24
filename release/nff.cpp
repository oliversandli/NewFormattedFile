#include <fstream>
#include <iostream>
#include <pwd.h>
#include <sstream>
#include <string>
#include <unistd.h>

std::string read_file(std::string file_name) {
    std::ifstream in_file;
    in_file.open(file_name);
    std::stringstream str_stream;
    str_stream << in_file.rdbuf();
    return str_stream.str();
}

void write_file(std::string file_name, std::string file_contents) {
    std::ofstream out(file_name);
    out << file_contents;
    out.close();
}

std::string conf_dir() {
    char *XDG_path_char = getenv("XDG_DATA_HOME");
    if (XDG_path_char == NULL) {
        struct passwd *pw = getpwuid(getuid());
        std::string home_path(pw->pw_dir);
        return home_path + "/.config";
    }
    std::string XDG_path(XDG_path_char);
    return XDG_path;
}

int main(int argc, char** argv) {
    if (argc == 2) {
        std::string new_file_name(argv[1]);
        if ((new_file_name == "--help") or (new_file_name == "-h")) {
            std::cout << "New Formatted File v1.0.1\nCreate new file with the format assigned to the file extension.\nSee https://github.com/oliversandli/NewFormattedFile for help/documentation." << std::endl;
        } else {
            std::string conf_path(conf_dir() + "/nff/templates/" + new_file_name.substr(new_file_name.find(".") + 1) + ".conf");
            std::string conf_contents(read_file(conf_path));
            if (conf_contents == "") {
                std::cout << "Error: no such config: " << conf_path << std::endl;
                return 1;
            } else {
                write_file(new_file_name, conf_contents);
            }
        }
    } else {
        std::cout << "Error: nff takes 1 argument but " << (argc - 1) << " were given" << std::endl;
        return 1;
    }
    return 0;
}
