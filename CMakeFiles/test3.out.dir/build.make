# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/misha/projects/progbase2/progbase2/tasks/dkr1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/misha/projects/progbase2/progbase2/tasks/dkr1/build

# Include any dependencies generated for this target.
include CMakeFiles/test3.out.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/test3.out.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/test3.out.dir/flags.make

CMakeFiles/test3.out.dir/tests/test3.c.o: CMakeFiles/test3.out.dir/flags.make
CMakeFiles/test3.out.dir/tests/test3.c.o: ../tests/test3.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/misha/projects/progbase2/progbase2/tasks/dkr1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/test3.out.dir/tests/test3.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/test3.out.dir/tests/test3.c.o   -c /home/misha/projects/progbase2/progbase2/tasks/dkr1/tests/test3.c

CMakeFiles/test3.out.dir/tests/test3.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test3.out.dir/tests/test3.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/misha/projects/progbase2/progbase2/tasks/dkr1/tests/test3.c > CMakeFiles/test3.out.dir/tests/test3.c.i

CMakeFiles/test3.out.dir/tests/test3.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test3.out.dir/tests/test3.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/misha/projects/progbase2/progbase2/tasks/dkr1/tests/test3.c -o CMakeFiles/test3.out.dir/tests/test3.c.s

CMakeFiles/test3.out.dir/tests/test3.c.o.requires:

.PHONY : CMakeFiles/test3.out.dir/tests/test3.c.o.requires

CMakeFiles/test3.out.dir/tests/test3.c.o.provides: CMakeFiles/test3.out.dir/tests/test3.c.o.requires
	$(MAKE) -f CMakeFiles/test3.out.dir/build.make CMakeFiles/test3.out.dir/tests/test3.c.o.provides.build
.PHONY : CMakeFiles/test3.out.dir/tests/test3.c.o.provides

CMakeFiles/test3.out.dir/tests/test3.c.o.provides.build: CMakeFiles/test3.out.dir/tests/test3.c.o


CMakeFiles/test3.out.dir/src/dict.c.o: CMakeFiles/test3.out.dir/flags.make
CMakeFiles/test3.out.dir/src/dict.c.o: ../src/dict.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/misha/projects/progbase2/progbase2/tasks/dkr1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/test3.out.dir/src/dict.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/test3.out.dir/src/dict.c.o   -c /home/misha/projects/progbase2/progbase2/tasks/dkr1/src/dict.c

CMakeFiles/test3.out.dir/src/dict.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test3.out.dir/src/dict.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/misha/projects/progbase2/progbase2/tasks/dkr1/src/dict.c > CMakeFiles/test3.out.dir/src/dict.c.i

CMakeFiles/test3.out.dir/src/dict.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test3.out.dir/src/dict.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/misha/projects/progbase2/progbase2/tasks/dkr1/src/dict.c -o CMakeFiles/test3.out.dir/src/dict.c.s

CMakeFiles/test3.out.dir/src/dict.c.o.requires:

.PHONY : CMakeFiles/test3.out.dir/src/dict.c.o.requires

CMakeFiles/test3.out.dir/src/dict.c.o.provides: CMakeFiles/test3.out.dir/src/dict.c.o.requires
	$(MAKE) -f CMakeFiles/test3.out.dir/build.make CMakeFiles/test3.out.dir/src/dict.c.o.provides.build
.PHONY : CMakeFiles/test3.out.dir/src/dict.c.o.provides

CMakeFiles/test3.out.dir/src/dict.c.o.provides.build: CMakeFiles/test3.out.dir/src/dict.c.o


CMakeFiles/test3.out.dir/src/_list.c.o: CMakeFiles/test3.out.dir/flags.make
CMakeFiles/test3.out.dir/src/_list.c.o: ../src/_list.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/misha/projects/progbase2/progbase2/tasks/dkr1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/test3.out.dir/src/_list.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/test3.out.dir/src/_list.c.o   -c /home/misha/projects/progbase2/progbase2/tasks/dkr1/src/_list.c

CMakeFiles/test3.out.dir/src/_list.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test3.out.dir/src/_list.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/misha/projects/progbase2/progbase2/tasks/dkr1/src/_list.c > CMakeFiles/test3.out.dir/src/_list.c.i

CMakeFiles/test3.out.dir/src/_list.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test3.out.dir/src/_list.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/misha/projects/progbase2/progbase2/tasks/dkr1/src/_list.c -o CMakeFiles/test3.out.dir/src/_list.c.s

