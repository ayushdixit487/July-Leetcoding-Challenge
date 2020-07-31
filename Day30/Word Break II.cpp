class Solution {
public:

	vector<string> ans;
	vector<vector<int>> dp;
	unordered_set<string> dict;
	vector<int> used;
	int mx;

	bool getAns(int i,string &s,string x) {
		if(i==s.length()) {
			x.pop_back();
			ans.push_back(x);
			return true;
		}

		string temp;
		if(used[i]!=-1) {
			if(used[i]==0) return 0;
			for(auto j: dp[i]) {
				temp= string(s.begin()+i,s.begin()+j);
				getAns(j,s,x+temp+" ");
			}
			return true;
		}

		temp="";
		used[i]=0;
		for(int j=i;j<s.length();j++) {
			temp+=s[j];
			if(dict.find(temp) !=dict.end() ) {
				bool b= getAns(j+1,s,x+temp+" ");
				if(b) dp[i].push_back(j+1);
				used[i]= used[i]||b;
			}
			if(j-i+1>=mx) break;
		}

		return used[i];
	}

	vector<string> wordBreak(string s, vector<string>& wordDict) {
		ans.clear(); dict.clear(); dp.clear(); used.clear();
		dp.resize(s.length()); mx=0;
		used.resize(s.length(),-1);

		for(auto &i: wordDict) {
			dict.insert(i);
			int x=i.length();
			mx= max(mx,x);
		}
		getAns(0,s,"");
		return ans;
	}
};
