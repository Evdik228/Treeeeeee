
#ifndef  UTILITIES_H_
#define  UTILITIES_H_


void Tree_dump(node_t * tree_root, node_t * this_node);
void Html_dump(int number_of_dumps);

inline int number_of_dumps = 0;  // i, know, that it`s global, but i need it to count dumps;


#endif