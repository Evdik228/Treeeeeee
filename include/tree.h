#ifndef  TREE_H_
#define  TREE_H_

#include<stdio.h>

typedef int tree_elem_t;

enum error_types {
    OKEY                = 0,
    ERROR               = 1,
};

struct node_t {

    tree_elem_t data;
    node_t * left = 0;
    node_t * right = 0;

};

node_t * New_node(tree_elem_t data);
void Add_vertex(node_t * tree_root, tree_elem_t elem);
void Tree_sort(tree_elem_t * array, size_t len_array);

#endif