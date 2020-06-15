#include <stdio.h>
#include <dirent.h>
#include <unistd.h>

int
main(void)
{
  DIR *dir = opendir(".");
  struct dirent *ent;

  if(dir != NULL)
    {
      while((ent = readdir(dir)) != NULL)
        {
          if(ent->d_name[0] == '.')
            continue;
          printf("%s ",ent->d_name); /* TODO: sort, and do not display . and .. */
        }
    }
  closedir(dir);
  printf("\n");

  return 0;
}
