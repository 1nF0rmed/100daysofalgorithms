/*
Description:
Given an array a that contains only numbers in the range from 1 to a.length, find the first duplicate number for which the second occurrence has the minimal index. In other words, if there are more than 1 duplicated numbers, return the number for which the second occurrence has a smaller index than the second occurrence of the other number does. If there are no such elements, return -1.

Example

For a = [2, 1, 3, 5, 3, 2], the output should be
firstDuplicate(a) = 3.

There are 2 duplicates: numbers 2 and 3. The second occurrence of 3 has a smaller index than the second occurrence of 2 does, so the answer is 3.

For a = [2, 4, 3, 5, 1], the output should be
firstDuplicate(a) = -1.

URL: https://app.codesignal.com/interview-practice/task/pMvymcahZ8dY4g75q
*/
// Approach 1 - Passed 5/11 hidden tests
int _firstDuplicate(std::vector<int> a) {
    int min = 9999;
    int res = -1;
    
    std::map<char, int> o;
    std::map<char,int>::iterator it;
    for(int i=0;i<a.size();i++) {
        it = o.find('0'+a[i]);
        if (it != o.end()) {
            if(o['0' + a[i]] == 0)
                o['0' + a[i]]=i;
        }
        else o['0' + a[i]] = 0;
    }

    for(it=o.begin();it!=o.end();it++) {
        std::cout << "n: " << it->first << std::endl;
        std::cout << "o: " << it->second << std::endl;
        if(it->second!=0 && it->second < min) {
            min = it->second;
            res = it->first - '0';
        }
    }
    
    return res;
}

// Approach 2 - Passes all the tests
int firstDuplicate(std::vector<int> a) {
    
    // return -1 if none found:
    int duplicate = -1;
    
    // iterate through array and test for duplicates:
    for (int i = 0; i < a.size(); i++) {
        
        // hold current number and it's abs val:
        int currentNum = a[i];
        int absCurr = abs(currentNum) - 1;
        
        // check if the slot indexed by currentNum is positive,
        // if so, it hasn't been seen, so flip it:
        if ( a[absCurr] > 0) {
            a[absCurr] = a[absCurr] * -1;
        }
        // if it's negative, it's been seen, return it:
        else {
            return abs(a[i]);
        }
        
    }

    return duplicate;
}