CMakeFiles/test3.out.dir/src/_list.c.o.requires:

.PHONY : CMakeFiles/test3.out.dir/src/_list.c.o.requires

CMakeFiles/test3.out.dir/src/_list.c.o.provides: CMakeFiles/test3.out.dir/src/_list.c.o.requires
	$(MAKE) -f CMakeFiles/test3.out.dir/build.make CMakeFiles/test3.out.dir/src/_list.c.o.provides.build
.PHONY : CMakeFiles/test3.out.dir/src/_list.c.o.provides

CMakeFiles/test3.out.dir/src/_list.c.o.provides.build: CMakeFiles/test3.out.dir/src/_list.c.o


CMakeFiles/test3.out.dir/src/parser.c.o: CMakeFiles/test3.out.dir/flags.make
CMakeFiles/test3.out.dir/src/parser.c.o: ../src/parser.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/misha/projects/progbase2/progbase2/tasks/dkr1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/test3.out.dir/src/parser.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/test3.out.dir/src/parser.c.o   -c /home/misha/projects/progbase2/progbase2/tasks/dkr1/src/parser.c

CMakeFiles/test3.out.dir/src/parser.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test3.out.dir/src/parser.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/misha/projects/progbase2/progbase2/tasks/dkr1/src/parser.c > CMakeFiles/test3.out.dir/src/parser.c.i

CMakeFiles/test3.out.dir/src/parser.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test3.out.dir/src/parser.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/misha/projects/progbase2/progbase2/tasks/dkr1/src/parser.c -o CMakeFiles/test3.out.dir/src/parser.c.s

CMakeFiles/test3.out.dir/src/parser.c.o.requires:

.PHONY : CMakeFiles/test3.out.dir/src/parser.c.o.requires

CMakeFiles/test3.out.dir/src/parser.c.o.provides: CMakeFiles/test3.out.dir/src/parser.c.o.requires
	$(MAKE) -f CMakeFiles/test3.out.dir/build.make CMakeFiles/test3.out.dir/src/parser.c.o.provides.build
.PHONY : CMakeFiles/test3.out.dir/src/parser.c.o.provides

CMakeFiles/test3.out.dir/src/parser.c.o.provides.build: CMakeFiles/test3.out.dir/src/parser.c.o


CMakeFiles/test3.out.dir/src/preetyprint.c.o: CMakeFiles/test3.out.dir/flags.make
CMakeFiles/test3.out.dir/src/preetyprint.c.o: ../src/preetyprint.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/misha/projects/progbase2/progbase2/tasks/dkr1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/test3.out.dir/src/preetyprint.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/test3.out.dir/src/preetyprint.c.o   -c /home/misha/projects/progbase2/progbase2/tasks/dkr1/src/preetyprint.c

CMakeFiles/test3.out.dir/src/preetyprint.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test3.out.dir/src/preetyprint.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/misha/projects/progbase2/progbase2/tasks/dkr1/src/preetyprint.c > CMakeFiles/test3.out.dir/src/preetyprint.c.i

CMakeFiles/test3.out.dir/src/preetyprint.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test3.out.dir/src/preetyprint.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/misha/projects/progbase2/progbase2/tasks/dkr1/src/preetyprint.c -o CMakeFiles/test3.out.dir/src/preetyprint.c.s

CMakeFiles/test3.out.dir/src/preetyprint.c.o.requires:

.PHONY : CMakeFiles/test3.out.dir/src/preetyprint.c.o.requires

CMakeFiles/test3.out.dir/src/preetyprint.c.o.provides: CMakeFiles/test3.out.dir/src/preetyprint.c.o.requires
	$(MAKE) -f CMakeFiles/test3.out.dir/build.make CMakeFiles/test3.out.dir/src/preetyprint.c.o.provides.build
.PHONY : CMakeFiles/test3.out.dir/src/preetyprint.c.o.provides

CMakeFiles/test3.out.dir/src/preetyprint.c.o.provides.build: CMakeFiles/test3.out.dir/src/preetyprint.c.o


CMakeFiles/test3.out.dir/src/lexer.c.o: CMakeFiles/test3.out.dir/flags.make
CMakeFiles/test3.out.dir/src/lexer.c.o: ../src/lexer.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/misha/projects/progbase2/progbase2/tasks/dkr1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/test3.out.dir/src/lexer.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/test3.out.dir/src/lexer.c.o   -c /home/misha/projects/progbase2/progbase2/tasks/dkr1/src/lexer.c

