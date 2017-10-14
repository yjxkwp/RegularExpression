#include <iostream>
#include <fstream>
#include <sstream>
#include "re.h"

int main(int argc, char **argv) {
    if(argc != 2){
        std::cerr << "参数不正确" << std::endl;
        return 0;
    }
    std::fstream fs(argv[1]);
    std::string line;
    while (std::getline(fs, line)){
        RegularExpression re = line;
        std::getline(fs, line);
        int num = atoi(line.c_str());
        for(int i = 0; i < num; ++i){
            std::getline(fs, line);
            bool m = re.match(line);
            std::getline(fs, line);
            if(m == (line == "1")){
                std::cout << "匹配成功" << std::endl;
            } else{
                std::cerr << "匹配失败" << std::endl;
            }
        }
        std::getline(fs, line);
    }
}