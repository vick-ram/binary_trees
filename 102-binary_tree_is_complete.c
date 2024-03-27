#include "binary_trees.h"
/**
 * queue_create - create an empty queue
 * Return: returns pointer to created queue
 */
queue_t *queue_create(void)
{
	queue_t *queue;

	queue = malloc(sizeof(queue_t));
	if (queue == NULL)
		return (NULL);

	queue->front = queue->rear = NULL;
	return (queue);
}
/**
 * enqueue - enqueue a node into the queue
 * @queue: pointer to the queue
 * @node: the node to enqueue
 * Return: returns mothing
 */
void enqueue(queue_t *queue, const binary_tree_t *node)
{
	queue_node_t *new_node;

	new_node = malloc(sizeof(queue_node_t));
	if (new_node == NULL)
		return;
	new_node->node = node;
	new_node->next = NULL;

	if (queue->front == NULL)
		queue->front = queue->rear = new_node;
	else
	{
		queue->rear->next = new_node;
		queue->rear = new_node;
	}
}
/**
 * dequeue - dequeue a node from the queue
 * @queue: node to dequeue
 * Return: returns pointer to the node dequeued
 */
const binary_tree_t *dequeue(queue_t *queue)
{
	const binary_tree_t *node;
	queue_node_t *temp;

	if (queue->front == NULL)
		return (NULL);

	node = queue->front->node;
	temp = queue->front;
	queue->front = queue->front->next;
	free(temp);

	if (queue->front == NULL)
		queue->rear = NULL;

	return (node);
}
/**
 * queue_destroy - destroy the queue
 * @queue: pointer to the queue
 * Return: returns nothing
 */
void queue_destroy(queue_t *queue)
{
	while (queue->front != NULL)
		dequeue(queue);

	free(queue);
}
/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	queue_t *queue;
	const binary_tree_t *current;
	int flag = 0;

	if (tree == NULL)
		return (0);
	queue = queue_create();
	if (queue == NULL)
		return (0);
	enqueue(queue, tree);
	while (queue->front != NULL)
	{
		current = dequeue(queue);
		if (current->left != NULL)
		{
			if (flag == 1)
			{
				queue_destroy(queue);
				return (0);
			}
			enqueue(queue, current->left);
		}
		else
			flag = 1;
		if (current->right != NULL)
		{
			if (flag == 1)
			{
				queue_destroy(queue);
				return (0);
			}
			enqueue(queue, current->right);
		}
		else
			flag = 1;
	}
	queue_destroy(queue);
	return (1);
}
