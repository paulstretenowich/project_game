# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

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
CMAKE_COMMAND = /Applications/CMake.app/Contents/bin/cmake

# The command to remove a file.
RM = /Applications/CMake.app/Contents/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/paul/Documents/ISBS/ISBS3/c++/dvlp_projet_jeu/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/paul/Documents/ISBS/ISBS3/c++/dvlp_projet_jeu/build

# Include any dependencies generated for this target.
include CMakeFiles/Jeu_Video_dvlp.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Jeu_Video_dvlp.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Jeu_Video_dvlp.dir/flags.make

CMakeFiles/Jeu_Video_dvlp.dir/main.cpp.o: CMakeFiles/Jeu_Video_dvlp.dir/flags.make
CMakeFiles/Jeu_Video_dvlp.dir/main.cpp.o: /Users/paul/Documents/ISBS/ISBS3/c++/dvlp_projet_jeu/src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/paul/Documents/ISBS/ISBS3/c++/dvlp_projet_jeu/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Jeu_Video_dvlp.dir/main.cpp.o"
	/usr/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Jeu_Video_dvlp.dir/main.cpp.o -c /Users/paul/Documents/ISBS/ISBS3/c++/dvlp_projet_jeu/src/main.cpp

CMakeFiles/Jeu_Video_dvlp.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Jeu_Video_dvlp.dir/main.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/paul/Documents/ISBS/ISBS3/c++/dvlp_projet_jeu/src/main.cpp > CMakeFiles/Jeu_Video_dvlp.dir/main.cpp.i

CMakeFiles/Jeu_Video_dvlp.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Jeu_Video_dvlp.dir/main.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/paul/Documents/ISBS/ISBS3/c++/dvlp_projet_jeu/src/main.cpp -o CMakeFiles/Jeu_Video_dvlp.dir/main.cpp.s

CMakeFiles/Jeu_Video_dvlp.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/Jeu_Video_dvlp.dir/main.cpp.o.requires

CMakeFiles/Jeu_Video_dvlp.dir/main.cpp.o.provides: CMakeFiles/Jeu_Video_dvlp.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/Jeu_Video_dvlp.dir/build.make CMakeFiles/Jeu_Video_dvlp.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/Jeu_Video_dvlp.dir/main.cpp.o.provides

CMakeFiles/Jeu_Video_dvlp.dir/main.cpp.o.provides.build: CMakeFiles/Jeu_Video_dvlp.dir/main.cpp.o


CMakeFiles/Jeu_Video_dvlp.dir/game.cpp.o: CMakeFiles/Jeu_Video_dvlp.dir/flags.make
CMakeFiles/Jeu_Video_dvlp.dir/game.cpp.o: /Users/paul/Documents/ISBS/ISBS3/c++/dvlp_projet_jeu/src/game.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/paul/Documents/ISBS/ISBS3/c++/dvlp_projet_jeu/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Jeu_Video_dvlp.dir/game.cpp.o"
	/usr/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Jeu_Video_dvlp.dir/game.cpp.o -c /Users/paul/Documents/ISBS/ISBS3/c++/dvlp_projet_jeu/src/game.cpp

CMakeFiles/Jeu_Video_dvlp.dir/game.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Jeu_Video_dvlp.dir/game.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/paul/Documents/ISBS/ISBS3/c++/dvlp_projet_jeu/src/game.cpp > CMakeFiles/Jeu_Video_dvlp.dir/game.cpp.i

CMakeFiles/Jeu_Video_dvlp.dir/game.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Jeu_Video_dvlp.dir/game.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/paul/Documents/ISBS/ISBS3/c++/dvlp_projet_jeu/src/game.cpp -o CMakeFiles/Jeu_Video_dvlp.dir/game.cpp.s

CMakeFiles/Jeu_Video_dvlp.dir/game.cpp.o.requires:

.PHONY : CMakeFiles/Jeu_Video_dvlp.dir/game.cpp.o.requires

CMakeFiles/Jeu_Video_dvlp.dir/game.cpp.o.provides: CMakeFiles/Jeu_Video_dvlp.dir/game.cpp.o.requires
	$(MAKE) -f CMakeFiles/Jeu_Video_dvlp.dir/build.make CMakeFiles/Jeu_Video_dvlp.dir/game.cpp.o.provides.build
.PHONY : CMakeFiles/Jeu_Video_dvlp.dir/game.cpp.o.provides

