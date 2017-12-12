#include "obj.h"

GLfloat borda_pote[4][9][3] = {
    {
       	{ -3.0, 0.0, -1.0 }, { -3.0, 3.0,-1.0 }, { 0.0, 3.0, -1.0 }, { 3.0, 3.0,-1.0 }, { 3.0, 0.0,-1.0 },
       	{ 3.0, -3.0,-1.0 }, { 0.0, -3.0,-1.0 }, { -3.0, -3.0,-1.0 }, { -3.0, 0.0,-1.0 }
    },
    {
       	{ -3.0, 0.0, -0.5 }, { -3.0, 3.0,-0.5 }, { 0.0, 3.0, -0.5 }, { 3.0, 3.0,-0.5 }, { 3.0, 0.0,-0.5 },
       	{ 3.0, -3.0,-0.5 }, { 0.0, -3.0,-0.5 }, { -3.0, -3.0,-0.5 }, { -3.0, 0.0,-0.5 }
    },
    {
    	{ -2.5, 0.0,  0.5 }, { -2.5, 2.5, 0.5 }, { 0.0, 2.5,  0.5 }, { 2.5, 2.5, 0.5 }, { 2.5, 0.0, 0.5 },
    	{ 2.5, -2.5, 0.5 }, { 0.0, -2.5, 0.5 }, { -2.5, -2.5, 0.5 }, { -2.5, 0.0, 0.5 }
    },
    {
    	{ -1.5, 0.0,  1.0 }, { -1.5, 1.5, 1.0 }, { 0.0, 1.5,  1.0 }, { 1.5, 1.5, 1.0 }, { 1.5, 0.0, 1.0 },
    	{ 1.5, -1.5, 1.0 }, { 0.0, -1.5, 1.0 }, { -1.5, -1.5, 1.0 }, { -1.5, 0.0, 1.0 }
    }
};

GLfloat borda_pote_esp[4][9][3] = {
    {
        { -3.0, 0.0, 1.0 }, { -3.0, 3.0, 1.0 }, { 0.0, 3.0, 1.0 }, { 3.0, 3.0, 1.0 }, { 3.0, 0.0, 1.0 },
        { 3.0, -3.0, 1.0 }, { 0.0, -3.0, 1.0 }, { -3.0, -3.0, 1.0 }, { -3.0, 0.0, 1.0 }
    },
    {
        { -3.0, 0.0, 0.5 }, { -3.0, 3.0,0.5 }, { 0.0, 3.0, 0.5 }, { 3.0, 3.0,0.5 }, { 3.0, 0.0,0.5 },
        { 3.0, -3.0,0.5 }, { 0.0, -3.0,0.5 }, { -3.0, -3.0,0.5 }, { -3.0, 0.0,0.5 }
    },
    {
      { -2.5, 0.0,  -0.5 }, { -2.5, 2.5, -0.5 }, { 0.0, 2.5,  -0.5 }, { 2.5, 2.5, -0.5 }, { 2.5, 0.0, -0.5 },
      { 2.5, -2.5, -0.5 }, { 0.0, -2.5, -0.5 }, { -2.5, -2.5, -0.5 }, { -2.5, 0.0, -0.5 }
    },
    {
      { -1.5, 0.0,  -1.0 }, { -1.5, 1.5, -1.0 }, { 0.0, 1.5,  -1.0 }, { 1.5, 1.5, -1.0 }, { 1.5, 0.0, -1.0 },
      { 1.5, -1.5, -1.0 }, { 0.0, -1.5, -1.0 }, { -1.5, -1.5, -1.0 }, { -1.5, 0.0, -1.0 }
    }
};

GLfloat fundo_pote[4][4][3] = {
    {
        { -1.0, 1.0, 1.0},    { -0.5, 1.5, 1.0},
        { 0.5, 1.5, 1.0},     { 1.0, 1.0, 1.0}
    },
    {
        { -1.5, 0.5, 1.0},    { -0.5, 0.5, 1.0},
        { 0.5, 0.5, 1.0},    {1.5, 0.5, 1.0}
    },
    {
        { -1.5, -0.5, 1.0},     { -0.5, -0.5, 1.0},
        { 0.5, -0.5, 1.0},       { 1.5, -0.5, 1.0}
    },
    {
        { -1.0, -1.0, 1.0},    { -0.5, -1.5, 1.0},
        {0.5, -1.5, 1.0},       {1.0, -1.0, 1.0}
    }
};

GLfloat fundo_pote_esp[4][4][3] = {
    {
        { -1.0, 1.0, -1.0},    { -0.5, 1.5, -1.0},
        { 0.5, 1.5, -1.0},     { 1.0, 1.0, -1.0}
    },
    {
        { -1.5, 0.5, -1.0},    { -0.5, 0.5, -1.0},
        { 0.5, 0.5, -1.0},    {1.5, 0.5, -1.0}
    },
    {
        { -1.5, -0.5, -1.0},     { -0.5, -0.5, -1.0},
        { 0.5, -0.5, -1.0},       { 1.5, -0.5, -1.0}
    },
    {
        { -1.0, -1.0, -1.0},    { -0.5, -1.5, -1.0},
        {0.5, -1.5, -1.0},       {1.0, -1.0, -1.0}
    }
};

GLfloat
pote_diffuse[] = { 0.3, 0.3, 0.3, 1.0 },
pote_specular[] = { .2, .2, .2, 1.0 },
pote_shininess[] = { 20.0 };

// desenha todas as partes
void desenha_pote (void) {
  glColor4f(0.7, 0.7, 0.7, .4);
  glEnable (GL_BLEND);
  glBlendFunc (GL_ONE, GL_ONE);

  glClearColor (0.0, 0.0, 0.0, 0.0);
  glMaterialfv(GL_FRONT, GL_DIFFUSE, pote_diffuse);
  glMaterialfv(GL_FRONT, GL_SPECULAR, pote_specular);
  glMaterialfv(GL_FRONT, GL_SHININESS, pote_shininess);

  glPushMatrix();
    glScalef(0.5, 0.5, 0.5);
    // bordas
    glPushMatrix();
      drawSurface2(borda_pote, 4, 9, 3);
      glColor4f(0.7, 0.7, 0.7, .4);
    glPopMatrix();

    // fundo
    glPushMatrix();
      glScalef(0.9, 0.9, 1);
      glTranslatef(-0.30, 0, 0);
      drawSurface(fundo_pote);
      glColor4f(0.7, 0.7, 0.7, .4);

      glPushMatrix();
        glRotatef(180, 0, 1, 0);
        glTranslatef(0, 0, 0.005);
        drawSurface(fundo_pote_esp);
        glColor4f(0.7, 0.7, 0.7, .4);
      glPopMatrix();

    glPopMatrix();

  glPopMatrix();
  glDisable (GL_BLEND);
}
