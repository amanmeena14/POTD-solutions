#include <bits/stdc++.h>
using namespace std;

int subset_maximization(const std::vector<int>& A, int N) {
    // Write your logic here.
    map<int,int> mpo,mpe;
    for(int i=0;i<A.size();i++){
        if(A[i]%2==0){
            mpe[A[i]]++;
        }
        else{
            mpo[A[i]]++;
        }
    }
    int len=INT_MAX;
    while(!mpe.empty()){
        int last=0,llen=0,llt=mpe.begin()->first;
        vector<int> vec;
        for(auto it:mpe){
            if(it.second>=last && (it.first-llt)<=2){
                llen++;
                last=it.second;
                llt=it.first;
                mpe[it.first]--;
                if(mpe[it.first]==0){
                    vec.push_back(it.first);
                }
            }
            else{
                break;
            }
        }
        for(int i=0;i<vec.size();i++){
            mpe.erase(vec[i]);
        }
        len=min(len,llen);
    }
    while(!mpo.empty()){
        int last=0,llen=0,llt=mpo.begin()->first;
        vector<int> vec;
        for(auto it:mpo){
            if(it.second>=last && (it.first-llt)<=2){
                llen++;
                last=it.second;
                llt=it.first;
                mpo[it.first]--;
                if(mpo[it.first]==0){
                   vec.push_back(it.first);
                }
            }
            else{
                break;
            }
        }
        for(int i=0;i<vec.size();i++){
            mpo.erase(vec[i]);
        }
        len=min(len,llen);
    }
    return len==INT_MAX?1:len;
}

int main() {
    int N;
    std::cin >> N;  // First input is the integer N
    std::vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> A[i];  // Remaining input is the array of integers
    }
    
    // Call user logic function and print the output
    int result = subset_maximization(A, N);
    std::cout << result << std::endl;
    
    return 0;
}
