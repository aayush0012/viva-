#include<bits/stdc++.h>
using namespace std;
int main(){
    int n ;
    cin >> n ;
    vector<int>seek(n); 
    for(int i =0; i<n; i++)cin>>seek[i]; 
    int start; 
    cin>>start; 
    // now we have to look for the nearest job 
    cout<<start; 
    vector<int>visited(n,0); 
    int ans = 0; 
    for(int i =0; i<n; i++){
        // find the nearest to the start
        int mini=100000; 
        int idx = -1; 
        for(int j = 0; j<n; j++){
            if(abs(seek[j]-start) < mini && !visited[j]){
                mini= abs(seek[j]-start); 
                idx = j; 
            }   
        }
        visited[idx]=1; 
        ans+=mini ; 
        start = seek[idx]; 
        cout<<"->"<<seek[idx]; 
    }
    

}