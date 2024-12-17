class Solution {
public:
    string repeatLimitedString(string s, int rep) {
        vector<int> v(26,0);
        for(int i=0;i<s.size();i++){
            v[s[i]-'a']++;
        }
        priority_queue<pair<int,int>> pq;
        for(int i=0;i<=25;i++){
            if(v[i]>0){
            pq.push({i,v[i]});}
        }
        string ns="";
        while(!pq.empty()){
            auto [c,val]=pq.top();
            pq.pop();
            for(int i=0;i<rep;i++){
                if(val>0){
                ns+=char(c+'a');
                val--;
                }
                else{
                    break;
                }
            }
            if(pq.empty()){
                continue;
            }
            if(val!=0){
                auto [cc,valv]=pq.top();
                pq.pop();
                ns+=char(cc+'a');
                valv--;
                if(valv>0){
                pq.push({cc,valv});}
                pq.push({c,val});
            }

        }
        return ns;
    }
};