
/*
Platform :- Leetcode
Problem :- Pascal Triangle
Approach :- we can analyse that no of elementh at 'ith' level is 'i' ,
            --> elements at level 1 = [ 1 ]
            --> elements at level 2 = [ 1, 1]
            --> for every level greater than 2 we have 1st and last element as '1' and 'jth' elements of that level is sum of elementh at previous level at index [ j-1] and [j]
                 A[i][j] = A[i-1][j-1] + A[i-1][j]
*/

