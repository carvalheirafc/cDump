#include <stdio.h>
#include "image.h"
 
 FILE *fp;
 FILE *fp2;   
    
    char tipo[2];
    char *pchar;
    int q;
    int l, c;
    int n, m;

void headin(){
    fp = fopen ("lena.txt", "r");
    fscanf(fp, "%s", tipo);
    fscanf(fp, "%i %i", &c, &l);
    fscanf(fp, "%i", &q);
    pchar = tipo;
}

void headout(char *pchar, int c, int l, int q){
    
    fprintf(fp2,"%s\n", tipo);
    fprintf(fp2,"%i %i\n", c, l);
    fprintf(fp2,"%i\n", q);
}

void imagein(int l, int c, pixel imagem[l][c]){
    
    int i, j;
    for(i=0;i<l;i++){
        for(j=0;j<c;j++){
            fscanf(fp, "%i %i %i\n", &imagem[i][j].r, &imagem[i][j].g, &imagem[i][j].b);
        }
    }
}

void imageout(int l, int c, pixel imagemod[l][c]){
    
    int i, j;
    for(i=0;i<l;i++){
        for(j=0;j<c;j++){
            fprintf(fp2, "%hhu %hhu %hhu\n", imagemod[i][j].r,imagemod[i][j].g,imagemod[i][j].b);
            
        }
    }    
}

void blur(int l, int c, pixel imagem[l][c], pixel imagemod[l][c]){
    int lin, col, i, j;
    int sumr, sumb, sumg;

    float boxblur[3][3] = {
            {0.0625, 0.125, 0.0625 },
            {0.125, 0.25, 0.125 },
            {0.0625, 0.125, 0.0625}
    };
    
    for(lin=1;lin<l-1;lin++){
        for(col=1;col<c-1;col++){
            sumr = 0;
            sumg = 0;
            sumb = 0;
            for(i=0;i<3;i++){
                for(j=0;j<3;j++){
                    sumr += (imagem[lin-1 + i][col-1 + j].r * boxblur[i][j]);
                    sumg += (imagem[lin-1 + i][col-1 + j].g * boxblur[i][j]); 
                    sumb += (imagem[lin-1 + i][col-1 + j].b * boxblur[i][j]);
                }
            }
        imagemod[lin][col].r = sumr;
        imagemod[lin][col].g = sumg;
        imagemod[lin][col].b = sumb; 
        }
    }
}

void sharp(int l, int c, pixel imagem[l][c], pixel imagemod[l][c]){
    int lin, col, i, j;
    int sumr, sumb, sumg;

    int boxsharp[3][3] = {
            {0, 1, 0},
            {1, 5, 1},
            {0, 1, 0}
    };
    for(lin=1;lin<l-1;lin++){
        for(col=1;col<c-1;col++){
            sumr = 0;
            sumg = 0;
            sumb = 0;
            for(i=0;i<3;i++){
                for(j=0;j<3;j++){
                    sumr += (imagem[lin-1 + i][col-1 + j].r * boxsharp[i][j]);
                    sumg += (imagem[lin-1 + i][col-1 + j].g * boxsharp[i][j]); 
                    sumb += (imagem[lin-1 + i][col-1 + j].b * boxsharp[i][j]);
                }
            }
        imagemod[lin][col].r = sumr;
        imagemod[lin][col].g = sumg;
        imagemod[lin][col].b = sumb; 
        }
    }
}

void tsobel(int l, int c, pixel imagem[l][c], pixel imagemod[l][c]){
    int lin, col, i, j;
    int sumr, sumb, sumg;

    int boxtsobel[3][3] = {
            {1, 2, 1},
            {0, 0, 0},
            {-1, -2, -1}
    };
    for(lin=1;lin<l-1;lin++){
        for(col=1;col<c-1;col++){
            sumr = 0;
            sumg = 0;
            sumb = 0;
            for(i=0;i<3;i++){
                for(j=0;j<3;j++){
                    sumr += (imagem[lin-1 + i][col-1 + j].r * boxtsobel[i][j]);
                    sumg += (imagem[lin-1 + i][col-1 + j].g * boxtsobel[i][j]); 
                    sumb += (imagem[lin-1 + i][col-1 + j].b * boxtsobel[i][j]);
                }
            }
        imagemod[lin][col].r = sumr;
        imagemod[lin][col].g = sumg;
        imagemod[lin][col].b = sumb; 
        }
    }
}

