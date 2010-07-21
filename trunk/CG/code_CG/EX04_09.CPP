#include <GL/glut.h>      
#include <math.h>
#define GL_PI 3.1415926535897

void init (void)
{
	glClearColor (1.0, 1.0, 1.0, 0.0);  		
	glMatrixMode (GL_PROJECTION);       	
	glLineWidth(2.0);			
	gluOrtho2D (-2.0, 2.0, -2.0, 2.0);
//  gluOrtho2D (0.0, 2.0, 0.0, 2.0);	// If want to plot only one octant
}

void myDisplay (void)
{
	// Specify the number of points on the circle line
	GLint circle_points = 200; 
	GLint i;
	GLfloat angle;
	glClear (GL_COLOR_BUFFER_BIT);		
	glColor3f (0.0, 0.0, 1.0);			

	glBegin(GL_LINE_LOOP); 
		for (i = 0; i < circle_points; i++) 
		{    
			angle = 2*GL_PI*i/circle_points; 
			glVertex2f (cos(angle), sin(angle)); 
		} 
	glEnd();

    	glFlush ( );     				
}

int  main (int argc, char** argv)
{
	glutInit (&argc, argv);                         			
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);   	
	glutInitWindowPosition (50, 100);  			
	glutInitWindowSize (400, 400);      			
	glutCreateWindow ("Drawing Circle with OpenGL"); 	
	init ( );                            				
	glutDisplayFunc (myDisplay);       			
	glutMainLoop ( );  
    return 0;                  				
}
