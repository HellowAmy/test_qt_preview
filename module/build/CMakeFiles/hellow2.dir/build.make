# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/cong/open/test_qt/test_qt_preview/module

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/cong/open/test_qt/test_qt_preview/module/build

# Include any dependencies generated for this target.
include CMakeFiles/hellow2.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/hellow2.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/hellow2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/hellow2.dir/flags.make

CMakeFiles/hellow2.dir/hellow2_autogen/mocs_compilation.o: CMakeFiles/hellow2.dir/flags.make
CMakeFiles/hellow2.dir/hellow2_autogen/mocs_compilation.o: hellow2_autogen/mocs_compilation.cpp
CMakeFiles/hellow2.dir/hellow2_autogen/mocs_compilation.o: CMakeFiles/hellow2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cong/open/test_qt/test_qt_preview/module/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/hellow2.dir/hellow2_autogen/mocs_compilation.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/hellow2.dir/hellow2_autogen/mocs_compilation.o -MF CMakeFiles/hellow2.dir/hellow2_autogen/mocs_compilation.o.d -o CMakeFiles/hellow2.dir/hellow2_autogen/mocs_compilation.o -c /home/cong/open/test_qt/test_qt_preview/module/build/hellow2_autogen/mocs_compilation.cpp

CMakeFiles/hellow2.dir/hellow2_autogen/mocs_compilation.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hellow2.dir/hellow2_autogen/mocs_compilation.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cong/open/test_qt/test_qt_preview/module/build/hellow2_autogen/mocs_compilation.cpp > CMakeFiles/hellow2.dir/hellow2_autogen/mocs_compilation.i

CMakeFiles/hellow2.dir/hellow2_autogen/mocs_compilation.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hellow2.dir/hellow2_autogen/mocs_compilation.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cong/open/test_qt/test_qt_preview/module/build/hellow2_autogen/mocs_compilation.cpp -o CMakeFiles/hellow2.dir/hellow2_autogen/mocs_compilation.s

CMakeFiles/hellow2.dir/src/test_dig/wid_preview_wid.o: CMakeFiles/hellow2.dir/flags.make
CMakeFiles/hellow2.dir/src/test_dig/wid_preview_wid.o: ../src/test_dig/wid_preview_wid.cpp
CMakeFiles/hellow2.dir/src/test_dig/wid_preview_wid.o: CMakeFiles/hellow2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cong/open/test_qt/test_qt_preview/module/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/hellow2.dir/src/test_dig/wid_preview_wid.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/hellow2.dir/src/test_dig/wid_preview_wid.o -MF CMakeFiles/hellow2.dir/src/test_dig/wid_preview_wid.o.d -o CMakeFiles/hellow2.dir/src/test_dig/wid_preview_wid.o -c /home/cong/open/test_qt/test_qt_preview/module/src/test_dig/wid_preview_wid.cpp

CMakeFiles/hellow2.dir/src/test_dig/wid_preview_wid.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hellow2.dir/src/test_dig/wid_preview_wid.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cong/open/test_qt/test_qt_preview/module/src/test_dig/wid_preview_wid.cpp > CMakeFiles/hellow2.dir/src/test_dig/wid_preview_wid.i

CMakeFiles/hellow2.dir/src/test_dig/wid_preview_wid.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hellow2.dir/src/test_dig/wid_preview_wid.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cong/open/test_qt/test_qt_preview/module/src/test_dig/wid_preview_wid.cpp -o CMakeFiles/hellow2.dir/src/test_dig/wid_preview_wid.s

# Object files for target hellow2
hellow2_OBJECTS = \
"CMakeFiles/hellow2.dir/hellow2_autogen/mocs_compilation.o" \
"CMakeFiles/hellow2.dir/src/test_dig/wid_preview_wid.o"

# External object files for target hellow2
hellow2_EXTERNAL_OBJECTS =

../lib/libhellow2.so: CMakeFiles/hellow2.dir/hellow2_autogen/mocs_compilation.o
../lib/libhellow2.so: CMakeFiles/hellow2.dir/src/test_dig/wid_preview_wid.o
../lib/libhellow2.so: CMakeFiles/hellow2.dir/build.make
../lib/libhellow2.so: /opt/qt5.15.13/lib/libQt5Widgets.so.5.15.13
../lib/libhellow2.so: /opt/qt5.15.13/lib/libQt5Gui.so.5.15.13
../lib/libhellow2.so: /opt/qt5.15.13/lib/libQt5Core.so.5.15.13
../lib/libhellow2.so: CMakeFiles/hellow2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/cong/open/test_qt/test_qt_preview/module/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX shared library ../lib/libhellow2.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/hellow2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/hellow2.dir/build: ../lib/libhellow2.so
.PHONY : CMakeFiles/hellow2.dir/build

CMakeFiles/hellow2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/hellow2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/hellow2.dir/clean

CMakeFiles/hellow2.dir/depend:
	cd /home/cong/open/test_qt/test_qt_preview/module/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/cong/open/test_qt/test_qt_preview/module /home/cong/open/test_qt/test_qt_preview/module /home/cong/open/test_qt/test_qt_preview/module/build /home/cong/open/test_qt/test_qt_preview/module/build /home/cong/open/test_qt/test_qt_preview/module/build/CMakeFiles/hellow2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/hellow2.dir/depend

