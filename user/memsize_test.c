#include "kernel/types.h"
#include "user/user.h"
int main() {
    printf("Memory size before malloc: %d\n", memsize());
    int *arr = malloc(20000);
    printf("Memory size after malloc: %d\n", memsize());
    free(arr);
    printf("Memory size after free: %d\n", memsize());
    exit(0);
}
