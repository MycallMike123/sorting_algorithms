#include "sort.h"

void swap_nodes(listint_t *left, listint_t **right);

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers in ascending
 * order using the Cocktail Shaker sort algorithm
 *
 * @list: A pointer to the doubly linked list
 */

void cocktail_sort_list(listint_t **list)
{
	listint_t *shaker_tail, *ct_shaker;
	bool shaken_not_stirred = false;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (shaker_tail = *list; shaker_tail->next != NULL;)
		shaker_tail = shaker_tail->next;

	while (shaken_not_stirred == false)
	{
		shaken_not_stirred = true;
		for (ct_shaker = *list; ct_shaker != tail; ct_shaker = ct_shaker->next)
		{
			if (ct_shaker->n > ct_shaker->next->n)
			{
				swap_nodes(list, &shaker_tail, &ct_shaker);
				print_list((const listint_t *)*list);
				shaken_not_stirred = false;
			}
		}

		for (ct_shaker = ct_shaker->prev; ct_shaker != *list;
				ct_shaker = ct_shaker->prev)
		{
			if (ct_shaker->n < ct_shaker->prev->n)
			{
				swap_node_bh(list, &shaker_tail, &ct_shaker);
				print_list((const listint_t *)*list);
				shaken_not_stirred = false;
			}
		}
	}
}

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 *
 * @list: A pointer to the head of a doubly-linked list
 * @tail: A pointer to the tail of the doubly-linked list
 * @shaker: A pointer to the current swapping node
 */

void swap_nodes(listint_t **list, listint_t **tail, listint_t **shaker)
{
	listint_t *temp = (*shaker)->next;

	if ((*shaker)->prev != NULL)
		(*shaker)->prev->next = temp;
	else
		*list = temp;

	temp->prev = (*shaker)->prev;
	(*shaker)->next = temp->next;

	if (temp->next != NULL)
		temp->next->prev = *shaker;
	else
		*tail = *shaker;

	(*shaker)->prev = temp;
	temp->next = *shaker;
	*shaker = temp;
}

/**
 * swap_node_bh - Swap a node in a listint_t doubly-linked
 * list of integers with the node behind it)
 * @list: A pointer to the head of a doubly-linked list
 * @tail: A pointer to the tail of the doubly-linked list
 * @shaker: A pointer to the current swapping node
 */

void swap_node_bh(listint_t **list, listint_t **tail, listint_t **shaker)
{
	listint_t *temp = (*shaker)->prev;

	if ((*shaker)->next != NULL)
		(*shaker)->next->prev = temp;
	else
		*tail = temp;

	temp->next = (*shaker)->next;
	(*shaker)->prev = temp->prev;
	if (temp->prev != NULL)
		temp->prev->next = *shaker;
	else
		*list = *shaker;
	(*shaker)->next = temp;
	temp->prev = *shaker;
	*shaker = temp;
}
