// Given two binary strings s1 and s2 consisting of only 0s and 1s. Find the resultant string after adding the two Binary Strings.
// Note: The input strings may contain leading zeros but the output string should not have any leading zeros.

// Input: s1 = "1101", s2 = "111"
// Output: 10100
// Explanation:
//  1101
// + 111
// 10100

// Input: s1 = "00100", s2 = "010"
// Output: 110
// Explanation: 
//   100
// +  10
//   110

// Constraints:
// 1 ≤s1.size(), s2.size()≤ 106

//solution:
class Solution {
  public:
    string removeLeadingZeroes(string& str){
        int i = 0;
        while(str[i] == '0')
        {
            i++;
        }
        return str.substr(i);
    }
    string addBinary(string& s1, string& s2) {
        s1 = removeLeadingZeroes(s1);
        s2 = removeLeadingZeroes(s2);
        
        if(s1.size() < s2.size()){
            return addBinary(s2,s1);
        }
        
        int i = s1.size() - 1;
        int j = s2.size() -1;
        
        int carry = 0;
        string ans = "";
        
        while(i >= 0 || carry){
            int sum = carry;
            if(i >= 0){
                sum += s1[i] - '0';
                i--;
            }
            if(j >= 0){
                sum += s2[j] - '0';
                j--;
            }
            ans = char((sum % 2)+ '0')+ ans;
            carry = sum /2;
            
        }
        return ans;
        
    }
};