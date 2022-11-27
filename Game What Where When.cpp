#include <iostream>
#include <vector>
#include <fstream>
#include <string>

int turnCounter = 0;
std::string sector;
int usedSectors[13];
bool check_offset(int);
void the_weel();
std::string show_question();
void check_sectorNumber(int&);

int main()
{
    int expertPoints = 0;
    int spectatorsPoints = 0;
    
   std::string truAnswer, answer;

    std::cout << "Lets play What? Where? When?!" << std::endl;
    for (; turnCounter < 13; turnCounter++)
    {
        the_weel();
        
        std::cout << "Attention! question is:" << std::endl;
        truAnswer = show_question();
        std::cout << truAnswer << std::endl;
        std::cout << "Experts, enter your answer: " << std::endl;
        getline(std::cin, answer);
        (answer == truAnswer ? expertPoints++ : spectatorsPoints++);
        if (expertPoints == 6 || spectatorsPoints == 6) break;
    }
    (expertPoints > spectatorsPoints ? std::cout << "Expetrs win!" : std::cout << "Spectators win!");
}

bool check_offset(int offset)
{
    if (offset < 0 && offset > 13)
    {
        return false;
    }
    else
    {
        return true;
    }
}

void the_weel()
{
   int offset = 0;
   int sectorNumber = 1;
   std::cout << "Please!Enter the offset of the weel:" << std::endl;
   std::cin >> offset;
   
   while(!check_offset(offset))
   {
       std::cerr << "Error! Enter the number only in range 0 - 13!" << std::endl;
       std::cin >> offset;
   }
   std::cin.ignore();
   sectorNumber += offset;
   check_sectorNumber(sectorNumber);
   /*std::cout << sectorNumber << std::endl;
   for (int i = 0; i < 13; i++)
   {
       std::cout << usedSectors[i];
   }
   std::cout << std::endl;*/
   for (int i = 0; i < 13; i++)
   {
       if (*(usedSectors + i) == 0)
       {
           *(usedSectors + i) = sectorNumber;
           break;
       }
   }
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
    question.open(sector);
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

void check_sectorNumber(int& sectorNumber)
{
    for (int i = 0; i < 13; i++)
    {
        if (sectorNumber == *(usedSectors + i))
        {
            sectorNumber++;
            check_sectorNumber(sectorNumber);
        }
        
    }

    //check_sectorNumber(sectorNumber);
}
