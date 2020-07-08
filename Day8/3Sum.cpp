class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>res ;
        if(n==0)
            return res;
        sort(nums.begin() , nums.end());
        for(int i =0;i<n;i++){
            int a = nums[i];
            int l = i+1;
            int r = n-1;
            while(l<r){
                if(nums[l]+nums[r]== -a){
                    vector<int> temp;
                    temp.push_back(a);
                    temp.push_back(nums[l]);
                    temp.push_back(nums[r]);
                    res.push_back(temp);
                     while (l < r && nums[l] == temp[1]) l++;

                while (l < r && nums[r] == temp[2]) r--;
                }else if(nums[l]+nums[r]+a >0)
                    r--;
                else
                    l++;
                    
            }
             while (i + 1 < nums.size() && nums[i + 1] == nums[i]) 
            i++;
        }
        return res;
    }
};
