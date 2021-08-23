#include "file.h"
void add_history(vars_t *head)
{
	vars_t *node;
	vars_t *newnode = head;
	node = malloc(sizeof(vars_t));
	if(node == NULL)
		return;
	node->command = head->history;
	node->next = NULL;
	if (head != NULL)
	{
		while (newnode->next != NULL)
		{
			newnode = newnode->next;
		}
		newnode->next = node;
	}else
	{
		head = node;
	}
}
char print_history(vars_t *h)
{
	vars_t *new = h;
	int count = 0;

	while (new)
	{
		printf("%s\n", new->command);
		new = new->next;
		count++;
	}
	return (0);
}