CMakeFiles/Jeu_Video_dvlp.dir/game.cpp.o.provides.build: CMakeFiles/Jeu_Video_dvlp.dir/game.cpp.o


CMakeFiles/Jeu_Video_dvlp.dir/menustate.cpp.o: CMakeFiles/Jeu_Video_dvlp.dir/flags.make
CMakeFiles/Jeu_Video_dvlp.dir/menustate.cpp.o: /Users/paul/Documents/ISBS/ISBS3/c++/dvlp_projet_jeu/src/menustate.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/paul/Documents/ISBS/ISBS3/c++/dvlp_projet_jeu/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Jeu_Video_dvlp.dir/menustate.cpp.o"
	/usr/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Jeu_Video_dvlp.dir/menustate.cpp.o -c /Users/paul/Documents/ISBS/ISBS3/c++/dvlp_projet_jeu/src/menustate.cpp

CMakeFiles/Jeu_Video_dvlp.dir/menustate.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Jeu_Video_dvlp.dir/menustate.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/paul/Documents/ISBS/ISBS3/c++/dvlp_projet_jeu/src/menustate.cpp > CMakeFiles/Jeu_Video_dvlp.dir/menustate.cpp.i

CMakeFiles/Jeu_Video_dvlp.dir/menustate.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Jeu_Video_dvlp.dir/menustate.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/paul/Documents/ISBS/ISBS3/c++/dvlp_projet_jeu/src/menustate.cpp -o CMakeFiles/Jeu_Video_dvlp.dir/menustate.cpp.s

CMakeFiles/Jeu_Video_dvlp.dir/menustate.cpp.o.requires:

.PHONY : CMakeFiles/Jeu_Video_dvlp.dir/menustate.cpp.o.requires

CMakeFiles/Jeu_Video_dvlp.dir/menustate.cpp.o.provides: CMakeFiles/Jeu_Video_dvlp.dir/menustate.cpp.o.requires
	$(MAKE) -f CMakeFiles/Jeu_Video_dvlp.dir/build.make CMakeFiles/Jeu_Video_dvlp.dir/menustate.cpp.o.provides.build
.PHONY : CMakeFiles/Jeu_Video_dvlp.dir/menustate.cpp.o.provides

CMakeFiles/Jeu_Video_dvlp.dir/menustate.cpp.o.provides.build: CMakeFiles/Jeu_Video_dvlp.dir/menustate.cpp.o


CMakeFiles/Jeu_Video_dvlp.dir/optionstate.cpp.o: CMakeFiles/Jeu_Video_dvlp.dir/flags.make
CMakeFiles/Jeu_Video_dvlp.dir/optionstate.cpp.o: /Users/paul/Documents/ISBS/ISBS3/c++/dvlp_projet_jeu/src/optionstate.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/paul/Documents/ISBS/ISBS3/c++/dvlp_projet_jeu/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Jeu_Video_dvlp.dir/optionstate.cpp.o"
	/usr/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Jeu_Video_dvlp.dir/optionstate.cpp.o -c /Users/paul/Documents/ISBS/ISBS3/c++/dvlp_projet_jeu/src/optionstate.cpp

CMakeFiles/Jeu_Video_dvlp.dir/optionstate.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Jeu_Video_dvlp.dir/optionstate.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/paul/Documents/ISBS/ISBS3/c++/dvlp_projet_jeu/src/optionstate.cpp > CMakeFiles/Jeu_Video_dvlp.dir/optionstate.cpp.i

CMakeFiles/Jeu_Video_dvlp.dir/optionstate.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Jeu_Video_dvlp.dir/optionstate.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/paul/Documents/ISBS/ISBS3/c++/dvlp_projet_jeu/src/optionstate.cpp -o CMakeFiles/Jeu_Video_dvlp.dir/optionstate.cpp.s

CMakeFiles/Jeu_Video_dvlp.dir/optionstate.cpp.o.requires:

.PHONY : CMakeFiles/Jeu_Video_dvlp.dir/optionstate.cpp.o.requires

CMakeFiles/Jeu_Video_dvlp.dir/optionstate.cpp.o.provides: CMakeFiles/Jeu_Video_dvlp.dir/optionstate.cpp.o.requires
	$(MAKE) -f CMakeFiles/Jeu_Video_dvlp.dir/build.make CMakeFiles/Jeu_Video_dvlp.dir/optionstate.cpp.o.provides.build
