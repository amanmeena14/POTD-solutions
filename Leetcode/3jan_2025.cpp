class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long tsum=0;
        for(int i=0;i<nums.size();i++){
            tsum+=nums[i];
        }
        long long sum=0;
        int res=0;
        for(int i=0;i<nums.size()-1;i++){
            sum+=nums[i];
            if(sum>=(tsum-sum)){
                res++;
            }
        }
        return res;
    }
};