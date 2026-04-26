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
    int index = 0; 

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

            // fill empty
            for(int j = 0; j < f; j++){
                if(frame[j] == -1){
                    frame[j] = pages[i]; 
                    found = true;
                    break; 
                }
            }

            // FIFO replace
            if(!found){
                frame[index] = pages[i];
                index = (index + 1) % f; 
            }
        }

        // print like normal student
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