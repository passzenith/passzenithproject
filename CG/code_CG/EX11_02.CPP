#include <GL/glut.h>
#include <stdlib.h>
 
void init(void) 
{
   glClearColor (0.0, 0.0, 0.0, 0.0);
}

void display (void)
{
  glClear (GL_COLOR_BUFFER_BIT);   
  glClearColor(1.0, 1.0, 1.0, 0.0);
  glPushMatrix();
  glutSolidTeapot(0.5);				// Draw the Teapot 
  glPopMatrix();
  glutSwapBuffers();
}

void keyboard (unsigned char key, int x, int y)
{
	switch (key)
	{
		case 'r':
			glColor3f(1.0, 0.0, 0.0);			// Set color to red
			glutPostRedisplay();
			break;
		case 'g':
			glColor3f(0.0, 1.0, 0.0);			// Set color to green
			glutPostRedisplay();
			break;
		case 'b':
			glColor3f(0.0, 0.0, 1.0);			// Set color to blue
			glutPostRedisplay();
			break;
		case 27:						// ESC key
			exit(0);					// exit
			break;
		default:
			break;
	}
}

int main (int argc, char **argv)
{
	glutInit (&argc, argv);             
	glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE);     
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(50, 50);
	glutCreateWindow ("Keyboard function : r=red, g=green, b=blue, ESC=exit");         
	glutDisplayFunc(display);           
	glutKeyboardFunc (keyboard);
	glutMainLoop ();                    
	return 0;
}
