// Write a program that opens the text.txt file (with the `fopen()` library call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    // Your code here 
    FILE * fp;

    fp = fopen ("text.txt", "w+");
    fprintf(fp, "%s", "working");
    int rc = fork();
    if(rc < 0) {
        printf("Fork Error");
    } else if(rc == 0) {
        fprintf(fp, "%s", "I am writing from the child process!\n");
    } else {
        fprintf(fp, "%s", "I am writing from the Parent process!\n");
    }
    fclose(fp);
    return 0;
}


//Both the parent and child have access to the file that is created... The text added by the child process is added before the code added to the parent process!
