#include <dirent.h>
#include <errno.h>
#include <fcntl.h>
#include <getopt.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

int
recursive_list_dirs(const char *directory)
{
	DIR *dir = opendir(directory);
	if(dir == NULL) {
		fprintf(stderr, "Error opening directory: %s\n", strerror(errno));
		puts(directory);
		return -1;
	}
	struct dirent *ent;

	while((ent = readdir(dir)) != NULL) {
		if(ent->d_type == DT_DIR) {
			char path[1024];
			if(!strcmp(ent->d_name, ".") || !strcmp(ent->d_name, ".."))
				continue;
			snprintf(path, sizeof(path), "%s/%s", directory, ent->d_name);
			printf("%s/%s\n", path, ent->d_name);
			recursive_list_dirs(path);
		} else
			printf("%s\n", ent->d_name);
	}
	closedir(dir);

	return 0;
}

int
main(int argc, char *argv[])
{
	int c;
	int all, show_slash, show_line, show_suffix, recursive;
	all = show_slash = show_line = show_suffix = recursive = 0;

	while((c = getopt(argc, argv, "1FRahlp")) != -1) {
		switch(c) {
			case '1':
				show_line = 1;
				break;
			case 'F':
				show_suffix = 1;
				show_slash = 1;
				break;
			case 'R':
				recursive = 1;
				break;
			case 'a':
				all = 1;
				break;
			case 'h':
				printf("usage: ls [-1FRalp] [file...]\n");
				return 0;
			case 'l':
				show_line = 1;
				break;
			case 'p':
				show_slash = 1;
				break;
		}
	}
	for(; optind < argc; optind++) {

		char directory[256];
		if(!argv[optind])
			strcpy(directory, "./");
		else
			strcpy(directory, argv[optind]); /* Very dirty code, i'll fix it
									    * later */
		DIR *dir = opendir(directory);
		if(dir == NULL) {
			/* maybe we were given a file? */
			perror(directory);
            continue;
		}
		struct dirent *ent;
		if(recursive) {
			recursive_list_dirs(directory);
			return 0;
		}

		char suffix, separator;
		suffix = separator = 0;
		if(!show_line && isatty(STDOUT_FILENO))
			separator = ' ';
		else
			separator = '\n';

		if(dir != NULL) {
			while((ent = readdir(dir)) != NULL) {
				suffix = 0;
				if(ent->d_name[0] == '.' && !all)
					continue;
				if(show_slash && ent->d_type == DT_DIR)
					suffix = '/';
				if(show_suffix) {
					switch(ent->d_type) {
						case DT_REG:
							/* check if executable */
							struct stat st;
							if(fstatat(dirfd(dir),
									 ent->d_name,
									 &st,
									 AT_SYMLINK_NOFOLLOW) < 0) {
								perror(ent->d_name);
								return -1;
							}
							if((st.st_mode & S_IEXEC) != 0)
								suffix = '*';
							break;
						case DT_FIFO:
							suffix = '|';
							break;
						case DT_LNK:
							suffix = '@';
							break;
						case DT_SOCK:
							suffix = '=';
							break;
					}
				}
				if(suffix != 0)
					printf("%s%c%c", ent->d_name, suffix, separator);
				else
					printf("%s%c", ent->d_name, separator);
			}
		}
		puts("");
		closedir(dir);
	}

	return 0;
}
