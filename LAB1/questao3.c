#include <GL/glut.h>
#include <math.h>
#include <stdlib.h>

//UNIVERSIDDADE FEDERAL DO AMAZONAS - UFAM
//INSTITUTO DE COMPUTAÇÃO - ICOMP
//INTRODUÇÃO A COMPUTAÇÃO GRÁFICA
//PROFESSOR : PIO
//ALUNO:THiAGO MORAES
//MATRÍCULA: 21452625

GLfloat x =2;
GLfloat y=5;
GLfloat raio=5;
//onde x e y sao o centro da circunferencia e raio é o raio.

void inicializa(){
  glClearColor(1.0,1.0,1.0,1.0);
  glMatrixMode(GL_PROJECTION);
  glClearColor(0.0,0.0,0.0,0.0);
  gluOrtho2D(-20,20,-20,20);
}
void fechar(unsigned char chave, int x, int y){ //funcao para fechar a janela, é só clicar na letra 'a' do teclado
   if(chave == 97){
     exit(-1);
   }
}
void desenharCircuferencia(void){ //desenha a circunferencia de raio 5
  glClear(GL_COLOR_BUFFER_BIT); //limpa o buffer
  glColor3f(0.0, 0.0, 1.0); //cor azul
  float i;
  glBegin(GL_POLYGON); //chamando a polygon para preencher a circunferencia
  glBegin(GL_LINE_STRIP);
    for(i=0.0;i<20;i=i+0.001){ //conjunto composto de linhas que equivale a um circulo
      glVertex2f(raio*cos(i)+x, raio*sin(i)+y);
    }
  glEnd();
  glEnd();
  glFlush();

}
int main(int argc, char** argv){
glutInit(&argc,argv);
glutInitWindowSize(500,500); //criando uma janela de dimensao 500x500
glutCreateWindow("CIRCUNFERENCIA"); //nome da janela
glutDisplayFunc(desenharCircuferencia);
glutKeyboardFunc(fechar); //chamada da funcao para fechar a janela
inicializa();
glutMainLoop();
}
