#include <stdio.h>
#include "menu.h"

int ch;

int menu(){
        
        printf("\t\t\t\tWellcome to Portable Photoshop !!\n");
        printf("\t\t\t\tTo continue select a option:\n");
        printf("\t\t\t\t     Blur...............1\n");
        printf("\t\t\t\t     Sharp..............2\n");
        printf("\t\t\t\t     Top Sobel..........3\n");
        printf("\t\t\t\t     Identity...........4\n");
        printf("\t\t\t\t     ThresHold..........5\n");
        printf("\t\t\t\t     Emboss.............6\n");
        printf("\t\t\t\t     Grayscale..........7\n");
        printf("\t\t\t\t     Flip Vertical......8\n");
        printf("\t\t\t\t     Left Rotation......9\n");
        printf("\t\t\t\t     No Filter.........10\n");
        printf("\t\t\t\t");
        scanf("%i", &ch);
    return ch;
}