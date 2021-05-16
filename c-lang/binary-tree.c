#include <stdio.h>
#include <stdlib.h>

#define MAXSTRLEN 15
#define NODESCOUNT 5

/*
    Binary tree
    Type in integers and see insert path, e.g.
    1 - right -> 7 - right -> 9 - left -> 8
*/

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

static struct TreeNode tree;

struct TreeNode *new_node(void)
{
    return (struct TreeNode *) malloc(sizeof(struct TreeNode));
}

void add(struct TreeNode *node, int val)
{ 
    if (!node->val)
    {
        node->val = val;
        printf("%d\n", val);
    }
    else
    {
        printf("%d", node->val);
        
        if (val <= node->val)
        {
            printf(" - left -> ");

            if (!node->left)
            {
                node->left = new_node();
                node->left->val = val;
                printf("%d\n", val);
            }
            else
            {
                add(node->left, val);
            }
        }
        else
        {
            printf(" - right -> ");

            if (!node->right)
            {
                node->right = new_node();
                node->right->val = val;
                printf("%d\n", val);
            }
            else
            {
                add(node->right, val);
            }
        }
    }
}

int main()
{
    int i;
    char s[MAXSTRLEN];
    
    for (i = NODESCOUNT; i > 0; i--)
    {
        add(&tree, atoi(fgets(s, MAXSTRLEN, stdin)));
    }
}
