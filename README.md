# libunistd POSIX/pthreads API for Windows

Anyone maintaining C/C++ code across Windows, Linux and MacOS, needs a POSIX library to be able to do single codebase builds on Windows. Libunistd supports all the common Linux POSIX calls, except for fork(). Instead of fork, use pthreads. 

Reasons to build Linux apps natively on Windows with libunistd:

1. To use the excellent static checker built into VC++ to catch buffer overflows at compile time
2. To have a single codebase, build the same C/C++ code on Linux, MacOS and (with libunistd) on Windows
3. To support Windows C/C++ programmers who may not be comfortable in a nix environment
4. Because you consider cygwin or WSL too heavy and clunky

Linux API on Windows Comparison:

| Software | License | API Compatibility | Advantages | Limitations | Installation |
|------------|------------|------------|------------|------------|------------|
| libunistd | MIT | POSIX and pthreads | Very lightweight, 99% header-only, VC++, no DLL | No fork() API call, but has pthreads instead | clone from github |
| Cygwin | LGPL | Linux subsystem on Windows | Heavy, full Linux CLI as MSYS2 on Windows | Tied to mingw compiler, no VC++, requires linking DLL | Complex installer with its own package manager |
| mingw | GPL | gcc on Windows | Port of the GNU Compiler Collection (GCC) | About the same as using gcc on Linux | Included in Cygwin |
| WSL2 | Various | Microsoft's Linux virtualization | Linux kernal with ext4 file system on Hyper-V  | VMWare or Virtual Box may be better choice | Part of Microsoft Windows |

## Installation

	% git clone https://github.com/robinrowe/libunistd

Set the include path in your VC++ project to include the directory libunistd/unistd, where you downloaded the libunistd the unistd.h file. In any Linux code you have that won't compile in VC++, first include the following at top of your header file:

	#include <unistd.h>

Doing this will include the magic to make basic Linux APIs work in Windows. Because unistd.h exists in Linux as a standard header file, making this change for Windows will not break any Linux code. Avoids #ifdef \_WIN32 ugliness in your code. Simply write C++ code as you would for Linux, and it should build in Visual Studio for Windows. 

Libunisd has much more than unistd.h. It implements many other header files that are POSIX standards, including pthreads.h. When porting your Linux program to Windows for the first time, you may have to include more POSIX headers than were necessary in your Linux code. In Linux, some standard headers include other standard header files. As a result, sometimes code that's not strictly legit may compile on Linux, even though it hasn't explicitly included all necessary header files. If you port Linux code to FreeBSD or Mac OS X, you have encountered this before. That's why the compiler may sometimes object to POSIX functions being unknown. Simple solution. Look up in the Linux man page the "unknown" function and include all the header files that the Linux man page says it requires.

## History

In 2002, the CinePaint graphics app only built on Linux. CinePaint program director Robin Rowe created the Windows port, but thought it poor design that he had \#ifdef _WIN32 sprinkled in application code. The POSIX compatibility code was spun off, separated to hide the Windows bits behind the Linux API calls. That is libunistd.

Years later, a major maker of U.S. traffic lights and the Linux safety-critical embedded software to control them, hired Rowe to do code optimization needed to support AI integration and also to create a Windows port so the engineers could in VC++. The controller ships as Linux gcc, not Windows. However, engineers more comfortable using Visual Studio. Being able to do development and initial testing on Windows is convenient and increased productivity.

A company that uses libunistd reached out with a few patches, but pretty much all of libunistd was coded by Rowe. 

## License

Open Source MIT/BSD.

## History

Libunistd was originally created to port Linux CinePaint to Windows in 2002. CinePaint is an open source HDR paint application used in making motion pictures, including the _Harry Potter_ and _Lord of the Rings_ films. Libunistd later moved from SourceForge to github and has been continuously improved, with more and more BSD and System V calls added. 

## Press About Libunistd...

https://goshrobin.com/cmaker-and-libunistd-presented-to-academy-software-foundation/

## Other Stuff in libunistd

Libunistd has some additional small libraries that are not POSIX, but can be useful to those of us developing cross-platform code. Libunistd has no dependencies on these. Use them if you wish. Qdecoder, Sqlite and xxHash have an MIT or similar license, however you should check their license terms carefully yourself as libunistd is not the owner of these other open source libraries.

1. Portable: System classes, such as StdFile that encapsulates the standard FILE* C API into a C++ class with constructors and destructors
2. Qdecoder: A small HTTP library created elsewhere  
3. Sqlite: A small SQL library created elsewhere, plus an added C++ wrapper class
4. xxHash: A small hash library created elsewhere
5. uuid: A small unique identifier library created elsewhere

## Author

	Robin.Rowe@CinePaint.org 
	Baltimore, Maryland +1 323-535-0952 
