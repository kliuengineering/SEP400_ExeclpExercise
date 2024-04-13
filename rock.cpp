// this program calls itself recursively
// and then forking a child process that prints the date
// there is no end to the running process
// may end up being a zombie process

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>

int main()
{
    int pid;
    printf("\nWe are starting a new instance of rock.cpp\n");
    
    
    // now forking additional processes
    // parent -> receives the child PID which is > 0
    // child -> receives 0
    pid = fork();
    if(pid < 0)
    {
        std::cerr << "fork() has failed...\n";
        exit(EXIT_FAILURE);
    }

    // parent
    else if( pid > 0 )
    {
        printf("parent -> process will now call + replace itself again (recursive)...\n");
        sleep(2);

        if( execlp("./rock", "rock", NULL) < 0 )
            printf("parent -> execlp() has failed...\n");
    }
    
    // child
    else if( pid == 0 )
    {
        printf("child -> process will now be replaced by /bin/date script...\n");
        sleep(1);

        if( execlp("/bin/date", "date", NULL) < 0 )
            printf("child -> execlp() has failed...\n");
    }
    
    exit(EXIT_FAILURE);
}
