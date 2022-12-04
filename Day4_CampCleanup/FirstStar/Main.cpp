#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <exception>

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

    unsigned int max = 0;
    for (std::string s : input) {
        std::vector<std::string> part = stwa(s, ",");
        std::vector<std::string> vpart1 = stwa(part[0], "-");
        std::vector<std::string> vpart2 = stwa(part[1], "-");
        std::vector<int> val{std::stoi(vpart1[0]), std::stoi(vpart1[1]), std::stoi(vpart2[0]), std::stoi(vpart2[1])};
        if (val[0] >= val[2] && val[1] <= val[3])
            max += 1;
        else if (val[2] >= val[0] && val[3] <= val[1])
            max += 1;
    }
    std::cout << max << std::endl;
    return 1;
}