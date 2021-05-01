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

#define t_node(name, type, parameter) t_node_(name, type, parameter)
#define t_node_(name, type, parameter)                                         \
  struct __t_node_##name_##type {                                              \
    type __dummy;                                                              \
    void (*func)(type * arg, parameter);                                       \
  }

#define t_node_func(type, name, parameter) t_node_func_(type, name, parameter)
#define t_node_func_(type, name, parameter)                                    \
  void t_##name_##type(type *arg, parameter)

#define t_node_declaration(type) t_node_declaration_(type)
#define t_node_declaration_(type0) type_##type0

#define t_node_func_declaration(name, type) t_node_func_declaration_(name, type)
#define t_node_func_declaration_(name, type) t_##name_##type

#define template_function(type, name, parameter, ...)                          \
  template_function_(type, name, parameter, __VA_ARGS__)
#define template_function_(type, name, parameter, ...)                         \
  void t_##name_##type(type *arg, parameter) {                                 \
    typedef type T;                                                            \
    { __VA_ARGS__ }                                                            \
  }

#define template_list(name, parameter, ...)                                    \
  t_node_func(VA_EXTRACT_0(__VA_ARGS__), name, parameter);                     \
  t_node_func(VA_EXTRACT_1(__VA_ARGS__), name, parameter);                     \
  struct __template_list_##name {                                              \
    t_node(name, VA_EXTRACT_0(__VA_ARGS__), parameter)                         \
        t_node_declaration(VA_EXTRACT_0(__VA_ARGS__));                         \
    t_node(name, VA_EXTRACT_1(__VA_ARGS__), parameter)                         \
        t_node_declaration(VA_EXTRACT_1(__VA_ARGS__));                         \
  } type_list_##name = {                                                       \
      .t_node_declaration(VA_EXTRACT_0(__VA_ARGS__)).func =                    \
          t_node_func_declaration(name, VA_EXTRACT_0(__VA_ARGS__)),            \
      .t_node_declaration(VA_EXTRACT_1(__VA_ARGS__)).func =                    \
          t_node_func_declaration(name, VA_EXTRACT_1(__VA_ARGS__))};           \
  template_function(VA_EXTRACT_0(__VA_ARGS__), name, parameter,                \
                    VA_REMAIN_1(__VA_ARGS__))                                  \
      template_function(VA_EXTRACT_1(__VA_ARGS__), name, parameter,            \
                        VA_REMAIN_1(__VA_ARGS__))

#define template_list2(name, parameter, ...)                                   \
  t_node_func(VA_EXTRACT_0(__VA_ARGS__), name, parameter);                     \
  t_node_func(VA_EXTRACT_1(__VA_ARGS__), name, parameter);                     \
  struct __template_list_##name {                                              \
    t_node(name, VA_EXTRACT_0(__VA_ARGS__), parameter)                         \
        t_node_declaration(VA_EXTRACT_0(__VA_ARGS__));                         \
    t_node(name, VA_EXTRACT_1(__VA_ARGS__), parameter)                         \
        t_node_declaration(VA_EXTRACT_1(__VA_ARGS__));                         \
  } type_list_##name = {                                                       \
      .t_node_declaration(VA_EXTRACT_0(__VA_ARGS__)).func =                    \
          t_node_func_declaration(name, VA_EXTRACT_0(__VA_ARGS__)),            \
      .t_node_declaration(VA_EXTRACT_1(__VA_ARGS__)).func =                    \
          t_node_func_declaration(name, VA_EXTRACT_1(__VA_ARGS__))};           \
  template_function(VA_EXTRACT_0(__VA_ARGS__), name, parameter,                \
                    VA_REMAIN_1(__VA_ARGS__))                                  \
      template_function(VA_EXTRACT_1(__VA_ARGS__), name, parameter,            \
                        VA_REMAIN_1(__VA_ARGS__))

#define template_list3(name, parameter, ...)                                   \
  t_node_func(VA_EXTRACT_0(__VA_ARGS__), name, parameter);                     \
  t_node_func(VA_EXTRACT_1(__VA_ARGS__), name, parameter);                     \
  t_node_func(VA_EXTRACT_2(__VA_ARGS__), name, parameter);                     \
  struct __template_list_##name {                                              \
    t_node(name, VA_EXTRACT_0(__VA_ARGS__), parameter)                         \
        t_node_declaration(VA_EXTRACT_0(__VA_ARGS__));                         \
    t_node(name, VA_EXTRACT_1(__VA_ARGS__), parameter)                         \
        t_node_declaration(VA_EXTRACT_1(__VA_ARGS__));                         \
    t_node(name, VA_EXTRACT_2(__VA_ARGS__), parameter)                         \
        t_node_declaration(VA_EXTRACT_2(__VA_ARGS__));                         \
  } type_list_##name = {                                                       \
      .t_node_declaration(VA_EXTRACT_0(__VA_ARGS__)).func =                    \
          t_node_func_declaration(name, VA_EXTRACT_0(__VA_ARGS__)),            \
      .t_node_declaration(VA_EXTRACT_1(__VA_ARGS__)).func =                    \
          t_node_func_declaration(name, VA_EXTRACT_1(__VA_ARGS__)),            \
      .t_node_declaration(VA_EXTRACT_2(__VA_ARGS__)).func =                    \
          t_node_func_declaration(name, VA_EXTRACT_2(__VA_ARGS__)),            \
  };                                                                           \
  template_function(VA_EXTRACT_0(__VA_ARGS__), name, parameter,                \
                    VA_REMAIN_2(__VA_ARGS__))                                  \
      template_function(VA_EXTRACT_1(__VA_ARGS__), name, parameter,            \
                        VA_REMAIN_2(__VA_ARGS__))                              \
          template_function(VA_EXTRACT_2(__VA_ARGS__), name, parameter,        \
                            VA_REMAIN_2(__VA_ARGS__))

#define template_call(type, name, arg, parameter)                              \
  type_list_##name.type_##type.func(&arg, parameter);
#endif