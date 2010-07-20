#include <GL/glut.h>      			
void init (void)
{
	glClearColor (1.0, 1.0, 1.0, 0.0);		
	glColor3f (0.0, 0.0, 1.0);			
	glLineWidth(4.0);			
	glMatrixMode (GL_PROJECTION);      
	glLoadIdentity ();
	gluOrtho2D (0.0, 400.0, 0.0, 300.0);
}

void myDisplay (void)
{
	int p0 [ ] = {50, 200};
	int p1 [ ] = {100, 50};
	int p2 [ ] = {300, 100};
	int p3 [ ] = {350, 250};
	int p4 [ ] = {200, 150};
	glClear (GL_COLOR_BUFFER_BIT);  

//	For function GL_LINES.
	glBegin (GL_LINES);			// 2 line from p0-p1 and p2-p3.
		glVertex2iv (p0);       
		glVertex2iv (p1);
		glVertex2iv (p2);
		glVertex2iv (p3);
		glVertex2iv (p4);
	glEnd ( );

//	For function GL_LINE_STRIP.
/*	glBegin (GL_LINE_STRIP);	// 4 line from p0-p1, p1-p2, p2-p3, p3-p4.
		glVertex2iv (p0);       
		glVertex2iv (p1);
		glVertex2iv (p2);
		glVertex2iv (p3);
		glVertex2iv (p4);
	glEnd ( );
*/

//	For function GL_LINE_LOOP.
/*	glBegin (GL_LINE_LOOP);	// 5 line from p0-p1, p1-p2, p2-p3, p3-p4 and p4-p0.
		glVertex2iv (p0);       
		glVertex2iv (p1);
		glVertex2iv (p2);
		glVertex2iv (p3);
		glVertex2iv (p4);
	glEnd ( );
*/

	glFlush ( );     
}

void main (int argc, char** argv)
{
	glutInit (&argc, argv);                        
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);   	
	glutInitWindowPosition (50, 100);			
	glutInitWindowSize (400, 300);			
	glutCreateWindow ("Draw lines with OpenGL Program"); 

	init ( );					
	glutDisplayFunc (myDisplay);		
	glutMainLoop ( );			
}
