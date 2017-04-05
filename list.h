/*
** list.h for  in /home/colnot_d
**
** Made by dorian colnot
** Login   <colnot_d@epitech.net>
**
** Started on  Tue Jun 19 14:54:21 2012 dorian colnot
** Last update Sun Jul 15 23:24:57 2012 dorian colnot
*/

#ifndef LIST_H_
# define LIST_H_

typedef struct s_list
{
  struct s_list *next;
  struct s_list *prev;
}		t_list;

typedef struct s_ptr
{
  t_list	*head;
  t_list	*tail;
}		t_ptr_list;



typedef struct  s_list_list_int
{
  t_list	list;
  t_ptr_list	ptr_list_int;
}		t_list_list_int;


typedef struct  s_list_int
{
  t_list	list;
  int		value;
}		t_list_int;
















typedef struct s_team
{
  t_list	team;
  int		nbt;
}		t_team;

typedef struct	s_player
{
  t_list	player;

  int		nb;
  t_ptr_list	ptr_team;
  t_team	*team;
  int		id;
  int		lvl;
//  int		team;
  int		goal;

//  t_direction	direction;
//  t_vision	*vision;
//  t_food	food[NB_FOOD];
//  t_stone	stone[NB_STONE];
}		t_player;



# define	T_LIST(n)		((t_list *)(n))
# define	T_PLAYER(n)		((t_player *)(n))
# define	T_TEAM(n)		((t_team *)(n))

# define	LIST_INIT_PTR(n)		list_init_ptr((n))
# define	LIST_INIT_NODE(n)		list_init_node(T_LIST(n))

# define	LIST_PUSH_BACK(b, n)		list_push_back((b), T_LIST(n))
# define	LIST_PUSH_FRONT(b, n)		list_push_front((b), T_LIST(n))

# define	LIST_POP_FRONT(b)		list_pop_front((b))
# define	LIST_POP_BACK(b)		list_pop_back(b)
# define	LIST_LENGHT(b)			list_lenght(b)
# define	LIST_FREE(n)			  list_free((n), free_in_node)

// CTRL MACRO

# define	INSERT_IN_LIST(b, n, dt, cmp)		insert_in_list((b), T_LIST(n), (dt), (cmp))
# define	FIND_NODE_IN_LIST(b, dt, cmp)		find_node_in_list((b), (void *)(dt), (cmp))
# define	DEL_NODE_IN_LIST(b, dt, cmp)		del_node_in_list((b), (void *)(dt), (cmp))
# define	LIST_APPLY_IN_LIST(b, f)		list_apply_in_list((b), (f))
# define	LIST_NEXT_NODE(n)			(n) = ((n)->next)
# define	LIST_PREV_NODE(n)			(n) = ((n)->prev)

void		list_init_node(t_list *node);

t_list		*insert_in_list(t_ptr_list *ptr, t_list *node, void *data_ref, bool (*cmp)());
bool		list_apply_in_list(t_ptr_list *ptr, bool (*f)());
t_list		*find_node_in_list(t_ptr_list *ptr, void *data_ref, bool (*cmp)());
bool		del_node_in_list(t_ptr_list *ptr, void *data_ref, bool (*cmp)());

void		list_push_back(t_ptr_list *ptr, t_list *node);
void		list_push_front(t_ptr_list *ptr, t_list *node);

void		list_pop_front(t_ptr_list *ptr);
void		list_pop_back(t_ptr_list *ptr);
void		list_free(t_ptr_list *ptr, void (*f)());
size_t		list_lenght(t_ptr_list *ptr);

#endif /* !LIST_H_ */
