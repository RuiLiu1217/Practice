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
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\liuru\OneDrive\Documents\GitHub\Practice

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\liuru\OneDrive\Documents\GitHub\Practice\build

# Include any dependencies generated for this target.
include test/CMakeFiles/PracticeTest.dir/depend.make

# Include the progress variables for this target.
include test/CMakeFiles/PracticeTest.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/PracticeTest.dir/flags.make

test/CMakeFiles/PracticeTest.dir/LintCodeTest.cpp.obj: test/CMakeFiles/PracticeTest.dir/flags.make
test/CMakeFiles/PracticeTest.dir/LintCodeTest.cpp.obj: test/CMakeFiles/PracticeTest.dir/includes_CXX.rsp
test/CMakeFiles/PracticeTest.dir/LintCodeTest.cpp.obj: ../test/LintCodeTest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\liuru\OneDrive\Documents\GitHub\Practice\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/CMakeFiles/PracticeTest.dir/LintCodeTest.cpp.obj"
	cd /d C:\Users\liuru\OneDrive\Documents\GitHub\Practice\build\test && C:\mingw64\mingw64\bin\x86_64-w64-mingw32-g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\PracticeTest.dir\LintCodeTest.cpp.obj -c C:\Users\liuru\OneDrive\Documents\GitHub\Practice\test\LintCodeTest.cpp

test/CMakeFiles/PracticeTest.dir/LintCodeTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PracticeTest.dir/LintCodeTest.cpp.i"
	cd /d C:\Users\liuru\OneDrive\Documents\GitHub\Practice\build\test && C:\mingw64\mingw64\bin\x86_64-w64-mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\liuru\OneDrive\Documents\GitHub\Practice\test\LintCodeTest.cpp > CMakeFiles\PracticeTest.dir\LintCodeTest.cpp.i

test/CMakeFiles/PracticeTest.dir/LintCodeTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PracticeTest.dir/LintCodeTest.cpp.s"
	cd /d C:\Users\liuru\OneDrive\Documents\GitHub\Practice\build\test && C:\mingw64\mingw64\bin\x86_64-w64-mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\liuru\OneDrive\Documents\GitHub\Practice\test\LintCodeTest.cpp -o CMakeFiles\PracticeTest.dir\LintCodeTest.cpp.s

# Object files for target PracticeTest
PracticeTest_OBJECTS = \
"CMakeFiles/PracticeTest.dir/LintCodeTest.cpp.obj"

# External object files for target PracticeTest
PracticeTest_EXTERNAL_OBJECTS =

test/PracticeTest.exe: test/CMakeFiles/PracticeTest.dir/LintCodeTest.cpp.obj
test/PracticeTest.exe: test/CMakeFiles/PracticeTest.dir/build.make
test/PracticeTest.exe: lib/libgtest_maind.a
test/PracticeTest.exe: libPractice.a
test/PracticeTest.exe: lib/libgtestd.a
test/PracticeTest.exe: test/CMakeFiles/PracticeTest.dir/linklibs.rsp
test/PracticeTest.exe: test/CMakeFiles/PracticeTest.dir/objects1.rsp
test/PracticeTest.exe: test/CMakeFiles/PracticeTest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\liuru\OneDrive\Documents\GitHub\Practice\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable PracticeTest.exe"
	cd /d C:\Users\liuru\OneDrive\Documents\GitHub\Practice\build\test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\PracticeTest.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/CMakeFiles/PracticeTest.dir/build: test/PracticeTest.exe

.PHONY : test/CMakeFiles/PracticeTest.dir/build

test/CMakeFiles/PracticeTest.dir/clean:
	cd /d C:\Users\liuru\OneDrive\Documents\GitHub\Practice\build\test && $(CMAKE_COMMAND) -P CMakeFiles\PracticeTest.dir\cmake_clean.cmake
.PHONY : test/CMakeFiles/PracticeTest.dir/clean

test/CMakeFiles/PracticeTest.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\liuru\OneDrive\Documents\GitHub\Practice C:\Users\liuru\OneDrive\Documents\GitHub\Practice\test C:\Users\liuru\OneDrive\Documents\GitHub\Practice\build C:\Users\liuru\OneDrive\Documents\GitHub\Practice\build\test C:\Users\liuru\OneDrive\Documents\GitHub\Practice\build\test\CMakeFiles\PracticeTest.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : test/CMakeFiles/PracticeTest.dir/depend
