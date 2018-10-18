/*
Description:

Time to win the lottery!

Given a lottery ticket (ticket), represented by an array of 2-value arrays, you must find out if you've won the jackpot. Example ticket:

{ { "ABC", 65 }, { "HGR", 74 }, { "BYHT", 74 } }
To do this, you must first count the 'mini-wins' on your ticket. Each sub array has both a string and a number within it. If the character code of any of the characters in the string matches the number, you get a mini win. Note you can only have one mini win per sub array.

Once you have counted all of your mini wins, compare that number to the other input provided (win). If your total is more than or equal to (win), return 'Winner!'. Else return 'Loser!'.

All inputs will be in the correct format. Strings on tickets are not always the same length.

URL: https://www.codewars.com/kata/lottery-ticket/cpp
*/

#include <random>
using namespace std;
typedef std::pair<std::string, int> p;
Describe(Test)
{
    It(Basic_tests)
    {
      Assert::That(bingo({p("ABC", 65), p("HGR", 74), p("BYHT", 74)}, 2), Equals("Loser!"));
      Assert::That(bingo({p("ABC", 65), p("HGR", 74), p("BYHT", 74)}, 1), Equals("Winner!"));
      Assert::That(bingo({p("HGTYRE", 74), p("BE", 66), p("JKTY", 74)}, 3), Equals("Loser!"));
    }
    It(Random_tests)
    {
      random_device rd;  //Will be used to obtain a seed for the random number engine
      mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
      
      for(int testNo = 0; testNo < 100; testNo++)
      {
        vector<p> ticket;
        int len = randomInt(1, 10)(gen), need = randomInt(0, 8)(gen);
        int win = randomInt(1, len)(gen);
        
        //Loop for len
        for(int i = 0; i < len; i++)
        {
          string name = "";
          int room = randomInt(2, 8)(gen);
          for(int j = 0; j < room; j++)
            name += names.at(randomInt(0, names.size() - 1)(gen));
          ticket.push_back(p(name, nums.at(randomInt(0, nums.size() -1)(gen)))); //Push back our name and num pair eg.("ABCD", 78)
        }
        string ticketStr = "[";  
        
        for(int l = 0; l < ticket.size(); l++)
        {
          ticketStr += "[" + ticket.at(l).first + ", " + to_string(ticket.at(l).second) + "]";
          
          if(l != ticket.size() - 1)
            ticketStr += ", ";
        }
        ticketStr += "]";
        
        cout << ticketStr << " and win: " << win << endl;
        
        Assert::That(bingo(ticket, win), Equals(solution(ticket, win)));
      }
    }
    
    uniform_int_distribution<> randomInt(int a, int b){ //Generates a random number 
      return uniform_int_distribution<>(a, b);
    }
    
    vector<char> names={'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    vector<int> nums={65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90};
    std::string solution(std::vector<std::pair<std::string, int>> ticket, int win)
{
  int count = 0;
  for(int i=0;i<ticket.size();i++) {
    if(ticket[i].first.find(char(ticket[i].second)) != std::string::npos)count++;
  }
  return (count>=win)?"Winner!":"Loser!";
}

};

