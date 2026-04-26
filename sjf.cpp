#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> at(n), bt(n);
    for(int i=0;i<n;i++) cin >> at[i];
    for(int i=0;i<n;i++) cin >> bt[i];

    vector<int> ct(n), tat(n), wt(n), done(n,0);

    int time = 0, completed = 0;

    while(completed < n){
        int idx = -1, mn = INT_MAX;

        for(int i=0;i<n;i++){
            if(at[i] <= time && !done[i] && bt[i] < mn){
                mn = bt[i];
                idx = i;
            }
        }

        if(idx == -1){
            time++;
            continue;
        }

        time += bt[idx];
        ct[idx] = time;
        tat[idx] = ct[idx] - at[idx];
        wt[idx] = tat[idx] - bt[idx];

        done[idx] = 1;
        completed++;
    }

    for(int i=0;i<n;i++){
        cout << "P" << i << " CT:" << ct[i]
             << " TAT:" << tat[i]
             << " WT:" << wt[i] << endl;
    }
}