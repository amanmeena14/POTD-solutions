class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        stack<int> st;
        int n=arr.size();
        // int ans=0;
        // st.push(arr[0]);
        for(int i=0;i<n;i++){
            if(st.empty() ||arr[i]>st.top()){
                st.push(arr[i]);
            }
            else{
                int maxi=st.top();
                while(!st.empty() && arr[i]<st.top()){
                    st.pop();
                }
                st.push(maxi);
            }
        }
        return st.size();
    }
};