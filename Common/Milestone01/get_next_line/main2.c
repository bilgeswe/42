#include "get_next_line_bonus.h"
#include <stdio.h>
int main(void)
{
    int fd = open("file.txt",O_RDONLY);
    int fd2= open("file2.txt", O_RDONLY);

    char *line = get_next_line(fd);
    char *line2= get_next_line(fd2);

    printf("%s", line);
    printf("%s", line2);

    close(fd);
    close(fd2);

    return(0);
}