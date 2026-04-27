#include <iostream>
using namespace std;

int forks[5] = {1, 1, 1, 1, 1}; // 1 = free, 0 = busy

void philosopher(int i){
    if(forks[i] == 1 && forks[(i+1)%5] == 1){
        // pick forks
        forks[i] = 0;
        forks[(i+1)%5] = 0;

        cout << "\nPhilosopher " << i << " is eating";

        // release forks
        forks[i] = 1;
        forks[(i+1)%5] = 1;
    }
    else{
        cout << "\nPhilosopher " << i << " is waiting (forks not available)";
    }
}

int main(){
    int choice;

    cout << "\nDining Philosopher Problem";
    cout << "\n0 to 4 philosopher numbers";
    cout << "\n5 to exit";

    while(true){
        cout << "\n\nEnter philosopher number: ";
        cin >> choice;

        if(choice >= 0 && choice < 5){
            philosopher(choice);
        }
        else if(choice == 5){
            break;
        }
        else{
            cout << "Invalid input";
        }
    }

    return 0;
}