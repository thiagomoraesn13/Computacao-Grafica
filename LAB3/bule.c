
//THIAGO MORAES
//21452625
//COMPUTACAO GRAFICA - 2016/2

#include <math.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>

GLfloat angle, fAspect;

double rotacionar = 10 ;
float lx = 0.0f,lz = -1.0f; //Direção da câmera
float x = 0.0f,z = 5.0f; //Posição da câmera
float angulo = 0.0f; //angulo pra rotacionr a tela

void Inicializa(){
  glClearColor(0, 0, 0, 0);
  glClearDepth(1.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  angle=45;
}

void desenha(){
  glClear(GL_COLOR_BUFFER_BIT |   GL_DEPTH_BUFFER_BIT);// limpa o frame buffer - cor / depth buffer
  glPushMatrix(); //Guarda a matriz de transformacao atuaal
  glRotated(rotacionar, 0, 1, 0); //Rotaciona pelo anguloRotacao no eixo y
  glColor3f(0.0, 0.0, 1.0);//cor do objeto
  glutWireTeapot(1.0f); //criando o bule
  glPopMatrix(); //Restaura a matriz
  glFlush();
  glutSwapBuffers(); //representa os buffers de desenho e retorna uma nova imagem do objeto.
}

void AlteraTamanhoJanela(int w, int h){
  if (h == 0){ //evitar que a janela fique muito pequena
    h = 1;
  }
  fAspect = w * 1.0 / h;
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity(); //Reinicia transformações
  glViewport(0, 0, w, h);
  gluPerspective(angle, fAspect, 0.1f, 100.0f);
  glMatrixMode(GL_MODELVIEW);
}
void movercamera(void){
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glLoadIdentity(); //reinicia as transformaçoes
  glTranslatef(0, 0, -3);
  gluLookAt(x, 1.0f, z, x+lx, 1.0f, z+lz, 0.0f, 1.0f, 0.0f); //movendo a camera
  desenha(); //chamando o bule
}
void mover(int chave, int xx, int yy){ //funcao para o angulo da camera conforme clicar nas setas do teclado, cima,baixo,direita e esquerda
  float fracao = 0.1f;
    if(chave == GLUT_KEY_LEFT ){
      angulo = angulo + 0.01f;
      lx = sin(angulo);
      lz = -cos(angulo);
    }
    if(chave==GLUT_KEY_LEFT) {
    angulo = angulo + 0.01f;
    lx = sin(angulo);
    lz = -cos(angulo);
    }
    if(chave==GLUT_KEY_RIGHT){
    angulo = angulo - 0.01f;
    lx = sin(angulo);
    lz = -cos(angulo);
    }
    if(chave == GLUT_KEY_UP){
    x = x + lx * fracao;
    z = z + lz * fracao;
    }
    if(chave == GLUT_KEY_DOWN){
    x = x - (lx * fracao);
    z = z - (lz * fracao);
    }
}
void fechar(unsigned char chave, int x, int y){ //funcao para fechar a janela, é só clicar na letra 'a' do teclado
   if(chave == 97){
     exit(-1);
   }
}
int main(int argc, char **argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(750,750);

    glutCreateWindow("bule-de-chá");
    glutDisplayFunc(movercamera);
    glutReshapeFunc(AlteraTamanhoJanela);
    glutIdleFunc(movercamera);
    glutSpecialFunc(mover);

    glutKeyboardFunc(fechar);
    glEnable(GL_DEPTH_TEST);
    Inicializa();
    glutMainLoop();
    return 0;
}
