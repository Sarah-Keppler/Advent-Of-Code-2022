#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <exception>
#include <algorithm>

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

    std::vector<unsigned int> bags{};
    unsigned int value = 0;
    for (std::string s : input) {
        if (0 == s.length()) {
            bags.push_back(value);
            value = 0;
        } else {
            value += std::stoi(s);
        }
    }
    bags.push_back(value);
    std::sort(bags.begin(), bags.end());
    unsigned int i = 0, max = 0;
    for (std::vector<unsigned int>::reverse_iterator it = bags.rbegin(), et = bags.rend(); it != et; ++it) {
        if (3 == i)
            break;
        max += *it;
        ++i;
    }
    std::cout << max << std::endl;
    return 1;
}