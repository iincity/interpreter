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
CMAKE_SOURCE_DIR = "/home/misha/bydlokoding/interpreter/interpreter c lan"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/misha/bydlokoding/interpreter/interpreter c lan/build"

# Include any dependencies generated for this target.
include CMakeFiles/task3_test.out.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/task3_test.out.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/task3_test.out.dir/flags.make

CMakeFiles/task3_test.out.dir/tests/test3.c.o: CMakeFiles/task3_test.out.dir/flags.make
CMakeFiles/task3_test.out.dir/tests/test3.c.o: ../tests/test3.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/misha/bydlokoding/interpreter/interpreter c lan/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/task3_test.out.dir/tests/test3.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/task3_test.out.dir/tests/test3.c.o   -c "/home/misha/bydlokoding/interpreter/interpreter c lan/tests/test3.c"

CMakeFiles/task3_test.out.dir/tests/test3.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/task3_test.out.dir/tests/test3.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/misha/bydlokoding/interpreter/interpreter c lan/tests/test3.c" > CMakeFiles/task3_test.out.dir/tests/test3.c.i

CMakeFiles/task3_test.out.dir/tests/test3.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/task3_test.out.dir/tests/test3.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/misha/bydlokoding/interpreter/interpreter c lan/tests/test3.c" -o CMakeFiles/task3_test.out.dir/tests/test3.c.s

CMakeFiles/task3_test.out.dir/tests/test3.c.o.requires:

.PHONY : CMakeFiles/task3_test.out.dir/tests/test3.c.o.requires

CMakeFiles/task3_test.out.dir/tests/test3.c.o.provides: CMakeFiles/task3_test.out.dir/tests/test3.c.o.requires
	$(MAKE) -f CMakeFiles/task3_test.out.dir/build.make CMakeFiles/task3_test.out.dir/tests/test3.c.o.provides.build
.PHONY : CMakeFiles/task3_test.out.dir/tests/test3.c.o.provides

CMakeFiles/task3_test.out.dir/tests/test3.c.o.provides.build: CMakeFiles/task3_test.out.dir/tests/test3.c.o


CMakeFiles/task3_test.out.dir/src/preetyprint.c.o: CMakeFiles/task3_test.out.dir/flags.make
CMakeFiles/task3_test.out.dir/src/preetyprint.c.o: ../src/preetyprint.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/misha/bydlokoding/interpreter/interpreter c lan/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/task3_test.out.dir/src/preetyprint.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/task3_test.out.dir/src/preetyprint.c.o   -c "/home/misha/bydlokoding/interpreter/interpreter c lan/src/preetyprint.c"

CMakeFiles/task3_test.out.dir/src/preetyprint.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/task3_test.out.dir/src/preetyprint.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/misha/bydlokoding/interpreter/interpreter c lan/src/preetyprint.c" > CMakeFiles/task3_test.out.dir/src/preetyprint.c.i

CMakeFiles/task3_test.out.dir/src/preetyprint.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/task3_test.out.dir/src/preetyprint.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/misha/bydlokoding/interpreter/interpreter c lan/src/preetyprint.c" -o CMakeFiles/task3_test.out.dir/src/preetyprint.c.s

CMakeFiles/task3_test.out.dir/src/preetyprint.c.o.requires:

.PHONY : CMakeFiles/task3_test.out.dir/src/preetyprint.c.o.requires

CMakeFiles/task3_test.out.dir/src/preetyprint.c.o.provides: CMakeFiles/task3_test.out.dir/src/preetyprint.c.o.requires
	$(MAKE) -f CMakeFiles/task3_test.out.dir/build.make CMakeFiles/task3_test.out.dir/src/preetyprint.c.o.provides.build
.PHONY : CMakeFiles/task3_test.out.dir/src/preetyprint.c.o.provides

CMakeFiles/task3_test.out.dir/src/preetyprint.c.o.provides.build: CMakeFiles/task3_test.out.dir/src/preetyprint.c.o


CMakeFiles/task3_test.out.dir/src/_list.c.o: CMakeFiles/task3_test.out.dir/flags.make
CMakeFiles/task3_test.out.dir/src/_list.c.o: ../src/_list.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/misha/bydlokoding/interpreter/interpreter c lan/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/task3_test.out.dir/src/_list.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/task3_test.out.dir/src/_list.c.o   -c "/home/misha/bydlokoding/interpreter/interpreter c lan/src/_list.c"

