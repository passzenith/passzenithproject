#include <stdlib.h>
#include <GL/glut.h>
#define SIZE 50.0

GLUquadricObj *theObj;
float i=0.0;

void init(void)
{
	glEnable(GL_DEPTH_TEST);
	glClearColor(0.0, 0.0, 0.0, 0.0);
	theObj = gluNewQuadric();
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPushMatrix();
	glColor3f(1.0, 0.0, 0.0);
	gluQuadricDrawStyle(theObj,GLU_FILL);			// Solid
	gluSphere(theObj, 20.0, 30, 20);							// Sun
	gluQuadricDrawStyle(theObj,GLU_LINE);			// Wire
	glRotatef(i, 0.0, 1.0, 0.0);
	glPushMatrix();														//Position A
	glTranslatef(40.0, 0.0, 0.0);
	glColor3f(1.0, 1.0, 0.0);
	glPushMatrix();														//Position B
	glRotatef(90, 1.0, 0.0, 0.5);
	gluDisk(theObj, 6.0, 8.0, 50, 2);							// Disk
	glPopMatrix();														//Position B

glRotatef(90.0, 1.0, 0.0, 0.0);
	gluSphere(theObj, 5.0, 50, 20);				// Small planet
	glPopMatrix();						//Position A
	glPopMatrix();
	glutSwapBuffers();
}

void animate (void)
{
  i += 0.1;
  glutPostRedisplay();				// Signal for display event 
 }

void reshape(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if(w<=h && w>0)
		glOrtho(-SIZE,SIZE,-h/w*SIZE, h/w*SIZE,0.0,2*SIZE);
	else if(h>0)
		glOrtho(-w/h*SIZE,w/h*SIZE, -SIZE,SIZE,0.0,2*SIZE);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0.0,0.0,-SIZE);
}

void keyboard(unsigned char key, int x, int y)
{
  switch(key)
  {
    case 27:
      exit(0);
      break;
    case 'f':
      glutFullScreen();
      break;
    case 'w':
      glutReshapeWindow(600, 600);
      break;
   }
}

int main (int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowSize(600, 600);
	glutCreateWindow("Solar System");
	init();
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutDisplayFunc(display);
	glutIdleFunc(animate);
	glutMainLoop();
	return 0;
}
