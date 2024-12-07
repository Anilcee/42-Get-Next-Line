#include "get_next_line.h"
int main(void)
{
    int fd;
    char *next_line;
    
    fd = open("texts/one_line_no_nl.txt", O_RDONLY);
    if (fd == -1)
    {
        perror("Error opening file");
        return 1;
    }
    int i =0;
    while (i<1)
    {
      next_line = get_next_line(fd); 
      char *control = "abcdefghijklmnopqrstuvwxyz";
      int j = 0;
      int len1 = ft_strlen(next_line);
      int len2 = ft_strlen(control);
      if (len1 != len2)
        printf("Error: %d != %d\n", len1, len2);
      while (next_line[j] != '\0')
      {
        if (next_line[j] != control[j])
        {
          printf("Error: %c != %c\n", next_line[j], control[j]);
        }
        j++;
      }
      printf("satir %d :%s", i+1,next_line);
      free(next_line);
      i++;
    }
    next_line = get_next_line(fd);
    if (next_line != NULL)
    {
        printf("Error: expected NULL, got %s\n", next_line);
        free(next_line);
    }
    close(fd);
    return 0;
}
