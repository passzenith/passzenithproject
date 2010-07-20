#include <GL/glut.h>	

void init(void)
{
	glEnable(GL_DEPTH_TEST);
	glClearColor(1.0, 1.0, 1.0, 0.0);	
	glColor3f(0.0, 0.0, 1.0);	
	glMatrixMode(GL_PROJECTION);	
    glOrtho(-1,1,-1,1,-1,1);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	
	
	glPushMatrix();
	glRotatef (90, 0.0, 1.0, 1.0);	
	glutWireCube (1); 
	
	glPopMatrix();
	glutSwapBuffers();
	glFlush ( );     
}

void main (int argc, char** argv)
{
	glutInit (&argc, argv);                       
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB); 
	glutInitWindowPosition (50, 50);
	glutInitWindowSize(400, 400);	
	glutCreateWindow("Cube in Orthogonal Projection");	
	init();			
	glutDisplayFunc(myDisplay);	
	glutIdleFunc(myDisplay);
	glutMainLoop();		
}