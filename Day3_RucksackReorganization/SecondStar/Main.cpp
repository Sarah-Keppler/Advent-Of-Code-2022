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
    for (unsigned int it = 0, et = input.size(); et > it; it += 3) {
        char common = '0';
        for (char c : input[it]) {
            std::size_t f_found = input[it + 1].find(c), s_found = input[it + 2].find(c);
            if (std::string::npos != f_found && std::string::npos != s_found) {
                common = input[it + 1][f_found];
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