CMakeFiles/test3.out.dir/src/lexer.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test3.out.dir/src/lexer.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/misha/projects/progbase2/progbase2/tasks/dkr1/src/lexer.c > CMakeFiles/test3.out.dir/src/lexer.c.i

CMakeFiles/test3.out.dir/src/lexer.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test3.out.dir/src/lexer.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/misha/projects/progbase2/progbase2/tasks/dkr1/src/lexer.c -o CMakeFiles/test3.out.dir/src/lexer.c.s

CMakeFiles/test3.out.dir/src/lexer.c.o.requires:

.PHONY : CMakeFiles/test3.out.dir/src/lexer.c.o.requires

CMakeFiles/test3.out.dir/src/lexer.c.o.provides: CMakeFiles/test3.out.dir/src/lexer.c.o.requires
	$(MAKE) -f CMakeFiles/test3.out.dir/build.make CMakeFiles/test3.out.dir/src/lexer.c.o.provides.build
.PHONY : CMakeFiles/test3.out.dir/src/lexer.c.o.provides

CMakeFiles/test3.out.dir/src/lexer.c.o.provides.build: CMakeFiles/test3.out.dir/src/lexer.c.o


CMakeFiles/test3.out.dir/src/tree.c.o: CMakeFiles/test3.out.dir/flags.make
CMakeFiles/test3.out.dir/src/tree.c.o: ../src/tree.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/misha/projects/progbase2/progbase2/tasks/dkr1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/test3.out.dir/src/tree.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/test3.out.dir/src/tree.c.o   -c /home/misha/projects/progbase2/progbase2/tasks/dkr1/src/tree.c

CMakeFiles/test3.out.dir/src/tree.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test3.out.dir/src/tree.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/misha/projects/progbase2/progbase2/tasks/dkr1/src/tree.c > CMakeFiles/test3.out.dir/src/tree.c.i

CMakeFiles/test3.out.dir/src/tree.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test3.out.dir/src/tree.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/misha/projects/progbase2/progbase2/tasks/dkr1/src/tree.c -o CMakeFiles/test3.out.dir/src/tree.c.s

CMakeFiles/test3.out.dir/src/tree.c.o.requires:

.PHONY : CMakeFiles/test3.out.dir/src/tree.c.o.requires

CMakeFiles/test3.out.dir/src/tree.c.o.provides: CMakeFiles/test3.out.dir/src/tree.c.o.requires
	$(MAKE) -f CMakeFiles/test3.out.dir/build.make CMakeFiles/test3.out.dir/src/tree.c.o.provides.build
.PHONY : CMakeFiles/test3.out.dir/src/tree.c.o.provides

CMakeFiles/test3.out.dir/src/tree.c.o.provides.build: CMakeFiles/test3.out.dir/src/tree.c.o


CMakeFiles/test3.out.dir/src/bintree.c.o: CMakeFiles/test3.out.dir/flags.make
CMakeFiles/test3.out.dir/src/bintree.c.o: ../src/bintree.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/misha/projects/progbase2/progbase2/tasks/dkr1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object CMakeFiles/test3.out.dir/src/bintree.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/test3.out.dir/src/bintree.c.o   -c /home/misha/projects/progbase2/progbase2/tasks/dkr1/src/bintree.c

CMakeFiles/test3.out.dir/src/bintree.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test3.out.dir/src/bintree.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/misha/projects/progbase2/progbase2/tasks/dkr1/src/bintree.c > CMakeFiles/test3.out.dir/src/bintree.c.i

CMakeFiles/test3.out.dir/src/bintree.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test3.out.dir/src/bintree.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/misha/projects/progbase2/progbase2/tasks/dkr1/src/bintree.c -o CMakeFiles/test3.out.dir/src/bintree.c.s

CMakeFiles/test3.out.dir/src/bintree.c.o.requires:

.PHONY : CMakeFiles/test3.out.dir/src/bintree.c.o.requires

CMakeFiles/test3.out.dir/src/bintree.c.o.provides: CMakeFiles/test3.out.dir/src/bintree.c.o.requires
	$(MAKE) -f CMakeFiles/test3.out.dir/build.make CMakeFiles/test3.out.dir/src/bintree.c.o.provides.build
.PHONY : CMakeFiles/test3.out.dir/src/bintree.c.o.provides

CMakeFiles/test3.out.dir/src/bintree.c.o.provides.build: CMakeFiles/test3.out.dir/src/bintree.c.o


