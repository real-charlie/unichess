# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

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
CMAKE_COMMAND = /snap/clion/x1/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/x1/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/florence/CLionProjects/UniChess

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/florence/CLionProjects/UniChess/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/UniChess.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/UniChess.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/UniChess.dir/flags.make

CMakeFiles/UniChess.dir/src/main.c.o: CMakeFiles/UniChess.dir/flags.make
CMakeFiles/UniChess.dir/src/main.c.o: ../src/main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/florence/CLionProjects/UniChess/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/UniChess.dir/src/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/UniChess.dir/src/main.c.o -c /home/florence/CLionProjects/UniChess/src/main.c

CMakeFiles/UniChess.dir/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/UniChess.dir/src/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/florence/CLionProjects/UniChess/src/main.c > CMakeFiles/UniChess.dir/src/main.c.i

CMakeFiles/UniChess.dir/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/UniChess.dir/src/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/florence/CLionProjects/UniChess/src/main.c -o CMakeFiles/UniChess.dir/src/main.c.s

CMakeFiles/UniChess.dir/src/handle_arg.c.o: CMakeFiles/UniChess.dir/flags.make
CMakeFiles/UniChess.dir/src/handle_arg.c.o: ../src/handle_arg.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/florence/CLionProjects/UniChess/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/UniChess.dir/src/handle_arg.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/UniChess.dir/src/handle_arg.c.o -c /home/florence/CLionProjects/UniChess/src/handle_arg.c

CMakeFiles/UniChess.dir/src/handle_arg.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/UniChess.dir/src/handle_arg.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/florence/CLionProjects/UniChess/src/handle_arg.c > CMakeFiles/UniChess.dir/src/handle_arg.c.i

CMakeFiles/UniChess.dir/src/handle_arg.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/UniChess.dir/src/handle_arg.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/florence/CLionProjects/UniChess/src/handle_arg.c -o CMakeFiles/UniChess.dir/src/handle_arg.c.s

CMakeFiles/UniChess.dir/src/error.c.o: CMakeFiles/UniChess.dir/flags.make
CMakeFiles/UniChess.dir/src/error.c.o: ../src/error.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/florence/CLionProjects/UniChess/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/UniChess.dir/src/error.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/UniChess.dir/src/error.c.o -c /home/florence/CLionProjects/UniChess/src/error.c

CMakeFiles/UniChess.dir/src/error.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/UniChess.dir/src/error.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/florence/CLionProjects/UniChess/src/error.c > CMakeFiles/UniChess.dir/src/error.c.i

CMakeFiles/UniChess.dir/src/error.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/UniChess.dir/src/error.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/florence/CLionProjects/UniChess/src/error.c -o CMakeFiles/UniChess.dir/src/error.c.s

CMakeFiles/UniChess.dir/src/sime_game.c.o: CMakeFiles/UniChess.dir/flags.make
CMakeFiles/UniChess.dir/src/sime_game.c.o: ../src/sime_game.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/florence/CLionProjects/UniChess/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/UniChess.dir/src/sime_game.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/UniChess.dir/src/sime_game.c.o -c /home/florence/CLionProjects/UniChess/src/sime_game.c

CMakeFiles/UniChess.dir/src/sime_game.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/UniChess.dir/src/sime_game.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/florence/CLionProjects/UniChess/src/sime_game.c > CMakeFiles/UniChess.dir/src/sime_game.c.i

CMakeFiles/UniChess.dir/src/sime_game.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/UniChess.dir/src/sime_game.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/florence/CLionProjects/UniChess/src/sime_game.c -o CMakeFiles/UniChess.dir/src/sime_game.c.s

CMakeFiles/UniChess.dir/src/move_actions.c.o: CMakeFiles/UniChess.dir/flags.make
CMakeFiles/UniChess.dir/src/move_actions.c.o: ../src/move_actions.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/florence/CLionProjects/UniChess/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/UniChess.dir/src/move_actions.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/UniChess.dir/src/move_actions.c.o -c /home/florence/CLionProjects/UniChess/src/move_actions.c

CMakeFiles/UniChess.dir/src/move_actions.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/UniChess.dir/src/move_actions.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/florence/CLionProjects/UniChess/src/move_actions.c > CMakeFiles/UniChess.dir/src/move_actions.c.i

CMakeFiles/UniChess.dir/src/move_actions.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/UniChess.dir/src/move_actions.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/florence/CLionProjects/UniChess/src/move_actions.c -o CMakeFiles/UniChess.dir/src/move_actions.c.s

# Object files for target UniChess
UniChess_OBJECTS = \
"CMakeFiles/UniChess.dir/src/main.c.o" \
"CMakeFiles/UniChess.dir/src/handle_arg.c.o" \
"CMakeFiles/UniChess.dir/src/error.c.o" \
"CMakeFiles/UniChess.dir/src/sime_game.c.o" \
"CMakeFiles/UniChess.dir/src/move_actions.c.o"

# External object files for target UniChess
UniChess_EXTERNAL_OBJECTS =

UniChess: CMakeFiles/UniChess.dir/src/main.c.o
UniChess: CMakeFiles/UniChess.dir/src/handle_arg.c.o
UniChess: CMakeFiles/UniChess.dir/src/error.c.o
UniChess: CMakeFiles/UniChess.dir/src/sime_game.c.o
UniChess: CMakeFiles/UniChess.dir/src/move_actions.c.o
UniChess: CMakeFiles/UniChess.dir/build.make
UniChess: CMakeFiles/UniChess.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/florence/CLionProjects/UniChess/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking C executable UniChess"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/UniChess.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/UniChess.dir/build: UniChess

.PHONY : CMakeFiles/UniChess.dir/build

CMakeFiles/UniChess.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/UniChess.dir/cmake_clean.cmake
.PHONY : CMakeFiles/UniChess.dir/clean

CMakeFiles/UniChess.dir/depend:
	cd /home/florence/CLionProjects/UniChess/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/florence/CLionProjects/UniChess /home/florence/CLionProjects/UniChess /home/florence/CLionProjects/UniChess/cmake-build-debug /home/florence/CLionProjects/UniChess/cmake-build-debug /home/florence/CLionProjects/UniChess/cmake-build-debug/CMakeFiles/UniChess.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/UniChess.dir/depend

