#include <stdio.h>
#include <sys/utsname.h>
#include <getopt.h>

int
main(int argc, char *argv[])
{
  int c;
  int all = 0;
  int machine = 0;
  int node_name = 0;
  int kernel_release = 0;
  int kernel_name = 0;
  int operating_system = 0;
  int nothing = 0;
  struct utsname kernel_info;

  if(argc == 1)
    nothing = 1;
  while((c = getopt(argc, argv, "amnrsv")) != -1)
    {
      switch(c)
        {
        case 'a': all = 1; break;
        case 'm': machine = 1; break;
        case 'n': node_name = 1; break;
        case 'r': kernel_release = 1; break;
        case 's': kernel_name = 1; break;
        case 'v': operating_system = 1; break;
        }
    }

  uname(&kernel_info);

  if(all)
    {
      printf("%s %s %s %s %s %s\n",
             kernel_info.machine,
             kernel_info.nodename,
             kernel_info.release,
             kernel_info.sysname,
             kernel_info.version,
             kernel_info.machine);
    }
  else
    {
      if(machine)
	printf("%s ",kernel_info.machine);
      if(node_name)
	printf("%s ",kernel_info.nodename);
      if(kernel_release)
	printf("%s ",kernel_info.release);
      if(kernel_name || nothing)
	printf("%s ",kernel_info.sysname);
      printf("\n");

    }
  return 0;
}
