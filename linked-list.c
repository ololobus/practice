#include <stdio.h>
#include <stdlib.h>

#define MAXSTRLEN 15
#define NODESCOUNT 3

/*
    Simple linked list
*/

struct ListNode
{
    int val;
    struct ListNode *link;
};

static struct ListNode list;

struct ListNode *new_node(void)
{
    return (struct ListNode *) malloc(sizeof(struct ListNode));
}

void add(struct ListNode *node, int val)
{    
    if (!node->link)
    {
        if (!node->val)
        {
            node->val = val;
        }
        else
        {
            node->link = new_node();
            node->link->val = val;
        }
    }
    else
    {
        add(node->link, val);
    }
}

void print(struct ListNode *list)
{
    printf("%d", list->val);
    
    if (list->link)
    {
        printf(" -> ");
        print(list->link);
    }
}

int main()
{
    int i;
    char s[MAXSTRLEN];
    
    for (i = NODESCOUNT; i > 0; i--)
    {
        add(&list, atoi(fgets(s, MAXSTRLEN, stdin)));
    }
    
    print(&list);
    printf("\n");
}