CMakeFiles/test3.out.dir/src/stringbuffer.c.o: CMakeFiles/test3.out.dir/flags.make
CMakeFiles/test3.out.dir/src/stringbuffer.c.o: ../src/stringbuffer.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/misha/projects/progbase2/progbase2/tasks/dkr1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building C object CMakeFiles/test3.out.dir/src/stringbuffer.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/test3.out.dir/src/stringbuffer.c.o   -c /home/misha/projects/progbase2/progbase2/tasks/dkr1/src/stringbuffer.c

CMakeFiles/test3.out.dir/src/stringbuffer.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test3.out.dir/src/stringbuffer.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/misha/projects/progbase2/progbase2/tasks/dkr1/src/stringbuffer.c > CMakeFiles/test3.out.dir/src/stringbuffer.c.i

CMakeFiles/test3.out.dir/src/stringbuffer.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test3.out.dir/src/stringbuffer.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/misha/projects/progbase2/progbase2/tasks/dkr1/src/stringbuffer.c -o CMakeFiles/test3.out.dir/src/stringbuffer.c.s

CMakeFiles/test3.out.dir/src/stringbuffer.c.o.requires:

.PHONY : CMakeFiles/test3.out.dir/src/stringbuffer.c.o.requires

CMakeFiles/test3.out.dir/src/stringbuffer.c.o.provides: CMakeFiles/test3.out.dir/src/stringbuffer.c.o.requires
	$(MAKE) -f CMakeFiles/test3.out.dir/build.make CMakeFiles/test3.out.dir/src/stringbuffer.c.o.provides.build
.PHONY : CMakeFiles/test3.out.dir/src/stringbuffer.c.o.provides

CMakeFiles/test3.out.dir/src/stringbuffer.c.o.provides.build: CMakeFiles/test3.out.dir/src/stringbuffer.c.o


CMakeFiles/test3.out.dir/src/stack.c.o: CMakeFiles/test3.out.dir/flags.make
CMakeFiles/test3.out.dir/src/stack.c.o: ../src/stack.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/misha/projects/progbase2/progbase2/tasks/dkr1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building C object CMakeFiles/test3.out.dir/src/stack.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/test3.out.dir/src/stack.c.o   -c /home/misha/projects/progbase2/progbase2/tasks/dkr1/src/stack.c

CMakeFiles/test3.out.dir/src/stack.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test3.out.dir/src/stack.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/misha/projects/progbase2/progbase2/tasks/dkr1/src/stack.c > CMakeFiles/test3.out.dir/src/stack.c.i

CMakeFiles/test3.out.dir/src/stack.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test3.out.dir/src/stack.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/misha/projects/progbase2/progbase2/tasks/dkr1/src/stack.c -o CMakeFiles/test3.out.dir/src/stack.c.s

CMakeFiles/test3.out.dir/src/stack.c.o.requires:

.PHONY : CMakeFiles/test3.out.dir/src/stack.c.o.requires

CMakeFiles/test3.out.dir/src/stack.c.o.provides: CMakeFiles/test3.out.dir/src/stack.c.o.requires
	$(MAKE) -f CMakeFiles/test3.out.dir/build.make CMakeFiles/test3.out.dir/src/stack.c.o.provides.build
.PHONY : CMakeFiles/test3.out.dir/src/stack.c.o.provides

CMakeFiles/test3.out.dir/src/stack.c.o.provides.build: CMakeFiles/test3.out.dir/src/stack.c.o


CMakeFiles/test3.out.dir/src/interpreter.c.o: CMakeFiles/test3.out.dir/flags.make
CMakeFiles/test3.out.dir/src/interpreter.c.o: ../src/interpreter.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/misha/projects/progbase2/progbase2/tasks/dkr1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building C object CMakeFiles/test3.out.dir/src/interpreter.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/test3.out.dir/src/interpreter.c.o   -c /home/misha/projects/progbase2/progbase2/tasks/dkr1/src/interpreter.c

CMakeFiles/test3.out.dir/src/interpreter.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test3.out.dir/src/interpreter.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/misha/projects/progbase2/progbase2/tasks/dkr1/src/interpreter.c > CMakeFiles/test3.out.dir/src/interpreter.c.i

CMakeFiles/test3.out.dir/src/interpreter.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test3.out.dir/src/interpreter.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/misha/projects/progbase2/progbase2/tasks/dkr1/src/interpreter.c -o CMakeFiles/test3.out.dir/src/interpreter.c.s

