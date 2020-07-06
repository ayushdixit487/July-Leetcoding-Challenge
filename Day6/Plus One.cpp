class Solution {
public:
    vector<int> plusOne(vector<int>& A) {
         int n = A.size();
         long long ans = 0 ;
         vector<int> result ;
         int carry =1;
          reverse(A.begin() , A.end());
          for(int i =0 ;i<n;i++){
               //carry = 0
        
            if((A[i]+carry)>9){
                result.push_back((A[i]+carry)%10);
                 carry = (A[i]+carry)/10;
             }else{
               result.push_back((A[i]+carry));
               carry = 0;
           }
    }
    
        if(carry>0)
           result.push_back(carry);
 
        reverse(result.begin() , result.end());
        for(int i =0 ;i<result.size();i++){
        if(result[0]== 0){
            result.erase(result.begin(),result.begin()+1);
             continue;
          }
            break;
          }
         return result;
   }
};
