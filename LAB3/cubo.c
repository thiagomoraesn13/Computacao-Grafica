//THIAGO MORAES
//21452625
//COMPUTACAO GRAFICA - 2016/2

#include <stdio.h>
#include <stdarg.h>
#include <math.h>
#include <GL/glut.h>

double rotacao_y=0;
double rotacao_x=0;

void display(){
  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);// limpa o frame buffer - cor / depth buffer
  glLoadIdentity();//Reinicia transformações

  // Rotacionar x e y
  glRotatef( rotacao_x, 1.0, 0.0, 0.0 );
  glRotatef( rotacao_y, 0.0, 1.0, 0.0 );

  //FRENTE
  glBegin(GL_POLYGON);
    glColor3f( 0.5, 1.0, 0.6 );
    glVertex3f(  0.5, -0.5, -0.5 );
    glVertex3f(  0.5,  0.5, -0.5 );
    glVertex3f( -0.5,  0.5, -0.5 );
    glVertex3f( -0.5, -0.5, -0.5 );
  glEnd();

  //TRASEIRA
  glBegin(GL_POLYGON);
    glColor3f(   1.0,  1.0, 1.0 );
    glVertex3f(  0.5, -0.5, 0.5 );
    glVertex3f(  0.5,  0.5, 0.5 );
    glVertex3f( -0.5,  0.5, 0.5 );
    glVertex3f( -0.5, -0.5, 0.5 );
  glEnd();

  // Lado roxo - DIREITA
  glBegin(GL_POLYGON);
    glColor3f(  1.0,  0.0,  1.0 );
    glVertex3f( 0.5, -0.5, -0.5 );
    glVertex3f( 0.5,  0.5, -0.5 );
    glVertex3f( 0.5,  0.5,  0.5 );
    glVertex3f( 0.5, -0.5,  0.5 );
  glEnd();
  // Lado verde - ESQUERDA
 glBegin(GL_POLYGON);
  glColor3f(   0.0,  1.0,  0.0 );
  glVertex3f( -0.5, -0.5, 0.5 );
  glVertex3f( -0.5,  0.5,  0.5 );
  glVertex3f( -0.5,  0.5, -0.5 );
  glVertex3f( -0.5, -0.5, -0.5 );
  glEnd();

  // Lado azul - TOPO
 glBegin(GL_POLYGON);
  glColor3f(   0.0,  0.0,  1.0 );
  glVertex3f(  0.5,  0.5,  0.5 );
  glVertex3f(  0.5,  0.5, -0.5 );
  glVertex3f( -0.5,  0.5, -0.5 );
  glVertex3f( -0.5,  0.5,  0.5 );
  glEnd();

  // Lado vermelho - BASE
 glBegin(GL_POLYGON);
  glColor3f(   1.0,  0.0,  0.0 );
  glVertex3f(  0.5, -0.5, -0.5 );
  glVertex3f(  0.5, -0.5,  0.5 );
  glVertex3f( -0.5, -0.5, 0.5 );
  glVertex3f( -0.5, -0.5, -0.5 );
  glEnd();

  glFlush();
  glutSwapBuffers();

}
void fechar(unsigned char chave, int x, int y){ //funcao para fechar a janela, é só clicar na letra 'a' do teclado
   if(chave == 97){
     exit(-1);
   }
}
void mover( int chave, int x, int y ) { //rotacionar o cubo
  if (chave == GLUT_KEY_RIGHT){
    rotacao_y += 5;
  }
  if (chave == GLUT_KEY_LEFT){
    rotacao_y -= 5;
  }
  if (chave == GLUT_KEY_UP){
    rotacao_x += 5;
  }
  if (chave == GLUT_KEY_DOWN){
    rotacao_x -= 5;
  }
  glutPostRedisplay(); ///atualiza o display
}
int main(int argc, char* argv[]){
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowPosition(100,100);
  glutInitWindowSize(400,400);
  glutCreateWindow("cubo-restart");
  glutDisplayFunc(display);
  glutSpecialFunc(mover);
  glutKeyboardFunc(fechar);
  glEnable(GL_DEPTH_TEST);
  glutMainLoop();
  return 0;
}
