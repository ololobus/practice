#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define MAXSTRLEN 15
#define NODESCOUNT 3

/*
    Doubly linked list with bidirectional links via Bitwise XOR
    https://en.wikipedia.org/wiki/Bitwise_operation#XOR
    https://en.wikipedia.org/wiki/Doubly_linked_list
    https://stackoverflow.com/a/26569748/978424
*/

struct ListNode
{
    int val;
    uintptr_t link;
};

static struct ListNode list;

struct ListNode *new_node(void)
{
    return (struct ListNode *) malloc(sizeof(struct ListNode));
}

uintptr_t xor(struct ListNode *next, struct ListNode *prev)
{
    return (uintptr_t)next ^ (uintptr_t)prev;
}

struct ListNode *rev_xor(uintptr_t link, struct ListNode *nodep)
{
    return (void *)(link ^ (uintptr_t)nodep);
}

void add(struct ListNode *node, struct ListNode *prev, int val)
{    
    if (!rev_xor(node->link, prev))
    {
        if (!node->val)
        {
            node->val = val;
        }
        else
        {
            node->link = xor(new_node(), prev);
            rev_xor(node->link, prev)->val = val;
            rev_xor(node->link, prev)->link = xor(0, node);
        }
    }
    else
    {
        add(rev_xor(node->link, prev), node, val);
    }
}

void print(struct ListNode *list, struct ListNode *prev)
{
    printf("%d", list->val);
    
    if (rev_xor(list->link, prev))
    {
        printf(" <-> ");
        print(rev_xor(list->link, prev), list);
    }
}

int main()
{
    int i;
    char s[MAXSTRLEN];
    
    for (i = NODESCOUNT; i > 0; i--)
    {
        add(&list, 0, atoi(fgets(s, MAXSTRLEN, stdin)));
    }
    
    print(&list, 0);
    printf("\n");
}
