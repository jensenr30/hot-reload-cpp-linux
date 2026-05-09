# Hot-Reloading C++ on Linux
A simple program demonstrating hot-reloading C++ code on linux.

Check out [dynamic-link-cpp-linux](https://github.com/jensenr30/dynamic-link-cpp-linux) to see a simpler program demonstrating dynamic linking only.


## Build and Run
```
make run
```


## Inspect the dynamic lib's symbols
```
readelf -s -W dynamic-lib.so
```


## Recommended Reading
- https://lwn.net/Articles/961117/
