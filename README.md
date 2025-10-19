# libunistd

[Libunistd](https://github.com/robinrowe/libunistd/) is a lightweight [POSIX](https://en.wikipedia.org/wiki/POSIX) and [pthreads](https://en.wikipedia.org/wiki/Pthreads) library for Windows that enables ordinary Linux C/C++ source code to build using Microsoft Visual Studio pretty much as-is. If you're developing C/C++ code across Windows, Linux and MacOS, use libunistd to make a single codebase strategy work. Libunistd supports all the common Linux pthreads POSIX calls, except fork(). Instead of fork, use C/C++threads or pthreads. 

Robin Rowe created libunistd, the Windows port of the Linux system calls, while porting CinePaint to Windows .Using libunstd provides common BSD and SysV calls under Windows. Using libunstd is quite lightweight, mainly headers, and works with VC++. Unlike the alternative [Cygwin](https://en.wikipedia.org/wiki/Cygwin), that brings the Linux development evironment including gcc to Windows. Cygwin is so much that it includes its own package management system.

## Usage

Set the include path in your VC++ project to include the directory of libunistd/unistd (where the unistd.h file is). In Windows, where you encounter any Linux-based code that won't compile,  include the following at top of your header or source file:

	#include <unistd.h>

Doing this will include the magic to make basic Linux APIs work in Windows. Because unistd.h exists in Linux as a standard header file, making this change for Windows will not break Linux code. 

No \#ifdef \_WIN32 ugliness in your code. Simply write C++ code as you would for Linux, and have it build in Visual Studio for Windows.

When porting your Linux program to Windows for the first time, you may have to include more POSIX headers than were necessary in your Linux code. In Linux, some standard headers include other standard header files. As a result, sometimes Linux code will compile that's not strictly legit, that it hasn't explicitly included all necessary header files. If you port Linux code to FreeBSD or Mac OS X, you may have encountered this before, that the compiler sometimes objects to unknown POSIX functions. Simple solution. Look up in the Linux man page the "unknown" function and include all the header files that the Linux man page says it requires.

## CMake Build Automation with Cmaker

Libunistd has a CMake build system. If you have a Linux codebase that uses `make`, that is not the right stuff for maintaining a platform-independent single codebase. Use my Cmake build automation software [Cmaker](https://gitlab.com/heroic-robots/cmaker) to create a new cmake build system automatically. Cmaker creates a recursive cmake build system without reference to anything except what C/C++ files it finds in the source directory and below. Will create a cmake recursive build system from scratch, within seconds.

## License

Open Source MIT/BSD. In other words, you may do pretty much whatever you want with libunistd. Not copyleft GNU. Similar for Qdecoder, Sqlite and xxHash, however you should check their license terms yourself as libunistd is not the owner of these other open source libraries.

## History

Libunistd was originally created to port Linux CinePaint to Windows in 2002. CinePaint is an open source HDR paint application used in making motion pictures, including the _Harry Potter_ and _Lord of the Rings_ films. Libunistd later moved from SourceForge to github and has been continuously improved, with more and more BSD and System V calls added. 

Libunistd is being used for safety-critical Linux embedded systems. Not to deliver a Windows build on an embedded system, rather for testing and QA of the same embedded system codebase in Windows with access to the superb Microsoft Visual Studio debugger and its excellent static code checker that detects memory overruns. 

## Version 1.3
Tagged 19 Oct 2025

- vasprintf()
- getline()
- gethostbyname2()
- getrusage()
- getrandom()
- flock()
- memmem()
- fnmatch()
- vsyslog()
- getopt()
- timwoj merge
- Wojtulewicz merge

## Other Stuff

Libunistd has some additional small libraries that are not POSIX, but can be useful to those of us developing cross-platform code. Libunistd has no dependencies on these. Use them if you wish.

1. Portable: System classes, such as StdFile that encapsulates the standard FILE* C API into a C++ class with constructors and destructors.
2. Qdecoder: A small HTTP library created elsewhere.  
3. Sqlite: A small SQL library created elsewhere.
4. xxHash: A small hash library created elsewhere.
5. uuid: A small unique identifier library created elsewhere.

## Code Contributors

- robinrowe
- Wojtulewicz
- timwoj

## Project Director

Robin.Rowe@cinepaint.org 
Baltimore, Maryland 323-535-0952

