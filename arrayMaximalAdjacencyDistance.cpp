/*
Description:
Given an array of integers, find the maximal absolute difference between any two of its adjacent elements.

Example

For inputArray = [2, 4, 1, 0], the output should be
arrayMaximalAdjacentDifference(inputArray) = 3.

URL: https://app.codesignal.com/arcade/intro/level-5/EEJxjQ7oo7C5wAGjE/description
*/
int arrayMaximalAdjacentDifference(std::vector<int> inputArray) {
    int max = -9999;
    for(int i=0;i<inputArray.size()-1;i++) {
        if(std::abs(inputArray[i]-inputArray[i+1])>max)max = std::abs(inputArray[i]-inputArray[i+1]);
    }
    return max;
}
