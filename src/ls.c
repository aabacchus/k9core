#include <stdio.h>
#include <dirent.h>
#include <getopt.h>

int
main(int argc, char *argv[])
{
     int c;
     int all, show_slash, show_line;
     all = show_slash = show_line = 0;

     while ((c = getopt(argc,argv,"lap")) != -1)
     {
          switch(c)
          {
          case 'a':
               all = 1;
               break;
          case 'p':
               show_slash = 1;
               break;
		case 'l':
			show_line = 1;
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
			if(!show_line) {
               if(ent->d_type == DT_DIR && show_slash)
                    printf("%s/ ",ent->d_name);
			else printf("%s ",ent->d_name);
			}
			else printf("%s\n",ent->d_name);
          }
     }
     puts("");
     closedir(dir);

     return 0;
}
