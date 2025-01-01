class Solution {
public:
    int maxScore(string s) {
        int t0=0,t1=0;
        for(char c:s){
            if(c=='0'){
                t0++;
            }
            else{
                t1++;
            }
        }
        int c0=0,c1=0,res=0;
        for(int i=0;i<s.size()-1;i++){
            if(s[i]=='0'){
                c0++;
            }
            else{
                c1++;
            }
            res=max(res,c0+(t1-c1));
        }
        return res;
    }
};