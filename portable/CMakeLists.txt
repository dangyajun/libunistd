# libunistd/portable/CMakeLists.txt

project(libportable)
message("--- Building library ${PROJECT_NAME} ---")

set(HEADERS
#	Astring.h
	AtomicCounter.h
	AtomicLock.h
	AtomicLock0.h
	AtomicMutex.h
	Breakpoint.h
	ipc/BsdMulticast.h
	ipc/BsdPacketServer.h
	ipc/BsdSocket.h
	ipc/BsdSocketClient.h
	ipc/BsdSocketPool.h
	ipc/BsdSocketServer.h
	ipc/BsdSocketStartup.h
	Buffer.h
	Cfile.h
	CommandLine.h
	Counter.h
	CppTypes.h
	endian.h
	Finder.h
	Folder.h
	homedir.h
	http/HtmlPage.h
	http/Http.h
	http/HttpDecoder.h
	Logger.h
	MsgBuffer.h
	Network.h
	ipc/Packet.h
	ipc/PacketBuffer.h
	ipc/PacketMarker.h
	ipc/PacketQueue.h
	ipc/PacketReader.h
	ipc/PacketSizer.h
	ipc/PacketWriter.h
	QtHelpers.h
	pump/Pump.h
	Random.h
	SoftLock.h
	StdBlob.h
	StdCopy.h
	StdDevice.h
	StdFile.h
	StdPipe.h
	strcpy.h
	SystemCall.h
	thread_semaphore.h
	time/Timecode.h
	pump/TimerPump.h
	time/Timespan.h
	time/Timestamp.h
	UnrealLogger.h
	time/VariableClock.h
	Vec3d.h
	VerboseCounter.h
	time/WallClock.h
	time/Watchdog.h
	WormFile.h
)
source_group("Header Files" FILES "${HEADERS}")

set(SOURCE
	ipc/BsdPacketServer.cpp
	ipc/BsdSocket.cpp
	ipc/BsdSocketClient.cpp
	ipc/BsdSocketPool.cpp
	ipc/BsdSocketServer.cpp
	ipc/BsdSocketStartup.cpp
	CommandLine.cpp
	http/Http.cpp
	Network.cpp
	ipc/PacketReader.cpp
	pump/Pump.cpp
	time/Timestamp.cpp
	time/VariableClock.cpp
	WormFile.cpp
)
source_group("Source Files" FILES "${SOURCE}")

include(GNUInstallDirs)
if (BUILD_SHARED_LIBS AND NOT BUILD_STATIC_LIBS AND BUILD_PORTABLE_SHARED)
	set(lib_type SHARED)
else ()
    set(lib_type STATIC)
endif ()
add_library("${PROJECT_NAME}" ${lib_type} "${HEADERS}" "${SOURCE}")

#######################################
# Export / installation configuration #
#######################################

# setup the version PROJECT_NAME
set_property(TARGET "${PROJECT_NAME}" PROPERTY VERSION "${${PROJECT_NAME}_VERSION}")
set_property(TARGET "${PROJECT_NAME}" PROPERTY SOVERSION "${${PROJECT_NAME}_VERSION_MAJOR}")

# install rules
list(APPEND installable_libs "${PROJECT_NAME}")
if (TARGET "${DEPENDANT_LIBRARY}")
	list(APPEND installable_libs "${DEPENDANT_LIBRARY}")
endif (TARGET "${DEPENDANT_LIBRARY}")
install(TARGETS ${installable_libs}
		EXPORT "${PROJECT_NAME}Targets"
		ARCHIVE DESTINATION "${CMAKE_INSTALL_LIBDIR}"
		LIBRARY DESTINATION "${CMAKE_INSTALL_LIBDIR}"
		RUNTIME DESTINATION "${CMAKE_INSTALL_BINDIR}")
install(FILES ${HEADERS}
		TYPE "INCLUDE")
