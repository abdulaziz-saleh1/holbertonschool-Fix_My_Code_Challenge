#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - Delete a node at a specific index from a list
 *
 * @head: A pointer to the first element of a list
 * @index: The index of the node to delete
 *
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
    dlistint_t *saved_head, *tmp;
    unsigned int p;

    if (head == NULL || *head == NULL)
        return (-1);

    saved_head = *head;

    if (index == 0)
    {
        tmp = (*head)->next;
        free(*head);
        *head = tmp;
        if (tmp != NULL)
            tmp->prev = NULL;
        return (1);
    }

    p = 0;
    while (p < index && *head != NULL)
    {
        *head = (*head)->next;
        p++;
    }

    if (*head == NULL)
    {
        *head = saved_head;
        return (-1);
    }

    (*head)->prev->next = (*head)->next;

    if ((*head)->next != NULL)
        (*head)->next->prev = (*head)->prev;

    free(*head);
    *head = saved_head;
    return (1);
}
