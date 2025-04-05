#include "get_next_line.h"

int main(void)
{
    int fd;
    fd = open("file.txt",O_RDONLY);

    char *line = get_next_line(fd);
    
    //line = get_next_line(fd);
    if(line)
    {
        printf("%s",line);
        free(line);
    }
    close(fd);

    return (0);
}