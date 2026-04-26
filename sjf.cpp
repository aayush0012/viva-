#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; 
    cin>>n;

    vector<pair<int,int>> vp;

    for(int i =0; i<n ; i++){
        int at, bt;
        cin >> at >> bt;
        vp.push_back({at, bt});
    }

    int current_time =0; 
    vector<int>ct(n); 
    float avg =0; 

    int number = 0; 
    vector<int>visited(n,0); 

    while(number<n){
        int mini = INT_MAX ; 
        int time  = -1; 
        int index = -1; 

        for(int i = 0; i<n; i++){
            int arrival = vp[i].first;
            int burst = vp[i].second; 

            if(arrival<=current_time && burst<mini && !visited[i]){
                mini=burst ;
                time = arrival; 
                index=i; 
            }
        }

        if(time==-1){
            current_time++; 
        }
        else{
            current_time+=mini ;
            ct[index]=current_time;
            visited[index]=1;  
            number++; 
        }
    }

    vector<int> tat(n), wt(n);

    for(int i=0; i<n ;i++){
        tat[i] = ct[i] - vp[i].first;
        wt[i] = tat[i] - vp[i].second;

        avg += wt[i];

        cout << "P" << i << " CT:" << ct[i]
             << " TAT:" << tat[i]
             << " WT:" << wt[i] << endl;
    }

    float ans= avg/n; 
    cout << "Average Waiting Time: " << ans << endl;

    return 0;
}