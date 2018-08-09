#include <GL/glut.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// actual vector representing the camera's direction
float lx=0.0f,lz=-1.0f;
// XZ position of the camera
float x=0.0f,z=5.0f;
double rotAngle =10;
// all variables initialized to 1.0, meaning
// the triangle will initially be white
float red=1.0f, blue=1.0f, green=1.0f;

// angle for rotating triangle
float angle = 0.0f;

//int dummy = 5;

void display()
{
		glClear(
	GL_COLOR_BUFFER_BIT |		// clear the frame buffer (color)
	GL_DEPTH_BUFFER_BIT);		// clear the depth buffer (depths)

		glPushMatrix();			// save the current camera transform

		glRotated(rotAngle, 0, 1, 0);	// rotate by rotAngle about y-axis


		glEnable(GL_COLOR_MATERIAL);	// specify object color
		glColor3f(1.0, 0.1, 0.1);		// redish

		glutSolidTeapot(1);			// draw the teapot

		glPopMatrix();			// restore the modelview matrix
		glFlush();				// force OpenGL to render now

		glutSwapBuffers();			// make the image visible
}


void drawSnowMan()
{

//glColor3f(1.0f, 1.0f, 1.0f);

glClear(GL_COLOR_BUFFER_BIT);
glColor3f(0.0f, 0.0f, 1.0f);
// Desenha o teapot com a cor corrente (wire-frame)

glutWireTeapot(50.0f);
}
void changeSize(int w, int h)
{

// Prevent a divide by zero, when window is too short
// (you cant make a window of zero width).
if (h == 0)
h = 1;
float ratio = w * 1.0 / h;

// Use the Projection Matrix
glMatrixMode(GL_PROJECTION);

// Reset Matrix
glLoadIdentity();

// Set the viewport to be the entire window
glViewport(0, 0, w, h);

// Set the correct perspective.
gluPerspective(45.0f, ratio, 0.1f, 100.0f);

// Get Back to the Modelview
glMatrixMode(GL_MODELVIEW);
}

void renderScene(void)
{

// Clear Color and Depth Buffers

glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

// Reset transformations
display();

// Set the camera
gluLookAt( x, 1.0f, z,
x+lx, 1.0f, z+lz,
0.0f, 1.0f, 0.0f);

// Draw ground
glColor3f(0.9f, 0.9f, 0.9f);
glBegin(GL_QUADS);
glVertex3f(-100.0f, 0.0f, -100.0f);
glVertex3f(-100.0f, 0.0f, 100.0f);
glVertex3f( 100.0f, 0.0f, 100.0f);
glVertex3f( 100.0f, 0.0f, -100.0f);
glEnd();



glutSwapBuffers();
}

void processNormalKeys(unsigned char key, int x, int y)
{

if (key == 27)
exit(0);
}

void processSpecialKeys(int key, int xx, int yy)
{

float fraction = 0.1f;

switch (key) {
case GLUT_KEY_LEFT :
angle -= 0.01f;
lx = sin(angle);
lz = -cos(angle);
break;
case GLUT_KEY_RIGHT :
angle += 0.01f;
lx = sin(angle);
lz = -cos(angle);
break;
case GLUT_KEY_UP :
x += lx * fraction;
z += lz * fraction;
break;
case GLUT_KEY_DOWN :
x -= lx * fraction;
z -= lz * fraction;
break;
}
}

int main(int argc, char **argv)
{

// init GLUT and create window

glutInit(&argc, argv);
glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
glutInitWindowPosition(100,100);
glutInitWindowSize(320,320);
glutCreateWindow("Lighthouse3D - GLUT Tutorial");

// register callbacks
glutDisplayFunc(renderScene);
glutReshapeFunc(changeSize);
glutIdleFunc(renderScene);
glutKeyboardFunc(processNormalKeys);
glutSpecialFunc(processSpecialKeys);

// OpenGL init
glEnable(GL_DEPTH_TEST);

// enter GLUT event processing cycle
glutMainLoop();

return 1;
}
