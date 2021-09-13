#include <errno.h>
#include <pwd.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

/* TODO: use strtok() to get the group */

int
main(int argc, char *argv[])
{
	if(argc == 1) {
		fprintf(stderr, "usage: chown owner file...\n");
		return 1;
	}
	const char *user = argv[1];

	errno = 0;
	struct passwd *data = getpwnam(user);
	if(data == NULL) {
		fprintf(stderr,
			   "chown: %s: %s\n",
			   user,
			   errno == 0 ? "user not found" : strerror(errno));
		return 1;
	}
	uid_t uid = data->pw_gid;
	gid_t gid = data->pw_gid; /* Change this with the strtok() thing */

	for(int i = 2; i <= argc; i++) {
		if(chown(argv[i], uid, gid) == -1) {
			fprintf(stderr, "chown: %s: %s\n", argv[i], strerror(errno));
			return 1;
		}
	}

	return 0;
}
