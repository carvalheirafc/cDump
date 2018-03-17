#include <stdio.h>
#include "image.h"
#include "menu.h"
FILE *fp;
FILE *fp2;

    char tipo[2];
    char *pchar;
    int q;
    int l, c;
    int menuch;
    int choice;

int main (){

    headin();
    pixel imagem[l][c];
    pixel imagemod[l][c];
    imagein(l, c, imagem);
    choice = menu();
        if (choice == 1){
          printf("\t\t\t\tBlur Selected\n");
          printf("\t\t\t\tModification Done\n");
          printf("\t\t\t\tImage saved as 'Blur.ppm'\n");
          fp2 = fopen ("Blur.ppm", "w+");
          blur(l, c, imagem, imagemod);      
          headout(pchar, c, l, q);
          imageout(l, c, imagemod);
        }
        if (choice == 2){
          printf("\t\t\t\tSharp Selected\n");
          printf("\t\t\t\tModification Done\n");
          printf("\t\t\t\tImage saved as 'Sharp.ppm'\n");
          fp2 = fopen ("Sharp.ppm", "w+");
          sharp(l, c, imagem, imagemod);    
          headout(pchar, c, l, q);
          imageout(l, c, imagemod);
        }
        if (choice == 3){
          printf("\t\t\t\tTop Sobel Selected\n");
          printf("\t\t\t\tModification Done\n");
          printf("\t\t\t\tImage saved as 'Top Sobel.ppm'\n");
          fp2 = fopen ("Top Sobel.ppm", "w+");
          tsobel(l, c, imagem, imagemod);
          headout(pchar, c, l, q);
          imageout(l, c, imagemod);  
        }
        if (choice == 4){  
          printf("\t\t\t\tIdentity Selected\n");
          printf("\t\t\t\tModification Done\n");
          printf("\t\t\t\tImage saved as 'Identity.ppm'\n");
          fp2 = fopen ("Identity.ppm", "w+");
          identidy(l, c, imagem, imagemod);
          headout(pchar, c, l, q);
          imageout(l, c, imagemod);
        }
        if (choice == 5){  
          printf("\t\t\t\tTresHolding Selected\n");
          printf("\t\t\t\tModification Done\n");
          printf("\t\t\t\tImage saved as 'Tresholding.ppm'\n");
          fp2 = fopen ("Tresholding.ppm", "w+");
          thresholding(c, l, imagem, imagemod);   
          headout(pchar, c, l, q);
          imageout(l, c, imagemod);
        }
        if (choice == 6){
          printf("\t\t\t\tEmboss Selected\n");
          printf("\t\t\t\tModification Done\n");
          printf("\t\t\t\tImage saved as 'Emboss.ppm'\n");
          fp2 = fopen ("Emboss.ppm", "w+");
          emboss(l, c, imagem, imagemod);
          headout(pchar, c, l, q);
          imageout(l, c, imagemod);
        }
        if (choice == 7){ 
          printf("\t\t\t\tGrayScale Selected\n");
          printf("\t\t\t\tModification Done\n");
          printf("\t\t\t\tImage saved as 'Grayscale.ppm'\n");
          fp2 = fopen ("Grayscale.ppm", "w+");
          grayscale(c, l, imagem, imagemod);
          headout(pchar, c, l, q);
          imageout(l, c, imagemod);
        }   
        if (choice == 8){
          printf("\t\t\t\tFlip Vertical Selected\n");
          printf("\t\t\t\tModification Done\n");
          printf("\t\t\t\tImage saved as 'Flip Vertical.ppm'\n");
          fp2 = fopen ("Flip Vertical.ppm", "w+");
          rotation(c, l, imagem, imagemod);
          headout(pchar, c, l, q);
          imageout(l, c, imagemod);
        }
        if (choice == 9){
          printf("\t\t\t\tRotaion Left Selected\n");
          printf("\t\t\t\tModification Done\n");
          printf("\t\t\t\tImage saved as 'Rotation Left.ppm'\n");
          fp2 = fopen ("Rotation Left.ppm", "w+");
          rotationleft(c, l, imagem, imagemod);  
          headout(pchar, c, l, q);
          imageout(l, c, imagemod);

        }
        if (choice  == 10){
          printf("\t\t\t\tNo Filter Selected\n");
          printf("\t\t\t\tProcess Done\n");
          printf("\t\t\t\tImage saved as 'Normal.ppm'\n");
          fp2 = fopen ("Normal.ppm", "w+");
          nofilter(c, l, imagem, imagemod);
          headout(pchar, c, l, q);
          imageout(l, c, imagemod);
        }


return 0;
}
