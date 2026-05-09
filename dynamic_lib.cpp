#include <cstdint>
#include <cstdlib>
#include <stdio.h>

#include "dynamic_lib_context.hpp"

static ListItem *alloc_new_list_item()
{
    ListItem *ptr = new ListItem;
    if (!ptr)
    {
        printf("failed to alloc\n");
        quick_exit(66);
    }
    ptr->value = INT32_MIN;
    ptr->next = NULL;
    return ptr;
}

static const int array_len = 10;
static int array[array_len];

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
    int last_value = -600;
    ListItem *ptr = ctx->list;
    while(1)
    {
        printf("%d  ", ptr->value);
        last_value = ptr->value;
        if (ptr->next == NULL) {
            ptr->next = alloc_new_list_item();
            ptr->next->value = ptr->value + 1;
            printf("%d  ", ptr->next->value);
            break;
        }
        ptr = ptr->next;
    }
    printf("\n");


    ctx->index++;
    ctx->index = ctx->index % array_len;
    array[ctx->index]++;

    printf("Array: \n");
    for (int i = 0; i < array_len; i++) {
        printf("%10d  ", array[i]);
    }
    printf("\n");

    return 9;
}
