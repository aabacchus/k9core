#include <stdio.h>
#include <dirent.h>
#include <getopt.h>

int
main(int argc, char *argv[])
{
  int c = getopt(argc,argv,"a");
  int all;
  switch(c)
    {
    case 'a':
      all = 1;
      break;
    }
  
  DIR *dir = opendir(".");
  struct dirent *ent;

  if(dir != NULL)
    {
      while((ent = readdir(dir)) != NULL)
        {
          if(ent->d_name[0] == '.' && !all)
            continue;
          printf("%s ",ent->d_name); /* TODO: sort, and do not display . and .. */
        }
    }
  closedir(dir);
  printf("\n");

  return 0;
}
