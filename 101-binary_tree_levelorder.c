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
 * binary_tree_levelorder - Goes through a binary
 * tree using level-order traversal
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node
 */
void binary_tree_levelorder(
		const binary_tree_t *tree, void (*func)(int))
{
	const binary_tree_t *current;
	queue_t *queue;

	if (tree == NULL || func == NULL)
		return;

	queue = queue_create();
	if (queue == NULL)
		return;

	enqueue(queue, tree);

	while (queue->front != NULL)
	{
		current = dequeue(queue);
		func(current->n);

		if (current->left != NULL)
			enqueue(queue, current->left);
		if (current->right != NULL)
			enqueue(queue, current->right);
	}

	queue_destroy(queue);
}
