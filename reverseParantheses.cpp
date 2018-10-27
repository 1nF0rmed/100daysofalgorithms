/*
Description:
You have a string s that consists of English letters, punctuation marks, whitespace characters, and brackets. It is guaranteed that the parentheses in s form a regular bracket sequence.

Your task is to reverse the strings contained in each pair of matching parentheses, starting from the innermost pair. The results string should not contain any parentheses.

Example

For string s = "a(bc)de", the output should be
reverseParentheses(s) = "acbde".

URL: https://app.codesignal.com/arcade/intro/level-3/3o6QFqgYSontKsyk4/description

*/

std::string reverseString(std::string s){
    for(int i = 0;i < s.size()/2;i++){
        char t = s[s.size()-1-i];
        s[s.size()-1-i] = s[i];
        s[i] = t;
    }
    return s;
}

std::string reverseParentheses(std::string s) {
    int begin = 0;
    int end = s.size() - 1;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '(')
            begin = i;
        if(s[i] == ')'){
            end = i;
            string temp = s.substr(begin + 1, end - begin - 1);
            return reverseParentheses(s.substr(0, begin) + reverseString(temp) + s.substr(end + 1));
         }
    }
    return s;
}
