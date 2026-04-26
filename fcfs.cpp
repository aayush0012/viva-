#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> at(n), bt(n);
    for(int i=0;i<n;i++) cin >> at[i];
    for(int i=0;i<n;i++) cin >> bt[i];

    vector<int> ct(n), tat(n), wt(n);

    ct[0] = at[0] + bt[0];

    for(int i=1;i<n;i++){
        if(ct[i-1] < at[i])
            ct[i] = at[i] + bt[i];
        else
            ct[i] = ct[i-1] + bt[i];
    }

    for(int i=0;i<n;i++){
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
    }

    for(int i=0;i<n;i++){
        cout << "P" << i << " CT:" << ct[i]
             << " TAT:" << tat[i]
             << " WT:" << wt[i] << endl;
    }
}