CMakeFiles/task3_test.out.dir/src/_list.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/task3_test.out.dir/src/_list.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/misha/bydlokoding/interpreter/interpreter c lan/src/_list.c" > CMakeFiles/task3_test.out.dir/src/_list.c.i

CMakeFiles/task3_test.out.dir/src/_list.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/task3_test.out.dir/src/_list.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/misha/bydlokoding/interpreter/interpreter c lan/src/_list.c" -o CMakeFiles/task3_test.out.dir/src/_list.c.s

CMakeFiles/task3_test.out.dir/src/_list.c.o.requires:

.PHONY : CMakeFiles/task3_test.out.dir/src/_list.c.o.requires

CMakeFiles/task3_test.out.dir/src/_list.c.o.provides: CMakeFiles/task3_test.out.dir/src/_list.c.o.requires
	$(MAKE) -f CMakeFiles/task3_test.out.dir/build.make CMakeFiles/task3_test.out.dir/src/_list.c.o.provides.build
.PHONY : CMakeFiles/task3_test.out.dir/src/_list.c.o.provides

CMakeFiles/task3_test.out.dir/src/_list.c.o.provides.build: CMakeFiles/task3_test.out.dir/src/_list.c.o


CMakeFiles/task3_test.out.dir/src/stack.c.o: CMakeFiles/task3_test.out.dir/flags.make
CMakeFiles/task3_test.out.dir/src/stack.c.o: ../src/stack.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/misha/bydlokoding/interpreter/interpreter c lan/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/task3_test.out.dir/src/stack.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/task3_test.out.dir/src/stack.c.o   -c "/home/misha/bydlokoding/interpreter/interpreter c lan/src/stack.c"

CMakeFiles/task3_test.out.dir/src/stack.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/task3_test.out.dir/src/stack.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/misha/bydlokoding/interpreter/interpreter c lan/src/stack.c" > CMakeFiles/task3_test.out.dir/src/stack.c.i

CMakeFiles/task3_test.out.dir/src/stack.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/task3_test.out.dir/src/stack.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/misha/bydlokoding/interpreter/interpreter c lan/src/stack.c" -o CMakeFiles/task3_test.out.dir/src/stack.c.s

CMakeFiles/task3_test.out.dir/src/stack.c.o.requires:

.PHONY : CMakeFiles/task3_test.out.dir/src/stack.c.o.requires

CMakeFiles/task3_test.out.dir/src/stack.c.o.provides: CMakeFiles/task3_test.out.dir/src/stack.c.o.requires
	$(MAKE) -f CMakeFiles/task3_test.out.dir/build.make CMakeFiles/task3_test.out.dir/src/stack.c.o.provides.build
.PHONY : CMakeFiles/task3_test.out.dir/src/stack.c.o.provides

CMakeFiles/task3_test.out.dir/src/stack.c.o.provides.build: CMakeFiles/task3_test.out.dir/src/stack.c.o


CMakeFiles/task3_test.out.dir/src/lexer.c.o: CMakeFiles/task3_test.out.dir/flags.make
CMakeFiles/task3_test.out.dir/src/lexer.c.o: ../src/lexer.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/misha/bydlokoding/interpreter/interpreter c lan/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/task3_test.out.dir/src/lexer.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/task3_test.out.dir/src/lexer.c.o   -c "/home/misha/bydlokoding/interpreter/interpreter c lan/src/lexer.c"

CMakeFiles/task3_test.out.dir/src/lexer.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/task3_test.out.dir/src/lexer.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/misha/bydlokoding/interpreter/interpreter c lan/src/lexer.c" > CMakeFiles/task3_test.out.dir/src/lexer.c.i

CMakeFiles/task3_test.out.dir/src/lexer.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/task3_test.out.dir/src/lexer.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/misha/bydlokoding/interpreter/interpreter c lan/src/lexer.c" -o CMakeFiles/task3_test.out.dir/src/lexer.c.s

CMakeFiles/task3_test.out.dir/src/lexer.c.o.requires:

.PHONY : CMakeFiles/task3_test.out.dir/src/lexer.c.o.requires

CMakeFiles/task3_test.out.dir/src/lexer.c.o.provides: CMakeFiles/task3_test.out.dir/src/lexer.c.o.requires
	$(MAKE) -f CMakeFiles/task3_test.out.dir/build.make CMakeFiles/task3_test.out.dir/src/lexer.c.o.provides.build
