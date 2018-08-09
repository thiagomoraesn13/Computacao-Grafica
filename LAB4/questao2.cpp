
//THIAGO MORAES
//21452625
//COMPUTACAO GRAFICA - 2016/2


#include <math.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>
#include <stdio.h>
#include <math.h>



#define LARGURA 500
#define ALTURA 500

float **p;
int indice;
int grau;

void fechar(unsigned char chave, int x, int y){ //funcao para fechar a janela, é só clicar na letra 'a' do teclado
   if(chave == 97){
     exit(-1);
   }
}

void atualiza(int x, int y) {
  float cx, cy;

  cx = (((float)(2.0f*x)/(float)LARGURA) - 1.0f);
  cy = (((float)(2.0f*y)/(float)ALTURA) - 1.0f);
  cy *= -1.0f;

  p[indice][0] = cx;
  p[indice][1] = cy;
  glutPostRedisplay();
}
void escolha(int botao, int estado, int x, int y) {
  if((botao == GLUT_LEFT_BUTTON) && (estado == GLUT_DOWN)) {
    indice = 1;
  }
  if((botao == GLUT_RIGHT_BUTTON) && (estado == GLUT_DOWN)) {
    indice = 2;
  }
  atualiza(x,y);
}

void captura(int x, int y) {
  atualiza(x,y);
}

float fatorial(int a) {
  int i;
  float produto;

  produto = 1.0f;

  for(i=a;i>0;i--) {
    produto *= (float)i;
  }
  return produto;
}

float combinacao(int a, int b) {
  return fatorial(b)/(fatorial(a)*fatorial(b-a));
}

void exibe(void) {
  GLint i;
  GLfloat u,x,y;

  glClear(GL_COLOR_BUFFER_BIT);

  glColor3f(1.0f,0.0f,0.0f);
  glBegin(GL_LINE_STRIP);
  for(i=0;i<(grau+1);i++) {
    glVertex2f(p[i][0],p[i][1]);
  }
  glEnd();

  glColor3f(0.0f,1.0f,0.0f);
  glBegin(GL_POINTS);
  for(u=0.0f;u<=1.0f;u+=0.001f) {
    x = ( (pow(1-u,2)*p[0][0]) + (2*u*p[1][0]*(1-u)) + (pow(u,2)*p[2][0]) );
    y = ( (pow(1-u,2)*p[0][1]) + (2*u*p[1][1]*(1-u)) + (pow(u,2)*p[2][1]) );
    glVertex2f(x,y);
  }
  glEnd();

  glFlush();
}

int main(int argc, char **argv) {
  int n;
  float x,y;
  int i;
  printf("Grau ? (>=3): ");
  scanf("%d",&n);
  printf("\n");
  if(n<3) {
    printf("GRAU >= 3!!!!");
    exit(0);
  }
  p = (float**) calloc(n,sizeof(float *));
  for(i=0;i<n;i++) {
    p[i] = (float *) calloc(2,sizeof(float));
  }

  for(i=0;i<n;i++) {
    printf("Ponto %d: ",i);
    scanf("%f %f",&x,&y);
    p[i][0] = x;
    p[i][1] = y;
  }

  grau = n - 1;

  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(ALTURA,LARGURA);
  glutInitWindowPosition(20,20);
  glutCreateWindow("Desenhando uma curva de Bézier");
  glutDisplayFunc(exibe);
  glutMouseFunc(escolha);
    glutKeyboardFunc(fechar);
  glutMotionFunc(captura);
  glutMainLoop();

  return 0;
}