.PHONY : CMakeFiles/Jeu_Video_dvlp.dir/optionstate.cpp.o.provides

CMakeFiles/Jeu_Video_dvlp.dir/optionstate.cpp.o.provides.build: CMakeFiles/Jeu_Video_dvlp.dir/optionstate.cpp.o


CMakeFiles/Jeu_Video_dvlp.dir/instructionstate.cpp.o: CMakeFiles/Jeu_Video_dvlp.dir/flags.make
CMakeFiles/Jeu_Video_dvlp.dir/instructionstate.cpp.o: /Users/paul/Documents/ISBS/ISBS3/c++/dvlp_projet_jeu/src/instructionstate.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/paul/Documents/ISBS/ISBS3/c++/dvlp_projet_jeu/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Jeu_Video_dvlp.dir/instructionstate.cpp.o"
	/usr/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Jeu_Video_dvlp.dir/instructionstate.cpp.o -c /Users/paul/Documents/ISBS/ISBS3/c++/dvlp_projet_jeu/src/instructionstate.cpp

CMakeFiles/Jeu_Video_dvlp.dir/instructionstate.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Jeu_Video_dvlp.dir/instructionstate.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/paul/Documents/ISBS/ISBS3/c++/dvlp_projet_jeu/src/instructionstate.cpp > CMakeFiles/Jeu_Video_dvlp.dir/instructionstate.cpp.i

CMakeFiles/Jeu_Video_dvlp.dir/instructionstate.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Jeu_Video_dvlp.dir/instructionstate.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/paul/Documents/ISBS/ISBS3/c++/dvlp_projet_jeu/src/instructionstate.cpp -o CMakeFiles/Jeu_Video_dvlp.dir/instructionstate.cpp.s

CMakeFiles/Jeu_Video_dvlp.dir/instructionstate.cpp.o.requires:

.PHONY : CMakeFiles/Jeu_Video_dvlp.dir/instructionstate.cpp.o.requires

CMakeFiles/Jeu_Video_dvlp.dir/instructionstate.cpp.o.provides: CMakeFiles/Jeu_Video_dvlp.dir/instructionstate.cpp.o.requires
	$(MAKE) -f CMakeFiles/Jeu_Video_dvlp.dir/build.make CMakeFiles/Jeu_Video_dvlp.dir/instructionstate.cpp.o.provides.build
.PHONY : CMakeFiles/Jeu_Video_dvlp.dir/instructionstate.cpp.o.provides

CMakeFiles/Jeu_Video_dvlp.dir/instructionstate.cpp.o.provides.build: CMakeFiles/Jeu_Video_dvlp.dir/instructionstate.cpp.o


CMakeFiles/Jeu_Video_dvlp.dir/introstate.cpp.o: CMakeFiles/Jeu_Video_dvlp.dir/flags.make
CMakeFiles/Jeu_Video_dvlp.dir/introstate.cpp.o: /Users/paul/Documents/ISBS/ISBS3/c++/dvlp_projet_jeu/src/introstate.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/paul/Documents/ISBS/ISBS3/c++/dvlp_projet_jeu/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/Jeu_Video_dvlp.dir/introstate.cpp.o"
	/usr/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Jeu_Video_dvlp.dir/introstate.cpp.o -c /Users/paul/Documents/ISBS/ISBS3/c++/dvlp_projet_jeu/src/introstate.cpp

CMakeFiles/Jeu_Video_dvlp.dir/introstate.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Jeu_Video_dvlp.dir/introstate.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/paul/Documents/ISBS/ISBS3/c++/dvlp_projet_jeu/src/introstate.cpp > CMakeFiles/Jeu_Video_dvlp.dir/introstate.cpp.i

CMakeFiles/Jeu_Video_dvlp.dir/introstate.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Jeu_Video_dvlp.dir/introstate.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/paul/Documents/ISBS/ISBS3/c++/dvlp_projet_jeu/src/introstate.cpp -o CMakeFiles/Jeu_Video_dvlp.dir/introstate.cpp.s

CMakeFiles/Jeu_Video_dvlp.dir/introstate.cpp.o.requires:

.PHONY : CMakeFiles/Jeu_Video_dvlp.dir/introstate.cpp.o.requires

