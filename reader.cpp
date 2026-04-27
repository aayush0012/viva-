#include <iostream>
using namespace std;

int readCount = 0;
int mutex = 1;   // for readCount protection
int wrt = 1;     // writer lock

void reader(int id){
    if(mutex == 1){
        mutex = 0;
        readCount++;

        if(readCount == 1){
            wrt = 0; // writer blocked
        }

        mutex = 1;

        cout << "\nReader " << id << " is reading";

        mutex = 0;
        readCount--;

        if(readCount == 0){
            wrt = 1; // writer allowed
        }

        mutex = 1;
    }
    else{
        cout << "\nReader " << id << " is waiting";
    }
}

void writer(int id){
    if(wrt == 1){
        wrt = 0;

        cout << "\nWriter " << id << " is writing";

        wrt = 1;
    }
    else{
        cout << "\nWriter " << id << " is waiting";
    }
}

int main(){
    int choice, id;

    cout << "\n1. Reader\n2. Writer\n3. Exit";

    while(true){
        cout << "\nEnter choice: ";
        cin >> choice;

        if(choice == 1){
            cout << "Enter Reader ID: ";
            cin >> id;
            reader(id);
        }
        else if(choice == 2){
            cout << "Enter Writer ID: ";
            cin >> id;
            writer(id);
        }
        else if(choice == 3){
            break;
        }
        else{
            cout << "Invalid choice";
        }
    }

    return 0;
}