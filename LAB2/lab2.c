#include <GL/glut.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

//UNIVERSIDDADE FEDERAL DO AMAZONAS - UFAM
//INSTITUTO DE COMPUTAÇÃO - ICOMP
//INTRODUÇÃO A COMPUTAÇÃO GRÁFICA
//PROFESSOR : PIO
//ALUNO:THiAGO MORAES
//MATRÍCULA: 21452625

// gcc lab2.c -o saida -lglut -lGLU -lGL


float universo = 21;

void inicializa(){

  glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
  glMatrixMode(GL_PROJECTION);
  glClearColor(0.0,0.0,0.0,0.0);
  gluOrtho2D(20.0f,-10.0f,20.0f,-10.0f);
}


void fechar(unsigned char chave, int x, int y){ //funcao para fechar a janela, é só clicar na letra 'a' do teclado
if(chave == 97){
  exit(-1);
}
}
void Bico(){ //bico do aviao
  glBegin(GL_TRIANGLES);
  glColor3f(0,1,0);
  glVertex3f(3.0,6.0,0.0);
  glVertex3f(4.0,8.0,0.0);
  glVertex3f(5.0,6.0,0.0);
  glEnd();
}

void Corpo(){ //corpo
  glBegin(GL_QUADS);
  glColor3f(0,0,1);
  glVertex3f(3.0,1.0,0.0);
  glVertex3f(5.0,1.0,0.0);
  glVertex3f(5.0,6.0,0.0);
  glVertex3f(3.0,6.0,0.0);
  glEnd();
}

void AsaEsquerda(){ //AsaEsquerda do aviao
  glBegin(GL_TRIANGLES);
  glColor3f(1,0,0);
  glVertex3f(1.5,1.0,0.0);
  glVertex3f(3.0,1.0,0.0);
  glVertex3f(3.0,3.0,0.0);
  glEnd();
}

void AsaDireita(){ //AsaDireita do aviao
  glBegin(GL_TRIANGLES);
  glColor3f(1,0,0);
  glVertex3f(5.0,1.0,0.0);
  glVertex3f(6.5,1.0,0.0);
  glVertex3f(5.0,3.0,0.0);
  glEnd();
}

void desenhaFoguete(void){ //funcao para desenhar o aviao e seguidamente rotacioná-lo e transladá-lo
  glTranslatef(15.0f,0.0f, 1.0f);
  for(universo=0.5;universo<30;universo++){
    glClear(GL_COLOR_BUFFER_BIT); //limpa o buffer
    glColor3f(0.0, 0.0, 1.0); //cor azul
    glRotatef(universo,0.0f, 0.0f, 1.0f);
    glPushMatrix();
    Bico();
    Corpo();
    AsaEsquerda();
    AsaDireita();
    usleep(100000);
    glFlush();
  }
  float i;
  for(i=0.01;i<7;i++){
    glTranslatef(0.0f,i, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT); //limpa o buffer
    glColor3f(0.0, 0.0, 1.0); //cor azul
    Bico();
    Corpo();
    usleep(100000);
    glFlush();
  }
  int j;
  for(j=0.01;j<23.001;j++){

    glRotatef(j,0.0f, 0.0f, 1.0f); //rotacionando
    glClear(GL_COLOR_BUFFER_BIT); //limpa o buffer
    glColor3f(0.0, 0.0, 1.0); //cor azul

    Bico();
    Corpo();

    usleep(100000); //micro sleep para poder visualizar a rotacao
    glFlush();
  }
  for(i=3;i>0.1;i--){
    glTranslatef(0.0f,i, 0.0f); //transladando o eixo y
    glClear(GL_COLOR_BUFFER_BIT); //limpa o buffer
    glColor3f(0.0, 0.0, 1.0); //cor azul
    Bico();
    Corpo();
    AsaEsquerda();
    AsaDireita();
    usleep(100000);
    glFlush();
  }

  for(j=0.01;j<23.001;j++){

    glRotatef(j,0.0f, 0.0f, 1.0f); //rotacionando o eixo x
    glClear(GL_COLOR_BUFFER_BIT); //limpa o buffer
    glColor3f(0.0, 0.0, 1.0); //cor azul
    Bico();
    Corpo();
    AsaEsquerda();
    AsaDireita();
    usleep(100000);
    glFlush();
  }

  for(i=5;i>0.1;i--){
    glTranslatef(0.0f,i, 0.0f); //transladando o eixo y
    glClear(GL_COLOR_BUFFER_BIT); //limpa o buffer
    glColor3f(0.0, 0.0, 1.0); //cor azul
    Bico();
    Corpo();
    AsaEsquerda();
    AsaDireita();
    usleep(100000);
    glFlush();
  }

  for(j=0.01;j<22.009;j++){

    glRotatef(j,0.0f, 0.0f, 1.0f); //rotacionando o eixo y
    glClear(GL_COLOR_BUFFER_BIT); //limpa o buffer
    glColor3f(0.0, 0.0, 1.0); //cor azul
    Bico();
    Corpo();
    AsaEsquerda();
    AsaDireita();

    glPopMatrix(); //devolvendo a matrix inicial

    usleep(100000);
    glFlush();
  }
}
int main(int argc, char** argv){
  glutInit(&argc,argv);
  glutInitWindowSize(1000,1000); //dimensao da janela
  glutInitWindowPosition(10,10);
  glutCreateWindow("FOGUETE DA NASA"); //nome da janela
  glutDisplayFunc(desenhaFoguete);
  glutKeyboardFunc(fechar); //chamada da funcao para fechar a janela, clique na letra a
  inicializa();
  glutMainLoop();
}
