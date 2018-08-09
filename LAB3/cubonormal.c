
//THIAGO MORAES
//21452625
//COMPUTACAO GRAFICA - 2016/2

#include <GL/glut.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

GLfloat angle, fAspect;
int muda =0;

// Função callback chamada para fazer o desenho
void Desenha(void){
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0f, 0.5f, 1.0f);

	glutWireCube(50.0f);
	glutSwapBuffers();
	sleep(5);

	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0f, 0.5f, 1.0f);
	glutSolidCube(50.0f);
	glutSwapBuffers();
}

void Inicializa (void){
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    angle=45;
}

void EspecificaParametrosVisualizacao(void){
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(angle,fAspect,0.1,500);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0,80,200, 0,0,0, 0,1,0);
}
void AlteraTamanhoJanela(GLsizei w, GLsizei h){

	if ( h == 0 ){
			h = 1;
	}
	glViewport(0, 0, w, h);
	fAspect = (GLfloat)w/(GLfloat)h;
	EspecificaParametrosVisualizacao();
}

void GerenciaMouse(int button, int state, int x, int y){
	if (button == GLUT_LEFT_BUTTON)
		if (state == GLUT_DOWN) {  // Zoom-in
			if (angle >= 10) angle -= 5;
		}
	if (button == GLUT_RIGHT_BUTTON){
		if (state == GLUT_DOWN) {  // Zoom-out
			if (angle <= 130){
				muda +=20; //angle += 5;
			}
		}
	}
	EspecificaParametrosVisualizacao();
	glutPostRedisplay();
}


void fechar(unsigned char chave, int x, int y){ //funcao para fechar a janela, é só clicar na letra 'a' do teclado
   if(chave == 97){
     exit(-1);
   }
}
int main(int argc, char** argv){
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(400,400);
	glutCreateWindow("Visualizacao 3D");
	glutDisplayFunc(Desenha);
	glutIdleFunc(EspecificaParametrosVisualizacao);
	glutReshapeFunc(AlteraTamanhoJanela);
	glutMouseFunc(GerenciaMouse);
	glutKeyboardFunc(fechar);
	Inicializa();
	glutMainLoop();
}
