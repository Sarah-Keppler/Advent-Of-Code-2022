#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <exception> 

static void getInput(std::vector<std::string> &input)
{
    std::ifstream file{"input.txt"};
    std::string line{};

    while (std::getline(file, line))
        input.push_back(line);
}

int main()
{
    std::vector<std::string> input{};
    try {
        getInput(input);
    } catch (std::exception const &error) {
        std::cerr << error.what() << std::endl;
        return 0;
    }

    unsigned int value = 0, max = 0;
    for (std::string s : input) {
        if (0 == s.length()) {
            if (max < value)
                max = value;
            value = 0;
        } else {
            value += std::stoi(s);
        }
    }
    if (max < value)
        max = value;
    std::cout << max << std::endl;
    return 1;
}