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
    if (*head == NULL) // If the list is empty
        return (-1);

    dlistint_t *current = *head;
    dlistint_t *tmp = NULL;
    
    if (index == 0) // If the node to delete is the first node
    {
        *head = current->next;
        if (*head != NULL)
            (*head)->prev = NULL;
        free(current);
        return (1);
    }

    // Traverse the list to find the node at the specified index
    for (unsigned int i = 0; current != NULL && i < index - 1; i++)
        current = current->next;

    // If the index is out of range
    if (current == NULL || current->next == NULL)
        return (-1);

    tmp = current->next->next; // Save the next of next node
    free(current->next); // Free the node at index
    current->next = tmp; // Link previous node with next of next node

    // If the next of next node exists, update its prev pointer
    if (tmp != NULL)
        tmp->prev = current;

    return (1);
}
