#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>

extern int flagPoints; // flag para mostrar os pontos do nurbs
extern GLUnurbsObj *theNurb;
extern GLUnurbsObj *theNurbEsp;

//função que mostra os pontos dos nurbs
void showPoints(GLfloat surfaceVec[4][4][3]);

// função que desenha
void drawSurface(GLfloat surfaceVec[4][4][3]);

// desenhar coisas redondas
void drawSurface2(GLfloat surfaceVec[4][9][3], int x, int y, int z);

//colher
void desenha_colher(void);

//pote
void desenha_pote(void);

//mesa
void desenha_mesa(void);

//frigideira
void desenha_frig (void);


/*
       +1  ^ Y
   *    *  |  *    *

   *    *  |  *    *
-1 ------------------> +1 X
   *    *  |  *    *

   *    *  |  *    *
       -1

// sup_esq (-1.5, 1.5, 0), inf_dir (1.5, -1.5, 0)
GLfloat coisa_quadrada[4][4][3] = {
   {
        { -1.5, 1.5, 0},    { -0.5, 1.5, 0},
        { 0.5, 1.5, 0},     { 1.5, 1.5, 0}
    },
    {
        { -1.5, 0.5, 0},    { -0.5, 0.5, 0},
        { 0.5, 0.5, 0},    {1.5, 0.5, 0}
    },
    {
        { -1.5, -0.5, 0},     { -0.5, -0.5, 0},
        { 0.5, -0.5, 0},       { 1.5, -0.5, 0}
    },
    {
        { -1.5, -1.5, 0},    { -0.5, -1.5, 0},
        {0.5, -1.5, 0},       {1.5, -1.5, 0}
    }
};

GLfloat cois_redonda[4][4][3] = {
 {

};
*/
