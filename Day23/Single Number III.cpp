class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size();
        if(n==0)
        return {};
        vector<int> res(2);
        int xorNumber =0;
        for(int num : nums)
            xorNumber^=num;
        int lsb = xorNumber&(-xorNumber);
        
        for(int num :nums){
            if((lsb &num)==0)
                res[1]^=num;
            else{
                res[0]^=num;
            }
        }
        return res;
        
    }
};
