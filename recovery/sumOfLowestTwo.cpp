/*
Description:

Create a function that returns the sum of the two lowest positive numbers given an array of minimum 4 integers. No floats or empty arrays will be passed.

For example, when an array is passed like [19, 5, 42, 2, 77], the output should be 7.

[10, 343445353, 3453445, 3453545353453] should return 3453455.

URL: https://www.codewars.com/kata/sum-of-two-lowest-positive-integers/cpp
*/
#include <algorithm>
#include <climits>
#include <random>

Describe(Tests)
{
    It(BasicTest)
    {
        long expected = 13;
        
        long actual = sumTwoSmallestNumbers({ 5, 8, 12, 19, 22 });
    
        Assert::That(actual, Is().EqualTo(expected));
    }
    
    It(ExtendedTest1)
    {
        long expected = 6;
        
        long actual = sumTwoSmallestNumbers({ 15, 28, 4, 2, 43 });
    
        Assert::That(actual, Is().EqualTo(expected));
    }
    
    It(ExtendedTest2)
    {
        long expected = 10;
        
        long actual = sumTwoSmallestNumbers({ 3, 87, 45, 12, 7 });
    
        Assert::That(actual, Is().EqualTo(expected));
    }
    
    It(ExtendedTest3)
    {
        long expected = 4000000000;
        
        long actual = sumTwoSmallestNumbers({ 2000000000, 2000000000, 2000000000, 2000000000, 2000000000 });
    
        Assert::That(actual, Is().EqualTo(expected));
    }
    
    It(RandomTests)
    {
        srand(time(0));
        
        auto solution = [](std::vector<int> numbers)
        {
            std::sort(numbers.begin(), numbers.end());
    
            return (long)numbers[0] + (long)numbers[1];
        };
        
        std::default_random_engine generator;
        std::uniform_int_distribution<int> distributor(1, INT_MAX);
        
        for(int i = 0; i < 100; i++)
        {
            int length = rand()%17 + 4;
            
            printf("Test for:\n");
            std::vector<int> numbers;
            for(int j = 0; j < length; j++)
            {
                int n = distributor(generator);
                numbers.push_back(n);
                
                printf("%d", n);
                
                if (j != length - 1)
                {
                    printf(", ");
                }
            }
            printf("\n<hr>\n");
            
            long expected = solution(numbers);
            
            long actual = sumTwoSmallestNumbers(numbers);
            
            Assert::That(actual, Is().EqualTo(expected));
        }
    }
};
long sumTwoSmallestNumbers(std::vector<int> numbers)
{
    std::sort(numbers.begin(), numbers.end());
    return (long long int)numbers[0] + numbers[1];
}
