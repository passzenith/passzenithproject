#include <GL/glut.h>
 
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

void mouseFcn (int button, int action, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && action == GLUT_DOWN)	// Left button
	{
		glColor3f(1.0, 0.0, 0.0);			// Set color to red
		glutPostRedisplay();
	}

	else if (button == GLUT_LEFT_BUTTON && action == GLUT_UP)// Release left 
	{
		glColor3f(1.0, 0.0, 0.0);			// Set color to red
		glutPostRedisplay();
	}
		else if (button == GLUT_RIGHT_BUTTON && action == GLUT_DOWN)	// Right
	{
		glColor3f(0.0, 1.0, 0.0);			// Set color to green
		glutPostRedisplay();
	}

	else if (button == GLUT_RIGHT_BUTTON && action == GLUT_UP)// Release
	{
		glColor3f(0.0, 1.0, 0.0);			// Set color to green
		glutPostRedisplay();
	}

	else 
	{
		glColor3f(0.0, 0.0, 1.0);			// Set color to blue
		glutPostRedisplay();
	}
}

void main (int argc, char **argv)
{
	glutInit (&argc, argv);             
	glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE);     
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(50, 50);
	glutCreateWindow ("Mouse function : Left mouse = red, Right mouse = green, Middle = blue");         
	glutDisplayFunc(display);           
	glutMouseFunc (mouseFcn);  
	glutMainLoop ();                    
}