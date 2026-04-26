#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; 
    cin>>n;

    vector<pair<int,int>> vp;

    // ek saath push (arrival, burst)
    for(int i =0; i<n ; i++){
        int at, bt;
        cin >> at >> bt;
        vp.push_back({at, bt});
    }

    // original burst store (important)
    vector<int> original_bt(n);
    for(int i=0;i<n;i++) original_bt[i] = vp[i].second;

    int current_time =0; 
    vector<int>ct(n); 
    float avg =0; 

    int number = 0; 
    vector<int>visited(n,0); 

    while(number<n){
        int mini = INT_MAX ; 
        int index = -1; 

        for(int i = 0; i<n; i++){
            int arrival = vp[i].first;

            if(arrival<=current_time && vp[i].second > 0 && vp[i].second < mini){
                mini = vp[i].second;
                index=i; 
            }
        }

        if(index==-1){
            current_time++; 
        }
        else{
            // ek unit execute
            vp[index].second--;  
            current_time++;

            // finish
            if(vp[index].second == 0){
                ct[index]=current_time;
                visited[index]=1;  
                number++; 
            }
        }
    }

    vector<int> tat(n), wt(n);

    for(int i=0; i<n ;i++){
        tat[i] = ct[i] - vp[i].first;
        wt[i] = tat[i] - original_bt[i];

        avg += wt[i];

        cout << "P" << i << " CT:" << ct[i]
             << " TAT:" << tat[i]
             << " WT:" << wt[i] << endl;
    }

    float ans= avg/n; 
    cout << "Average Waiting Time: " << ans << endl;

    return 0;
}