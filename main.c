//
// Created by batel on 30/12/2021.
//
#include "algo.h"

// T 3 2 1 3 S 2 0 S 5 2

int main()
{
    char ch = '0';
    pnode nodesList = NULL;
    int nodeNum = 0, counter = 0;
    // do-while for all the cases
    do
    {
        fflush(stdin);
        if (scanf(" %c", &ch) == EOF)
        {
            break;
        }
        //printf("%c ", ch);
        switch (ch)
        {
            case 'A':             /**when 'A' is chosen run function (1) - create graph*/
				nodeNum = build_graph_cmd(&nodesList);
                counter = 0;
				//print_graph(nodesList);
                break;
            case 'n':             /**when 'n' - create node**/
				if (counter < nodeNum)
                {
                    insert_node_cmd(&nodesList, 0);
                    counter++;
                }
				//print_graph(nodesList);
                break;
            case 'B':            /**when 'B' is chosen run function (2) - create new node**/
				insert_node_cmd(&nodesList, 1);
				//print_graph(nodesList);
                break;
            case 'D':            /**when 'D' is chosen run function (2) - delete node**/
				delete_node_cmd(&nodesList);
				//print_graph(nodesList);
                break;
            case 'S':            /**when 'S' is chosen run function (3) - get the length of shortest path**/
                shortsPath_S_cmd(&nodesList);
                break;
            case 'P':            /**when 'S' is chosen run function (3) - get the shortest path**/
                shortsPath_P_cmd(&nodesList);
                break;
            case 'T':            /**when 'T' is chosen run function (2) - tsp algo**/
                TSP_cmd(nodesList);
                break;
            default:            /**ignore other chars**/
                break;
        }

    } while (ch != 'q');

    delete_graph(&nodesList);

    return (0);
}