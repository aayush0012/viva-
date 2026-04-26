#include<bits/stdc++.h>
using namespace std;
int main() {
    int n ;
    cin>>n;
    vector<int>seek(n); 
    for(int i =0; i<n; i++)cin>>seek[i]; 
    sort(seek.begin(),seek.end()); 
    int start =0 ;
    cin>>start; 
    cout<<start; 
    // we go right and then we go left 
    int idx=-1; 
    int ans=0 ;
    int end =200; 
    for(int i =0; i<n; i++){
        if(seek[i]<start){
            continue;
        }
        else{
            idx=i; 
            break; 
        }
    }
    if(idx==-1){
        cout<<"->"<<end; 
        ans+=abs(start-end);
        start=end; 
        for(int i =n-1; i>=0; i--){
            ans+=abs(seek[i]-start);
            start=seek[i]; 
            cout<<"->"<<seek[i]; 
        }
        cout<<ans<<endl; 

    }
    else{
        vector<int>visited(n,0); 
        for(int i =idx; i<n; i++){
            ans+=abs(seek[i]-start);
            start=seek[i]; 
            cout<<"->"<<seek[i]; 
        }
        cout<<"->"<<end ;
        ans+=abs(start-end); 
        start=end;
        for(int i = idx-1;i>=0; i--){
                ans+=abs(seek[i]-start); 
                start=seek[i]; 
                cout<<"->"<<seek[i]; 

        }
    
        cout<<ans<<endl ;
    }
}