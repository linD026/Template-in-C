# Template-in-C
---
## support
This project(template) only can be use on function.
And its only can be **two** or **three** different type.

## How to get
It is only one header, so just include it.
```
#include "template.h"
```

## How to use
For declaring different type of the function
```
template_list2(function_name, parameter, type_1, type_2,
  function_content
)

template_list3(function_name, parameter, type_1, type_2, type3,
  function_content
)
```

For calling the function:
```
  template_call(type_you_declared, function_name, T_parameter, parameter);
```

## Example
```cpp
#include <stdio.h>

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
    int a = arg->integer, b = 11;
    for (int i = 0;i < a;i++) {
        printf("a %d\n", i);
    }
    T in = {.integer = 1};
    printf("%d\n", in.integer);
    printf("%ld %s %d\n", sizeof(T), arg->string, a);
)

int main(void) {
    struct_test s = {.integer = 5, .floating = 2, .string = "struct_test"};
    template_call(struct_test, test, s, s.integer);
    struct_test1 s1 = {.integer = 10, .string = "struct_test1"};
    template_call(struct_test1, test, s1, s1.integer);
}
```


* Using the `T`, the name of type, when you want to declare the variable which is the type of `template_list` and `template_call` declarated.  
* The template function already has the variable with `arg` name to receive the variable from `T_parameter`. 
* Its cannot send the variable like `3` into the `T_parameter`, you need to declare the object before you send it.