.PHONY : CMakeFiles/task3_test.out.dir/src/lexer.c.o.provides

CMakeFiles/task3_test.out.dir/src/lexer.c.o.provides.build: CMakeFiles/task3_test.out.dir/src/lexer.c.o


CMakeFiles/task3_test.out.dir/src/dict.c.o: CMakeFiles/task3_test.out.dir/flags.make
CMakeFiles/task3_test.out.dir/src/dict.c.o: ../src/dict.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/misha/bydlokoding/interpreter/interpreter c lan/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/task3_test.out.dir/src/dict.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/task3_test.out.dir/src/dict.c.o   -c "/home/misha/bydlokoding/interpreter/interpreter c lan/src/dict.c"

CMakeFiles/task3_test.out.dir/src/dict.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/task3_test.out.dir/src/dict.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/misha/bydlokoding/interpreter/interpreter c lan/src/dict.c" > CMakeFiles/task3_test.out.dir/src/dict.c.i

CMakeFiles/task3_test.out.dir/src/dict.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/task3_test.out.dir/src/dict.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/misha/bydlokoding/interpreter/interpreter c lan/src/dict.c" -o CMakeFiles/task3_test.out.dir/src/dict.c.s

CMakeFiles/task3_test.out.dir/src/dict.c.o.requires:

.PHONY : CMakeFiles/task3_test.out.dir/src/dict.c.o.requires

CMakeFiles/task3_test.out.dir/src/dict.c.o.provides: CMakeFiles/task3_test.out.dir/src/dict.c.o.requires
	$(MAKE) -f CMakeFiles/task3_test.out.dir/build.make CMakeFiles/task3_test.out.dir/src/dict.c.o.provides.build
.PHONY : CMakeFiles/task3_test.out.dir/src/dict.c.o.provides

CMakeFiles/task3_test.out.dir/src/dict.c.o.provides.build: CMakeFiles/task3_test.out.dir/src/dict.c.o


CMakeFiles/task3_test.out.dir/src/fs.c.o: CMakeFiles/task3_test.out.dir/flags.make
CMakeFiles/task3_test.out.dir/src/fs.c.o: ../src/fs.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/misha/bydlokoding/interpreter/interpreter c lan/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/task3_test.out.dir/src/fs.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/task3_test.out.dir/src/fs.c.o   -c "/home/misha/bydlokoding/interpreter/interpreter c lan/src/fs.c"

CMakeFiles/task3_test.out.dir/src/fs.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/task3_test.out.dir/src/fs.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/misha/bydlokoding/interpreter/interpreter c lan/src/fs.c" > CMakeFiles/task3_test.out.dir/src/fs.c.i

CMakeFiles/task3_test.out.dir/src/fs.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/task3_test.out.dir/src/fs.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/misha/bydlokoding/interpreter/interpreter c lan/src/fs.c" -o CMakeFiles/task3_test.out.dir/src/fs.c.s

CMakeFiles/task3_test.out.dir/src/fs.c.o.requires:

.PHONY : CMakeFiles/task3_test.out.dir/src/fs.c.o.requires

CMakeFiles/task3_test.out.dir/src/fs.c.o.provides: CMakeFiles/task3_test.out.dir/src/fs.c.o.requires
	$(MAKE) -f CMakeFiles/task3_test.out.dir/build.make CMakeFiles/task3_test.out.dir/src/fs.c.o.provides.build
.PHONY : CMakeFiles/task3_test.out.dir/src/fs.c.o.provides

CMakeFiles/task3_test.out.dir/src/fs.c.o.provides.build: CMakeFiles/task3_test.out.dir/src/fs.c.o


CMakeFiles/task3_test.out.dir/src/stringbuffer.c.o: CMakeFiles/task3_test.out.dir/flags.make
CMakeFiles/task3_test.out.dir/src/stringbuffer.c.o: ../src/stringbuffer.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/misha/bydlokoding/interpreter/interpreter c lan/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_8) "Building C object CMakeFiles/task3_test.out.dir/src/stringbuffer.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/task3_test.out.dir/src/stringbuffer.c.o   -c "/home/misha/bydlokoding/interpreter/interpreter c lan/src/stringbuffer.c"

