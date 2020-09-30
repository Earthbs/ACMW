/*
Given a binary string s (a string consisting only of '0's and '1's), we can split s into 3 non-empty strings s1, s2, s3 (s1+ s2+ s3 = s).

Return the number of ways s can be split such that the number of characters '1' is the same in s1, s2, and s3.

Since the answer may be too large, return it modulo 10^9 + 7.

 

Example 1:

Input: s = "10101"
Output: 4
Explanation: There are four ways to split s in 3 parts where each part contain the same number of letters '1'.
"1|010|1"
"1|01|01"
"10|10|1"
"10|1|01"
Example 2:

Input: s = "1001"
Output: 0
Example 3:

Input: s = "0000"
Output: 3
Explanation: There are three ways to split s in 3 parts.
"0|0|00"
"0|00|0"
"00|0|0"
Example 4:

Input: s = "100100010100110"
Output: 12
 

Constraints:

s[i] == '0' or s[i] == '1'
3 <= s.length <= 10^5

*/

// ans%(1000000007)
#define ll long long int
#define mod 1000000007 

class Solution {
public:
    int numWays(string s) {
        ll num_of_ones = 0;
        for(ll i = 0; i<s.size(); i++){
            if(s[i] == '1') num_of_ones = num_of_ones%mod + 1;
        }
        if(num_of_ones == 0) return (((s.size()-1)%mod * (s.size()-2)%mod)%mod)/2;
        if(num_of_ones % 3 != 0) return 0;
        
        ll i = 0;
        ll first = 0; ll second = 0;
        ll first_ones = 0; ll second_ones = 0;
  
           while(i<s.size() && first_ones < num_of_ones/3){
               if(s[i] == '1') first_ones = first_ones%mod + 1;
               i++;
           }
        
           while(i<s.size() && s[i] == '0') {first = first%mod + 1; i++;}
        
           while(i<s.size() && second_ones < num_of_ones/3){
               if(s[i] == '1') second_ones = second_ones%mod + 1;
               i++;
           }
           while(i<s.size() && s[i] == '0') {second = second%mod + 1; i++;}
        
    return ((first+1)%mod*(second+1)%mod)%mod;
    }
};