/*
Description:
A Narcissistic Number is a number which is the sum of its own digits, each raised to the power of the number of digits in a given base. In this Kata, we will restrict ourselves to decimal (base 10).

For example, take 153 (3 digits):

    1^3 + 5^3 + 3^3 = 1 + 125 + 27 = 153
and 1634 (4 digits):

    1^4 + 6^4 + 3^4 + 4^4 = 1 + 1296 + 81 + 256 = 1634
The Challenge:

Your code must return true or false depending upon whether the given number is a Narcissistic number in base 10.

Error checking for text strings or other invalid inputs is not required, only valid integers will be passed into the function.

Problem Link: https://www.codewars.com/kata/does-my-number-look-big-in-this/train/cpp
*/

#include <ctime>
#include <cstdlib>
#include <cmath>

using namespace std;

bool narcissistic( int value ){
  std::string val = std::to_string(value);
  int sum = 0;
  for(int i=val.length()-1;i>-1;i--){
    sum += pow((int)val[i] - 48, val.length());
  }
  return sum==value;
}

Describe(Narcissistic_function)
{
	It(small_numbers)
	{
		Assert::That(narcissistic(1), Equals(true));
		Assert::That(narcissistic(5), Equals(true));
		Assert::That(narcissistic(7), Equals(true));
	}
	It(larger_numbers)
	{
		Assert::That(narcissistic(153), Equals(true));
		Assert::That(narcissistic(370), Equals(true));
		Assert::That(narcissistic(371), Equals(true));
		Assert::That(narcissistic(1634), Equals(true));

	}
	It(randomized_test_1)
	{
		srand(time(NULL));
		for (int i = 0; i < 10; i++) {
			int num = (rand() % 5 + 5) * 60000 + (rand() % 99 + 1);
			Assert::That(narcissistic(num), Equals(false));
		}
	}
	It(randomized_test_2)
	{
		vector<int> bignums = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 153, 370, 371, 407, 1634, 8208, 9474, 54748, 92727, 93084, 548834, 1741725,
			                          4210818, 9800817, 9926315, 24678050, 24678051 };
		for (int b : bignums)
			if (rand() % 11 > 5)
				Assert::That(narcissistic(b), Equals(true));
			else {
				int num = (rand() % 5 + 5) * 900000 + (rand() % 99 + 1);
				Assert::That(narcissistic(num), Equals(false));
			}
	}
};
