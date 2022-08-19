# ESP-IDF in C++: Hello World + Led Blink!

## Led Blink is a component class called Gpio programmed in C++. 

The project **Hello World** contains one source file in C++ language [main.cpp](./core/src/main.cpp) and one header file [main.h](./core/include/main.h). The files are located in the folder [core](./core).

It also has a component called Gpio inside the application module, this component controls the Led Blink, you can see more details here: [Gpio.cpp](./application/Gpio/Gpio.cpp) and one header file [Gpio.h](./application/Gpio/Gpio.h).


ESP-IDF projects are built using CMake. The project build configuration is contained in `CMakeLists.txt`
files that provide set of directives and instructions describing the project's source files and targets
(executable, library, or both).

Below is short explanation of remaining files in the project folder.

```
//=====================================================================================\\
//***************************         Project Structure        ************************\\
//=====================================================================================\\
/**
 * @file main.cpp
 * @author FMFigueroa (felixmanuelfigueroa@gmail.com)
 * @brief ESP-IDF in CPP: Hello World + Blink Led!
 * @version 0.1
 * @date 2022-08-17
 *
 * @copyright Copyright (c) 2022
 */
//=====================================================================================\\
│
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
│   │── Gpio
│   │    │── Gpio.h
│   │    └── Gpio.cpp
│   │
│   └── CMakeLists.txt  
│
└── README.md                  This is the file you are currently reading
```

Additionally, the Hello World project contains Makefile and component.mk files, used for the legacy Make based build system.
They are not used or needed when building with CMake and idf.py.
