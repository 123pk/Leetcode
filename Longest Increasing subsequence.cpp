  
/*
Platform :- Leetcode
Approach :- for each index i from [ 0 to nums.size() ] find the max subsequence length that can be formed using the 'ith' element , ( yes it is a dp problem ) . 
            we can do so by checking all the elements before it for (i we will chck from j=0 to j<i) if ( A[j]<A[i] )then the max subsequence length till 'ith'
            index is ----> [ max( val[i] , val[j]+1) ] where val[i] = max subsequence length till ith index
            then out of all values for each index return the max one .
*/
class Solution {
public:
    int lengthOfLIS(vector<int>& A) {
        int n=A.size();
        
        //val store the max length of subsequence till for ith index
        vector<int>val(n,1);
        for(int i=1;i<n;++i){
                for(int j=0;j<i;++j){
                    if(A[j]<A[i]){
                        val[i]=max(val[i],val[j]+1);
                    }
                }
        }
        
        
        int ans=INT_MIN;
        for(auto &x:val){
            ans=max(ans,x);
        }
        return ans;
    }
};
