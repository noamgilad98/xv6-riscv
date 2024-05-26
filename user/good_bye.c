#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc, char *argv[])
{
    // Define the exit message
    const char *exit_msg = "Goodbye World xv6";
    
    // Call the exit system call with the exit status and message
    exit(0, exit_msg);
    
    // This line will never be reached, but it's good practice to return a value
    return 0;
}
