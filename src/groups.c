#include <errno.h>
#include <grp.h>
#include <pwd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int
main(int argc, char *argv[])
{
	struct passwd *pwd;
	errno = 0;
	if(argc == 2)
		pwd = getpwnam(argv[1]);
	else
		pwd = getpwuid(getuid());
	if(pwd == NULL) {
		fprintf(stderr,
			   "groups: %s: %s\n",
			   argv[1],
			   errno == 0 ? "user not found" : strerror(errno));
		return 1;
	}

	int ngroups = 10;
	uid_t *groups = malloc(ngroups);
	if(getgrouplist(pwd->pw_name, pwd->pw_gid, groups, &ngroups) == -1) {
		/* the user is a member of more than ngroups groups */
		return 1;
	}
	struct group *gr;
	for(int i = 0; i < ngroups; i++) {
		gr = getgrgid(groups[i]);
		printf("%s ", gr->gr_name);
	}
	printf("\n");
	return 0;
}
