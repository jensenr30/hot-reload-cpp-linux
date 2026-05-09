#include <cstdint>
#include <cstdlib>
#include <stdio.h>

#include "dynamic_lib_context.hpp"

static ListItem *alloc_new_list_item() {
    ListItem *ptr = new ListItem;
    if (!ptr)
    {
        printf("failed to alloc\n");
        quick_exit(66);
    }
    ptr->value = INT32_MIN;
    return ptr;
}

// 'extern "C"' prevents the C++ compiler from mangling the name of this function
// this allows the main program to look-up this function's address by name
extern "C"
int dynamic_library_function(DynamicLibContext *ctx)
{
    printf("Hello from %s()\n", __func__);

    if (!ctx->list)
    {
        ctx->list = alloc_new_list_item();
        ctx->list->value = 0;
    }

    printf("List:\n");
    ListItem *last_valid_list_item = ctx->list;
    int last_value = INT32_MIN;
    ListItem *ptr = ctx->list;
    while(ptr)
    {
        printf("%d  ", ptr->value);
        last_value = ptr->value;
        last_valid_list_item = ptr;
        ptr = ptr->next;
    }

    last_valid_list_item->next = alloc_new_list_item();
    last_valid_list_item->next->value = last_value++;

    return 5;
}
