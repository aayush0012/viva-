#include<bits/stdc++.h>
using namespace std;
// Disk Scheduling Algorithm 
int main() {
    int n ; 
    cin>>n; 
    vector<int>seek(n); 
    for(int i =0; i<n; i++){
        cin>>seek[i]; 
    }
    int start; 
    cin>>start; 
    int ans = 0;
    cout<<start<<"->"<<" ";
    for(int i =0; i<n; i++){
        ans+=abs(seek[i]-start); 
        cout<<seek[i]<<"->"<<" ";
        start=seek[i]; 
    } 

    cout<<endl;  
    cout<<"Total seek time is "<<ans<<endl; 
}