// sys/posix_stdio.h
// Copyright 4 Feb 2026 Robin.Rowe@CinePaint.org
// License open source MIT

#ifndef posix_stdio_h
#define posix_stdio_h

#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>

#define STDIN_FILENO _fileno(stdin)
#define STDOUT_FILENO _fileno(stdout)
#define STDERR_FILENO _fileno(stderr)

inline 
int fileno(FILE *stream)
{	return _fileno(stream);
}

inline
FILE *fdopen(int fildes, const char *mode)
{	return _fdopen(fildes,mode);
}

inline
int fcntl(int handle, int mode,...)
{	(void)handle;
	(void)mode;
	STUB_0(fcntl);
}

#if _CRT_DECLARE_NONSTDC_NAMES == 1
inline
ssize_t write(int fd,const void* buf,size_t count)
{	return _write(fd,buf,count);
}

inline
ssize_t read(int fd,void* buf,size_t count)
{	return _read(fd,buf,count);
}
#else
#define write _write
#define reat _read
#endif

inline
FILE *popen(const char *command, const char *type)
{	
#ifdef _DEBUG
	printf("popen(%s,%s)\n",command,type);
#endif
	return _popen(command,type);
}

inline
int pclose(FILE *stream)
{	return stream ? _pclose(stream):-1;
}

// Define missing POSIX constants for MSVC
#ifndef S_IFLNK
#define S_IFLNK  0xA000
#endif

#ifndef S_ISLNK
#define S_ISLNK(m) (((m) & _S_IFMT) == S_IFLNK)
#endif

#ifndef S_ISREG
#define S_ISREG(m) (((m) & _S_IFMT) == _S_IFREG)
#endif

#ifndef S_ISDIR
#define S_ISDIR(m) (((m) & _S_IFMT) == _S_IFDIR)
#endif

#ifndef S_IREAD
#define S_IREAD  _S_IREAD
#endif

#ifndef S_IWRITE
#define S_IWRITE _S_IWRITE
#endif

#ifndef S_IEXEC
#define S_IEXEC  _S_IEXEC
#endif

// POSIX permission bits
#ifndef S_IRWXU
#define S_IRWXU  0000700
#define S_IRUSR  0000400
#define S_IWUSR  0000200
#define S_IXUSR  0000100
#define S_IRWXG  0000070
#define S_IRGRP  0000040
#define S_IWGRP  0000020
#define S_IXGRP  0000010
#define S_IRWXO  0000007
#define S_IROTH  0000004
#define S_IWOTH  0000002
#define S_IXOTH  0000001
#endif

//int lstat(const char *path, struct stat *statbuf);

#endif
