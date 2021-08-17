/**
 * Template in C - The function templates in C project
 * 
 * It work like function templates of C++, but have some restrictions. Like: 
 * - can only declare one return type
 * - only one parameter, which named arg, with template type T in the function 
 * - only provide two or three different types to declare. 
 * 
 * contributed by linD026
 */
#ifndef __TEMPLATE_H__
#define __TEMPLATE_H__

#define VA_EXTRACT_3(get, ...) VA_EXTRACT_2(__VA_ARGS__)
#define VA_EXTRACT_2(get, ...) VA_EXTRACT_1(__VA_ARGS__)
#define VA_EXTRACT_1(get, ...) VA_EXTRACT_0(__VA_ARGS__)
#define VA_EXTRACT_0(get, ...) get

#define VA_REMAIN_3(not, ...) VA_REMAIN_2(__VA_ARGS__)
#define VA_REMAIN_2(not, ...) VA_REMAIN_1(__VA_ARGS__)
#define VA_REMAIN_1(not, ...) VA_REMAIN_0(__VA_ARGS__)
#define VA_REMAIN_0(not, ...) __VA_ARGS__

#define __template_function(return_type, type, name, parameter, ...)           \
    return_type t_##name_##type(type *args, parameter)                         \
    {                                                                          \
        typedef type T;                                                        \
        {                                                                      \
            __VA_ARGS__                                                        \
        }                                                                      \
    }

#define template_function(return_type, type, name, parameter, ...)             \
    __template_function(return_type, type, name, parameter, __VA_ARGS__)

#define template_list2(return_type, name, parameter, ...)                      \
    template_function(return_type, VA_EXTRACT_0(__VA_ARGS__), name, parameter, \
                      VA_REMAIN_1(__VA_ARGS__))                                \
    template_function(return_type, VA_EXTRACT_1(__VA_ARGS__), name, parameter, \
                      VA_REMAIN_1(__VA_ARGS__))

#define template_list3(return_type, name, parameter, ...)                      \
    template_function(return_type, VA_EXTRACT_0(__VA_ARGS__), name, parameter, \
                      VA_REMAIN_2(__VA_ARGS__))                                \
    template_function(return_type, VA_EXTRACT_1(__VA_ARGS__), name, parameter, \
                      VA_REMAIN_2(__VA_ARGS__))                                \
    template_function(return_type, VA_EXTRACT_2(__VA_ARGS__), name, parameter, \
                      VA_REMAIN_2(__VA_ARGS__))

#define __template_call(type, name, args, parameter)                           \
    t_##name_##type(args, parameter);

#define template_call(type, name, args, parameter)                             \
    __template_call(type, name, args, parameter)
#endif