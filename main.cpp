#include <stdio.h>
#include <dlfcn.h>

int main()
{
    printf("Hello from %s()\n", __func__);
    // Attempt to load the dynamic library file
    const char *lib_file = "./dynamic-lib.so";
    void *lib_handle = dlopen(lib_file, RTLD_NOW);

    if (lib_handle == NULL)
    {
        fprintf(stderr, "%s\n", dlerror());
        fprintf(stderr, "Failed to open %s\n", lib_file);
        return 1;
    }

    // Attempt to find the address of the function provided by the dynamic library
    const char *lib_func_name = "dynamic_library_function";
    void *pointer = dlsym(lib_handle, lib_func_name);

    if (pointer == NULL)
    {
        fprintf(stderr, "%s\n", dlerror());
        fprintf(stderr, "Failed to obtain pointer to function: %s\n", lib_func_name);
        return 2;
    }

    // Cast the void-pointer into function-pointer so we can call the function at which it points.
    // NOTE: the function-pointer signature MUST match the function signature in the dynamic library
    int (*pointer_to_dynamically_loaded_function)(void) = (int (*)(void))pointer;

    // call the function we dynamically loaded
    int result = pointer_to_dynamically_loaded_function();

    printf("The dynamically loaded function returned %d\n", result);

    int err = dlclose(lib_handle);
    if (err) {
        fprintf(stderr, "%s\n", dlerror());
        fprintf(stderr, "Failed to unload dynamic lib\n");
        return 3;
    }
    return 0;
}