CMakeFiles/Jeu_Video_dvlp.dir/introstate.cpp.o.provides: CMakeFiles/Jeu_Video_dvlp.dir/introstate.cpp.o.requires
	$(MAKE) -f CMakeFiles/Jeu_Video_dvlp.dir/build.make CMakeFiles/Jeu_Video_dvlp.dir/introstate.cpp.o.provides.build
.PHONY : CMakeFiles/Jeu_Video_dvlp.dir/introstate.cpp.o.provides

CMakeFiles/Jeu_Video_dvlp.dir/introstate.cpp.o.provides.build: CMakeFiles/Jeu_Video_dvlp.dir/introstate.cpp.o


CMakeFiles/Jeu_Video_dvlp.dir/deadstate.cpp.o: CMakeFiles/Jeu_Video_dvlp.dir/flags.make
CMakeFiles/Jeu_Video_dvlp.dir/deadstate.cpp.o: /Users/paul/Documents/ISBS/ISBS3/c++/dvlp_projet_jeu/src/deadstate.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/paul/Documents/ISBS/ISBS3/c++/dvlp_projet_jeu/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/Jeu_Video_dvlp.dir/deadstate.cpp.o"
	/usr/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Jeu_Video_dvlp.dir/deadstate.cpp.o -c /Users/paul/Documents/ISBS/ISBS3/c++/dvlp_projet_jeu/src/deadstate.cpp

CMakeFiles/Jeu_Video_dvlp.dir/deadstate.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Jeu_Video_dvlp.dir/deadstate.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/paul/Documents/ISBS/ISBS3/c++/dvlp_projet_jeu/src/deadstate.cpp > CMakeFiles/Jeu_Video_dvlp.dir/deadstate.cpp.i

CMakeFiles/Jeu_Video_dvlp.dir/deadstate.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Jeu_Video_dvlp.dir/deadstate.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/paul/Documents/ISBS/ISBS3/c++/dvlp_projet_jeu/src/deadstate.cpp -o CMakeFiles/Jeu_Video_dvlp.dir/deadstate.cpp.s

CMakeFiles/Jeu_Video_dvlp.dir/deadstate.cpp.o.requires:

.PHONY : CMakeFiles/Jeu_Video_dvlp.dir/deadstate.cpp.o.requires

CMakeFiles/Jeu_Video_dvlp.dir/deadstate.cpp.o.provides: CMakeFiles/Jeu_Video_dvlp.dir/deadstate.cpp.o.requires
	$(MAKE) -f CMakeFiles/Jeu_Video_dvlp.dir/build.make CMakeFiles/Jeu_Video_dvlp.dir/deadstate.cpp.o.provides.build
.PHONY : CMakeFiles/Jeu_Video_dvlp.dir/deadstate.cpp.o.provides

CMakeFiles/Jeu_Video_dvlp.dir/deadstate.cpp.o.provides.build: CMakeFiles/Jeu_Video_dvlp.dir/deadstate.cpp.o


CMakeFiles/Jeu_Video_dvlp.dir/stage1state.cpp.o: CMakeFiles/Jeu_Video_dvlp.dir/flags.make
CMakeFiles/Jeu_Video_dvlp.dir/stage1state.cpp.o: /Users/paul/Documents/ISBS/ISBS3/c++/dvlp_projet_jeu/src/stage1state.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/paul/Documents/ISBS/ISBS3/c++/dvlp_projet_jeu/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/Jeu_Video_dvlp.dir/stage1state.cpp.o"
	/usr/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Jeu_Video_dvlp.dir/stage1state.cpp.o -c /Users/paul/Documents/ISBS/ISBS3/c++/dvlp_projet_jeu/src/stage1state.cpp

CMakeFiles/Jeu_Video_dvlp.dir/stage1state.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Jeu_Video_dvlp.dir/stage1state.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/paul/Documents/ISBS/ISBS3/c++/dvlp_projet_jeu/src/stage1state.cpp > CMakeFiles/Jeu_Video_dvlp.dir/stage1state.cpp.i

CMakeFiles/Jeu_Video_dvlp.dir/stage1state.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Jeu_Video_dvlp.dir/stage1state.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/paul/Documents/ISBS/ISBS3/c++/dvlp_projet_jeu/src/stage1state.cpp -o CMakeFiles/Jeu_Video_dvlp.dir/stage1state.cpp.s

CMakeFiles/Jeu_Video_dvlp.dir/stage1state.cpp.o.requires:

