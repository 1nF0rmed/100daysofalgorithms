/*
Description:
You are given an array of integers. On each move you are allowed to increase exactly one of its element by one. Find the minimal number of moves required to obtain a strictly increasing sequence from the input.

Example

For inputArray = [1, 1, 1], the output should be
arrayChange(inputArray) = 3.

URL: https://app.codesignal.com/arcade/intro/level-4/xvkRbxYkdHdHNCKjg/description
*/
int arrayChange(std::vector<int> inputArray) {
    int moves = 0;
    for(int i=0;i<inputArray.size()-1;i++) {
        if(inputArray[i]>=inputArray[i+1]) {
            int diff = (inputArray[i]-inputArray[i+1])+1;
            moves += diff;
            std::cout << moves << std::endl;
            inputArray[i+1] += diff;
        }
    }
    
    return moves;
}
