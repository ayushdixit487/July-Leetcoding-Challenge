class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
            map<int,int> m;
        for(int i=0;i<nums.size();i++)
        {
             m[nums[i]]++;
        }
        
        priority_queue<pair<int,int>> pq;
        
        
        for(auto x:m)
        { 
            pq.push(make_pair(x.second,x.first));
        }
        
        vector<int> ans;
        
        int j=0;
        
        while(j<k)
        {
            ans.push_back(pq.top().second);
            pq.pop();
            j++;
        }
        return ans;
    }
    
};