CMakeFiles/test3.out.dir/src/interpreter.c.o.requires:

.PHONY : CMakeFiles/test3.out.dir/src/interpreter.c.o.requires

CMakeFiles/test3.out.dir/src/interpreter.c.o.provides: CMakeFiles/test3.out.dir/src/interpreter.c.o.requires
	$(MAKE) -f CMakeFiles/test3.out.dir/build.make CMakeFiles/test3.out.dir/src/interpreter.c.o.provides.build
.PHONY : CMakeFiles/test3.out.dir/src/interpreter.c.o.provides

CMakeFiles/test3.out.dir/src/interpreter.c.o.provides.build: CMakeFiles/test3.out.dir/src/interpreter.c.o


CMakeFiles/test3.out.dir/src/std_functions.c.o: CMakeFiles/test3.out.dir/flags.make
CMakeFiles/test3.out.dir/src/std_functions.c.o: ../src/std_functions.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/misha/projects/progbase2/progbase2/tasks/dkr1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building C object CMakeFiles/test3.out.dir/src/std_functions.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/test3.out.dir/src/std_functions.c.o   -c /home/misha/projects/progbase2/progbase2/tasks/dkr1/src/std_functions.c

CMakeFiles/test3.out.dir/src/std_functions.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test3.out.dir/src/std_functions.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/misha/projects/progbase2/progbase2/tasks/dkr1/src/std_functions.c > CMakeFiles/test3.out.dir/src/std_functions.c.i

CMakeFiles/test3.out.dir/src/std_functions.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test3.out.dir/src/std_functions.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/misha/projects/progbase2/progbase2/tasks/dkr1/src/std_functions.c -o CMakeFiles/test3.out.dir/src/std_functions.c.s

CMakeFiles/test3.out.dir/src/std_functions.c.o.requires:

.PHONY : CMakeFiles/test3.out.dir/src/std_functions.c.o.requires

CMakeFiles/test3.out.dir/src/std_functions.c.o.provides: CMakeFiles/test3.out.dir/src/std_functions.c.o.requires
	$(MAKE) -f CMakeFiles/test3.out.dir/build.make CMakeFiles/test3.out.dir/src/std_functions.c.o.provides.build
.PHONY : CMakeFiles/test3.out.dir/src/std_functions.c.o.provides

CMakeFiles/test3.out.dir/src/std_functions.c.o.provides.build: CMakeFiles/test3.out.dir/src/std_functions.c.o


CMakeFiles/test3.out.dir/src/ast.c.o: CMakeFiles/test3.out.dir/flags.make
CMakeFiles/test3.out.dir/src/ast.c.o: ../src/ast.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/misha/projects/progbase2/progbase2/tasks/dkr1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building C object CMakeFiles/test3.out.dir/src/ast.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/test3.out.dir/src/ast.c.o   -c /home/misha/projects/progbase2/progbase2/tasks/dkr1/src/ast.c

CMakeFiles/test3.out.dir/src/ast.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test3.out.dir/src/ast.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/misha/projects/progbase2/progbase2/tasks/dkr1/src/ast.c > CMakeFiles/test3.out.dir/src/ast.c.i

CMakeFiles/test3.out.dir/src/ast.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test3.out.dir/src/ast.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/misha/projects/progbase2/progbase2/tasks/dkr1/src/ast.c -o CMakeFiles/test3.out.dir/src/ast.c.s

CMakeFiles/test3.out.dir/src/ast.c.o.requires:

.PHONY : CMakeFiles/test3.out.dir/src/ast.c.o.requires

CMakeFiles/test3.out.dir/src/ast.c.o.provides: CMakeFiles/test3.out.dir/src/ast.c.o.requires
	$(MAKE) -f CMakeFiles/test3.out.dir/build.make CMakeFiles/test3.out.dir/src/ast.c.o.provides.build
.PHONY : CMakeFiles/test3.out.dir/src/ast.c.o.provides

CMakeFiles/test3.out.dir/src/ast.c.o.provides.build: CMakeFiles/test3.out.dir/src/ast.c.o


