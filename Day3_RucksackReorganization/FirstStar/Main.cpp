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

    unsigned int max = 0;
    for (std::string s : input) {
        unsigned int half = s.length() / 2;
        std::string first{s.substr(0, half)}, second{s.substr(half)};
        char common = '0';
        for (char c : first) {
            std::size_t idx = second.find(c);
            if (std::string::npos != idx) {
                common = second[idx];
                break;
            }
        }
        unsigned int value = (unsigned int)common;
        if (97 > value)
            value = value + (-65 + 27);
        else
            value -= 96;
        max += value;
    }
    std::cout << max << std::endl;
    return 1;
}