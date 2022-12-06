#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <exception>
#include <stack>

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

    unsigned int max = 0;
    std::vector<std::stack<char>> piles{};
    for (unsigned int x = 0; ARR_SIZE > x; ++x) {
        piles.push_back(std::stack<char>{});
        for (int i = PILE_HEIGHT - 1; 0 <= i; --i) {
            char c = input[i][1 + (4 * x)];
            if (' ' != c)
                piles[x].push(c);
            else
                break;
        }
    }
    for (unsigned int i = PILE_HEIGHT + 2, e = input.size(); e > i; ++i) {
        std::vector<std::string> words{stwa(input[i], " ")};
        std::stack<char> temp{};
        for (int x = 0, e = std::stoi(words[1]); e > x; ++x) {
            temp.push(piles[std::stoi(words[3]) - 1].top());
            piles[std::stoi(words[3]) - 1].pop();
        }
        for (int x = 0, e = std::stoi(words[1]); e > x; ++x) {
            piles[std::stoi(words[5]) - 1].push(temp.top());
            temp.pop();
        }
    }
    for (std::stack<char> p : piles)
        std::cout << p.top();
    std::cout << std::endl;
    return 1;
}