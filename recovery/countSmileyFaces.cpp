/*
Description:
Given an array (arr) as an argument complete the function countSmileys that should return the total number of smiling faces.

Rules for a smiling face:
-Each smiley face must contain a valid pair of eyes. Eyes can be marked as : or ;
-A smiley face can have a nose but it does not have to. Valid characters for a nose are - or ~
-Every smiling face must have a smiling mouth that should be marked with either ) or D.
No additional characters are allowed except for those mentioned.
Valid smiley face examples:
:) :D ;-D :~)
Invalid smiley faces:
;( :> :} :] 

Example cases:

countSmileys([':)', ';(', ';}', ':-D']);       // should return 2;
countSmileys([';D', ':-(', ':-)', ';~)']);     // should return 3;
countSmileys([';]', ':[', ';*', ':$', ';-D']); // should return 1;

Note: In case of an empty array return 0. You will not be tested with invalid input (input will always be an array). Order of the face (eyes, nose, mouth) elements will always be the same

Happy coding!

URL:https://www.codewars.com/kata/count-the-smiley-faces/cpp
*/

#include <regex>
#include <random>
#include <math.h>
Describe(Tests)
{
  It(Basic_testing)
  {
    Assert::That(countSmileys({}), Equals(0));
    Assert::That(countSmileys({":D", ":~)", ";~)", ":)"}), Equals(4));
    Assert::That(countSmileys({":)", ":(", ":D", ":O", ":;"}), Equals(2));      
    Assert::That(countSmileys({";]", ":[", ";*", ":$", ";-D"}), Equals(1));   
  }
  It(Random_testing)
  {
    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_real_distribution<> dis(0.0, 1.0);
  
    for(int i = 0; i < 100; i++)
    {
      //Construct our array of 7 smileys
      std::vector<std::string> arr = {sm(gen, dis), sm(gen, dis), sm(gen, dis), sm(gen, dis), sm(gen, dis), sm(gen, dis), sm(gen, dis)};
      std::string msg = "Testing for: [";
      for(int i = 0; i < 7; i++)
        msg += "'" + (i < 6 ? arr.at(i) + "', " : arr.at(i) + "']");      
      std::cout << msg << std::endl;
      
      Assert::That(countSmileys(arr), Equals(solution(arr)));  
    }
  }
  std::string sm(std::mt19937& gen,  std::uniform_real_distribution<>& dis)
  {
    int i = round(dis(gen));
    int j = round(dis(gen) * 2);
    int k = round(dis(gen) * 3);
    bool t = dis(gen) < 0.5; //Determines wether the next smiley will have a nose or not
    return std::string(1, ":;"[i]) + std::string(1, (t ? "-~o"[j] : '\0')) + std::string(1, "D)>("[k]);
  }
  
  int solution(std::vector<std::string> arr) //My solution
  {
    int count = 0;
    for(auto& val : arr)
    {
      if(val.size() == 3)
        count += (val[0] == ':' || val[0] == ';') && (val[1] == '~' || val[1] == '-') && (val[2] == ')' || val[2] == 'D') ? 1 : 0;
      else if(val.size() == 2)
        count += (val[0] == ':' || val[0] == ';') && (val[1] == ')' || val[1] == 'D') ? 1 : 0;
    }
    return count;
  }
};
int countSmileys(std::vector<std::string> arr)
{
  int count = 0;
  std::regex b("(:|;)(~|-)*(\\)|D)*");
  for(std::string a:arr) {
      if(regex_match(a, b))count++;
  }
  
  return count;
}
