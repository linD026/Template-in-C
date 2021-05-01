#include <stdio.h>
#include <stdint.h>

#include "template.h"

template_list2(test, const char *string, int16_t, int32_t, printf("hello\n");)


int main (void) {
    int16_t i16 = 16;
    int32_t i32 = 32;
    int64_t i64 = 64;
    template_call(int16_t, test, i16, "int 16");
    template_call(int32_t, test, i32, "int 32");
    //template_call(int64_t, test, i64, "int 64");

    printf("%d\n", VA_EXTRACT_3(0, 1, 2, 3));
}