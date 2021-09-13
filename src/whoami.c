#include <errno.h>
#include <pwd.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int
main(void)
{
	errno = 0;
	struct passwd *user_data = getpwuid(getuid());
	if(user_data == NULL) {
		fprintf(stderr,
			   "whoami: %s\n",
			   errno == 0 ? "user not found" : strerror(errno));
		return 1;
	}
	printf("%s\n", user_data->pw_name);
	return 0;
}
