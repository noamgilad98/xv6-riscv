#include "kernel/types.h"
#include "user/user.h"

int main() {
    int mask = (1 << 0) | (1 << 2); // Allow running on CPU 0 and CPU 2
    set_affinity_mask(mask);
    while (1) {
        printf("Process %d running\n", getpid());
        sleep(100);
    }
    exit(0, "Done"); // Ensure this matches the signature in user.h
}