CMakeFiles/task3_test.out.dir/src/stringbuffer.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/task3_test.out.dir/src/stringbuffer.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/misha/bydlokoding/interpreter/interpreter c lan/src/stringbuffer.c" > CMakeFiles/task3_test.out.dir/src/stringbuffer.c.i

CMakeFiles/task3_test.out.dir/src/stringbuffer.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/task3_test.out.dir/src/stringbuffer.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/misha/bydlokoding/interpreter/interpreter c lan/src/stringbuffer.c" -o CMakeFiles/task3_test.out.dir/src/stringbuffer.c.s

CMakeFiles/task3_test.out.dir/src/stringbuffer.c.o.requires:

.PHONY : CMakeFiles/task3_test.out.dir/src/stringbuffer.c.o.requires

CMakeFiles/task3_test.out.dir/src/stringbuffer.c.o.provides: CMakeFiles/task3_test.out.dir/src/stringbuffer.c.o.requires
	$(MAKE) -f CMakeFiles/task3_test.out.dir/build.make CMakeFiles/task3_test.out.dir/src/stringbuffer.c.o.provides.build
.PHONY : CMakeFiles/task3_test.out.dir/src/stringbuffer.c.o.provides

CMakeFiles/task3_test.out.dir/src/stringbuffer.c.o.provides.build: CMakeFiles/task3_test.out.dir/src/stringbuffer.c.o


CMakeFiles/task3_test.out.dir/src/bintree.c.o: CMakeFiles/task3_test.out.dir/flags.make
CMakeFiles/task3_test.out.dir/src/bintree.c.o: ../src/bintree.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/misha/bydlokoding/interpreter/interpreter c lan/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_9) "Building C object CMakeFiles/task3_test.out.dir/src/bintree.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/task3_test.out.dir/src/bintree.c.o   -c "/home/misha/bydlokoding/interpreter/interpreter c lan/src/bintree.c"

CMakeFiles/task3_test.out.dir/src/bintree.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/task3_test.out.dir/src/bintree.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/misha/bydlokoding/interpreter/interpreter c lan/src/bintree.c" > CMakeFiles/task3_test.out.dir/src/bintree.c.i

CMakeFiles/task3_test.out.dir/src/bintree.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/task3_test.out.dir/src/bintree.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/misha/bydlokoding/interpreter/interpreter c lan/src/bintree.c" -o CMakeFiles/task3_test.out.dir/src/bintree.c.s

CMakeFiles/task3_test.out.dir/src/bintree.c.o.requires:

.PHONY : CMakeFiles/task3_test.out.dir/src/bintree.c.o.requires

CMakeFiles/task3_test.out.dir/src/bintree.c.o.provides: CMakeFiles/task3_test.out.dir/src/bintree.c.o.requires
	$(MAKE) -f CMakeFiles/task3_test.out.dir/build.make CMakeFiles/task3_test.out.dir/src/bintree.c.o.provides.build
.PHONY : CMakeFiles/task3_test.out.dir/src/bintree.c.o.provides

CMakeFiles/task3_test.out.dir/src/bintree.c.o.provides.build: CMakeFiles/task3_test.out.dir/src/bintree.c.o


CMakeFiles/task3_test.out.dir/src/parser.c.o: CMakeFiles/task3_test.out.dir/flags.make
CMakeFiles/task3_test.out.dir/src/parser.c.o: ../src/parser.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/misha/bydlokoding/interpreter/interpreter c lan/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_10) "Building C object CMakeFiles/task3_test.out.dir/src/parser.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/task3_test.out.dir/src/parser.c.o   -c "/home/misha/bydlokoding/interpreter/interpreter c lan/src/parser.c"

CMakeFiles/task3_test.out.dir/src/parser.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/task3_test.out.dir/src/parser.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/misha/bydlokoding/interpreter/interpreter c lan/src/parser.c" > CMakeFiles/task3_test.out.dir/src/parser.c.i

CMakeFiles/task3_test.out.dir/src/parser.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/task3_test.out.dir/src/parser.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/misha/bydlokoding/interpreter/interpreter c lan/src/parser.c" -o CMakeFiles/task3_test.out.dir/src/parser.c.s

CMakeFiles/task3_test.out.dir/src/parser.c.o.requires:

.PHONY : CMakeFiles/task3_test.out.dir/src/parser.c.o.requires

