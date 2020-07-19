class Solution {
public:
    string addBinary(string a, string b) {
        string ans = "";
        int n = a.length();
        int m =  b.length();
        int carry =0;
        while(n>0 && m>0){
            int no = a[n-1]-'0'  + b[m-1]-'0' + carry;
            ans = ans+ to_string(no%2);
            carry = no/2;
            n--; m--;
            
        }
        while(m>0){
            int no = b[m-1]-'0' +carry;
            ans= ans+ to_string(no%2);
            carry = no/2;
             m--;
        }
         while(n>0){
            int no = a[n-1]-'0' +carry;
            ans= ans + to_string(no%2);
            carry = no/2;
             n--;
        }
        if(carry>0)
            ans+= to_string(carry);
        
        reverse(ans.begin(),ans.end());
        
        return ans;
        
    }
};
