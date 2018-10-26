/*
Description:
Given an array of strings, return another array containing all of its longest strings.

Example

For inputArray = ["aba", "aa", "ad", "vcd", "aba"], the output should be
allLongestStrings(inputArray) = ["aba", "vcd", "aba"].

URL: https://app.codesignal.com/arcade/intro/level-3/fzsCQGYbxaEcTr2bL/description
*/
struct compare {
    bool operator()(const std::string& first, const std::string& second) {
        return first.size() < second.size();
    }
};

std::vector<std::string> allLongestStrings(std::vector<std::string> inputArray) {
    std::vector<std::string> res;
    compare c;
    std::sort(inputArray.begin(), inputArray.end(), c);
    int max = inputArray[inputArray.size()-1].length();
    for(auto it=inputArray.begin();it != inputArray.end(); ++it) {
        if((*it).length()==max)res.push_back(*it);
    }
    return res;
}
