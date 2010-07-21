#include <GL/glut.h>

void init(void)
{
	glEnable(GL_DEPTH_TEST);
	glClearColor(1.0, 1.0, 1.0, 0.0);	// Set display-window color to white.
	glColor3f(0.0, 0.0, 1.0);	
	glMatrixMode(GL_PROJECTION);	
    	glOrtho(-50, 50,-50, 50,-50,50);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void color (int selectedColor)
{
	switch (selectedColor) 
	{
		case 1:  glColor3f (1.0, 0.0, 0.0);  break;	//  Set color to red
		case 2:  glColor3f (0.0, 1.0, 0.0);  break;	//  set color to green
		case 3:  glColor3f (0.0, 0.0, 1.0);  break;	//  Set color to blue
		case 4:  glColor3f (0.0, 0.0, 0.0);  break;	//  set color to black
	}
	glutPostRedisplay ( );
}

void display (void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glEnable (GL_LINE_SMOOTH);
	glEnable (GL_BLEND);
	glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glPushMatrix();
	glutWireTeapot (20);

	glPopMatrix();
	glutSwapBuffers();
	glFlush ( );     
}

int main (int argc, char **argv)
{
	glutInit (&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition (50, 50);
	glutInitWindowSize (500, 500);
	glutCreateWindow ("Menu Example");

	init ( );
	glutDisplayFunc (display);

	glutCreateMenu (color);              // Create pop-up menu.
		glutAddMenuEntry ("Red", 1);
		glutAddMenuEntry ("Green", 2);
		glutAddMenuEntry ("Blue", 3);
		glutAddMenuEntry ("Black", 4);

	/*  Select a menu option using the right mouse button.  */
	glutAttachMenu (GLUT_RIGHT_BUTTON);

	glutMainLoop ( );
	return 0;
}
