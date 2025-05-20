// Given a string s consisting of lowercase English Letters. Return the first non-repeating character in s.
// If there is no non-repeating character, return '$'.
// Note: When you return '$' driver code will output -1.

// Examples:

// Input: s = "geeksforgeeks"
// Output: 'f'
// Explanation: In the given string, 'f' is the first character in the string which does not repeat.

// Input: s = "racecar"
// Output: 'e'
// Explanation: In the given string, 'e' is the only character in the string which does not repeat.

// Input: s = "aabbccc"
// Output: -1
// Explanation: All the characters in the given string are repeating.

// Constraints:
// 1 ≤ s.size() ≤ 105

//solutions:

class Solution {
  public:
  const int MAX_CHAR = 26;
    char nonRepeatingChar(string &s) {
        // Your code here
        vector <int> freq(MAX_CHAR, 0);
        
        for(char c:s)
        {
            freq[c-'a']++;
        }
        
        for(char c:s)
        {
            if(freq[c - 'a']== 1)
            {
                return c;
            }
        }
        return '$';
    }
};