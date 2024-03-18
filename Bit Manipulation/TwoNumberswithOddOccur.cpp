#include <bits/stdc++.h>
using namespace std;
vector<int> twoOddNum(vector<int> arr)
{
    // Write your code here.
    int XOR = 0;

    // Find XOR of all elements in the array
    for (int num : arr)
    {
        XOR ^= num;
    }

    // Find the rightmost set bit in XOR
    int rightmostSetBit = XOR & -XOR;

    // Initialize two numbers with odd occurrences
    int num1 = 0, num2 = 0;

    // Partition the array based on the rightmost set bit
    for (int num : arr)
    {
        if (num & rightmostSetBit)
        {
            // Group 1 (rightmost set bit is set)
            num1 ^= num;
        }
        else
        {
            // Group 2 (rightmost set bit is not set)
            num2 ^= num;
        }
    }

    // Ensure num1 is greater than num2
    if (num1 < num2)
    {
        swap(num1, num2);
    }

    return {num1, num2};
}