Make sure you have CMake installed (modify `cmake_minimum_required` if needed) before proceeding.

To run the tests:

```shell
$ cmake -S . -B build
$ cmake --build build
$ cd build
$ ctest
```