CMakeFiles/task3_test.out.dir/src/parser.c.o.provides: CMakeFiles/task3_test.out.dir/src/parser.c.o.requires
	$(MAKE) -f CMakeFiles/task3_test.out.dir/build.make CMakeFiles/task3_test.out.dir/src/parser.c.o.provides.build
.PHONY : CMakeFiles/task3_test.out.dir/src/parser.c.o.provides

CMakeFiles/task3_test.out.dir/src/parser.c.o.provides.build: CMakeFiles/task3_test.out.dir/src/parser.c.o


CMakeFiles/task3_test.out.dir/src/tree.c.o: CMakeFiles/task3_test.out.dir/flags.make
CMakeFiles/task3_test.out.dir/src/tree.c.o: ../src/tree.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/misha/bydlokoding/interpreter/interpreter c lan/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_11) "Building C object CMakeFiles/task3_test.out.dir/src/tree.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/task3_test.out.dir/src/tree.c.o   -c "/home/misha/bydlokoding/interpreter/interpreter c lan/src/tree.c"

CMakeFiles/task3_test.out.dir/src/tree.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/task3_test.out.dir/src/tree.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/misha/bydlokoding/interpreter/interpreter c lan/src/tree.c" > CMakeFiles/task3_test.out.dir/src/tree.c.i

CMakeFiles/task3_test.out.dir/src/tree.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/task3_test.out.dir/src/tree.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/misha/bydlokoding/interpreter/interpreter c lan/src/tree.c" -o CMakeFiles/task3_test.out.dir/src/tree.c.s

CMakeFiles/task3_test.out.dir/src/tree.c.o.requires:

.PHONY : CMakeFiles/task3_test.out.dir/src/tree.c.o.requires

CMakeFiles/task3_test.out.dir/src/tree.c.o.provides: CMakeFiles/task3_test.out.dir/src/tree.c.o.requires
	$(MAKE) -f CMakeFiles/task3_test.out.dir/build.make CMakeFiles/task3_test.out.dir/src/tree.c.o.provides.build
.PHONY : CMakeFiles/task3_test.out.dir/src/tree.c.o.provides

CMakeFiles/task3_test.out.dir/src/tree.c.o.provides.build: CMakeFiles/task3_test.out.dir/src/tree.c.o


CMakeFiles/task3_test.out.dir/src/interpreter.c.o: CMakeFiles/task3_test.out.dir/flags.make
CMakeFiles/task3_test.out.dir/src/interpreter.c.o: ../src/interpreter.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/misha/bydlokoding/interpreter/interpreter c lan/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_12) "Building C object CMakeFiles/task3_test.out.dir/src/interpreter.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/task3_test.out.dir/src/interpreter.c.o   -c "/home/misha/bydlokoding/interpreter/interpreter c lan/src/interpreter.c"

CMakeFiles/task3_test.out.dir/src/interpreter.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/task3_test.out.dir/src/interpreter.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/misha/bydlokoding/interpreter/interpreter c lan/src/interpreter.c" > CMakeFiles/task3_test.out.dir/src/interpreter.c.i

CMakeFiles/task3_test.out.dir/src/interpreter.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/task3_test.out.dir/src/interpreter.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/misha/bydlokoding/interpreter/interpreter c lan/src/interpreter.c" -o CMakeFiles/task3_test.out.dir/src/interpreter.c.s

CMakeFiles/task3_test.out.dir/src/interpreter.c.o.requires:

.PHONY : CMakeFiles/task3_test.out.dir/src/interpreter.c.o.requires

CMakeFiles/task3_test.out.dir/src/interpreter.c.o.provides: CMakeFiles/task3_test.out.dir/src/interpreter.c.o.requires
	$(MAKE) -f CMakeFiles/task3_test.out.dir/build.make CMakeFiles/task3_test.out.dir/src/interpreter.c.o.provides.build
.PHONY : CMakeFiles/task3_test.out.dir/src/interpreter.c.o.provides

CMakeFiles/task3_test.out.dir/src/interpreter.c.o.provides.build: CMakeFiles/task3_test.out.dir/src/interpreter.c.o


CMakeFiles/task3_test.out.dir/src/ast.c.o: CMakeFiles/task3_test.out.dir/flags.make
CMakeFiles/task3_test.out.dir/src/ast.c.o: ../src/ast.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/misha/bydlokoding/interpreter/interpreter c lan/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_13) "Building C object CMakeFiles/task3_test.out.dir/src/ast.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/task3_test.out.dir/src/ast.c.o   -c "/home/misha/bydlokoding/interpreter/interpreter c lan/src/ast.c"

