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

#define t_node(return_type, name, type, parameter)                             \
  t_node_(return_type, name, type, parameter)
#define t_node_(return_type, name, type, parameter)                            \
  struct __t_node_##name_##type {                                              \
    type __dummy;                                                              \
    return_type (*func)(type * arg, parameter);                                \
  }

#define t_node_func(return_type, type, name, parameter)                        \
  t_node_func_(return_type, type, name, parameter)
#define t_node_func_(return_type, type, name, parameter)                       \
  return_type t_##name_##type(type *arg, parameter)

#define t_node_declaration(type) t_node_declaration_(type)
#define t_node_declaration_(type0) type_##type0

#define t_node_func_declaration(name, type) t_node_func_declaration_(name, type)
#define t_node_func_declaration_(name, type) t_##name_##type

#define template_function(return_type, type, name, parameter, ...)             \
  template_function_(return_type, type, name, parameter, __VA_ARGS__)
#define template_function_(return_type, type, name, parameter, ...)            \
  return_type t_##name_##type(type *arg, parameter) {                          \
    typedef type T;                                                            \
    { __VA_ARGS__ }                                                            \
  }

#define template_list(return_type, name, parameter, ...)                       \
  t_node_func(return_type, VA_EXTRACT_0(__VA_ARGS__), name, parameter);        \
  t_node_func(return_type, VA_EXTRACT_1(__VA_ARGS__), name, parameter);        \
  struct __template_list_##name {                                              \
    t_node(return_type, name, VA_EXTRACT_0(__VA_ARGS__), parameter)            \
        t_node_declaration(VA_EXTRACT_0(__VA_ARGS__));                         \
    t_node(return_type, name, VA_EXTRACT_1(__VA_ARGS__), parameter)            \
        t_node_declaration(VA_EXTRACT_1(__VA_ARGS__));                         \
  } type_list_##name = {                                                       \
      .t_node_declaration(VA_EXTRACT_0(__VA_ARGS__)).func =                    \
          t_node_func_declaration(name, VA_EXTRACT_0(__VA_ARGS__)),            \
      .t_node_declaration(VA_EXTRACT_1(__VA_ARGS__)).func =                    \
          t_node_func_declaration(name, VA_EXTRACT_1(__VA_ARGS__))};           \
  template_function(return_type, VA_EXTRACT_0(__VA_ARGS__), name, parameter,   \
                    VA_REMAIN_1(__VA_ARGS__))                                  \
      template_function(return_type, VA_EXTRACT_1(__VA_ARGS__), name,          \
                        parameter, VA_REMAIN_1(__VA_ARGS__))

#define template_list2(return_type, name, parameter, ...)                      \
  t_node_func(return_type, VA_EXTRACT_0(__VA_ARGS__), name, parameter);        \
  t_node_func(return_type, VA_EXTRACT_1(__VA_ARGS__), name, parameter);        \
  struct __template_list_##name {                                              \
    t_node(return_type, name, VA_EXTRACT_0(__VA_ARGS__), parameter)            \
        t_node_declaration(VA_EXTRACT_0(__VA_ARGS__));                         \
    t_node(return_type, name, VA_EXTRACT_1(__VA_ARGS__), parameter)            \
        t_node_declaration(VA_EXTRACT_1(__VA_ARGS__));                         \
  } type_list_##name = {                                                       \
      .t_node_declaration(VA_EXTRACT_0(__VA_ARGS__)).func =                    \
          t_node_func_declaration(name, VA_EXTRACT_0(__VA_ARGS__)),            \
      .t_node_declaration(VA_EXTRACT_1(__VA_ARGS__)).func =                    \
          t_node_func_declaration(name, VA_EXTRACT_1(__VA_ARGS__))};           \
  template_function(return_type, VA_EXTRACT_0(__VA_ARGS__), name, parameter,   \
                    VA_REMAIN_1(__VA_ARGS__))                                  \
      template_function(return_type, VA_EXTRACT_1(__VA_ARGS__), name,          \
                        parameter, VA_REMAIN_1(__VA_ARGS__))

#define template_list3(return_type, name, parameter, ...)                      \
  t_node_func(return_type, VA_EXTRACT_0(__VA_ARGS__), name, parameter);        \
  t_node_func(return_type, VA_EXTRACT_1(__VA_ARGS__), name, parameter);        \
  t_node_func(return_type, VA_EXTRACT_2(__VA_ARGS__), name, parameter);        \
  struct __template_list_##name {                                              \
    t_node(return_type, name, VA_EXTRACT_0(__VA_ARGS__), parameter)            \
        t_node_declaration(VA_EXTRACT_0(__VA_ARGS__));                         \
    t_node(return_type, name, VA_EXTRACT_1(__VA_ARGS__), parameter)            \
        t_node_declaration(VA_EXTRACT_1(__VA_ARGS__));                         \
    t_node(return_type, name, VA_EXTRACT_2(__VA_ARGS__), parameter)            \
        t_node_declaration(VA_EXTRACT_2(__VA_ARGS__));                         \
  } type_list_##name = {                                                       \
      .t_node_declaration(VA_EXTRACT_0(__VA_ARGS__)).func =                    \
          t_node_func_declaration(name, VA_EXTRACT_0(__VA_ARGS__)),            \
      .t_node_declaration(VA_EXTRACT_1(__VA_ARGS__)).func =                    \
          t_node_func_declaration(name, VA_EXTRACT_1(__VA_ARGS__)),            \
      .t_node_declaration(VA_EXTRACT_2(__VA_ARGS__)).func =                    \
          t_node_func_declaration(name, VA_EXTRACT_2(__VA_ARGS__)),            \
  };                                                                           \
  template_function(return_type, VA_EXTRACT_0(__VA_ARGS__), name, parameter,   \
                    VA_REMAIN_2(__VA_ARGS__))                                  \
      template_function(return_type, VA_EXTRACT_1(__VA_ARGS__), name,          \
                        parameter, VA_REMAIN_2(__VA_ARGS__))                   \
          template_function(return_type, VA_EXTRACT_2(__VA_ARGS__), name,      \
                            parameter, VA_REMAIN_2(__VA_ARGS__))

#define template_call(type, name, arg, parameter)                              \
  type_list_##name.type_##type.func(&arg, parameter);
#endif