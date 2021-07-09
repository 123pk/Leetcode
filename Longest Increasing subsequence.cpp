  
/*
Platform :- Leetcode
Approach :- for each index i from [ 0 to nums.size() ] find the max subsequence length that can be formed using the 'ith' element , ( yes it is a dp problem ) . 
            we can do so by checking all the elements before it for (i we will chck from j=0 to j<i) if ( A[j]<A[i] )then the max subsequence length till 'ith'
            index is ----> [ max( val[i] , val[j]+1) ] where val[i] = max subsequence length till ith index
            then out of all values for each index return the max one .
*/
