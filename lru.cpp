#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; 
    cin >> n; 
    int f;
    cin >> f;
    vector<int> pages(n); 
    for(int i = 0; i < n; i++) cin >> pages[i];
    vector<int> frame(f, -1);
    int page_fault = 0; 
    for(int i = 0; i < n; i++){
        bool fault = true;
        // check hit
        for(int j = 0; j < f; j++){
            if(frame[j] == pages[i]){
                fault = false;
                break;
            }
        }
        if(fault){
            page_fault++;
            bool found = false;
            // empty frame fill
            for(int j = 0; j < f; j++){
                if(frame[j] == -1){
                    frame[j] = pages[i];
                    found = true;
                    break;
                }
            }

            if(!found){
                int lru_index = -1;
                int min_last_used = INT_MAX;
                for(int j = 0; j < f; j++){
                    int last_used = -1;

                    for(int k = i-1; k >= 0; k--){
                        if(pages[k] == frame[j]){
                            last_used = k;
                            break;
                        }
                    }

                    if(last_used < min_last_used){
                        min_last_used = last_used;
                        lru_index = j;
                    }
                }

                frame[lru_index] = pages[i];
            }
        }
        cout << pages[i] << " -> ";
        for(auto it : frame){
            if(it == -1) cout << "- ";
            else cout << it << " ";
        }

        if(fault) cout << "Fault";
        else cout << "Hit";

        cout << endl;
    }
    cout << "Page Faults: " << page_fault << endl;
    cout << "Page Hits: " << n - page_fault << endl;
}