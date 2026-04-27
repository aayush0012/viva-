#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter buffer size: ";
    cin >> n;

    int buffer = 0; // current items

    int choice;

    while (true) {
        cout << "\n1. Produce\n2. Consume\n3. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        if (choice == 1) {
            if (buffer < n) {
                buffer++;
                cout << "Produced item. Total = " << buffer;
            } else {
                cout << "Buffer Full!";
            }
        }
        else if (choice == 2) {
            if (buffer > 0) {
                cout << "Consumed item " << buffer;
                buffer--;
            } else {
                cout << "Buffer Empty!";
            }
        }
        else if (choice == 3) {
            break;
        }
        else {
            cout << "Invalid choice";
        }
    }

    return 0;
}