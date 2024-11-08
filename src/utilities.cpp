
#include "../include/tree.h"
#include "../include/utilities.h"

#include <stdlib.h>


void Dump_vertices(node_t * node, node_t * this_node, FILE * file_f) {

    if( !node ) {
        return;
    }

    if (node->left)  Dump_vertices(node->left, this_node, file_f);
    if (node->right) Dump_vertices(node->right, this_node, file_f);

    if (node == this_node && node) {

        fprintf(file_f, "node%d[shape = doublecircle; style = bold; fillcolor = \"#55ffff\"; color = \"#55ffff\"; fontcolor = \"#55ffff\"; ", node);
        fprintf(file_f, "label = \" %d \"]; ", node->data);
        fprintf(file_f, "\n");

    } 
    else if (node) {

        fprintf(file_f, "node%d[shape = circle; style = bold; fillcolor = \"#0000aa\"; color = \"#55ffff\"; fontcolor = \"#55ffff\"; ", node);
        fprintf(file_f, "label = \" %d \"]; ", node->data);
        fprintf(file_f, "\n");
    }

}

void Dump_ribs(node_t * node, FILE * file_f) {
    
    if( !node ) {
        return;
    }

    if (node->left)  Dump_ribs(node->left,  file_f);
    if (node->right) Dump_ribs(node->right, file_f);

    if (node && node->right) {

        fprintf(file_f, "node%d -> node%d [color = \"#E4D00A\"; weight = 0;];\n", node, node->right);
    }
    if (node && node->left) {

         fprintf(file_f, "node%d -> node%d [color = \"#C70039\"; weight = 0;];\n", node, node->left);
    }  
    
}


void Tree_dump(node_t * tree_root, node_t * this_node) {

    char file_name[25] = ""; 
    
    snprintf(file_name, 25, "./debug/dot/graph%d.dot", number_of_dumps);

    FILE * file_f = fopen(file_name, "w");    //check if open 

    fprintf(file_f, "digraph Tree {\n");
    fprintf(file_f, "  graph [\n");
    fprintf(file_f, "  charset = \"UTF-8\";\n  label = \"like faaar tree\"\n");
    fprintf(file_f, "    bgcolor   = \"#0000aa\", \nfontcolor = white, \n fontsize  = 18, \n style = \"rounded\",   \n");
    fprintf(file_f, "rankdir = HR,\n margin  = 0.3, \nsplines = spline \n splines = true \nranksep = 1.0, \nnodesep = 0.9\n");
    fprintf(file_f, " ];\n");

    fprintf(file_f, "\n");
    Dump_vertices(tree_root, this_node, file_f);

    fprintf(file_f, "\n");
    Dump_ribs(tree_root, file_f);

    fprintf(file_f, "}\n");
    

    char command[65] = "";

    snprintf(command, 65, "dot ./debug/dot/graph%d.dot -Tpng -o ./debug/img/graph%d.png \n", number_of_dumps, number_of_dumps);

    fclose(file_f);
    
    system(command);

    number_of_dumps++;

}

void Html_dump(int number_of_dumps) {

    FILE * file_f = fopen("log.html", "w");

    fprintf(file_f, "<!DOCTYPE html>\n"      
                    "<html lang=\"ru\">\n" 
                    "<head>\n"
                    "<meta charset=\"UTF-8\">\n"
                    "<meta name=\"viewport\" content=\"width=device-width,initial-scale=1\">\n"
                    "<title>List</title>\n"
                    "<link rel=\"stylesheet\" href=\"log.css\">\n"
                    "</head>\n"
                    "<body>\n"
                    "<h1>DED CVADROBER</h1>\n"
                    "<div class=\"flex-container\">\n");


    for ( int i = 0; i < number_of_dumps; i++ ) {

        fprintf(file_f, "<div class = \"elem\">" 
                        "<img src = \"./debug/img/graph%d.png\" height = \"600\">" 
                        "</div>\n\n", i);
        }

    fclose(file_f);

}
