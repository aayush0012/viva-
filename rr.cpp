#include<bits/stdc++.h>
using namespace std;
int main(){
    int n; 
    cin>>n;
    vector<int>at(n);
    vector<int>bt(n); 
    for(int i =0; i<n ; i++){
        cin>>at[i]; 
    } 
     for(int i =0; i<n ; i++){
        cin>>bt[i]; 
    } 
    int tq; 
    cin>>tq;
    queue<int>q;
    int inital = 0; 
    vector<pair<int,int>>vp;
    for(int i =0; i<n; i++){
        vp.push_back({at[i],bt[i]}); 
    }
    int complete=0;
    int prev=-1; 
    int current_time =0; 
    vector<int>ct(n); 
    vector<int>completed(n,0); 
    while(complete!=n){
        // ab hume jin bhi processes ka arrival time 
        for(int i =0; i<n; i++){
            if(vp[i].first<=current_time && !completed[i]){
                    q.push(i); 
                    completed[i]=1; 
            }
        }
        if(prev!=-1){
            q.push(prev); 
            prev=-1; 
        }
        if(q.empty()){
            // that means abhi koi nhi aya 
            current_time ++; 
            continue; 
        }
        else{
            int idx =q.front(); 
            q.pop(); 
            if(vp[idx].second>tq){
                vp[idx].second-=tq;
                prev=idx;
                current_time+=tq;
            }
            else{
                complete++; 
                current_time+=vp[idx].second; 
                ct[idx]=current_time ; 
            }
        }
    }

vector<int>tat(n), wt(n);
double avg_tat = 0, avg_wt = 0;


for(int i = 0; i < n; i++){
    tat[i] = ct[i] - at[i];
    wt[i] = tat[i] - bt[i];

    avg_tat += tat[i];
    avg_wt += wt[i];
}

// table print
cout << "\n\nPID\tAT\tBT\tCT\tTAT\tWT\n";

for(int i = 0; i < n; i++){
    cout << i << "\t"
         << at[i] << "\t"
         << bt[i] << "\t"
         << ct[i] << "\t"
         << tat[i] << "\t"
         << wt[i] << endl;
}

// averages
cout << "\nAverage TAT = " << avg_tat / n << endl;
cout << "Average WT = " << avg_wt / n << endl;
}