# Hot-Reloading C++ on Linux
A simple program demonstrating hot-reloading C++ code on linux.

## Build and Run
```
make run
```

While the program is running, try editing `dynamic-lib.cpp` and see what happens


## Inspect the dynamic lib's symbols
```
readelf -s -W dynamic-lib.so
```


## Recommended Reading
- https://lwn.net/Articles/961117/
