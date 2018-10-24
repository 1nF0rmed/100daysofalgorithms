/*
Description:


*/
#include <random>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cctype>

using namespace std;

Describe(extracting_Max_from_digits)
{
    It(pass_basic_tests)
    {
        Assert::That(maxNumber(213), Equals(321));
          Assert::That(maxNumber(7389), Equals(9873));
            Assert::That(maxNumber(63792), Equals(97632));
        
    }
    It(pass_digit_Occurrence_repeation)
    {
        Assert::That(maxNumber(566797), Equals(977665));
          Assert::That(maxNumber(2399783), Equals(9987332));
            Assert::That(maxNumber(79797979), Equals(99997777));
        
    }
    It(pass_large_numbers)
    {
        Assert::That(maxNumber(17693284), Equals(98764321));
          Assert::That(maxNumber(17758936), Equals(98776531));
            Assert::That(maxNumber(134976658), Equals(987665431));
        
    }
 long long int maxNumber (long long int  number) 
{
    long long int result = 0;
    vector<int> vec;
    while(number>0){
      vec.push_back(number%10);
      number /= 10;
    }
    
    sort(vec.rbegin(), vec.rend());
    
    for(auto a:vec) {
      result = (result*10) + a;
    }
    
    return result;
}

long long int modelSolution(long long int n)
{
    auto str = std::to_string(n);
    std::sort(str.begin(), str.end(), std::greater<>());
    return std::stoll(str);
}

It(passes_some_random_tests)
    {
        std::random_device dev;
        std::mt19937 prng{dev()};
        std::uniform_int_distribution<long long int> dist{0, 1000000002};
        for (int i = 0; i < 100; ++i)
        {
            const auto r = dist(prng);
            Assert::That(maxNumber(r), Equals(modelSolution(r)));
        }
    }
};
