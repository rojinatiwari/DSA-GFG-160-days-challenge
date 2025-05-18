// Given two strings, one is a text string txt and the other is a pattern string pat. The task is to print the indexes of all the occurrences of the pattern string in the text string. Use 0-based indexing while returning the indices. 
// Note: Return an empty list in case of no occurrences of pattern.

// Examples :

// Input: txt = "abcab", pat = "ab"
// Output: [0, 3]
// Explanation: The string "ab" occurs twice in txt, one starts at index 0 and the other at index 3. 

// Input: txt = "abesdu", pat = "edu"
// Output: []
// Explanation: There's no substring "edu" present in txt.

// Input: txt = "aabaacaadaabaaba", pat = "aaba"
// Output: [0, 9, 12]
// Explanation:

// Constraints:
// 1 ≤ txt.size() ≤ 106
// 1 ≤ pat.size() < txt.size()
// Both the strings consist of lowercase English alphabets.

//solution:
class Solution {
  public:
  
    void getLPSArr(string& pat, vector<int>& lps)
    {
        lps[0] = 0;
        
        int len = 0, i =1;
        
        while(i < pat.size())
        {
            if(pat[i] == pat[len])
            {
                len++;
                lps[i] = len;
                i++;
            }else{
                if(len != 0){
                    len =lps[len -1];
                }else{
                  lps[i] = 0;
                i++;  
                }
            }   
        }
    }
  
    vector<int> search(string& pat, string& txt) {
        // code here
        vector<int> lps(pat.length());
        vector<int> ans;
        
        getLPSArr(pat,lps);
        
        for(int i = 0, j= 0; i<txt.size();)
        {
            if(txt[i] == pat[j])
            {
                i++; j++;
                if(j == pat.length())
                {
                    ans.push_back(i- j);
                    j = lps[j-1];
                }
            }
            
            else{
                if(j!= 0)
                {
                    j = lps[j -1];
                } else {
                    i++;
                }
            }
        }
        return ans;
        
    }
};


