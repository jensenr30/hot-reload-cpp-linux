#include <stdio.h>

// 'extern "C"' prevents the C++ compiler from mangling the name of this function
// this allows the main program to look-up this function's address by name
extern "C"
int dynamic_library_function(void) {
    printf("Hello from %s()\n", __func__);
    return 7;
}
