#include "obj.h"

// função que recebe uma superfície 16x16 e a desenha
// todos os objetos aqui são 16x16
void drawSurface(GLfloat surfaceVec[4][4][3]) {
    GLfloat knots[8] = {0.0, 0.0, 0.0, 0.0, 1.0, 1.0, 1.0, 1.0};
    
    gluBeginSurface(theNurb);
    gluNurbsSurface(theNurb, 8, knots, 8, knots, 4 * 3, 3, &surfaceVec[0][0][0], 4, 4, GL_MAP2_VERTEX_3);
    gluEndSurface(theNurb);
    showPoints(surfaceVec);
}

// função que mostra os pontos se a variável global pointsFlag estiver ativa
// esta função é referenciada de http://www.glprogramming.com/red/chapter12.html
void showPoints(GLfloat surfaceVec[4][4][3]) {
    if (flagPoints) {
        glPointSize(5.0);
        glDisable(GL_LIGHTING);
        glColor3f(1.0, 1.0, 0.0);
        glBegin(GL_POINTS);
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                glVertex3f(surfaceVec[i][j][0], surfaceVec[i][j][1], surfaceVec[i][j][2]);
            }
        }
    glEnd();
    glEnable(GL_LIGHTING);
    }
}