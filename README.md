# ESP-IDF in CPP: Hello World + Blink Led!

The project **Hello World** contains one source file in C++ language [main.cpp](./core/src/main.cpp) and one header file [main.h](./core/include/main.h). The files are located in the folder [core](./core).

ESP-IDF projects are built using CMake. The project build configuration is contained in `CMakeLists.txt`
files that provide set of directives and instructions describing the project's source files and targets
(executable, library, or both).

Below is short explanation of remaining files in the project folder.

```
├── CMakeLists.txt
├── core
│   │── include
│   │   └── main.h
│   │── src
│   │   └── main.cpp
│   │
│   └── CMakeLists.txt
│
├── application
│   └── gipio
│       │── gpio.h
│       └── gpio.cpp  
│
└── README.md                  This is the file you are currently reading
```

Additionally, the Hello World project contains Makefile and component.mk files, used for the legacy Make based build system.
They are not used or needed when building with CMake and idf.py.