.PHONY : CMakeFiles/Jeu_Video_dvlp.dir/stage1state.cpp.o.requires

CMakeFiles/Jeu_Video_dvlp.dir/stage1state.cpp.o.provides: CMakeFiles/Jeu_Video_dvlp.dir/stage1state.cpp.o.requires
	$(MAKE) -f CMakeFiles/Jeu_Video_dvlp.dir/build.make CMakeFiles/Jeu_Video_dvlp.dir/stage1state.cpp.o.provides.build
.PHONY : CMakeFiles/Jeu_Video_dvlp.dir/stage1state.cpp.o.provides

CMakeFiles/Jeu_Video_dvlp.dir/stage1state.cpp.o.provides.build: CMakeFiles/Jeu_Video_dvlp.dir/stage1state.cpp.o


CMakeFiles/Jeu_Video_dvlp.dir/texturemanager.cpp.o: CMakeFiles/Jeu_Video_dvlp.dir/flags.make
CMakeFiles/Jeu_Video_dvlp.dir/texturemanager.cpp.o: /Users/paul/Documents/ISBS/ISBS3/c++/dvlp_projet_jeu/src/texturemanager.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/paul/Documents/ISBS/ISBS3/c++/dvlp_projet_jeu/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/Jeu_Video_dvlp.dir/texturemanager.cpp.o"
	/usr/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Jeu_Video_dvlp.dir/texturemanager.cpp.o -c /Users/paul/Documents/ISBS/ISBS3/c++/dvlp_projet_jeu/src/texturemanager.cpp

CMakeFiles/Jeu_Video_dvlp.dir/texturemanager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Jeu_Video_dvlp.dir/texturemanager.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/paul/Documents/ISBS/ISBS3/c++/dvlp_projet_jeu/src/texturemanager.cpp > CMakeFiles/Jeu_Video_dvlp.dir/texturemanager.cpp.i

CMakeFiles/Jeu_Video_dvlp.dir/texturemanager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Jeu_Video_dvlp.dir/texturemanager.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/paul/Documents/ISBS/ISBS3/c++/dvlp_projet_jeu/src/texturemanager.cpp -o CMakeFiles/Jeu_Video_dvlp.dir/texturemanager.cpp.s

CMakeFiles/Jeu_Video_dvlp.dir/texturemanager.cpp.o.requires:

.PHONY : CMakeFiles/Jeu_Video_dvlp.dir/texturemanager.cpp.o.requires

CMakeFiles/Jeu_Video_dvlp.dir/texturemanager.cpp.o.provides: CMakeFiles/Jeu_Video_dvlp.dir/texturemanager.cpp.o.requires
	$(MAKE) -f CMakeFiles/Jeu_Video_dvlp.dir/build.make CMakeFiles/Jeu_Video_dvlp.dir/texturemanager.cpp.o.provides.build
.PHONY : CMakeFiles/Jeu_Video_dvlp.dir/texturemanager.cpp.o.provides

CMakeFiles/Jeu_Video_dvlp.dir/texturemanager.cpp.o.provides.build: CMakeFiles/Jeu_Video_dvlp.dir/texturemanager.cpp.o


# Object files for target Jeu_Video_dvlp
Jeu_Video_dvlp_OBJECTS = \
"CMakeFiles/Jeu_Video_dvlp.dir/main.cpp.o" \
"CMakeFiles/Jeu_Video_dvlp.dir/game.cpp.o" \
"CMakeFiles/Jeu_Video_dvlp.dir/menustate.cpp.o" \
"CMakeFiles/Jeu_Video_dvlp.dir/optionstate.cpp.o" \
"CMakeFiles/Jeu_Video_dvlp.dir/instructionstate.cpp.o" \
"CMakeFiles/Jeu_Video_dvlp.dir/introstate.cpp.o" \
"CMakeFiles/Jeu_Video_dvlp.dir/deadstate.cpp.o" \
"CMakeFiles/Jeu_Video_dvlp.dir/stage1state.cpp.o" \
"CMakeFiles/Jeu_Video_dvlp.dir/texturemanager.cpp.o"

# External object files for target Jeu_Video_dvlp
Jeu_Video_dvlp_EXTERNAL_OBJECTS =

