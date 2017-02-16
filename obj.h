#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>

extern int flagPoints; // flag para mostrar os pontos do nurbs
extern GLUnurbsObj *theNurb;

//função que mostra os pontos dos nurbs
void showPoints(GLfloat surfaceVec[4][4][3]);

// função que desenha
void drawSurface(GLfloat surfaceVec[4][4][3]);

// objeto 1
void desenha_frig(void);

// objeto 2
