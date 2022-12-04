#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <exception>

#define LOSE 0
#define DRAW 3
#define WIN 6

#define M_ROCK 'X'
#define M_PAPER 'Y'
#define M_SCISSOR 'Z'
#define O_ROCK 'A'
#define O_PAPER 'B'
#define O_SCISSOR 'C'

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
        unsigned int score = 0;
        char own = s[2];
        switch(own) {
            case M_ROCK:
                score += 1;
                break;
            case M_PAPER:
                score += 2;
                break;
            case M_SCISSOR:
                score += 3;
                break;
            default:
                break;
        }
        switch(s[0]) {
            case O_ROCK:
                if (M_ROCK == own)
                    score += DRAW;
                else if (M_PAPER == own)
                    score += WIN;
                else if (M_SCISSOR == own)
                    score += LOSE;
                break;
            case O_PAPER:
                if (M_ROCK == own)
                    score += LOSE;
                else if (M_PAPER == own)
                    score += DRAW;
                else if (M_SCISSOR == own)
                    score += WIN;
                break;
            case O_SCISSOR:
                if (M_ROCK == own)
                    score += WIN;
                else if (M_PAPER == own)
                    score += LOSE;
                else if (M_SCISSOR == own)
                    score += DRAW;
                break;
            default:
                break;
        }
        max += score;
    }
    std::cout << max << std::endl;
    return 1;
}