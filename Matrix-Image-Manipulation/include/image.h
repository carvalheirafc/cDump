#ifndef IMAGE_H
#define IMAGE_H

typedef struct{
    int r;
    int g;
    int b;
}pixel;

void headin();
void headout(char *pchar, int c, int l, int q);
void imagein();
void imageout(int l, int c, pixel imagemod[l][c]);
void clear(int l, int c, pixel imagem[l][c], pixel imagemod[l][c]);
void blur(int l, int c, pixel imagem[l][c], pixel imagemod[l][c]);
void sharp(int l, int c, pixel imagem[l][c], pixel imagemod[l][c]);
void tsobel(int l, int c, pixel imagem[l][c], pixel imagemod[l][c]);
void identidy(int l, int c, pixel imagem[l][c], pixel imagemod[l][c]);
void emboss(int l, int c, pixel imagem[l][c], pixel imagemod[l][c]);
void thresholding(int c, int l, pixel imagem[l][c], pixel imagemod[l][c]);
void grayscale(int c, int l, pixel imagem[l][c], pixel imagemod[l][c]);
void rotation(int c, int l, pixel imagem[l][c], pixel imagemod[l][c]);
void rotationleft(int c, int l, pixel imagem[l][c], pixel imagemod[l][c]);
void nofilter(int c, int l, pixel imagem[l][c], pixel imagemod[l][c]);

#endif // IMAGE_H