# k9core coding style

Pretty similar to the GNU code standards.

## Functions definition

Functions have to begin with return type, breakline, and functionname,
also brackets will be in a new line:

~~~c
int
main(int argc, char *argv[])
~~~

## Line length

A line of code must no exced 75 characters. If it exceeds, do a
breakline:

~~~c

int 
a_very_long_function(int a_very_long_parameter, int
                     another_very_long_parameter);
~~~

## Statements

Do not do declarations inside an if block. Declarations inside while
loop are OK.

~~~c
int fd;
if((fd = open("file", O_CREAT)) == -1) /* Don't do this */
{
 /* Whatever */
}

/* Do this instead */

int fd = open("file", O_CREAT);
if(fd == -1) 
{
	/* Whatever */
}
~~~

## Do not include .c files

Just don't.

## Comments

Do not use C++ style comments. Comments at beggining of the line
should explain what the line does. not how it does. Comments at the
end of the line must be explanations of something:

~~~c
// This is a wrong comment

/* This is a correct comment */

/* Makes a syscall giving a file descriptor... */

fd = open("whatever",O_RDONLY); /* WRONG */

/* Creates a file descriptor on the file whatever */

fd = open("whatever",O_RDONLY); /* Yes */

/* 420 is 644 in decimal */ <- WRONG
chmod("whatever",420)

chmod("whatever",420) /* 420 is 644 in decimal

~~~

## For commiters

Commiters may or may not be anonymous. If you want to be
anonymous. Set whatever you want to git name and git email.

If you don't want to be anonymous, you should sign your commits using
gpg. See
[this]https://docs.gitlab.com/ee/user/project/repository/gpg_signed_commits/()

