# Template-in-C
---
## support

This project( template ) only can be use on function.

And its only can be **two** or **three** different types.

## How to get
It is only one header, so just include it.
```cpp
#include "template.h"
```

## How to use
For declaring different type of the function
```cpp
template_list2(function_type, function_name, parameter, type_1, type_2,
  function_content
)
```
```cpp
template_list3(function_type, function_name, parameter, type_1, type_2, type3,
  function_content
)
```

For calling the function:
```cpp
template_call(type_you_declared, function_name, T_parameter, parameter);
```

## Example
```cpp
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

template_list3(int, test, void *d[], struct_test, struct_test1, struct_test2,
    int a = *(int *)d[1];
    int b = *(int *)d[0], c = 11;
    printf("a %d, b %d\n", a, b);
    for (int i = 0;i < c;i++) {
        printf("%d\n", i);
    }
    T in = {.integer = 1};
    printf("%d\n", in.integer);
    printf("%ld %s %d %d\n", sizeof(T), args->string, a, b);
    return c;
)

int main(void) {
    struct_test s = {.integer = 5, .floating = 2, .string = "struct_test"};
    struct_test1 s1 = {.integer = 10, .string = "struct_test1"};
    void *list[2] = {&s.integer, &s1.integer};
    template_call(struct_test, test, &s, list);
    int get = template_call(struct_test1, test, &s1, list);
    printf("%d\n", get);
    
}
```

* Using the `T`, the name of type, when you want to declare the variable which is the type of `template_list` and `template_call` declarated.  
* The template function already has the variable with `args` name to receive the variable from `T_parameter`. 
* Its cannot send the variable like `3` into the `T_parameter`, you need to declare the object before you send it.
