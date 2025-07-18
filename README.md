# Simple Fractals

A program to create interactable fractals in real-time, built in C++ using the SFML library.

The fractals themselves are generated by re-projecting the applications screen onto smaller, virtual, translucent sub-screens which can be translated, rotated and scaled by a user. When these sub-screens overlap, they become superimposed; this effect then recurses down the series of sub-screens, generating fractals without any taxing computation!

I created this after seeing a Youtube video from the channel CodeParade (see <a href="https://www.youtube.com/watch?v=Pv26QAOcb6Q&t=0s" target="_blank">here</a>) in which he uses a webcam to record the screen. I couldn't be bothered setting up a webcam, so I instead created this app as a means of learning the basics of SFML.

## Controls
- <kbd>Space</kbd> Add new sub-screen at mouse position
- <kbd>Left Mouse (Hold)</kbd> Click and drag sub-screens
- <kbd>Right Mouse</kbd> Delete hovered sub-screen
- <kbd>Scroll</kbd> Rotate hovered sub-screen
- <kbd>Shift</kbd> + <kbd>Scroll</kbd>  Scale hovered sub-screen
- <kbd>Esc</kbd> Close the program

## Development Setup

> Note: This project has been built from the [CMake SFML Project Template](https://github.com/SFML/cmake-sfml-project) and has been made with cross-OS compatability in mind. The following instructions have been modified slightly from the template repo's setup guide...

1. Install [Git](https://git-scm.com/downloads) and [CMake](https://cmake.org/download/). Use your system's package manager if available.
2. If you use Linux, install SFML's dependencies using your system package manager. On Ubuntu and other Debian-based distributions you can use the following commands:
   ```
   sudo apt update
   sudo apt install \
       libxrandr-dev \
       libxcursor-dev \
       libxi-dev \
       libudev-dev \
       libfreetype-dev \
       libflac-dev \
       libvorbis-dev \
       libgl1-mesa-dev \
       libegl1-mesa-dev \
       libfreetype-dev
   ```
3. Configure and build your project. Most popular IDEs support CMake projects with very little effort on your part.

   - [VS Code](https://code.visualstudio.com) via the [CMake extension](https://code.visualstudio.com/docs/cpp/cmake-linux)
   - [Visual Studio](https://docs.microsoft.com/en-us/cpp/build/cmake-projects-in-visual-studio?view=msvc-170)
   - [CLion](https://www.jetbrains.com/clion/features/cmake-support.html)
   - [Qt Creator](https://doc.qt.io/qtcreator/creator-project-cmake.html)

   Using CMake from the command line is straightforward as well.
   Be sure to run these commands in the root directory of the project you just created.

   ```
   cmake -B build
   cmake --build build
   ```

4. Enjoy!

## But I want to...

### Upgrade SFML

SFML is found via CMake's [FetchContent](https://cmake.org/cmake/help/latest/module/FetchContent.html) module.
FetchContent automatically downloads SFML from GitHub and builds it alongside your own code.
Beyond the convenience of not having to install SFML yourself, this ensures ABI compatibility and simplifies things like specifying static versus shared libraries.

Modifying what version of SFML you want is as easy as changing the `GIT_TAG` argument.
Currently it uses SFML 3 via the `3.0.0` tag.

### Change Compilers

See the variety of [`CMAKE_<LANG>_COMPILER`](https://cmake.org/cmake/help/latest/variable/CMAKE_LANG_COMPILER.html) options.
In particular you'll want to modify `CMAKE_CXX_COMPILER` to point to the C++ compiler you wish to use.

### Change Compiler Optimizations

CMake abstracts away specific optimizer flags through the [`CMAKE_BUILD_TYPE`](https://cmake.org/cmake/help/latest/variable/CMAKE_BUILD_TYPE.html) option.
By default this project recommends `Release` builds which enable optimizations.
Other build types include `Debug` builds which enable debug symbols but disable optimizations.
If you're using a multi-configuration generator (as is often the case on Windows), you can modify the [`CMAKE_CONFIGURATION_TYPES`](https://cmake.org/cmake/help/latest/variable/CMAKE_CONFIGURATION_TYPES.html#variable:CMAKE_CONFIGURATION_TYPES) option.

### Change Generators

While CMake will attempt to pick a suitable default generator, some systems offer a number of generators to choose from.
Ubuntu, for example, offers Makefiles and Ninja as two potential options.
For a list of generators, click [here](https://cmake.org/cmake/help/latest/manual/cmake-generators.7.html).
To modify the generator you're using you must reconfigure your project providing a `-G` flag with a value corresponding to the generator you want.
You can't simply modify an entry in the CMakeCache.txt file unlike the above options.
Then you may rebuild your project with this new generator.

## License

The source code is licensed under Public Domain.
