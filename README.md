[![GitHub Streak](https://github-readme-streak-stats.herokuapp.com?user=Mahmuttalemdar&theme=tokyonight)](https://git.io/streak-stats)

# TICTACTOE.AI
![test-clang-format](https://github.com/Mahmuttalemdar/TicTacToe.AI/workflows/test-clang-format/badge.svg)
![Building(CMake)](https://github.com/Mahmuttalemdar/TicTacToe.AI/workflows/Building(CMake)/badge.svg)

TicTacToe game that is implemented with "MiniMax-Alpha Beta Pruning" algorithm and using module based Qt-Qml architecture.

# New Features!

  - Used Qt 5.15.2
  - Added statechart and asynchronus event grab mechanism
  - Designed with Qt static plugin based architecture.
  - Created installer and portable files.
  - Fixed general issues.
  - Deployed mac and windows platforms
  - Added Easy, Medium and Hard game modes.
  - Added game tile size option
  - Added score screen.
  
### Tech

TicTacToeAI uses a number of open source projects to work properly:
* [CMake] - used latest cmake as a project generator.
* [C++ 17] - used modern c++ features!
* [QT 5.15.2] - used latest qt5 framework.

#### Building for source

TicTacToeAI requires [Qt](https://download.qt.io/archive/qt/5.15/5.15.2/) v5.15.2 to run.

Build with cmake with console/terminal for standalone build...

```sh
$ cd TicTacToe.AI
$ mkdir build
$ cd build
$ cmake .. -DQt5_DIR="path/of/qt5/lib/cmake/Qt5" -DDEPLOYMENT_MODE=0
$ make
```

Build with cmake with console/terminal for installer build...

```sh
$ cd TicTacToe.AI
$ mkdir build
$ cd build
$ cmake .. -DQt5_DIR="path/of/qt5/lib/cmake/Qt5" -DDEPLOYMENT_MODE=1
$ make
```


### Todos

 - Create a unit and integrations tests
 - Design pipeline for linux platform

License
----

MIT

**may the force be with you!**
