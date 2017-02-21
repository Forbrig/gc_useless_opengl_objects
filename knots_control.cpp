#include "obj.h"

// função que recebe uma superfície com 16 pontos e a desenha
// todos os objetos aqui são com 16 pontos
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

// outra função para desenhar superficies em nurbs,
// tive dificuldades em editar a primeira
// x, y, z são surfaceVec[x][y][z]
void drawSurface2(GLfloat surfaceVec[4][9][3], int x, int y, int z) {
		int u, v;
		GLint un = 30;
		GLint vn = 30;

	    glMap2f(GL_MAP2_VERTEX_3, 0, 1, y*z, x, 0, 1, z, y, &surfaceVec[0][0][0]);
	    glEnable(GL_MAP2_VERTEX_3);
	    glEnable(GL_AUTO_NORMAL);
	    glBegin(GL_QUADS);
	    for (u = 0; u < un; u++) {
	        for (v = 0; v < vn; v++) {
	            glEvalCoord2f((GLfloat)v / vn, (GLfloat)(u+1) / un);
	            glEvalCoord2f((GLfloat)(v+1) / vn, (GLfloat)(u+1) / un);
	            glEvalCoord2f((GLfloat)(v+1) / vn, (GLfloat)u / un);
	            glEvalCoord2f((GLfloat)v / vn, (GLfloat)u / un);
	        }
	    }
	    glEnd();
}
/*
// espelha imagens simétricas
// utilizado para espelhar objetos, pois a luz só é calculada (e refletida),
// de um lado do nurbs, o outro fica fosco
// são desenhados, então, 2 objetos, 1 de "costas para o outro"
void espelha (GLfloat atual[4][4][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            theNurbEsp[i][j][2] = atual[i][j][2];
            if (1) {
            	//printf("%f <> ", esp[i][j][2]);
            	theNurbEsp[i][j][2] = atual[i][j][2] * -1;
            	//printf("%f\n", esp[i][j][2]);	
            }
        }
    }
}
*/