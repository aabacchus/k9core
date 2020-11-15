#include <stdio.h>
#include <dirent.h>
#include <getopt.h>

int
main(int argc, char *argv[])
{
     int c;
     int all, show_slash;
     all = show_slash = 0;

     while ((c = getopt(argc,argv,"ap")) != -1)
     {
          switch(c)
          {
          case 'a':
               all = 1;
               break;
          case 'p':
               show_slash = 1;
               break;
          }

     }
     DIR *dir = opendir(".");
     struct dirent *ent;

     if(dir != NULL)
     {
          while((ent = readdir(dir)) != NULL)
          {
               if(ent->d_name[0] == '.' && !all)
                    continue;
               if(ent->d_type == DT_DIR && show_slash)
                    printf("%s/ ",ent->d_name);
	       else printf("%s ",ent->d_name);
          }
     }
     puts("");
     closedir(dir);

     return 0;
}
