
class Solution {
public:
    string reverseWords(string x) {
        if(x=="")
            return "";
        while(x[0]==' ')
        {
            x.erase(0, 1); 
        }
        if(x.length()==0)
            return "";
    while(x[x.length()-1] == ' ')
    { 
        x.erase(x.length()-1, x.length()); 
    }
        
     reverse(x.begin(),x.end());
     x = x +' ';
        string ans = "";
        string temp ="";
        for(int i =0 ;i<x.length();i++){
            if(x[i]!=' '){
                temp =temp+ x[i];
            }
            if(x[i]==' ' && temp!=""){
                reverse(temp.begin(),temp.end());
                ans = ans+temp + ' ';
                temp ="";
            }
        }
        ans.erase(ans.length()-1,ans.length());
        return ans;
    }
};