void identidy(int l, int c, pixel imagem[l][c], pixel imagemod[l][c]){
    int lin, col, i, j;
    int sumr, sumb, sumg;

    int boxidentidy[3][3] = {
            {0, 0, 0},
            {0, 1, 0},
            {0, 0, 0}
    };
    for(lin=1;lin<l-1;lin++){
        for(col=1;col<c-1;col++){
            sumr = 0;
            sumg = 0;
            sumb = 0;
            for(i=0;i<3;i++){
                for(j=0;j<3;j++){
                    sumr += (imagem[lin-1 + i][col-1 + j].r * boxidentidy[i][j]);
                    sumg += (imagem[lin-1 + i][col-1 + j].g * boxidentidy[i][j]); 
                    sumb += (imagem[lin-1 + i][col-1 + j].b * boxidentidy[i][j]);
                }
            }
        imagemod[lin][col].r = sumr;
        imagemod[lin][col].g = sumg;
        imagemod[lin][col].b = sumb;  
        }
    }
}
void emboss(int l, int c, pixel imagem[l][c], pixel imagemod[l][c]){
    int lin, col, i, j;
    int sumr, sumb, sumg;

    int boxemboss[3][3] = {
            {-2, -1, 0},
            {-1, 1, 1},
            {0, 1, 2}
    };
    for(lin=1;lin<l-1;lin++){
        for(col=1;col<c-1;col++){
            sumr = 0;
            sumg = 0;
            sumb = 0;
            for(i=0;i<3;i++){
                for(j=0;j<3;j++){
                    sumr += (imagem[lin-1 + i][col-1 + j].r * boxemboss[i][j]);
                    sumg += (imagem[lin-1 + i][col-1 + j].g * boxemboss[i][j]); 
                    sumb += (imagem[lin-1 + i][col-1 + j].b * boxemboss[i][j]);
                }
            }
        imagemod[lin][col].r = sumr;
        imagemod[lin][col].g = sumg;
        imagemod[lin][col].b = sumb; 
        }
    }
}

void thresholding(int c, int l, pixel imagem[l][c], pixel imagemod[l][c]){

    int i, j;
    int med;
    for(i=0;i<l;i++){
        med = 0;
        for(j=0;j<c;j++){
            med = (imagem[i][j].r + imagem[i][j].g + imagem[i][j].b) / 3; 
            if (med >= 128){
            imagemod[i][j].r = 255;
            imagemod[i][j].g = 255;
            imagemod[i][j].b = 255;
            }
            if(med < 128){
            imagemod[i][j].r = 0;
            imagemod[i][j].g = 0;
            imagemod[i][j].b = 0;   
            }
        }
    }
}

void grayscale(int c, int l, pixel imagem[l][c], pixel imagemod[l][c]){

    int i, j;
    int med;
    for(i=0;i<l;i++){
        med = 0;
        for(j=0;j<c;j++){
            med = (imagem[i][j].r + imagem[i][j].g + imagem[i][j].b) / 3; 
            imagemod[i][j].r = med;
            imagemod[i][j].g = med;
            imagemod[i][j].b = med;
        }
    }
}
void rotation(int c, int l, pixel imagem[l][c], pixel imagemod[l][c]){
    int i, j;
    for(i=0;i<l;i++){
        for(j=0;j<c;j++){
            imagemod[i][j].r = imagem[l-i-1][c-j-1].r;
            imagemod[i][j].g = imagem[l-i-1][c-j-1].g;
            imagemod[i][j].b = imagem[l-i-1][c-j-1].b;
        }
    }        
}
void rotationleft(int c, int l, pixel imagem[l][c], pixel imagemod[l][c]){
    int i, j;
    for(i=0;i<l;i++){
        for(j=0;j<c;j++){
            imagemod[i][j].r = imagem[j][i].r;
            imagemod[i][j].g = imagem[j][i].g;
            imagemod[i][j].b = imagem[j][i].b;
        }
    }
}
void nofilter(int c, int l, pixel imagem[l][c], pixel imagemod[l][c]){
    
    int i, j;
    for(i=0;i<l;i++){
        for(j=0;j<c;j++){
            imagemod[i][j].r = imagem[i][j].r;
            imagemod[i][j].g = imagem[i][j].g;
            imagemod[i][j].b = imagem[i][j].b;
            
        }
    }    
}

