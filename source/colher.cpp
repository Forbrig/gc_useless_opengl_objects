#include "obj.h"

GLfloat concha_colh[4][4][3] = {
    {
        { -0.5, 0.80, 0},    { -0.15, 1.25, 0}, 
        { 0.15, 1.25, 0},     { 0.5, 0.80, 0}
    },
    {
        { -0.75, 0.5, 0},    { -0.5, 0.5, -0.5}, 
        { 0.5, 0.5, -0.5},    {0.75, 0.5, 0}
    }, 
    {
        { -1.0, -0.5, 0},     { -0.5, -0.5, -0.5}, 
        { 0.5, -0.5, -0.5},       { 1.0, -0.5, 0}
    }, 
    {
        { -0.5, -1.0, 0},    { -0.15, -1.25, 0}, 
        { 0.15, -1.25, 0},       { 0.5, -1.0, 0}
    }
};

GLfloat concha_colh_esp[4][4][3] = {
    {
        { -0.5, 0.80, 0},    { -0.15, 1.25, 0}, 
        { 0.15, 1.25, 0},     { 0.5, 0.80, 0}
    },
    {
        { -0.75, 0.5, 0},    { -0.5, 0.5, 0.5}, 
        { 0.5, 0.5, 0.5},    {0.75, 0.5, 0}
    }, 
    {
        { -1.0, -0.5, 0},     { -0.5, -0.5, 0.5}, 
        { 0.5, -0.5, 0.5},       { 1.0, -0.5, 0}
    }, 
    {
        { -0.5, -1.0, 0},    { -0.15, -1.25, 0}, 
        { 0.15, -1.25, 0},       { 0.5, -1.0, 0}
    }
};

GLfloat alca_colh[4][4][3] = {
    {
        { -0.10, 1.5, 0},    { -0.05, 1.5, 0}, 
        { 0.05, 1.5, 0},     { 0.10, 1.5, 0}
    }, 
    {
        { -0.10, 0.85, 0.35},    { -0.05, 0.85, 0.50}, 
        { 0.05, 0.85, 0.50},    {0.10, 0.85, 0.35}
    }, 
    {
        { -0.25, -0.5, 0},     { -0.15, -0.5, 0}, 
        { 0.15, -0.5, 0},       { 0.25, -0.5, 0}
    }, 
    {
        { -0.15, -1.25, 0},    { -0.15, -1.5, 0}, 
        {0.15, -1.5, 0},       {0.15, -1.25, 0}
    }
};

GLfloat alca_colh_esp[4][4][3] = {
    {
        { -0.10, 1.5, 0},    { -0.05, 1.5, 0}, 
        { 0.05, 1.5, 0},     { 0.10, 1.5, 0}
    }, 
    {
        { -0.10, 0.85, -0.35},    { -0.05, 0.85, -0.50}, 
        { 0.05, 0.85, -0.50},    {0.10, 0.85, -0.35}
    }, 
    {
        { -0.25, -0.5, 0},     { -0.15, -0.5, 0}, 
        { 0.15, -0.5, 0},       { 0.25, -0.5, 0}
    }, 
    {
        { -0.15, -1.25, 0},    { -0.15, -1.5, 0}, 
        {0.15, -1.5, 0},       {0.15, -1.25, 0}
    }
};

GLfloat
colh_diffuse[] = { 0.7, 0.7, 0.7, 1.0 },
colh_specular[] = { 1.0, 1.0, 1.0, 1.0 },
colh_shininess[] = { 20.0 };


// desenha todas as partes
void desenha_colher(void) {
    glColor4f(0.4, 0.4, 0.4, 0.4); // cinza prateado
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, colh_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, colh_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, colh_shininess);

    glPushMatrix();
        glScalef(0.8, 0.8, 0.8);
        // alca
        glPushMatrix();
            glTranslatef(0, -2.67, 0); //1.5 + 1.25
            drawSurface(alca_colh);
            glColor4f(0.4, 0.4, 0.4, 0.4);
            /*
            glPushMatrix();
                glRotatef(180, 0, 1, 0);
                glTranslatef(0, 0, 0.01);
                drawSurface(alca_colh_esp);
                glColor4f(0.4, 0.4, 0.4, 0.4);
            glPopMatrix();
            */
        glPopMatrix();

        // concha
        glPushMatrix();
            drawSurface(concha_colh);
            glColor4f(0.4, 0.4, 0.4, 0.4);
            /*
            glPushMatrix();
                glRotatef(180, 0, 1, 0);
                glTranslatef(0, 0, 0.01);
                drawSurface(concha_colh_esp);
            glPopMatrix();
            */
        glPopMatrix();
        
    glPopMatrix();
}