#include<bits/stdc++.h>
#include<thread>
#include<mutex>
using namespace std;

queue<int> buffer;
mutex mtx;

void producer(){
    for(int i = 1; i <= 5; i++){
        mtx.lock();
        buffer.push(i);
        cout << "Produced: " << i << endl;
        mtx.unlock();
    }
}

void consumer(){
    for(int i = 1; i <= 5; i++){
        mtx.lock();
        if(!buffer.empty()){
            cout << "Consumed: " << buffer.front() << endl;
            buffer.pop();
        }
        mtx.unlock();
    }
}

int main(){
    thread p(producer), c(consumer);

    p.join();
    c.join();
}