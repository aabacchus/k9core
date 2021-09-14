#include <errno.h>
#include <getopt.h>
#include <pwd.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
int
main(int argc, char *argv[])
{
	/* TODO: support supplying username as an arg */
	int c = getopt(argc, argv, "Ggnru");
	errno = 0;
	struct passwd *user_data = getpwnam(getlogin());
	if(user_data == NULL) {
		fprintf(stderr,
			   "id: %s: %s\n",
			   getlogin(),
			   errno == 0 ? "user not found" : strerror(errno));
		return 1;
	}
	switch(c) {
		case 'g':
		case 'u':
			printf("%u\n", user_data->pw_gid);
			break;
		case 'n':
			printf("%s\n", user_data->pw_name);
			break;
		default:
			printf("%u %s\n",
				  user_data->pw_gid,
				  user_data->pw_name); /* I know
								    * it does not work
								    * like this */
	}

	return 0;
}
