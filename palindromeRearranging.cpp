/*
Description:
Given a string, find out if its characters can be rearranged to form a palindrome.

Example

For inputString = "aabb", the output should be
palindromeRearranging(inputString) = true.

We can rearrange "aabb" to make "abba", which is a palindrome.

URL: https://app.codesignal.com/arcade/intro/level-4/Xfeo7r9SBSpo3Wico/description
*/
bool palindromeRearranging(std::string inputString) {

    int count = 0;
    std::map<char, int> occur;
    std::map<char,int>::iterator it;
    for(char ch:inputString) {
        it = occur.find(ch);
        if (it != occur.end())occur[ch]++;
        else occur[ch] = 1;
        
        std::cout << ch << std::endl;
        std::cout << occur[ch] << std::endl;
    }
    for(map<char,int>::iterator it = occur.begin(); it != occur.end(); ++it) {
        if(it->second%2!=0) count++;
    }
    return (count<=1)?true:false;
}
