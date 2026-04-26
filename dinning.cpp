#include<bits/stdc++.h>
#include<thread>
#include<mutex>
using namespace std;

mutex forks[5];

void philosopher(int i){
    while(true){
        cout << "Philosopher " << i << " is thinking\n";

        forks[i].lock();
        forks[(i+1)%5].lock();

        cout << "Philosopher " << i << " is eating\n";

        forks[i].unlock();
        forks[(i+1)%5].unlock();
    }
}

int main(){
    thread t[5];

    for(int i = 0; i < 5; i++){
        t[i] = thread(philosopher, i);
    }

    for(int i = 0; i < 5; i++){
        t[i].join();
    }
}