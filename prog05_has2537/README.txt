This program module will run UTPodDriver.cpp Song.cpp UTPod.cpp with functions from UTPod.h and Song.h

The program serves like an IPod system and the purpose is to run the main file which is UTPodDriver.cpp.
This IPod can add songs, remove songs, shuffle, sort, display songs and reveal memory usage just like an apple IPod.

*ALL COMPILATION AND RUN INSTRUCTIONS FOR LINUX TERMINAL WITH GCC COMPILER INSTALLED*

To compile:

- enter
  g++ -std=c++11 -o UTPod  UTPodDriver.cpp UTPod.cpp Song.cpp

  in linux terminal.

- or simply enter "make" with no arguments or quotation marks.

This will compile c program into an executable name UTPod

To run:

- Enter "./UTPod <name_of_file>" without quotes in terminal. name_of_file will be the name of whatever file
represents the picture in the directory.
