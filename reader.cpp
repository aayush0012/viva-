#include<bits/stdc++.h>
#include<thread>
#include<mutex>
using namespace std;

mutex mtx;
int readCount = 0;

void reader(int id){
    mtx.lock();
    readCount++;
    if(readCount == 1){
        cout << "Writer blocked\n";
    }
    mtx.unlock();

    cout << "Reader " << id << " is reading\n";

    mtx.lock();
    readCount--;
    if(readCount == 0){
        cout << "Writer allowed\n";
    }
    mtx.unlock();
}

void writer(int id){
    mtx.lock();
    cout << "Writer " << id << " is writing\n";
    mtx.unlock();
}

int main(){
    thread r1(reader,1), r2(reader,2), w1(writer,1);

    r1.join();
    r2.join();
    w1.join();
}