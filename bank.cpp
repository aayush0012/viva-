#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m; // n = processes, m = resources

    vector<vector<int>> alloc(n, vector<int>(m));
    vector<vector<int>> maxm(n, vector<int>(m));
    vector<vector<int>> need(n, vector<int>(m));
    vector<int> avail(m);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> alloc[i][j];
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> maxm[i][j];
        }
    }
    for(int j = 0; j < m; j++){
        cin >> avail[j];
    }

    // need = max - alloc
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            need[i][j] = maxm[i][j] - alloc[i][j];
        }
    }

    vector<bool> done(n, false);
    vector<int> safeSeq;

    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            if(!done[i]){
                bool possible = true;

                for(int j = 0; j < m; j++){
                    if(need[i][j] > avail[j]){
                        possible = false;
                        break;
                    }
                }

                if(possible){
                    // release resources
                    for(int j = 0; j < m; j++){
                        avail[j] += alloc[i][j];
                    }

                    safeSeq.push_back(i);
                    done[i] = true;
                }
            }
        }
    }

    // check safe
    if(safeSeq.size() == n){
        cout << "Safe Sequence: ";
        for(auto it : safeSeq){
            cout << "P" << it << " ";
        }
    }
    else{
        cout << "Deadlock (Unsafe State)";
    }
}