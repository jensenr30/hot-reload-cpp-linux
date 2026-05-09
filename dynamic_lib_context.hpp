#ifndef CONTEXT_HPP
#define CONTEXT_HPP

struct ListItem {
    int value;
    struct ListItem *next;
};

// a struct containing ALL the data and pointers to data to be used by the dynamic library
struct DynamicLibContext {
    ListItem *list;
};

#endif /* CONTEXT_HPP */
