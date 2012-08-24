#include <iostream>
#include <stdio.h>
#include <pthread.h>
using namespace std;

int global_int = 0;
void *thread_func(void* args) {
    for (int i = 0; i < 20000; i++) {
        global_int++;
    }
    return NULL;
}

int main() {
    pthread_t thrd[8];

    for (int i = 0; i < 8; i++) {
        pthread_create(&thrd[i], NULL, thread_func, NULL);

    }

    for (int i = 0; i < 8; i++) {
        pthread_join(thrd[i], NULL);
    }

    printf("%d\n", global_int);
}



