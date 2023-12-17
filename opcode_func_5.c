#include "monty.h"
/**
 * add_node - Add node to the beginning of list.
* @head: Pointer to first node.
* @n: Data inside node.
* Return: Pointer to first node.
*/
stack_t *add_node(stack_t **head, const int n)
{
	stack_t *new = malloc(sizeof(stack_t));

	if (new == NULL)
		return (NULL);

	if (*head == NULL)
	{
		new->n = n;
		new->next = NULL;
		new->prev = NULL;
		*head = new;
		return (*head);
	}

	(*head)->prev = new;
	new->n = n;
	new->next = *head;
	new->prev = NULL;
	*head = new;
	return (*head);
}

/**
 * add_node_at_end - Add node to end of list.
 * @head: Pointer to first node.
 * @n: Data inside node.
 * Return: Pointer to first node.
 */
stack_t *add_node_at_end(stack_t **head, const int n)
{
	stack_t *tmp = *head;
	stack_t *new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
		return (NULL);

	new_node->n = n;

	if (*head == NULL)
	{
		new_node->next = NULL;
		new_node->prev = NULL;
		*head = new_node;
		return (new_node);
	}

	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}

	tmp->next = new_node;
	new_node->prev = tmp;
	new_node->next = NULL;
	return (new_node);
}

/**
 * delete_node_at_index - Delete node a specific spot.
 * @head: Pointer to first node on list.
 * @index: Position to delete.
 * Return: 1 if successful, -1 if failure.
 */
int delete_node_at_index(stack_t **head, unsigned int index)
{
	stack_t *tmp, *tmp2;
	unsigned int i;

	if (*head == NULL)
		return (-1);

	tmp = *head;

	if (index == 0)
	{
		*head = tmp->next;
		if (tmp->next != NULL)
			tmp->next->prev = NULL;
		free(tmp);
		return (1);
	}
	i = 0;
	while (i < (index - 1))
	{
		if (tmp == NULL)
			return (-1);
		tmp = tmp->next;
		i++;
	}
	tmp2 = (tmp->next)->next;
	if (tmp->next->next != NULL)
		tmp->next->next->prev = tmp;
	free(tmp->next);
	tmp->next = tmp2;

	return (1);
}

/**
 * free_list - Free a list.
 * @head: Pointer to first node.
 *
 */
void free_list(stack_t *head)
{
	stack_t *tmp;

	while (head != NULL)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}
