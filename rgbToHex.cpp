/*
Description:

The rgb() method is incomplete. Complete the method so that passing in RGB decimal values will result in a hexadecimal representation being returned. The valid decimal values for RGB are 0 - 255. Any (r,g,b) argument values that fall out of that range should be rounded to the closest valid value.

The following are examples of expected output values:

rgb(255, 255, 255) # returns FFFFFF
rgb(255, 255, 300) # returns FFFFFF
rgb(0,0,0) # returns 000000
rgb(148, 0, 211) # returns 9400D3

URL: https://www.codewars.com/kata/rgb-to-hex-conversion/cpp
*/
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <sstream>
#include <iomanip>

class RGBToHex
{
  public:
  static std::string rgb(int r, int g, int b);
};

std::string RGBToHex::rgb(int r, int g, int b) {
    std::string res;
    for(auto a: std::vector<int>{ r, g, b}) {
        std::stringstream ss;
        ss << std::hex << ((a<0)?0:(a>255)?255:a);
        res += ((a<=15)?"0":"")+ss.str();
    }
    
    std::transform(res.begin(), res.end(), res.begin(), static_cast<int(*)(int)>(std::toupper));
    
    return res;
}

// Expected test solution
std::string testRGB(int r, int g, int b)
{
  std::ostringstream oss;
  oss << std::uppercase << std::setfill('0') << std::hex
      << std::setw(2) << (r < 0 ? 0 : r > 255 ? 255 : r)
      << std::setw(2) << (g < 0 ? 0 : g > 255 ? 255 : g)
      << std::setw(2) << (b < 0 ? 0 : b > 255 ? 255 : b);
  return oss.str();
}

Describe(ExampleTests)
{
    It(BasicTests)
    {
        Assert::That(RGBToHex::rgb(0,0,0), Equals("000000"));
        Assert::That(RGBToHex::rgb(1,2,3), Equals("010203"));
        Assert::That(RGBToHex::rgb(255,255,255), Equals("FFFFFF"));
        Assert::That(RGBToHex::rgb(254,253,252), Equals("FEFDFC"));
        Assert::That(RGBToHex::rgb(-20,275,125), Equals("00FF7D"));
    }
    
    It(RandomTests)
    {
        srand(time(NULL));
        for (int i = 0; i < 5; i++) {
            int r = (rand() % 256) + (int)(pow(-1, rand() % 2)) * (rand() % 256);
            int g = (rand() % 256) + (int)(pow(-1, rand() % 2)) * (rand() % 256);
            int b = (rand() % 256) + (int)(pow(-1, rand() % 2)) * (rand() % 256);
            Assert::That(RGBToHex::rgb(r, g, b), Equals(testRGB(r, g, b)));
        }
    }
};
