// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    // Your code here
    int x = 100;
    int rc = fork();

    if(rc < 0) {
        printf(stderr, "fork failed");
    } else if (rc == 0) {
        x = 20;
        printf("value of x in child: %d", x);
    } else {
        x = 33;
        printf("value of x in parent: %d", x);
    }

    return 0;
}
