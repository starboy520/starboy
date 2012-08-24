#include <stdio.h>
#include <linux/unistd.h>
#include <sys/syscall.h>
#include <unistd.h>

pid_t gettid(void) {
    return syscall(__NR_gettid);
}

int main() {
    printf("my pid %d\n", (int)gettid());
    printf("%d\n", pthread_self());
    while (1) {
        sleep(1);
    }
    return 0;
}

