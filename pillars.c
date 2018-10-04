/*
Description:

There are pillars near the road. The distance between the pillars is the same and the width of the pillars is the same. Your function accepts three arguments:

number of pillars (≥ 1);
distance between pillars (10 - 30 meters);
width of the pillar (10 - 50 centimeters).
Calculate the distance between the first and the last pillar in centimeters (without the width of the first and last pillar).

*/

#include <algorithm>
#include <cstdlib>
#include <ctime>

Describe(Fixed_Tests)
{
    It(Tests)
    {
        Assert::That(pillars(1, 10, 10), Equals(0));
        Assert::That(pillars(2, 20, 25), Equals(2000));
        Assert::That(pillars(11, 15, 30), Equals(15270));
    }
};

static long solution(int n, int d, int w) {
  return --n * d * 100 + std::max(--n, 0) * w;
}

long pillars(int num_of_pillars, int distance, int width) {
  return num_of_pillars == 1 ? 0 : ((num_of_pillars - 2) * width) + ((num_of_pillars - 1 ) * distance * 100);
}

static int randint(int a, int b) {return a + rand() % (b - a + 1);}

Describe(Random_Tests)
{
    It(Tests)
    {
        srand(time(0));
        for (int i = 0; i < 100; i++) {
          int n = randint(1, 1000), d = randint(10, 30), w = randint(10, 50);
          long result = solution(n, d, w);
          Assert::That(pillars(n, d, w), Equals(result));
        }
    }
};
