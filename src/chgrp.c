#include <stdio.h>
#include <unistd.h>
#include <grp.h>
#include <errno.h>
#include <string.h>

int
main(int argc, char *argv[])
{
  if(argc == 1 || argc == 2)
    {
      fprintf(stderr,"usage: chgrp group file...\n");
      return 1;
    }
  struct group *group_data = getgrnam(argv[1]);
  gid_t gid = group_data->gr_gid;
  for(int i = 2; i<argc; i++)
    {
      if(chown(argv[i],gid,getuid()) == -1)
	fprintf(stderr,"error %i = %s\n",errno,strerror(errno));
	
    }

}
