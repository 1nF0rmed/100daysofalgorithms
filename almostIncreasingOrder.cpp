/*
Description:

Given a sequence of integers as an array, determine whether it is possible to obtain a strictly increasing sequence by removing no more than one element from the array.

Example

For sequence = [1, 3, 2, 1], the output should be
almostIncreasingSequence(sequence) = false.

There is no one element in this array that can be removed in order to get a strictly increasing sequence.

For sequence = [1, 3, 2], the output should be
almostIncreasingSequence(sequence) = true.

You can remove 3 from the array to get the strictly increasing sequence [1, 2]. Alternately, you can remove 2 to get the strictly increasing sequence [1, 3].

Input/Output

[execution time limit] 0.5 seconds (cpp)

[input] array.integer sequence

Guaranteed constraints:
2 ≤ sequence.length ≤ 105,
-105 ≤ sequence[i] ≤ 105.

[output] boolean

Return true if it is possible to remove one element from the array in order to get a strictly increasing sequence, otherwise return false.

URL: https://app.codesignal.com/arcade/intro/level-2/2mxbGwLzvkTCKAJMG/
*/

bool almostIncreasingSequence(std::vector<int> sequence) {
  int val = 0;
    int currentBig = sequence.at(0);
    for (int i = 1; i < sequence.size(); i++){
        if( currentBig < sequence.at(i))
        {
            currentBig = sequence.at(i);
        }
        else{
            val++;
            if( val>1)
            {
                return false;
            }
            if( i > 1 ){
                if (sequence.at(i) > sequence.at(i-2)){
                    if( currentBig < sequence.at(i) ){
                    }
                    else{
                        currentBig = sequence.at(i);
                    }
                }
            }
            else{
                currentBig = sequence.at(i);
            }
        }
    }
    return true;
}
