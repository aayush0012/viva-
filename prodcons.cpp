#include <iostream>
#include <vector>

using namespace std;
int mutex = 1;     
int full = 0;      
int empty_slots;  
int x = 0;         

void producer() {
    --mutex;        
    ++full;         
    --empty_slots; 
    x++;          
    cout << "\nProducer produces item " << x;
    ++mutex;      
}

void consumer() {
    --mutex;       
    --full;         
    ++empty_slots; 
    cout << "\nConsumer consumes item " << x;
    x--;            
    ++mutex;       
}

int main() {
    int n, choice;
    cout << "Enter buffer size: ";
    cin >> n;
    empty_slots = n; 

    cout << "\n1. PRODUCER"
         << "\n2. CONSUMER"
         << "\n3. EXIT";

    while (true) {
        cout << "\n\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                if ((mutex == 1) && (empty_slots != 0)) {
                    producer();
                } else {
                    cout << "Buffer is full! Cannot produce.";
                }
                break;

            case 2:
                if ((mutex == 1) && (full != 0)) {
                    consumer();
                } else {
                    cout << "Buffer is empty! Cannot consume.";
                }
                break;

            case 3:
                exit(0);
                break;
                
            default:
                cout << "Invalid choice!";
        }
    }

    return 0;
}