CMakeFiles/task3_test.out.dir/src/ast.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/task3_test.out.dir/src/ast.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/misha/bydlokoding/interpreter/interpreter c lan/src/ast.c" > CMakeFiles/task3_test.out.dir/src/ast.c.i

CMakeFiles/task3_test.out.dir/src/ast.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/task3_test.out.dir/src/ast.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/misha/bydlokoding/interpreter/interpreter c lan/src/ast.c" -o CMakeFiles/task3_test.out.dir/src/ast.c.s

CMakeFiles/task3_test.out.dir/src/ast.c.o.requires:

.PHONY : CMakeFiles/task3_test.out.dir/src/ast.c.o.requires

CMakeFiles/task3_test.out.dir/src/ast.c.o.provides: CMakeFiles/task3_test.out.dir/src/ast.c.o.requires
	$(MAKE) -f CMakeFiles/task3_test.out.dir/build.make CMakeFiles/task3_test.out.dir/src/ast.c.o.provides.build
.PHONY : CMakeFiles/task3_test.out.dir/src/ast.c.o.provides

CMakeFiles/task3_test.out.dir/src/ast.c.o.provides.build: CMakeFiles/task3_test.out.dir/src/ast.c.o


CMakeFiles/task3_test.out.dir/src/std_functions.c.o: CMakeFiles/task3_test.out.dir/flags.make
CMakeFiles/task3_test.out.dir/src/std_functions.c.o: ../src/std_functions.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/misha/bydlokoding/interpreter/interpreter c lan/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_14) "Building C object CMakeFiles/task3_test.out.dir/src/std_functions.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/task3_test.out.dir/src/std_functions.c.o   -c "/home/misha/bydlokoding/interpreter/interpreter c lan/src/std_functions.c"

CMakeFiles/task3_test.out.dir/src/std_functions.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/task3_test.out.dir/src/std_functions.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/misha/bydlokoding/interpreter/interpreter c lan/src/std_functions.c" > CMakeFiles/task3_test.out.dir/src/std_functions.c.i

CMakeFiles/task3_test.out.dir/src/std_functions.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/task3_test.out.dir/src/std_functions.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/misha/bydlokoding/interpreter/interpreter c lan/src/std_functions.c" -o CMakeFiles/task3_test.out.dir/src/std_functions.c.s

CMakeFiles/task3_test.out.dir/src/std_functions.c.o.requires:

.PHONY : CMakeFiles/task3_test.out.dir/src/std_functions.c.o.requires

CMakeFiles/task3_test.out.dir/src/std_functions.c.o.provides: CMakeFiles/task3_test.out.dir/src/std_functions.c.o.requires
	$(MAKE) -f CMakeFiles/task3_test.out.dir/build.make CMakeFiles/task3_test.out.dir/src/std_functions.c.o.provides.build
.PHONY : CMakeFiles/task3_test.out.dir/src/std_functions.c.o.provides

CMakeFiles/task3_test.out.dir/src/std_functions.c.o.provides.build: CMakeFiles/task3_test.out.dir/src/std_functions.c.o


# Object files for target task3_test.out
task3_test_out_OBJECTS = \
"CMakeFiles/task3_test.out.dir/tests/test3.c.o" \
"CMakeFiles/task3_test.out.dir/src/preetyprint.c.o" \
"CMakeFiles/task3_test.out.dir/src/_list.c.o" \
"CMakeFiles/task3_test.out.dir/src/stack.c.o" \
"CMakeFiles/task3_test.out.dir/src/lexer.c.o" \
"CMakeFiles/task3_test.out.dir/src/dict.c.o" \
"CMakeFiles/task3_test.out.dir/src/fs.c.o" \
"CMakeFiles/task3_test.out.dir/src/stringbuffer.c.o" \
"CMakeFiles/task3_test.out.dir/src/bintree.c.o" \
"CMakeFiles/task3_test.out.dir/src/parser.c.o" \
"CMakeFiles/task3_test.out.dir/src/tree.c.o" \
"CMakeFiles/task3_test.out.dir/src/interpreter.c.o" \
"CMakeFiles/task3_test.out.dir/src/ast.c.o" \
"CMakeFiles/task3_test.out.dir/src/std_functions.c.o"

