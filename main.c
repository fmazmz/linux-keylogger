#include <stdio.h>
#include <linux/input.h>
#include <fcntl.h>
#include <unistd.h>


int main(int argc, char *argv[]) {

    if (argc != 2) 
    {
        printf("Usage: %s <event-file-path>\n", argv[0]);
        return -1;
    }
    printf("Linux Keylogger\n");
    

    int fd = open(argv[1], O_RDONLY, 0);

    struct input_event ie;

    read(fd, &ie, sizeof(ie));

    printf("Key pressed: %d\n", ie.code);

    return 0;
}