Jeu_Video_dvlp: CMakeFiles/Jeu_Video_dvlp.dir/main.cpp.o
Jeu_Video_dvlp: CMakeFiles/Jeu_Video_dvlp.dir/game.cpp.o
Jeu_Video_dvlp: CMakeFiles/Jeu_Video_dvlp.dir/menustate.cpp.o
Jeu_Video_dvlp: CMakeFiles/Jeu_Video_dvlp.dir/optionstate.cpp.o
Jeu_Video_dvlp: CMakeFiles/Jeu_Video_dvlp.dir/instructionstate.cpp.o
Jeu_Video_dvlp: CMakeFiles/Jeu_Video_dvlp.dir/introstate.cpp.o
Jeu_Video_dvlp: CMakeFiles/Jeu_Video_dvlp.dir/deadstate.cpp.o
Jeu_Video_dvlp: CMakeFiles/Jeu_Video_dvlp.dir/stage1state.cpp.o
Jeu_Video_dvlp: CMakeFiles/Jeu_Video_dvlp.dir/texturemanager.cpp.o
Jeu_Video_dvlp: CMakeFiles/Jeu_Video_dvlp.dir/build.make
Jeu_Video_dvlp: /usr/local/lib/libSDL2main.a
Jeu_Video_dvlp: /usr/local/lib/libSDL2.dylib
Jeu_Video_dvlp: /usr/local/lib/libSDL2_image.dylib
Jeu_Video_dvlp: /usr/local/lib/libSDL2_ttf.dylib
Jeu_Video_dvlp: /usr/local/lib/libSDL2_mixer.dylib
Jeu_Video_dvlp: CMakeFiles/Jeu_Video_dvlp.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/paul/Documents/ISBS/ISBS3/c++/dvlp_projet_jeu/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Linking CXX executable Jeu_Video_dvlp"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Jeu_Video_dvlp.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Jeu_Video_dvlp.dir/build: Jeu_Video_dvlp

.PHONY : CMakeFiles/Jeu_Video_dvlp.dir/build

CMakeFiles/Jeu_Video_dvlp.dir/requires: CMakeFiles/Jeu_Video_dvlp.dir/main.cpp.o.requires
CMakeFiles/Jeu_Video_dvlp.dir/requires: CMakeFiles/Jeu_Video_dvlp.dir/game.cpp.o.requires
CMakeFiles/Jeu_Video_dvlp.dir/requires: CMakeFiles/Jeu_Video_dvlp.dir/menustate.cpp.o.requires
CMakeFiles/Jeu_Video_dvlp.dir/requires: CMakeFiles/Jeu_Video_dvlp.dir/optionstate.cpp.o.requires
CMakeFiles/Jeu_Video_dvlp.dir/requires: CMakeFiles/Jeu_Video_dvlp.dir/instructionstate.cpp.o.requires
CMakeFiles/Jeu_Video_dvlp.dir/requires: CMakeFiles/Jeu_Video_dvlp.dir/introstate.cpp.o.requires
CMakeFiles/Jeu_Video_dvlp.dir/requires: CMakeFiles/Jeu_Video_dvlp.dir/deadstate.cpp.o.requires
CMakeFiles/Jeu_Video_dvlp.dir/requires: CMakeFiles/Jeu_Video_dvlp.dir/stage1state.cpp.o.requires
CMakeFiles/Jeu_Video_dvlp.dir/requires: CMakeFiles/Jeu_Video_dvlp.dir/texturemanager.cpp.o.requires

.PHONY : CMakeFiles/Jeu_Video_dvlp.dir/requires

CMakeFiles/Jeu_Video_dvlp.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Jeu_Video_dvlp.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Jeu_Video_dvlp.dir/clean

CMakeFiles/Jeu_Video_dvlp.dir/depend:
	cd /Users/paul/Documents/ISBS/ISBS3/c++/dvlp_projet_jeu/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/paul/Documents/ISBS/ISBS3/c++/dvlp_projet_jeu/src /Users/paul/Documents/ISBS/ISBS3/c++/dvlp_projet_jeu/src /Users/paul/Documents/ISBS/ISBS3/c++/dvlp_projet_jeu/build /Users/paul/Documents/ISBS/ISBS3/c++/dvlp_projet_jeu/build /Users/paul/Documents/ISBS/ISBS3/c++/dvlp_projet_jeu/build/CMakeFiles/Jeu_Video_dvlp.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Jeu_Video_dvlp.dir/depend

