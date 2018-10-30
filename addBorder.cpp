/*
Description:
Given a rectangular matrix of characters, add a border of asterisks(*) to it.

Example

For

picture = ["abc",
           "ded"]
the output should be

addBorder(picture) = ["*****",
                      "*abc*",
                      "*ded*",
                      "*****"]

URL: https://app.codesignal.com/arcade/intro/level-4/ZCD7NQnED724bJtjN/description
*/
std::vector<std::string> addBorder(std::vector<std::string> picture) {
    std::vector<std::string> res;
    res.push_back(std::string(picture[0].length()+2, '*'));
    for(auto a:picture){
        a.insert(0, "*");
        a+="*";
        res.push_back(a);
    }
    res.push_back(std::string(picture[0].length()+2, '*'));
    
    return res;
}

/*Number 1 in C++ Solution*/
std::vector<std::string> addBorder(std::vector<std::string> picture) {
    for(auto &s: picture)
        s = "*"+s+"*";
    picture.insert(picture.begin(), string(picture[0].size(),'*'));
    picture.insert(picture.end(), string(picture[0].size(),'*'));
    return picture;
}
