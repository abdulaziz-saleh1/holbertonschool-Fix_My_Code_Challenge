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
    dlistint_t *current, *tmp;
    unsigned int p;

    if (head == NULL || *head == NULL)
        return (-1);

    current = *head;

    if (index == 0)
    {
        tmp = current->next;
        free(current);
        *head = tmp;
        if (tmp != NULL)
            tmp->prev = NULL;
        return (1);
    }

    for (p = 0; current != NULL && p < index; p++)
        current = current->next;

    if (current == NULL)
        return (-1);

    if (current->prev != NULL)
        current->prev->next = current->next;

    if (current->next != NULL)
        current->next->prev = current->prev;

    free(current);
    return (1);
}
