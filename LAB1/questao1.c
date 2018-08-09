#include <GL/glut.h>

//UNIVERSIDDADE FEDERAL DO AMAZONAS - UFAM
//INSTITUTO DE COMPUTAÇÃO - ICOMP
//INTRODUÇÃO A COMPUTAÇÃO GRÁFICA
//PROFESSOR : PIO
//ALUNO:THiAGO MORAES
//MATRÍCULA: 21452625

void inicializa(){
  glClearColor(1.0,1.0,1.0,1.0);
  glMatrixMode(GL_PROJECTION);
  glClearColor(0.0,0.0,0.0,0.0);
  gluOrtho2D(-2,2,-2,2);
}

void fechar(unsigned char chave, int x, int y){ //funcao para fechar a janela, é só clicar na letra 'a' do teclado
   if(chave == 97){
     exit(-1);
   }
}

void display(){ //desenhar o retangulo
glClear(GL_COLOR_BUFFER_BIT);
glBegin(GL_POLYGON);
     glVertex2f(-0.9, -0.5);
     glVertex2f(-0.9, 0.5);
     glVertex2f(0.9, 0.5);
     glVertex2f(0.9, -0.5);
glEnd();
glFlush();
}
int main(int argc, char** argv)
{
glutInit(&argc,argv);
glutCreateWindow("questao1");
glutDisplayFunc(display);
glutKeyboardFunc(fechar);
inicializa();
glutMainLoop();
}
