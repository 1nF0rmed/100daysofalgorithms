/*
Description:
Note: Try to solve this task in O(n) time using O(1) additional space, where n is the number of elements in l, since this is what you'll be asked to do during an interview.

Given a singly linked list of integers, determine whether or not it's a palindrome.

Example

For l = [0, 1, 0], the output should be
isListPalindrome(l) = true;
For l = [1, 2, 2, 3], the output should be
isListPalindrome(l) = false.

URL: https://app.codesignal.com/interview-practice/task/HmNvEkfFShPhREMn4
*/
// Definition for singly-linked list:
// template<typename T>
// struct ListNode {
//   ListNode(const T &v) : value(v), next(nullptr) {}
//   T value;
//   ListNode *next;
// };
//
ListNode<int> *h = NULL;
bool isListPalindrome(ListNode<int> * l) {
    ListNode<int> *temp = l;

    unsigned int count = 0;

    //push all elements of the list in an array, and count total number of nodes
    std::vector<int> array;
    if(l==NULL)return true;

    while (temp != NULL)
    {
        count++;
        array.push_back (temp->value);
        temp = temp->next;
    }

    bool check = true;

    for (unsigned int i = 0, j = array.size() -1; i < j; i++, j--)
    {
        if (array.at(i) != array.at(j))
            check = false;
    }

    return check;
}
