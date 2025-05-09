// You are given an array of integer arr[] where each number represents a vote to a candidate. Return the candidates that have votes greater than one-third of the total votes, If there's not a majority vote, return an empty array. 

// Note: The answer should be returned in an increasing format.

// Examples:

// Input: arr[] = [2, 1, 5, 5, 5, 5, 6, 6, 6, 6, 6]
// Output: [5, 6]
// Explanation: 5 and 6 occur more n/3 times.

// Input: arr[] = [1, 2, 3, 4, 5]
// Output: []
// Explanation: o candidate occur more than n/3 times.

// Constraint:
// 1 <= arr.size() <= 106
// -109 <= arr[i] <= 109

//solution:
class Solution {
  public:
    // Function to find the majority elements in the array
    vector<int> findMajority(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans;
        
        if(n == 0) return ans;
        if(n == 1) return arr;
        
        int ele1 = 0,ele2 = 0, cand1 = 0, cand2 = 0;
        
        for (int num : arr)
        {if(num == ele1)
        {
            cand1++;
        }
        else if(num == ele2)
        {
            cand2++;
        }
        else if(cand1 == 0)
        {ele1 = num;
        cand1 = 1;
            
        }else if(cand2 == 0)
        {
            ele2 = num;
            cand2 = 1;
        }else {
            cand1--;
            cand2--;
        }
        }
        
        
        cand1 = 0;
        cand2 = 0;
        for(int num : arr)
        {
            if(num == ele1)
            cand1++;
            else if(num == ele2) cand2++;
        }
        
        if(cand1>n/3) ans.push_back(ele1);
        if(cand2>n/3 && ele2 != ele1) ans.push_back(ele2);
           
           
           sort(ans.begin(), ans.end());
           return ans;
        
        
    }
    
    
};