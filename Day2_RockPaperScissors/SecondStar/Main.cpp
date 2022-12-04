#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <exception>

#define V_LOSE 0
#define V_DRAW 3
#define V_WIN 6
#define LOSE 'X'
#define DRAW 'Y'
#define WIN 'Z'
#define MV_ROCK 1
#define MV_PAPER 2
#define MV_SCISSOR 3
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
        char todo = s[2];
        switch(todo) {
            case LOSE:
                score += V_LOSE;
                break;
            case DRAW:
                score += V_DRAW;
                break;
            case WIN:
                score += V_WIN;
                break;
            default:
                break;
        }
        switch(s[0]) {
            case O_ROCK:
                if (LOSE == todo)
                    score += MV_SCISSOR;
                else if (DRAW == todo)
                    score += MV_ROCK;
                else if (WIN == todo)
                    score += MV_PAPER;
                break;
            case O_PAPER:
                if (LOSE == todo)
                    score += MV_ROCK;
                else if (DRAW == todo)
                    score += MV_PAPER;
                else if (WIN == todo)
                    score += MV_SCISSOR;
                break;
            case O_SCISSOR:
                if (LOSE == todo)
                    score += MV_PAPER;
                else if (DRAW == todo)
                    score += MV_SCISSOR;
                else if (WIN == todo)
                    score += MV_ROCK;
                break;
            default:
                break;
        }
        max += score;
    }
    std::cout << max << std::endl;
    return 1;
}