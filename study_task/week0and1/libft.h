#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
void *ft_memmove(void *dest, const void *source, size_t n);
void *ft_memcpy(void *dest, const void *source, size_t n);
int ft_strlen(char *str);
char *ft_strcat(char *dest, char *source);
char *ft_strchr(char *str, char c);
char *ft_strcpy(char *dest, char *src);
char *ft_strdup(char *src);
int	ft_strcmp(char *s1, char *s2);
int	ft_strncmp(char *s1, char *s2, unsigned int n);
char *ft_strncpy(char *dest, char *src, unsigned int n);
char *ft_strstr(char *str, char *to_find);
char *ft_strrchr(char *str, char c);
int	ft_atoi(char *str);
long long ft_abs(int num);
int ft_intlen(int num);
char *ft_itoa(int num);
size_t ft_int_len(int n);
char *ft_itoa2(int n);
int	ft_isalpha(char *str);
int	ft_isdigit(char *str);
int ft_isascii(char ch);
int	ft_isprint(char *str);
char ft_toupper(char c);
char ft_tolower(char c);
void *ft_bzero(void *dest, size_t len);
int ft_strequ(char const *s1, char const *s2);
int ft_strnequ(char const *s1, char const *s2, size_t n);
char *ft_strjoin(char const *s1, char const *s2);
char *ft_substr(char const *s, unsigned int start, size_t len);
int is_white(char c);
int new_len(char const *s);
char *ft_strtrim(char const *s);
int	is_c(char str_i, char c);
int	words_num(char *str, char c);
void split_words(char **arr, char *str, char c);
// week1part2
typedef struct s_list
{
    void    *content;
    struct  s_list *next;
} t_list;
t_list *ft_lstnew(void const *content);
void ft_lstadd_front(t_list **lst, t_list *new);
void ft_lstadd_back(t_list **lst, t_list *new);
size_t ft_lstsize(t_list *lst);
t_list *ft_lstlast(t_list *lst);
void ft_lstdelone(t_list *lst, void (*del)(void *));
void ft_lstclear(t_list **lst, void (*del)(void *));
void ft_lstiter(t_list *lst, void (*f)(void *));
t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif