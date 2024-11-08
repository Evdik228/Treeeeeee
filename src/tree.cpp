
#include <stdio.h>
#include <stdlib.h>

#include "../include/tree.h"
#include "../include/utilities.h"

void Tree_destruct(node_t * node) {

    if( !node ) {
        return;
    }

    if (node->left)  Tree_destruct(node->left);
    if (node->right) Tree_destruct(node->right);

    free(node);
}

void Tree_out_preorder(node_t * node){

    if( !node ) {
        return;
    }

    printf("(");
    printf("%d", node->data);

    if (node->left)  Tree_out_preorder(node->left);
    if (node->right) Tree_out_preorder(node->right);

    printf(")");

}

void Tree_out_postorder(node_t * node) {

    if( !node ) {
        return;
    }

    printf("(");

    if (node->left)  Tree_out_postorder(node->left);
    if (node->right) Tree_out_postorder(node->right);

    printf("%d", node->data);
    printf(")");
}

void Tree_out_order(node_t * node) {

    if( !node ) {
        return;
    }   

    printf("(");

    if (node->left)  Tree_out_order(node->left);

    printf("%d", node->data);

    if (node->right) Tree_out_order(node->right);

    printf(")");
}


void Tree_sort(tree_elem_t * array, size_t len_array) {

    node_t * tree_root = (node_t *) calloc(1, sizeof(* tree_root));

    tree_root->data = *array;

    for (size_t id = 1; id < len_array; id++ ) {

        Tree_dump(tree_root, tree_root);

        Add_vertex(tree_root, array[id]);

    }

    Tree_dump(tree_root, tree_root);

    //Tree_out_preorder(tree_root);
    printf("\n");

    //Tree_out_postorder(tree_root);
    printf("\n");

    Tree_out_order(tree_root);
    printf("\n");

    Tree_destruct(tree_root);
}

void Add_vertex(node_t * node, tree_elem_t elem) {


    if (elem <= node->data && node->left == 0) {

        node->left = New_node(elem);
        return;
    }

    else if(elem > node->data && node->right == 0) {

        node->right = New_node(elem);
        return;
    }

    else if(elem <= node->data) {

        Add_vertex(node->left, elem);

    } else {

        Add_vertex(node->right, elem);
    }
}

node_t * New_node(tree_elem_t data) {

    node_t * node = (node_t *) calloc(1, sizeof(* node));
    node->data = data;

    return node;

}

// i`m not understand, how to point 