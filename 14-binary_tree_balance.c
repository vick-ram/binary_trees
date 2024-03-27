#include "binary_trees.h"
/**
 * binary_tree_balance - Measures the
 * balance factor of a binary tree
 * @tree: Pointer to the root node of the tree
 * to measure the balance factor
 *
 * Return: Balance factor of the binary tree, 0 if tree is NULL
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	size_t left, right;

	if (tree == NULL)
		return (0);

	left = binary_tree_height(tree->left);
	right = binary_tree_height(tree->right);

	return ((int)left - (int)right);
}
