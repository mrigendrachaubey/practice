/*
1. check some /dev/<node>
2. check if some module is loaded from /sys/modules
3. create a socket and ready it for listening
4.
*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <string.h>
#include <sys/un.h>

/*to include execvpe include _GNU_SOURCE*/
#define _GNU_SOURCE
#include <unistd.h>
extern int execvpe(const char *file, char *const argv[], char *const envp[]);


#define SERVER_PATH "/dev/socktest"

int main(void)
{
/*file vars*/
        int fd_dev = 0;
        FILE *pfile;

/*socket vars*/
        int listfd;
        struct sockaddr_un saddr;

/*exec command vars*/
        char *path = getenv("PATH");
        char  pathenv[strlen(path) + sizeof("PATH=")];
        sprintf(pathenv, "PATH=%s", path);
        char *envp[] = {pathenv, NULL};
        char *tests[] = {"ls", "-li", NULL}; //run ls -li command

/*return vars*/
        int c, rc;

/*unused vars*/
        int fd_modules = 0;   

/*file operations*/     
        fd_dev = open("/dev/tty", O_RDONLY);
        if(fd_dev < 0) {
                printf("not able to open /dev/tty\n");
                //exit(1);
        }
        else
                printf("opened /dev/tty\n");
        
        pfile = fopen("/proc/modules", "r");
        while ( (c = fgetc(pfile)) != EOF) {
                printf("%c",c);
        }

/*socket operations*/
        listfd = socket(AF_UNIX, SOCK_STREAM, 0);
        if (listfd < 0)
        {
                perror("socket() failed");
                //exit(1);
        }
   
        memset(&saddr, 0, sizeof(saddr));
        saddr.sun_family = AF_UNIX;
        strcpy(saddr.sun_path, SERVER_PATH);

        //struct sockaddr_un saddr = {AF_UNIX, "/dev/testsock"};
        rc = bind(listfd, (struct sockaddr *)&saddr, sizeof(saddr));
        if (rc < 0)
        {
                perror("bind() failed");
                //exit(1);
        }

        rc = listen(listfd, 10);
        if (rc < 0)
        {
                perror("listen() failed");
                //exit(1);
        }        

/*execvpe operations*/
        rc = execvpe(tests[0], tests, envp);
        if (rc < 0)
                fprintf(stderr, "failed to execute \"%s\"\n", tests[0]);
    
        return 0;
}
