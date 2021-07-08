/*
Platform :-Leetcode
Approach :- draw a 2-d matrix of pair where A[i][j] have a pair of { nums1[i] , nums2[j] } , we create a dp[n][m] where n = num1.size() , m = nums2.size()
            i. if i == 0 or j == 0 then if we have equal pair we store 1 in dp[i][j]
            ii. for i,j>0 we check if A[i][j] have equal pair then we make dp[i][j]=1 and add dp[i-1][j-1] to it 
            iii. if second condition is not met we store dp[i][j] = 0
            iv. after each operation we store the max value in ans and return at end
*/
