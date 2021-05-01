#include <stdio.h>
#include <stdint.h>

#include "template.h"

typedef struct {
    int integer;
    const char* string;
    double floating;
} struct_test;

typedef struct {
    int integer;
    const char* string;
    double floating;
    int dummy;
} struct_test1;

typedef struct {
    int integer;
    const char* string;
    double floating;
    int dummy;
} struct_test2;

template_list3(test, int a, struct_test, struct_test1, struct_test2,
    int a = 10, b = 11;
    for (int i = 0;i < a;i++) {
        printf("a %d\n", i);
    }
    printf("%ld %s %d\n", sizeof(T), arg->string, a);
)

int main(void) {
    struct_test s = {.integer = 2, .floating = 2, .string = "struct_test"};
    template_call(struct_test, test, s, s.integer);
}