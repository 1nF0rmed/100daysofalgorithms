/*
Description:
Two arrays are called similar if one can be obtained from another by swapping at most one pair of elements in one of the arrays.

Given two arrays a and b, check whether they are similar.

Example

For a = [1, 2, 3] and b = [1, 2, 3], the output should be
areSimilar(a, b) = true.

The arrays are equal, no need to swap any elements.

For a = [1, 2, 3] and b = [2, 1, 3], the output should be
areSimilar(a, b) = true.

We can obtain b from a by swapping 2 and 1 in b.

For a = [1, 2, 2] and b = [2, 1, 1], the output should be
areSimilar(a, b) = false.

Any swap of any two elements either in a or in b won't make a and b equal.

URL: https://app.codesignal.com/arcade/intro/level-4/xYXfzQmnhBvEKJwXP/description
*/
bool areSimilar(std::vector<int> a, std::vector<int> b) {
    // Naive approach
    if(a.size()!=b.size())return false;
    
    std::vector<int> d;
    for(int i=0;i<a.size();i++) {
        if(a[i]!=b[i])d.push_back(i);
    }
    
    if(d.size()==0)return true;
    if(d.size()==2) {
        int ind1 = d.at(0);
        int ind2 = d.at(1);
        return (a[ind1]==b[ind2] && a[ind2]==b[ind1]);
    }
    
    return false;
}
