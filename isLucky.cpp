/*
Description:
Ticket numbers usually consist of an even number of digits. A ticket number is considered lucky if the sum of the first half of the digits is equal to the sum of the second half.

Given a ticket number n, determine if it's lucky or not.

Example

For n = 1230, the output should be
isLucky(n) = true;
For n = 239017, the output should be
isLucky(n) = false.

URL: https://app.codesignal.com/arcade/intro/level-3/3AdBC97QNuhF6RwsQ/description

*/

bool isLucky(int n) {
    std::string _n = std::to_string(n);
    int l_sum=0, r_sum=0;
    for(int i=0,j=_n.length()-1;i<(_n.length())/2;i++,j--) {
        l_sum+=_n[i]- '0';r_sum+=_n[j]- '0';
    }
    return l_sum==r_sum;
}
