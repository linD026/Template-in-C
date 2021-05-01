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

* Using the `T`, the name of type, when you want to declare the variable which is the type of `template_list` and `template_call` declarated.  
* The template function already has the variable with `arg` name to receive the variable from `T_parameter`. 
* Its cannot send the variable like `3` into the `T_parameter`, you need to declare the object before you send it.
