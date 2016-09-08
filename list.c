/*
** list.c for  in /home/colnot_d
**
** Made by dorian colnot
** Login   <colnot_d@epitech.net>
**
** Started on  Tue Jun 19 15:16:45 2012 dorian colnot
** Last update Sun Jul 15 23:24:54 2012 dorian colnot
*/

#include	<string.h>
#include	<stdio.h>
#include	<stdbool.h>
#include	<stdlib.h>

#include	"list.h"

size_t		list_lenght(t_ptr_list *ptr)
{
  t_list	*it;
  size_t	i;

  it = ptr->head;
  i = 0;
  while (it)
    {
      it = it->next;
      ++i;
    }
  return (i);
}

void	list_init_ptr(t_ptr_list *ptr)
{
  ptr->head = NULL;
  ptr->tail = NULL;
}

void	list_init_node(t_list *node)
{
  node->next = NULL;
  node->prev = NULL;
}

t_list		*insert_in_list(t_ptr_list *ptr,
			   t_list *node,
			   void *data_ref,
			   bool (*cmp)())
{
  t_list	*it;

  if ((!ptr->head) || (!node) || (!data_ref) || (!cmp))
    return (NULL);
  it = ptr->head;
  while (it)
    {
      if ((*cmp)(it, data_ref))
	{
	  node->prev = it;
	  node->next = it->next;

	  it->next->prev = node;
	  it->next = node;
	}
      it = it->next;
    }
  return (node);
}

t_list		*find_node_in_list(t_ptr_list *ptr, void *data_ref, bool (*cmp)())
{
  t_list	*it;

  if ((!ptr->head) || (!data_ref) || (!cmp))
    return (NULL);
  it = ptr->head;
  while (it)
    {
      if ((*cmp)(it, data_ref))
	return (it);
      it = it->next;
    }
  return (NULL);
}

bool		del_node_in_list(t_ptr_list *ptr, void *data_ref, bool (*cmp)())
{
  t_list	*node;

  if ((node = find_node_in_list(ptr, data_ref, cmp)) != NULL)
    {
      node->next->prev = node->prev;
      node->prev->next = node->next;
      node->next = NULL;
      node->prev = NULL;
      free(node);
      return (true);
    }
  return(false);
}

bool		list_apply_in_list(t_ptr_list *ptr, bool (*f)())
{
  t_list	*it;

  if ((!ptr->head) || (!f))
    return (true);
  it = ptr->head;
  while (it)
    {
      (*f)(it);
      it = it->next;
    }
  return (false);
}

void		list_push_front(t_ptr_list *ptr, t_list *node)
{
  if (ptr->head)
    {
      node->next = ptr->head;
      ptr->head->prev = node;
    }
  else
    {
      ptr->head = node;
      ptr->tail = node;
    }
}

void		list_push_back(t_ptr_list *ptr, t_list *node)
{
  if (ptr->tail)
    {
      ptr->tail->next = node;
      node->prev = ptr->tail;
      ptr->tail = node;
    }
  else
    {
      ptr->head = node;
      ptr->tail = node;
    }
}

void		list_pop_front(t_ptr_list *ptr)
{
  t_list	*it;

  it = ptr->head;
  ptr->head = it->next;
  if (it->next)
    it->next->prev = NULL;
  else
    ptr->tail = NULL;
  free(it);
}

void		list_pop_back(t_ptr_list *ptr)
{
  t_list	*it;

  if (!ptr->tail)
    return ;
  it = ptr->tail;
  ptr->tail = it->prev;
  if (it->prev)
    it->prev->next = NULL;
  else
    ptr->head = NULL;
  free(it);
}

void		list_free(t_ptr_list *ptr, void (*f)())
{
  t_list	*it;
  t_list	*next;

  it = ptr->head;
  if (f)
    {
      while (it)
	{
	  f(it);
	  it = it->next;
	}
    }
  it = ptr->head;
  while (it)
    {
      next = it->next;
      free(it);
      it = next;
    }
  ptr->head = NULL;
  ptr->tail = NULL;
}

/* bool	get_value(t_list *node, void *data_ref) */
/* { */
/*   int	*tmp = data_ref; */
/*   return (T_PLAYER(node)->nb == *tmp); */
/* } */

/* void	free_in_node(t_list *list) */
/* { */
/*   /\* if (T_PLAYER(list)->ptr_team.head) *\/ */
/*   /\* printf("projet %d \n", T_TEAM(list)->nbt); *\/ */
/*   T_PLAYER(list)->nb = 53; */
/*   list_free(&(T_PLAYER(list))->ptr_team, NULL); */
/* } */

void		free_list_int(t_list *list)
{
  t_ptr_list	*ptr_list =  &(((t_list_list_int*)list)->ptr_list_int);

  list_free(ptr_list, NULL);
}


int	main()
{
  t_ptr_list	ptr_lli;

  LIST_INIT_PTR(&(ptr_lli));
  for (int i = 5; i > 0; i--)
    {
      t_list_list_int	*node_lli;
      node_lli = malloc(sizeof(*node_lli));
      LIST_INIT_NODE(node_lli);
      LIST_INIT_PTR(&(node_lli->ptr_list_int));
      for (int j = 5; j > 0; j--)
	{
	  t_list_int *node_li = malloc(sizeof(*node_li));
	  LIST_INIT_NODE(node_li);
	  node_li->value = j;
	  LIST_PUSH_BACK(&(node_lli->ptr_list_int), node_li);
	}
      LIST_PUSH_BACK(&ptr_lli, node_lli);
    }
  list_free(&(ptr_lli), &free_list_int);
  return 0;
}

/*
int	main()
{
  t_ptr_list	ptr_player;
  t_player	*player;
  int		i;
  int		j;
  t_list	*list;

  i = 0;

  LIST_INIT_PTR(&ptr_player);
  while (i < 10)
    {
      player = malloc(sizeof(*player));
      LIST_INIT_PTR(&player->ptr_team);
      LIST_INIT_NODE(player);
      player->nb = i;
      LIST_PUSH_BACK(&ptr_player, player);
      j = 0;
      while (j < 5)
      	{
      	  player->team = malloc(sizeof(*(player->team)));
      	  LIST_INIT_NODE(player->team);
      	  player->team->nbt = j;
      	  LIST_PUSH_BACK(&(player->ptr_team), player->team);
      	  ++j;
      	}
      ++i;
    }
  list = ptr_player.head;
  t_list *tmp;
  while (list)
    {
      printf("%d-\n", (T_PLAYER(list))->nb);
      tmp = player->ptr_team.head;
      while (tmp)
      	{
      	  printf("%d <<<==TOTO\n", (T_TEAM(list))->nbt);
      	  LIST_NEXT_NODE(tmp);
      	}
      LIST_NEXT_NODE(list);
    }
  printf("sizeof list %ld\n", list_lenght(&ptr_player));



  player = malloc(sizeof(*player));
  LIST_INIT_NODE(player);
  int		k = 3;
  player->nb = 42;
  INSERT_IN_LIST(&ptr_player, player, &k, get_value);



  tmp = ptr_player.tail;
  while (tmp)
    {
      printf("\n%d-\n", ((t_player *)tmp)->nb);
      LIST_PREV_NODE(tmp);
    }

  LIST_FREE(&ptr_player);

  list_free(&ptr_player, free_in_node);
  return (EXIT_SUCCESS);
}
*/
