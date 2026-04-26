#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> at(n), bt(n), rt(n);
    for(int i=0;i<n;i++) cin >> at[i];
    for(int i=0;i<n;i++){
        cin >> bt[i];
        rt[i] = bt[i];
    }

    vector<int> ct(n), tat(n), wt(n);

    int time = 0, completed = 0;

    while(completed < n){
        int idx = -1, mn = INT_MAX;

        for(int i=0;i<n;i++){
            if(at[i] <= time && rt[i] > 0 && rt[i] < mn){
                mn = rt[i];
                idx = i;
            }
        }

        if(idx == -1){
            time++;
            continue;
        }

        rt[idx]--;
        time++;

        if(rt[idx] == 0){
            ct[idx] = time;
            tat[idx] = ct[idx] - at[idx];
            wt[idx] = tat[idx] - bt[idx];
            completed++;
        }
    }

    for(int i=0;i<n;i++){
        cout << "P" << i << " CT:" << ct[i]
             << " TAT:" << tat[i]
             << " WT:" << wt[i] << endl;
    }
}