class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int res=0;
        for(int i=0;i<words.size();i++){
            for(int j=i+1;j<words.size();j++){
                if(words[i].size()<=words[j].size()){
                    if(words[j].substr(0,words[i].size())==words[i] && words[j].substr(words[j].size()-words[i].size())==words[i]){
                        res++;
                    }
                    // if(words[j].substr(words[j].size()-words[i].size())==words[i]){
                    //     res++;
                    // }
                }
            }
        }
        return res;
    }
};