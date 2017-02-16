#include "obj.h"


GLfloat tigela_fri[4][4][3] = {
    {
        { -1.0, 1.0, 0},    { -0.5, 1.5, 0}, 
        { 0.5, 1.5, 0},     { 1.0, 1.0, 0}
    }, 
    {
        { -1.5, 0.5, 0},    { -0.5, 0.5, -0.5}, 
        { 0.5, 0.5, -0.5},    {1.5, 0.5, 0}
    }, 
    {
        { -1.5, -0.5, 0},     { -0.5, -0.5, -0.5}, 
        { 0.5, -0.5, -0.5},       { 1.5, -0.5, 0}
    }, 
    {
        { -1.0, -1.0, 0},    { -0.5, -1.5, 0}, 
        {0.5, -1.5, 0},       {1.0, -1.0, 0}
    }
};

// desenha todas as partes
void desenha_frig (void) {
    glPushMatrix(); 
        glPushMatrix();
            //glTranslatef(0, 3.9, 0);
            glEnable(GL_BLEND);
            glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
            glColor4f(1, 1, 1, 0.4);
            //glRotatef(90, 1, 0, 0);
            drawSurface(tigela_fri); //
        
    glPopMatrix();
}