# External object files for target task3_test.out
task3_test_out_EXTERNAL_OBJECTS =

task3_test.out: CMakeFiles/task3_test.out.dir/tests/test3.c.o
task3_test.out: CMakeFiles/task3_test.out.dir/src/preetyprint.c.o
task3_test.out: CMakeFiles/task3_test.out.dir/src/_list.c.o
task3_test.out: CMakeFiles/task3_test.out.dir/src/stack.c.o
task3_test.out: CMakeFiles/task3_test.out.dir/src/lexer.c.o
task3_test.out: CMakeFiles/task3_test.out.dir/src/dict.c.o
task3_test.out: CMakeFiles/task3_test.out.dir/src/fs.c.o
task3_test.out: CMakeFiles/task3_test.out.dir/src/stringbuffer.c.o
task3_test.out: CMakeFiles/task3_test.out.dir/src/bintree.c.o
task3_test.out: CMakeFiles/task3_test.out.dir/src/parser.c.o
task3_test.out: CMakeFiles/task3_test.out.dir/src/tree.c.o
task3_test.out: CMakeFiles/task3_test.out.dir/src/interpreter.c.o
task3_test.out: CMakeFiles/task3_test.out.dir/src/ast.c.o
task3_test.out: CMakeFiles/task3_test.out.dir/src/std_functions.c.o
task3_test.out: CMakeFiles/task3_test.out.dir/build.make
task3_test.out: CMakeFiles/task3_test.out.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/misha/bydlokoding/interpreter/interpreter c lan/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_15) "Linking C executable task3_test.out"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/task3_test.out.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/task3_test.out.dir/build: task3_test.out

.PHONY : CMakeFiles/task3_test.out.dir/build

CMakeFiles/task3_test.out.dir/requires: CMakeFiles/task3_test.out.dir/tests/test3.c.o.requires
CMakeFiles/task3_test.out.dir/requires: CMakeFiles/task3_test.out.dir/src/preetyprint.c.o.requires
CMakeFiles/task3_test.out.dir/requires: CMakeFiles/task3_test.out.dir/src/_list.c.o.requires
CMakeFiles/task3_test.out.dir/requires: CMakeFiles/task3_test.out.dir/src/stack.c.o.requires
CMakeFiles/task3_test.out.dir/requires: CMakeFiles/task3_test.out.dir/src/lexer.c.o.requires
CMakeFiles/task3_test.out.dir/requires: CMakeFiles/task3_test.out.dir/src/dict.c.o.requires
CMakeFiles/task3_test.out.dir/requires: CMakeFiles/task3_test.out.dir/src/fs.c.o.requires
CMakeFiles/task3_test.out.dir/requires: CMakeFiles/task3_test.out.dir/src/stringbuffer.c.o.requires
CMakeFiles/task3_test.out.dir/requires: CMakeFiles/task3_test.out.dir/src/bintree.c.o.requires
CMakeFiles/task3_test.out.dir/requires: CMakeFiles/task3_test.out.dir/src/parser.c.o.requires
CMakeFiles/task3_test.out.dir/requires: CMakeFiles/task3_test.out.dir/src/tree.c.o.requires
CMakeFiles/task3_test.out.dir/requires: CMakeFiles/task3_test.out.dir/src/interpreter.c.o.requires
CMakeFiles/task3_test.out.dir/requires: CMakeFiles/task3_test.out.dir/src/ast.c.o.requires
CMakeFiles/task3_test.out.dir/requires: CMakeFiles/task3_test.out.dir/src/std_functions.c.o.requires

.PHONY : CMakeFiles/task3_test.out.dir/requires

CMakeFiles/task3_test.out.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/task3_test.out.dir/cmake_clean.cmake
.PHONY : CMakeFiles/task3_test.out.dir/clean

CMakeFiles/task3_test.out.dir/depend:
	cd "/home/misha/bydlokoding/interpreter/interpreter c lan/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/misha/bydlokoding/interpreter/interpreter c lan" "/home/misha/bydlokoding/interpreter/interpreter c lan" "/home/misha/bydlokoding/interpreter/interpreter c lan/build" "/home/misha/bydlokoding/interpreter/interpreter c lan/build" "/home/misha/bydlokoding/interpreter/interpreter c lan/build/CMakeFiles/task3_test.out.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/task3_test.out.dir/depend

