#include <dirent.h>
#include <errno.h>
#include <getopt.h>
#include <stdio.h>
#include <string.h>

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

	while((c = getopt(argc, argv, "lapFR")) != -1) {
		switch(c) {
			case 'a':
				all = 1;
				break;
			case 'p':
				show_slash = 1;
				break;
			case 'l':
				show_line = 1;
				break;
			case 'F':
				show_suffix = 1;
				show_slash = 1;
				break;
			case 'R':
				recursive = 1;
				break;
		}
	}
	char directory[256];
	if(!argv[optind])
		strcpy(directory, "./");
	else
		strcpy(directory, argv[optind]); /* Very dirty code, i'll fix it
								    * later */
	DIR *dir = opendir(directory);
	struct dirent *ent;
	if(recursive) {
		recursive_list_dirs(directory);
		return 0;
	}

	char suffix, separator;
	suffix = separator = 0;
	if(!show_line /* && STDOUT_FILENO is a tty */)
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
				/* TODO: add suffix '*' if executable */
			}

			printf("%s%c%c", ent->d_name, suffix, separator);
		}
	}
	puts("");
	closedir(dir);

	return 0;
}
