class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if(n==0)
        return tasks.size();
        int m = tasks.size();
        vector<int> freq(26);
        for(int i=0;i<m;i++){
            freq[tasks[i]-'A']++;
        }
        sort(freq.begin(),freq.end());
        int mostFrequent = freq[25];
        int idleTime = (mostFrequent -1)*n;
        
        for(int i=24;i>=0;i--){
            idleTime -= min(mostFrequent-1,freq[i]);
            if(idleTime<0)
                return m;
        }
        return m+idleTime;
    }
};
