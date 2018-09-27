#include <random>
#include <iostream>

/* Description:
All of the animals are having a feast! Each animal is bringing one dish. There is just one rule: the dish must start and end with the same letters as the animal's name.
For example, the great blue heron is bringing garlic naan and the chickadee is bringing chocolate cake.
Write a function feast that takes the animal's name and dish as arguments and returns true or false to indicate whether the beast is allowed to bring the dish to the feast.
Assume that beast and dish are always lowercase strings, and that each has at least two letters. beast and dish may contain hyphens and spaces, but these will not appear at the beginning or end of the string.
They will not contain numerals.
*/

struct seeder{
  template<typename T>
  void generate(T begin, T end) const {
    for (std::random_device r; begin != end; begin++) *begin = r();
  }
};

auto& prng_engine(){
  seeder s;
  static std::mt19937 engine{s};
  return engine;
}

auto randint(int a, int b){
  std::uniform_int_distribution<> dist{a, b};
  return dist(prng_engine());
}

bool sol(const std::string& beast, const std::string& dish){
  return beast[0] == dish[0] && beast[beast.size() - 1] == dish[dish.size() - 1];
}

// Function to be tested
bool feast(std::string beast, std::string dish){
  return beast[0] == dish[0] && beast.back() == dish.back();
}

// Tests
Describe(Feast){
  It(BasicTests){
    Assert::That(feast("great blue heron", "garlic naan"), Equals(true));
    Assert::That(feast("chickadee", "chocolate cake"), Equals(true));
    Assert::That(feast("brown bear", "bear claw"), Equals(false));
    Assert::That(feast("marmot", "mulberry tart"), Equals(true));
    Assert::That(feast("porcupine", "pie"), Equals(true));
    Assert::That(feast("electric eel", "lasagna"), Equals(false));
    Assert::That(feast("slow loris", "salsas"), Equals(true));
    Assert::That(feast("ox", "orange lox"), Equals(true));
    Assert::That(feast("blue-footed booby", "blueberry"), Equals(true));
    Assert::That(feast("blue-footed booby", "binary human"), Equals(false));
  }
  It(RandomTests){
    std::string base = "abcdefghijklmnopqrstuvwxyz";
    for (int i = 0; i < 40; i++){
      std::string beast = "", dish = "";
      unsigned int beastLen = randint(3, 40), dishLen = randint(3, 38);
      for (; beastLen--;) beast += base[randint(0, base.size() - 1)];
      for (; dishLen--;) dish += base[randint(0, base.size() - 1)];
      dish = randint(0, 1) ? dish : beast[0] + dish + beast[beast.size() - 1];
      std::cout << "Testing for '" << beast << "' and '" << dish << "'\n\n";
      Assert::That(feast(beast, dish), Equals(sol(beast, dish)));
    }
  }
};
