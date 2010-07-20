#include <GL/glut.h>

void init(void) 
{
   glClearColor (1.0, 1.0, 1.0, 0.0);
   glShadeModel (GL_FLAT);
}

void display(void)
{
   glClear (GL_COLOR_BUFFER_BIT);
   glColor3f (0.0, 0.0, 0.0);
   glLoadIdentity ();             
   /* viewing transformation  */
   gluLookAt (0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 1.0, 1.0, 0.0);
   glRotatef (90.0, 0.0, 1.0, 1.0);	
   glutWireCube (2.0);
   glFlush ();
}

void reshape (int w, int h)
{
   glViewport (0, 0, (GLsizei) w, (GLsizei) h); 
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity ();
   glFrustum (-1.0, 1.0, -1.0, 1.0, 2.0, 20.0);
   glMatrixMode (GL_MODELVIEW);
}

void main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
   glutInitWindowSize (500, 500); 
   glutInitWindowPosition (50, 50);
   glutCreateWindow ("Cube in Perspective Projection Look at (1, 1, 0)");
   init ();
   glutDisplayFunc(display); 
   glutReshapeFunc(reshape);
   glutMainLoop();
}
