# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.25

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

# Produce verbose output by default.
VERBOSE = 1

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /snap/cmake/1216/bin/cmake

# The command to remove a file.
RM = /snap/cmake/1216/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/semelion/CLionProjects/oop_course_spring_2023/trafnyak_s_l/rational

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/semelion/CLionProjects/oop_course_spring_2023/trafnyak_s_l/rational/build

# Include any dependencies generated for this target.
include prj.test/CMakeFiles/rational_test.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include prj.test/CMakeFiles/rational_test.dir/compiler_depend.make

# Include the progress variables for this target.
include prj.test/CMakeFiles/rational_test.dir/progress.make

# Include the compile flags for this target's objects.
include prj.test/CMakeFiles/rational_test.dir/flags.make

prj.test/CMakeFiles/rational_test.dir/rational_test.cpp.o: prj.test/CMakeFiles/rational_test.dir/flags.make
prj.test/CMakeFiles/rational_test.dir/rational_test.cpp.o: /home/semelion/CLionProjects/oop_course_spring_2023/trafnyak_s_l/rational/prj.test/rational_test.cpp
prj.test/CMakeFiles/rational_test.dir/rational_test.cpp.o: prj.test/CMakeFiles/rational_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/semelion/CLionProjects/oop_course_spring_2023/trafnyak_s_l/rational/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object prj.test/CMakeFiles/rational_test.dir/rational_test.cpp.o"
	cd /home/semelion/CLionProjects/oop_course_spring_2023/trafnyak_s_l/rational/build/prj.test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT prj.test/CMakeFiles/rational_test.dir/rational_test.cpp.o -MF CMakeFiles/rational_test.dir/rational_test.cpp.o.d -o CMakeFiles/rational_test.dir/rational_test.cpp.o -c /home/semelion/CLionProjects/oop_course_spring_2023/trafnyak_s_l/rational/prj.test/rational_test.cpp

prj.test/CMakeFiles/rational_test.dir/rational_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/rational_test.dir/rational_test.cpp.i"
	cd /home/semelion/CLionProjects/oop_course_spring_2023/trafnyak_s_l/rational/build/prj.test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/semelion/CLionProjects/oop_course_spring_2023/trafnyak_s_l/rational/prj.test/rational_test.cpp > CMakeFiles/rational_test.dir/rational_test.cpp.i

prj.test/CMakeFiles/rational_test.dir/rational_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/rational_test.dir/rational_test.cpp.s"
	cd /home/semelion/CLionProjects/oop_course_spring_2023/trafnyak_s_l/rational/build/prj.test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/semelion/CLionProjects/oop_course_spring_2023/trafnyak_s_l/rational/prj.test/rational_test.cpp -o CMakeFiles/rational_test.dir/rational_test.cpp.s

# Object files for target rational_test
rational_test_OBJECTS = \
"CMakeFiles/rational_test.dir/rational_test.cpp.o"

# External object files for target rational_test
rational_test_EXTERNAL_OBJECTS =

/home/semelion/CLionProjects/oop_course_spring_2023/trafnyak_s_l/rational/bin/rational_test: prj.test/CMakeFiles/rational_test.dir/rational_test.cpp.o
/home/semelion/CLionProjects/oop_course_spring_2023/trafnyak_s_l/rational/bin/rational_test: prj.test/CMakeFiles/rational_test.dir/build.make
/home/semelion/CLionProjects/oop_course_spring_2023/trafnyak_s_l/rational/bin/rational_test: prj.lab/rational/librational.a
/home/semelion/CLionProjects/oop_course_spring_2023/trafnyak_s_l/rational/bin/rational_test: prj.test/CMakeFiles/rational_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/semelion/CLionProjects/oop_course_spring_2023/trafnyak_s_l/rational/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable /home/semelion/CLionProjects/oop_course_spring_2023/trafnyak_s_l/rational/bin/rational_test"
	cd /home/semelion/CLionProjects/oop_course_spring_2023/trafnyak_s_l/rational/build/prj.test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/rational_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
prj.test/CMakeFiles/rational_test.dir/build: /home/semelion/CLionProjects/oop_course_spring_2023/trafnyak_s_l/rational/bin/rational_test
.PHONY : prj.test/CMakeFiles/rational_test.dir/build

prj.test/CMakeFiles/rational_test.dir/clean:
	cd /home/semelion/CLionProjects/oop_course_spring_2023/trafnyak_s_l/rational/build/prj.test && $(CMAKE_COMMAND) -P CMakeFiles/rational_test.dir/cmake_clean.cmake
.PHONY : prj.test/CMakeFiles/rational_test.dir/clean

prj.test/CMakeFiles/rational_test.dir/depend:
	cd /home/semelion/CLionProjects/oop_course_spring_2023/trafnyak_s_l/rational/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/semelion/CLionProjects/oop_course_spring_2023/trafnyak_s_l/rational /home/semelion/CLionProjects/oop_course_spring_2023/trafnyak_s_l/rational/prj.test /home/semelion/CLionProjects/oop_course_spring_2023/trafnyak_s_l/rational/build /home/semelion/CLionProjects/oop_course_spring_2023/trafnyak_s_l/rational/build/prj.test /home/semelion/CLionProjects/oop_course_spring_2023/trafnyak_s_l/rational/build/prj.test/CMakeFiles/rational_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : prj.test/CMakeFiles/rational_test.dir/depend

