/*
Description:
Given two strings, find the number of common characters between them.

Example

For s1 = "aabcc" and s2 = "adcaa", the output should be
commonCharacterCount(s1, s2) = 3.

Strings have 3 common characters - 2 "a"s and 1 "c".

URL: https://app.codesignal.com/arcade/intro/level-3/JKKuHJknZNj4YGL32/description

*/

int commonCharacterCount(std::string s1, std::string s2) {
    int count = 0;
    for(auto i:s1){
        for(int j=0;j<s2.length();j++) {
            if(i==s2[j] ){count++;s2.erase(s2.begin()+j);break;}
        }
    }
    return count;
}
