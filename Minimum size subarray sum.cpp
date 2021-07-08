/*
Platform :- Leetcode
Problem :- minimize size subarray sum
Approach :- we traverse the array ans take two pointer both is initialised to (start = 0 & end = 0) in beginning as we move ahead we do ( tot + = nums[i] and end =i )
            if the value is ( tot > target && (tot - nums[start] >target)) we do ( tot - = nums[start] ,start++) till the time ( start < end ) and our condition is satisfied   
            at the end if our ( tot>= target) we store the min value of ( (end -start)+1) in ans
*/
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int start=0,end=0;
        int tot=0,ans=0;
        for(int i=0;i<nums.size();++i){
            tot+=nums[i];
            end=i;
          //  cout<<tot<<" "<<end<<" ";
            while(tot>target && start<end){
                if((tot-nums[start])>=target){
                    tot-=nums[start];
                    start++;
                }
                else break;
            }
            if(tot>=target) {
                if(ans==0)ans=(end-start)+1;
                else ans=min(ans,(end-start)+1);
            }
        }
        
        return ans;
    }
};
