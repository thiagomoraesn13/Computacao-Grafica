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

void Desenha()
{
glBegin(GL_POLYGON);
glVertex2f(0,0);
glVertex2f(0,10);
glEnd();
}
void FazDesenho()
{
glTranslatef(10,0,0);
glRotatef(-45,0,0,1);
Desenha(); // 1
glLoadIdentity();
glTranslatef(0,10,0);
Desenha(); // 2
glTranslatef(0,10,0);
glRotatef(90,0,0,1);
Desenha(); // 3
glRotatef(-90,0,0,1);
Desenha(); // 4
}

int main(int argc, char** argv)
{
glutInit(&argc,argv);

  glutInitWindowSize(1000,1000);
  glutCreateWindow("questao1");
glutDisplayFunc(FazDesenho);
glutKeyboardFunc(fechar);
inicializa();
glutMainLoop();
}
