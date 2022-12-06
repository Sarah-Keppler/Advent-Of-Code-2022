#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <exception>
#define ARR_SIZE 9
#define PILE_HEIGHT 8

static std::vector<std::string> stwa(std::string const & s, std::string const &separator)
{
    std::vector<std::string> arr{};
    int start = 0;
    int end = s.find(separator);
    while (-1 != end) {
        arr.push_back(s.substr(start, end));
        start = end + separator.size();
        end = s.find(separator, start);
    }
    arr.push_back(s.substr(start));
    return arr;
}

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

    unsigned int i = 0;
    for (unsigned int e = input[0].size(); e > i; ++i) {
        std::string temp{input[0].substr(i, 4)};
        bool marker = true;
        for (unsigned int it = 0, et = temp.size(); et > it; ++it) {
            unsigned int n = 0;
            char const c = temp[it];
            for (unsigned int xi = 0, xe = temp.size(); xe > xi; ++xi)
                if (c == temp[xi])
                    n++;
            if (n > 1) {
                marker = false;
                break;
            }
        }
        if (marker) {
            break;
        }
    }
    std::cout << i + 4 << std::endl;
    return 1;
}