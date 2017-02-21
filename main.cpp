//g++ main.cpp -o main -lglut -lGL -lGLU
//referencias: http://www.glprogramming.com/red/chapter12.html
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include "obj.h"  
GLfloat gira = 0;

int flagPoints = 0; // var global
GLUnurbsObj *theNurb;

void display(void) {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glPushMatrix();
  	gluLookAt (0, 0, 10, 0, 0, 0, 0, 1, 0);

    glRotatef(gira += .1, 1, 1, 0);
    //desenha_frig();
    desenha_colher();
    
    //desenha_pote();
  

  glPopMatrix();
  glFlush();
}

// flag de erros do nurbs
void nurbsError(GLenum errorCode) {
   const GLubyte *estring;
   estring = gluErrorString(errorCode);
   fprintf (stderr, "Nurbs Error: %s\n", estring);
   exit (0);
}
   
// inicia algumas diretivas, como luz
void init(void) {
   GLfloat luzAmbiente[4] = { 0.2,0.2,0.2,1.0 };
    GLfloat luzDifusa[4] = { 0.7,0.6,0.6,1.0 };    // "cor"
    GLfloat luzEspecular[4] = { 0.8,0.8,0.8, 1.0 };// "brilho"
    GLfloat posicaoLuz[4] = { 10.0, 10.0, 0, 1.0 };
//
    // Capacidade de brilho do material
    GLfloat especularidade[4] = { 0.0,0.0,0.0,1.0 };
    GLint especMaterial = 2;

    // Define a reflet�ncia do material
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, especularidade);
    // Define a concentra��o do brilho
    glMateriali(GL_FRONT_AND_BACK, GL_SHININESS, especMaterial);

    // Ativa o uso da luz ambiente
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luzAmbiente);

    // Define os par�metros da luz de n�mero 0
    glLightfv(GL_LIGHT1, GL_AMBIENT, luzAmbiente);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, luzDifusa);
    glLightfv(GL_LIGHT1, GL_SPECULAR, luzEspecular);
    glLightfv(GL_LIGHT1, GL_POSITION, posicaoLuz);

    // Habilita a defini��o da cor do material a partir da cor corrente
    glEnable(GL_COLOR_MATERIAL);
    //Habilita o uso de ilumina��o
    glEnable(GL_LIGHTING);
    // Habilita a luz de n�mero 1
    glEnable(GL_LIGHT1);

   theNurb = gluNewNurbsRenderer();
   gluNurbsProperty(theNurb, GLU_SAMPLING_TOLERANCE, 25.0);
   gluNurbsProperty(theNurb, GLU_DISPLAY_MODE, GLU_FILL);
   gluNurbsCallback(theNurb, GLU_ERROR, (GLvoid (*)()) nurbsError);
}

// função referente a tela
void reshape(int w, int h) {
   glViewport(0, 0, (GLsizei) w, (GLsizei) h);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   gluPerspective (45.0, (GLdouble)w/(GLdouble)h, 1.0, 500.0);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   glTranslatef (0.0, 0.0, -5.0);
}

// função do glut que le chars do teclado
void keyboard(unsigned char key, int x, int y) {
   switch (key) {
      case 'c':
      case 'C':
         flagPoints = !flagPoints;
         glutPostRedisplay();
         break;
      case 27:
         exit(0);
         break;
      default:
         break;
   }
}


void Redraw(void) { // função de loop
   glutPostRedisplay();
}

int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
   glutInitWindowSize (500, 500);
   glutInitWindowPosition (100, 100);
   glutCreateWindow(argv[0]);
   init();
   glutIdleFunc(Redraw);
   glutReshapeFunc(reshape);
   glutDisplayFunc(display);
   glutKeyboardFunc (keyboard);
   glutMainLoop();
   return 0; 
}