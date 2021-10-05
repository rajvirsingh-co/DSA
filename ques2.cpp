// Question Link : https://leetcode.com/problems/valid-palindrome-ii/

// Level : Medium 

class Solution {
public:
    bool ispalindrome(string s){
        string r = s ; 
        reverse(r.begin(),r.end());
        if(r==s)return true;
        return false;
    }
    
    
    bool validPalindrome(string s) {
        int n = s.size();
        if(ispalindrome(s)){
            return true;
        }
        int i=0,j=n-1;
        while(i<=j){
            if(s[i]==s[j]){
                i++;j--;
            }
            else{
                break;
            }
        }
        
        if(ispalindrome(s.substr(i,j-i)) || ispalindrome(s.substr(i+1,j-i)) )return true;
        else
            return false;
    }
};