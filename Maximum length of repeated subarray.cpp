/*
Platform :-Leetcode
Approach :- draw a 2-d matrix of pair where A[i][j] have a pair of { nums1[i] , nums2[j] } , we create a dp[n][m] where n = num1.size() , m = nums2.size()
            i. if i == 0 or j == 0 then if we have equal pair we store 1 in dp[i][j]
            ii. for i,j>0 we check if A[i][j] have equal pair then we make dp[i][j]=1 and add dp[i-1][j-1] to it 
            iii. if second condition is not met we store dp[i][j] = 0
            iv. after each operation we store the max value in ans and return at end
*/
class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int ans=0;
        int n=nums1.size();
        int m=nums2.size();
        
        int dp[n][m];
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(i==0||j==0){
                    if(nums1[i]==nums2[j])dp[i][j]=1;
                    else dp[i][j]=0;
                }
                else{
                    if(nums1[i]==nums2[j])dp[i][j]=1+dp[i-1][j-1];
                    else dp[i][j]=0;
                    
                }
                 ans=max(ans,dp[i][j]);
            }
        }
        
        
        return ans;
    }
};
