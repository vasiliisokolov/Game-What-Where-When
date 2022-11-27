#include <iostream>
#include <vector>
#include <fstream>
#include <string>

void the_weel(int *);
std::string show_question();

int main()
{
    int expertPoints = 0;
    int spectatorsPoints = 0;
    int turnCounter = 13;
    int usedSectors[13];
    std::string truAnswer, answer;
    std::cout << "Lets play What? Where? When?!" << std::endl;
    for (; turnCounter != 0; turnCounter--)
    {
        if (expertPoints == 6 || spectatorsPoints == 6) break;
        std::cout << "Attention! question is:" << std::endl;
        truAnswer = show_question();
        std::cout << truAnswer << std::endl;
        std::cout << "Experts, enter your answer: " << std::endl;
        getline(std::cin, answer);
        (answer == truAnswer ? expertPoints++ : spectatorsPoints);

    }
    (expertPoints > spectatorsPoints ? std::cout << "Expetrs win!" : std::cout << "Spectators win!");
}

void the_weel(int *usedSectors)
{
    int offset = 0;
    int sectorNumber = 0;
    std::string sector;

    switch (sectorNumber)
    {
        case 1:
            sector = "Sector1.txt";
            break;
        case 2:
            sector = "Sector2.txt";
            break;
        case 3:
            sector = "Sector3.txt";
            break;
        case 4:
            sector = "Sector4.txt";
            break;
        case 5:
            sector = "Sector5.txt";
            break;
        case 6:
            sector = "Sector6.txt";
            break;
        case 7:
            sector = "Sector7.txt";
            break;
        case 8:
            sector = "Sector8.txt";
            break;
        case 9:
            sector = "Sector9.txt";
            break;
        case 10:
            sector = "Sector10.txt";
            break;
        case 11:
            sector = "Sector11.txt";
            break;
        case 12:
            sector = "Sector12.txt";
            break;
        case 13:
            sector = "Sector13.txt";
            break;
    }
}

std::string show_question()
{
    std::fstream question;
    std::string answer = "";
    std::vector<char> buffer;
    char temp = 0; {};
    question.open("Sector1.txt");
    if (question.is_open())
    {
        int counter = 0;
        while (true)
        {
            question.get(temp);
            if (temp == '|') break;
            buffer.push_back(temp);
            counter++;
        }
        for (int i = 0; i < buffer.size(); i++)
        {
            std::cout << buffer[i];
        }
        std::cout << std::endl;
        while (true)
        {
            question.get(temp);
            if (temp == '&') break;
            answer += temp;
        }
        question.close();
        return std::string(answer);
    }
    else
    {
        std::cerr << "Error!" << std::endl;
        return std::string("error!");
    }
}
