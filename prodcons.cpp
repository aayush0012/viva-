#include <iostream>
#include <windows.h>
using namespace std;

#define BUFFER_SIZE 5

int buffer[BUFFER_SIZE];
int in = 0, out = 0;

HANDLE mutex1;   // for mutual exclusion
HANDLE empty;    // counts empty slots
HANDLE full;     // counts filled slots

// Producer
DWORD WINAPI producer(LPVOID arg) {
    for(int i = 1; i <= 10; i++) {
        WaitForSingleObject(empty, INFINITE);
        WaitForSingleObject(mutex1, INFINITE);

        buffer[in] = i;
        cout << "Produced: " << i << endl;
        in = (in + 1) % BUFFER_SIZE;

        ReleaseMutex(mutex1);
        ReleaseSemaphore(full, 1, NULL);

        Sleep(500);
    }
    return 0;
}

// Consumer
DWORD WINAPI consumer(LPVOID arg) {
    for(int i = 1; i <= 10; i++) {
        WaitForSingleObject(full, INFINITE);
        WaitForSingleObject(mutex1, INFINITE);

        int item = buffer[out];
        cout << "Consumed: " << item << endl;
        out = (out + 1) % BUFFER_SIZE;

        ReleaseMutex(mutex1);
        ReleaseSemaphore(empty, 1, NULL);

        Sleep(800);
    }
    return 0;
}

int main() {
    mutex1 = CreateMutex(NULL, FALSE, NULL);
    empty = CreateSemaphore(NULL, BUFFER_SIZE, BUFFER_SIZE, NULL);
    full = CreateSemaphore(NULL, 0, BUFFER_SIZE, NULL);

    HANDLE p = CreateThread(NULL, 0, producer, NULL, 0, NULL);
    HANDLE c = CreateThread(NULL, 0, consumer, NULL, 0, NULL);

    WaitForSingleObject(p, INFINITE);
    WaitForSingleObject(c, INFINITE);

    CloseHandle(p);
    CloseHandle(c);
    CloseHandle(mutex1);
    CloseHandle(empty);
    CloseHandle(full);

    return 0;
}