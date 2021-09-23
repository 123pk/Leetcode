/*
Platform :- Github
Approach :- Take care of case when:-
          i. length of string in 1 ,here we cannot make a string which is not a palindrome
          ii. length is 2 or 3 here if first letter is 'a' then we change the last letter to'b' else we change the first letter to 'a'.
          iii. for all other lengths we traverse through the first half and loof for values which are not 'a' if we found any we change it to 'a' else
               we change the last letter to 'b'.
*/
class Solution {
public:
    string breakPalindrome(string palindrome) {
        
        int n=palindrome.size();
        
        if(n==1)return "";
        
        n/=2;
        int m = palindrome.size();
        
        if(m==2||m==3){
            if(palindrome[0]=='a'){
                palindrome[m-1]='b';
            }
            else palindrome[0]='a';
            return palindrome;
        }
        
        
        int f=0;
        for(int i=0;i<n;++i){
            if(palindrome[i]!='a'){
                f=1;
                palindrome[i]='a';
                break;
            }
        }
        
        if(f==0)palindrome[m-1]='b';
        return palindrome;
    }
};
