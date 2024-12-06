
#include "get_next_line.h"

int main(void)
{
    int fd;
    char *next_line;
    
    fd = open("texts/example.txt", O_RDONLY);
    if (fd == -1)
    {
        perror("Error opening file");
        return 1;
    }
    int i =0;
    while (i<12)
    {
      next_line = get_next_line(fd); 
      printf("satir %d : %s", i+1,next_line);
      free(next_line);
      i++;
    }
    close(fd);
    return 0;
}
