#include "obj.h"
/*
GLfloat tampo_mesa_up[7][1][3] = {
    {{0,-.5, 0}},
    {{.5,-.5, 0}},
    {{0.25, -0.0669873, 0}},
    {{0, 0.3880254, 0}},
    {{-.25,  -0.0669873, 0}},
    {{-.5,-.5, 0}},
    {{0,-.5, 0}}
};
*/

GLfloat tampo_mesa_up[4][4][3] = {
    {
        { -1.0, 1.0, 0.15},    { -0.5, 1.5, 0.15},
        { 0.5, 1.5, 0.15},     { 1.0, 1.0, 0.15}
    },
    {
        { -1.5, 0.5, 0.15},    { -0.5, 0.5, 0.15},
        { 0.5, 0.5, 0.15},    {1.5, 0.5, 0.15}
    },
    {
        { -1.5, -0.5, 0.15},     { -0.5, -0.5, 0.15},
        { 0.5, -0.5, 0.15},       { 1.5, -0.5, 0.15}
    },
    {
        { -1.0, -1.0, 0.15},    { -0.5, -1.5, 0.15},
        {0.5, -1.5, 0.15},       {1.0, -1.0, 0.15}
    }
};

GLfloat tampo_mesa_down[4][4][3] = {
    {
        { -1.0, 1.0, -0.15},    { -0.5, 1.5, -0.15},
        { 0.5, 1.5, -0.15},     { 1.0, 1.0, -0.15}
    },
    {
        { -1.5, 0.5, -0.15},    { -0.5, 0.5, -0.15},
        { 0.5, 0.5, -0.15},    {1.5, 0.5, -0.15}
    },
    {
        { -1.5, -0.5, -0.15},     { -0.5, -0.5, -0.15},
        { 0.5, -0.5, -0.15},       { 1.5, -0.5, -0.15}
    },
    {
        { -1.0, -1.0, -0.15},    { -0.5, -1.5, -0.15},
        {0.5, -1.5, -0.15},       {1.0, -1.0, -0.15}
    }
};

GLfloat
mesa_diffuse[] = { 0.7, 0.7, 0.7, 1.0 },
mesa_specular[] = { .2, .2, .2, 1.0 },
mesa_shininess[] = { 20.0 };



void desenha_mesa(void) {
	glColor4f(0.8, 0.8, 0.8, .4);
	glClearColor (0.0, 0.0, 0.0, 0.0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mesa_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mesa_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mesa_shininess);


    glPushMatrix();
	    glPushMatrix();
	    	glScalef(5, 5, 1);
	    	drawSurface(tampo_mesa_up);
			glColor4f(0.8, 0.8, 0.8, .4);
	    	drawSurface(tampo_mesa_down);
	    glPopMatrix();

		/*
		glPushMatrix();
			glScalef(2.9, 2.9, 1);
			glTranslatef(0.5, 0, 0);
	    	drawSurface2(contorno_mesa, 4, 9, 3);
	    glPopMatrix();
		*/
    glPopMatrix();
}
