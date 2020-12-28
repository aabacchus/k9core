#include <stdio.h>
#include <dirent.h>
#include <getopt.h>
#include <string.h>

int
recursive_list_dirs(const char *directory)
{
	
	DIR *dir;
	struct dirent *ent;
	if (!(dir = opendir(directory)))
		return -1;

	while((ent = readdir(dir)) != NULL) {
		if(ent->d_type == DT_DIR) {
			char path[1024];
			if (strcmp(ent->d_name, ".") == 0||strcmp(ent->d_name, "..") == 0)
				continue;
			snprintf(path, sizeof(path), "%s/%s", directory, ent->d_name);
			printf("%s/%s\n",path,ent->d_name);
			recursive_list_dirs(path);
		}
		else printf("%s\n",ent->d_name);
	}
	closedir(dir);
	
	return 0;
}

int
main(int argc, char *argv[])
{
     int c;
     int all, show_slash, show_line, recursive;
     all = show_slash = show_line = recursive = 0;

     while ((c = getopt(argc,argv,"lapR")) != -1)
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
		case 'R':
			recursive = 1;
			break;
          }

     }
	if(recursive)
	{
		recursive_list_dirs(argv[1]);
	}
	char directory[256];
	if(!argv[optind])
		strcpy(directory,".");
	else strcpy(directory,argv[optind]); /* Very dirty code, i'll fix it
							   * later */
     DIR *dir = opendir(directory);
     struct dirent *ent;
	if(recursive)
	{
		recursive_list_dirs(directory);
		return 0;
	}
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
