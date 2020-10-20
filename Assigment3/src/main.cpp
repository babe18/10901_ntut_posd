#include "terminal.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <regex>

int main(int argc, char const *argv[])
{
    if (argc == 5) {
        std::ifstream ipf(argv[1]);
        std::ofstream opf(argv[2]);
        std::string fileContext = "";
        std::stringstream ss;
        
        while (std::getline(ipf, fileContext))
        {
            ss << std::regex_replace(fileContext, std::regex("[\r\n]"), "") << " ";
        }
        ss << std::string(argv[4]) << " " << std::string(argv[3]);
        opf << Terminal(ss.str()).showResult();
        ipf.close();
        opf.close();
        return 0;
    }
    return -1;
}
