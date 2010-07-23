#include <GL/glut.h>

#define UP 0
#define DOWN 1

int width = 600;
int height = 600;

float position = -10.0;
float angle = 0.0;
int wingDir = UP;


void drawLeftWing()
{
	glBegin(GL_QUADS);
		glColor3f(1,0,0);
		glVertex3f(1.0, 0.0, 0.0);
		glColor3f(1,1,0);
		glVertex3f(1.0, 0.0, -1.0);
		glColor3f(1,1,0);
		glVertex3f(-1.0, 0.0, -1.0);
		glColor3f(1,0,0);
		glVertex3f(-1.0, 0.0, 0.0);
	glEnd();
}

void drawRightWing()
{
	glBegin(GL_QUADS);
		glColor3f(1,0,0);
		glVertex3f(1.0, 0.0, 0.0);
		glColor3f(1,0,0);
		glVertex3f(-1.0, 0.0, 0.0);
		glColor3f(1,1,0);
		glVertex3f(-1.0, 0.0, 1.0);
		glColor3f(1,1,0);
		glVertex3f(1.0, 0.0, 1.0);
	glEnd();
}

void display(void)								
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();								
	gluLookAt(10, 5, 10, 0, 0, 0, 0, 1, 0);
	glTranslatef(position, 0, 0);

	glPushMatrix();
	glRotatef(angle, 1, 0, 0);
	drawLeftWing();
	glPopMatrix();

	glRotatef(-angle, 1, 0, 0);
	drawRightWing();

	if (wingDir == UP) 
	{
		angle += 0.5;
			if (angle > 45)
				wingDir = DOWN;
	}
	else 
	{
		angle -= 0.5;
			if (angle < -45)
				wingDir = UP;
	}
     	         
	position += 0.001;
    
	glutSwapBuffers();
}

void init()
{
	glClearColor(0.5, 0.5, 1.0, 1.0);
	
	glEnable(GL_DEPTH_TEST);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();	
	gluPerspective(45.0f,width/height,1.0f,100.0f);
	glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(width, height);
	glutCreateWindow("Butterfly");
	glutDisplayFunc(display);
	glutIdleFunc(display);
	init();
	glutMainLoop();
	return 0;
}
