# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = D:\CLion\bin\cmake\win\bin\cmake.exe

# The command to remove a file.
RM = D:\CLion\bin\cmake\win\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Twinkle\Desktop\yiwei\kickstart\local\code

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Twinkle\Desktop\yiwei\kickstart\local\code\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/2020D.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/2020D.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/2020D.dir/flags.make

CMakeFiles/2020D.dir/2020D.cpp.obj: CMakeFiles/2020D.dir/flags.make
CMakeFiles/2020D.dir/2020D.cpp.obj: ../2020D.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Twinkle\Desktop\yiwei\kickstart\local\code\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/2020D.dir/2020D.cpp.obj"
	D:\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\2020D.dir\2020D.cpp.obj -c C:\Users\Twinkle\Desktop\yiwei\kickstart\local\code\2020D.cpp

CMakeFiles/2020D.dir/2020D.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/2020D.dir/2020D.cpp.i"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Twinkle\Desktop\yiwei\kickstart\local\code\2020D.cpp > CMakeFiles\2020D.dir\2020D.cpp.i

CMakeFiles/2020D.dir/2020D.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/2020D.dir/2020D.cpp.s"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Twinkle\Desktop\yiwei\kickstart\local\code\2020D.cpp -o CMakeFiles\2020D.dir\2020D.cpp.s

# Object files for target 2020D
2020D_OBJECTS = \
"CMakeFiles/2020D.dir/2020D.cpp.obj"

# External object files for target 2020D
2020D_EXTERNAL_OBJECTS =

2020D.exe: CMakeFiles/2020D.dir/2020D.cpp.obj
2020D.exe: CMakeFiles/2020D.dir/build.make
2020D.exe: CMakeFiles/2020D.dir/linklibs.rsp
2020D.exe: CMakeFiles/2020D.dir/objects1.rsp
2020D.exe: CMakeFiles/2020D.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Twinkle\Desktop\yiwei\kickstart\local\code\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 2020D.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\2020D.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/2020D.dir/build: 2020D.exe

.PHONY : CMakeFiles/2020D.dir/build

CMakeFiles/2020D.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\2020D.dir\cmake_clean.cmake
.PHONY : CMakeFiles/2020D.dir/clean

CMakeFiles/2020D.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Twinkle\Desktop\yiwei\kickstart\local\code C:\Users\Twinkle\Desktop\yiwei\kickstart\local\code C:\Users\Twinkle\Desktop\yiwei\kickstart\local\code\cmake-build-debug C:\Users\Twinkle\Desktop\yiwei\kickstart\local\code\cmake-build-debug C:\Users\Twinkle\Desktop\yiwei\kickstart\local\code\cmake-build-debug\CMakeFiles\2020D.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/2020D.dir/depend

