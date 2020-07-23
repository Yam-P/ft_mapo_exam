#ifndef FT_LIST_H
# define FT_LIST_H

typedef struct  s_list t_list;

struct s_list
{
    struct s_list   *next;
    int	            data;
};

t_list	*sort_list(t_list* lst, int (*cmp)(int, int));

#endif