# Object files for target test3.out
test3_out_OBJECTS = \
"CMakeFiles/test3.out.dir/tests/test3.c.o" \
"CMakeFiles/test3.out.dir/src/dict.c.o" \
"CMakeFiles/test3.out.dir/src/_list.c.o" \
"CMakeFiles/test3.out.dir/src/parser.c.o" \
"CMakeFiles/test3.out.dir/src/preetyprint.c.o" \
"CMakeFiles/test3.out.dir/src/lexer.c.o" \
"CMakeFiles/test3.out.dir/src/tree.c.o" \
"CMakeFiles/test3.out.dir/src/bintree.c.o" \
"CMakeFiles/test3.out.dir/src/stringbuffer.c.o" \
"CMakeFiles/test3.out.dir/src/stack.c.o" \
"CMakeFiles/test3.out.dir/src/interpreter.c.o" \
"CMakeFiles/test3.out.dir/src/std_functions.c.o" \
"CMakeFiles/test3.out.dir/src/ast.c.o"

# External object files for target test3.out
test3_out_EXTERNAL_OBJECTS =

test3.out: CMakeFiles/test3.out.dir/tests/test3.c.o
test3.out: CMakeFiles/test3.out.dir/src/dict.c.o
test3.out: CMakeFiles/test3.out.dir/src/_list.c.o
test3.out: CMakeFiles/test3.out.dir/src/parser.c.o
test3.out: CMakeFiles/test3.out.dir/src/preetyprint.c.o
test3.out: CMakeFiles/test3.out.dir/src/lexer.c.o
test3.out: CMakeFiles/test3.out.dir/src/tree.c.o
test3.out: CMakeFiles/test3.out.dir/src/bintree.c.o
test3.out: CMakeFiles/test3.out.dir/src/stringbuffer.c.o
test3.out: CMakeFiles/test3.out.dir/src/stack.c.o
test3.out: CMakeFiles/test3.out.dir/src/interpreter.c.o
test3.out: CMakeFiles/test3.out.dir/src/std_functions.c.o
test3.out: CMakeFiles/test3.out.dir/src/ast.c.o
test3.out: CMakeFiles/test3.out.dir/build.make
test3.out: CMakeFiles/test3.out.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/misha/projects/progbase2/progbase2/tasks/dkr1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Linking C executable test3.out"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test3.out.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/test3.out.dir/build: test3.out

.PHONY : CMakeFiles/test3.out.dir/build

CMakeFiles/test3.out.dir/requires: CMakeFiles/test3.out.dir/tests/test3.c.o.requires
CMakeFiles/test3.out.dir/requires: CMakeFiles/test3.out.dir/src/dict.c.o.requires
CMakeFiles/test3.out.dir/requires: CMakeFiles/test3.out.dir/src/_list.c.o.requires
CMakeFiles/test3.out.dir/requires: CMakeFiles/test3.out.dir/src/parser.c.o.requires
CMakeFiles/test3.out.dir/requires: CMakeFiles/test3.out.dir/src/preetyprint.c.o.requires
CMakeFiles/test3.out.dir/requires: CMakeFiles/test3.out.dir/src/lexer.c.o.requires
CMakeFiles/test3.out.dir/requires: CMakeFiles/test3.out.dir/src/tree.c.o.requires
CMakeFiles/test3.out.dir/requires: CMakeFiles/test3.out.dir/src/bintree.c.o.requires
CMakeFiles/test3.out.dir/requires: CMakeFiles/test3.out.dir/src/stringbuffer.c.o.requires
CMakeFiles/test3.out.dir/requires: CMakeFiles/test3.out.dir/src/stack.c.o.requires
CMakeFiles/test3.out.dir/requires: CMakeFiles/test3.out.dir/src/interpreter.c.o.requires
CMakeFiles/test3.out.dir/requires: CMakeFiles/test3.out.dir/src/std_functions.c.o.requires
CMakeFiles/test3.out.dir/requires: CMakeFiles/test3.out.dir/src/ast.c.o.requires

.PHONY : CMakeFiles/test3.out.dir/requires

CMakeFiles/test3.out.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/test3.out.dir/cmake_clean.cmake
.PHONY : CMakeFiles/test3.out.dir/clean

CMakeFiles/test3.out.dir/depend:
	cd /home/misha/projects/progbase2/progbase2/tasks/dkr1/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/misha/projects/progbase2/progbase2/tasks/dkr1 /home/misha/projects/progbase2/progbase2/tasks/dkr1 /home/misha/projects/progbase2/progbase2/tasks/dkr1/build /home/misha/projects/progbase2/progbase2/tasks/dkr1/build /home/misha/projects/progbase2/progbase2/tasks/dkr1/build/CMakeFiles/test3.out.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/test3.out.dir/depend

