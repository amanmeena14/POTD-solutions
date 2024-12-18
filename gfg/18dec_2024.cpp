
#include<bits/stdc++.h>
class Solution {
  public:
    bool check(vector<int> arr,int k,int mid){
        int ss=1,sum=0;
        for(int i=0;i<arr.size();i++){
            if(sum+arr[i]>mid){
                ss+=1;
                sum=arr[i];
                
            if(ss>k){
                return false;
            }
            }
            else{
                sum+=arr[i];
            }
        }
        return true;
        
    }
    int findPages(vector<int> &arr, int k) {
        // code here
        if(arr.size()<k){
            return -1;
        }
        int r=0,l=0;
        for(auto it:arr){
            r+=it;
            l=max(l,it);
        }
        while(l<=r){
            int mid=(l+r)/2;
            if(check(arr,k,mid)){
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return l;
    }
};