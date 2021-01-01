#include <stdio.h>
#include <ctype.h>
#include <getopt.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

/* TODO: fucking make this thing read binary data
* Possible solutions: 
* fread()
* fgets()
* rewrite this entire thing using read() (not a good idea 
* because it's slow as shit)
*/

int show_lines, show_words, show_bytes;
struct wc_values data;

struct wc_values
{
	int lines;
	int bytes;
	int words;
};

int
wc(const char *filename, struct wc_values *data)
{
	FILE *file = fopen(filename,"r");
	if(file == NULL) {
		fprintf(stderr,"error opening file %s: %s\n",
			filename,
			strerror(errno));
		return -1;
	}
	char c;
	char a;
	int newlines, spaces, bytes = 0;
	newlines = spaces = bytes = 0;
	while((c = fgetc(file)) > 0) {
		a = c;
		if(!isascii(c))
			a = toascii(c);
		bytes++;
		if(a == '\n')
			newlines++;
		if(isspace(c))
			spaces++;
	}
	data->bytes = bytes;
	data->lines = newlines;
	data->words = spaces;

	fclose(file);
	return 0;
}
void
print_values(const char *filename, struct wc_values data)
{
	if(show_bytes && show_lines && show_words)
		printf("%i %i %i",
			data.lines,
			data.words,
			data.bytes);
	else	{
		if(!show_lines)
			printf("%i ",data.lines);
		if(!show_words)
			printf("%i ",data.words);
		if(!show_bytes)
			printf("%i ",data.bytes);
	}
	printf(" %s\n",filename);
}
int
main(int argc, char *argv[])
{
	int c;
	struct wc_values data;
	int return_value = 0; /* Please let me know a better name */
	show_lines = show_words = show_bytes = 1;
	/* Process arguments */
	while((c = getopt(argc,argv,"lwcm")) > 0){
		switch(c)	{
		case 'l':
			show_lines = 0;
			break;
		case 'w':
			show_words = 0;
			break;
		case 'c':
		case 'm':
			show_bytes = 0;
			break;

		}
	}

	if(optind == argc) {
		wc("/dev/stdin",&data); /* lol */
		print_values("stdin",data);
	}
	else for(int i = optind; i<argc; i++) {
			if(argv[i][0] == '-')
				return_value = wc("/dev/stdin",&data);
			else
				return_value = wc(argv[i],&data);
			if (return_value == 0)
				print_values(argv[i],data);
		}
	return 0;
}
