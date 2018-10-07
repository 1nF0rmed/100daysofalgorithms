/*
Description:

Deoxyribonucleic acid (DNA) is a chemical found in the nucleus of cells and carries the "instructions" for the development and functioning of living organisms.

If you want to know more http://en.wikipedia.org/wiki/DNA

In DNA strings, symbols "A" and "T" are complements of each other, as "C" and "G". You have function with one side of the DNA (string, except for Haskell); you need to get the other complementary side. DNA strand is never empty or there is no DNA at all (again, except for Haskell).

More similar exercise are found here http://rosalind.info/problems/list-view/ (source)

DNA_strand ("ATTGC") # return "TAACG"

DNA_strand ("GTAT") # return "CATA"

*/

#include <string>

std::string DNAStrand(std::string dna)
{
  std::map<char, char> comp = { {'A','T'},{'C','G'},{'T','A'},{'G','C'} };
  for(int i=0;i<dna.length();i++) {
    dna[i] = comp[dna[i]];
  }
  return dna;
}

Describe(ExmapleTests)
{
    It(BasicTests)
    {
        Assert::That(DNAStrand("AAAA"), Equals("TTTT"));
        Assert::That(DNAStrand("ATTGC"), Equals("TAACG"));
        Assert::That(DNAStrand("GTAT"), Equals("CATA"));
    }
};

Describe(ExtendedTests)
{
    It(Tests)
    {
        Assert::That(DNAStrand("AAGG"), Equals("TTCC"));
        Assert::That(DNAStrand("CGCG"), Equals("GCGC"));
        Assert::That(DNAStrand("ATTGC"), Equals("TAACG"));
        Assert::That(DNAStrand("GTATCGATCGATCGATCGATTATATTTTCGACGAGATTTAAATATATATATATACGAGAGAATACAGATAGACAGATTA"), Equals("CATAGCTAGCTAGCTAGCTAATATAAAAGCTGCTCTAAATTTATATATATATATGCTCTCTTATGTCTATCTGTCTAAT"));
    }
    
    It(RandomTests)
    {
        srand(time(0));
        
        std::function<std::string (std::string)> solution = [](std::string dna)
        {
            std::string result;
    
            for(int i = 0; i < dna.size(); i++)
            {
                if (dna[i] == 'A')
                {
                    result += 'T';
                }
                else if (dna[i] == 'T')
                {
                    result += 'A';
                }
                else if (dna[i] == 'C')
                {
                    result += 'G';
                }
                else if (dna[i] == 'G')
                {
                    result += 'C';
                }
            }
            
            return result;
        };
        
        std::string dnaBase = "ATCG";
        for(int i = 0; i < 100; i++)
        {
            int length = rand()%101 + 1;
            
            std::string testDNA;
            for(int j = 0; j < length; j++)
            {
                testDNA += dnaBase[rand()%dnaBase.size()];
            }
            
            std::string expected = solution(testDNA);
            std::string actual = DNAStrand(testDNA);
            
            Assert::That(actual, Is().EqualTo(expected));
        }
    }
};
