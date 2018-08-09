

#include <cmath>
#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>

using namespace std;
//ângulo de rotação
double anguloRotacao = 10;
//Direção da câmera
float lx = 0.0f,lz = -1.0f;
//Posição da câmera
float x = 0.0f,z = 5.0f;
//ângulo para rotacionar via tecla
float angulo = 0.0f;

void desenhaTeaPot(){
// limpa o frame buffer - cor
glClear(GL_COLOR_BUFFER_BIT |
  // limpa o depth buffer
  GL_DEPTH_BUFFER_BIT);
  //Guarda a transformação atual da câmera
  glPushMatrix();
  //Rotaciona pelo anguloRotacao no eixo y
  glRotated(anguloRotacao, 0, 1, 0);
  //Cor do Teapot
  glEnable(GL_COLOR_MATERIAL);
  glColor3f(0.0, 0.0, 1.0);
  //glutSolidTeapot(1);
  	glutWireTeapot(5.0f);
  //Restaura a matriz
  glPopMatrix();
  glFlush();
  //Faz a imagem ser visível
  glutSwapBuffers();
}

void aumentarTamanho(int w, int h){
  //Previne divisão por zero quando a janela é muito pequena
  if (h == 0){
    h = 1;
  }
  float ratio = w * 1.0 / h;
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glViewport(0, 0, w, h);
  gluPerspective(45.0f, ratio, 0.1f, 100.0f);
  glMatrixMode(GL_MODELVIEW);
}

void exibirCameraObjeto(void){
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  //Reset nas transformações
  glLoadIdentity();
  //Configuração da câmera
  glTranslatef(0, 0, -3);
  gluLookAt(x, 1.0f, z, x+lx, 1.0f, z+lz, 0.0f, 1.0f, 0.0f);
  desenhaTeaPot();
}

void teclasMovimentaObjeto(unsigned char chave, int x, int y){
  switch (chave){
    case 'e':
    //incrementa a rotação em 5 graus
    anguloRotacao += 5;
    break;
    case 'd':
    //Decrementa a rotação em 5 graus
    anguloRotacao -= 5;
    break;
    case 's':
    exit(0);
  }
  glutPostRedisplay();
}

void teclasMovimentaCamera(int chave, int xx, int yy){
  float fracao = 0.1f;
  switch (chave) {
    case GLUT_KEY_LEFT :
    angulo = angulo - 0.01f;
    lx = sin(angulo);
    lz = -cos(angulo);
    break;
    case GLUT_KEY_RIGHT :
    angulo = angulo + 0.01f;
    lx = sin(angulo);
    lz = -cos(angulo);
    break;
    case GLUT_KEY_UP :
    x = x + lx * fracao;
    z = z + lz * fracao;
    break;
    case GLUT_KEY_DOWN :
    x = x - (lx * fracao);
    z = z - (lz * fracao);
    break;
  }
}

void init(){
  //Cor do fundo
  glClearColor(0, 0, 0, 0);
  //Fundo da profundidade
  glClearDepth(1.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(60, 1, 1, 1000);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluLookAt(        // set up the camera
    0.0, 0.0, 5.0,    //Posição do olho
    0.0, 0.0, 0.0,    //Posição look at
    0.0, 1.0, 0.0);   //Direction de cima
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    float lpos[] = { 5, 5, 5, 0 };
    glLightfv(GL_LIGHT0, GL_POSITION, lpos);
    glShadeModel(GL_SMOOTH);
  }

  int main(int argc, char **argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(600,480);
    glutCreateWindow("TEAPOT");
    glutDisplayFunc(exibirCameraObjeto);
    glutReshapeFunc(aumentarTamanho);
    glutIdleFunc(exibirCameraObjeto);
    glutKeyboardFunc(teclasMovimentaObjeto);
    glutSpecialFunc(teclasMovimentaCamera);
    glEnable(GL_DEPTH_TEST);
    init();
    glutMainLoop();
    return 0;
  }
