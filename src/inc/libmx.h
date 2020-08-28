#pragma once

#include <stddef.h>
#include <stdbool.h>
#include <wchar.h>
#include <dirent.h>

typedef struct s_list {
    void *data;
    struct s_list *next;
}              t_list;

typedef struct s_fd_node {
    int fd;
    int buff_len;
    char *last_buff;
    int last_delim_index;
}              t_fd_node;

// Utils pack
//
void mx_printchar(char c);
void mx_print_unicode(wchar_t c);
void mx_printstr(const char *s);
void mx_printline(const char *s);
int mx_out_fd(int new_value);
void mx_printbool(bool value);
void mx_print_strarr(char **arr, const char *delim);
void mx_printint(int n);
double mx_pow(double n, unsigned int pow);
int mx_sqrt(int x);
char *mx_nbr_to_hex(unsigned long nbr);
unsigned long mx_hex_to_nbr(const char *hex);
char *mx_itoa(int number);
void mx_foreach(int *arr, int size, void(*f)(int));
int mx_binary_search(char **arr, int size, const char *s, int *count);
int mx_bubble_sort(char **arr, int size);
int mx_quicksort(char **arr, int left, int right);

// String pack
//
int mx_strlen(const char *s);
void mx_swap_char(char *s1, char *s2);
void mx_str_reverse(char *s);
void mx_strdel(char **str);
void mx_del_strarr(char ***arr);
int mx_get_char_index(const char *str, char c);
char *mx_strndup(const char *str, size_t n);
char *mx_strdup(const char *str);
char *mx_strndup(const char *str, size_t n);
char *mx_strcpy(char *dst, const char *src);
char *mx_strncpy(char *dst, const char *src, int len);
int mx_strcmp(const char *s1, const char *s2);
int mx_strncmp(const char *s1, const char *s2, size_t n);
char *mx_strcat(char *restrict s1, const char *restrict s2);
int mx_count_substr(const char *str, const char *sub);
char *mx_strstr(const char *haystack, const char *needle);
int mx_get_substr_index(const char *str, const char *sub);
int mx_count_words(const char *str, char c);
char *mx_strnew(const int size);
char *mx_strtrim(const char *str);
char *mx_del_extra_spaces(const char *str);
char **mx_strsplit(const char *s, char c);
char *mx_strjoin(const char *s1, const char *s2);
char *mx_file_to_str(const char *file);
int mx_read_line(char **lineptr, size_t buf_size, char delim, const int fd);
t_fd_node *mx_add_fd_data(t_list **list, int fd, int buff_len);
void mx_remove_fd_node(t_list **list, t_fd_node *node);
char *mx_replace_substr(const char *str, const char *sub, const char *replace);
bool mx_isdigit(int c);
bool mx_isspace(int c);
bool mx_isalpha(int c);

// Memory pack
//
void *mx_memset(void *b, int c, size_t len);
void *mx_memcpy(void *restrict dst, const void *restrict src, size_t n);
void *
mx_memccpy(void *restrict dst, const void *restrict src, int c, size_t n);
int mx_memcmp(const void *s1, const void *s2, size_t n);
void *mx_memchr(const void *s, int c, size_t n);
void *mx_memrchr(const void *s, int c, size_t n);
void *mx_memmem(const void *big, size_t big_len, const void *little,
                size_t little_len);
void *mx_memmove(void *dst, const void *src, size_t len);
void *mx_realloc(void *ptr, size_t size);

// List
//
t_list *mx_create_node(void *data);
void mx_push_front(t_list **list, void *data);
void mx_push_back(t_list **list, void *data);
void mx_pop_front(t_list **list);
void mx_pop_back(t_list **list);
int mx_list_size(t_list *list);
t_list *mx_sort_list(t_list *list, bool(*cmp)(void *a, void *b));
t_list *mx_find_node(t_list *list, void *data,
                     bool(*is_equal)(void *data_1, void *data_2));
void mx_foreach_list(t_list *list, void(*f)(t_list *node));
t_list *mx_listdup(t_list *list, void *(*copy)(void *data));
void *mx_list_data_at(t_list *list, int index);
void mx_list_delete(t_list *list);
void mx_list_attach_back(t_list **list_head, t_list *list_tail);

// Files
//
int
mx_scandir(const char *dirname, struct dirent ***namelist,
           int (*select)(const struct dirent *),
           int (*compar)(const struct dirent **, const struct dirent **));
int mx_alphasort(const struct dirent **d1, const struct dirent **d2);
int mx_select_exclude_dot_dirs(const struct dirent *dirent);
