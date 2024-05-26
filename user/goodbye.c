#include "kernel/types.h"
#include "user/user.h"

int main(int argc, char *argv[])
{
    // Call the exit system call with the exit status and message
    exit(0, "Goodbye World xv6");
    
    // This line will never be reached, but it's good practice to return a value
    return 0;
}
