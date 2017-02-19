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

// espelha a imagem (avesso)
void espelha (GLfloat esp[4][4][3]);

// objeto 1
void desenha_frig(void);

// objeto 2
void desenha_colher(void);

// objeto 3


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
        { -0.5, 0.5, 0},    { -0.5, 1.5, 0}, 
        { 0.5, 1.5, 0},     { 0.5, 0.5, 0}
    }, 
    {
        { -1.5, 0.5, 0},    { -0.25, 0.25, -1}, 
        { 0.25, 0.25, -1},    {1.5, 0.5, 0}
    }, 
    {
        { -1.5, -0.5, 0},     { -0.25, -0.25, -1.5}, 
        { 0.25, -0.25, -1.5},       { 1.5, -0.5, 0}
    }, 
    {
        { -0.5, -0.5, 0},    { -0.5, -1.5, 0}, 
        {0.5, -1.5, 0},       {0.5, -0.5, 0}
    }
};
*/