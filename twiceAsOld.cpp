/*
Description:
Your function takes two arguments:

current father's age (years)
current age of his son (years)
Сalculate how many years ago the father was twice as old as his son (or in how many years he will be twice as old).

Problem: https://www.codewars.com/kata/twice-as-old/train/cpp
*/

#include <cstdlib>
#include <ctime>

Describe(Fixed_Tests)
{
    It(Tests)
    {
        Assert::That(twice_as_old(36 ,7), Equals(22));
        Assert::That(twice_as_old(55, 30), Equals(5));
        Assert::That(twice_as_old(42, 21), Equals(0));
        Assert::That(twice_as_old(22, 1), Equals(20));
        Assert::That(twice_as_old(29, 0), Equals(29));
    }
};

static int twice_as_old(int dad, int son) {
  int i=1;
  if (dad==son*2)
    return 0;
  /*
  if(ceil(dad/2.0) > son) {
    while(i>0){
      if(dad+i == (son+i)*2)return i;
      i++;
    }
  } else {
    while(i>0) {
      if(dad-i == (son-i)*2)return i;
      i++;
    }
  } 
  return -1;*/
  return abs(dad - (son*2)); // 2(son + i) = (dad + i) => i = dad - 2*son 
}

static int randint(int a, int b) {return a + rand() % (b - a + 1);}

Describe(Random_Tests)
{
    It(Tests)
    {
        srand(time(0));
        for (int i = 0; i < 100; i++) {
            int dad = randint(18, 100);
            int son = std::max(0, dad - randint(18, 40));
            Assert::That(twice_as_old(dad, son), Equals(twice_as_old(dad, son)));
        }
    }
};
