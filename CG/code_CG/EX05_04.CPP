#include <GL/glut.h>      			

#define   drawOneLine(x1, y1, x2, y2) glBegin(GL_LINES); \
   glVertex2f ((x1),(y1)); glVertex2f ((x2),(y2)); glEnd();

void init (void)
{
	glClearColor (1.0, 1.0, 1.0, 0.0);		
	glMatrixMode (GL_PROJECTION);       	
	glLoadIdentity ();
	gluOrtho2D (0.0, 400.0, 0.0, 400.0);
}

void myDisplay (void)
{
 	glClear (GL_COLOR_BUFFER_BIT);

// Line from the bottom 
//	1st row — dotted line with factor = 1 
	glEnable (GL_LINE_STIPPLE);
	glLineWidth (1.0);					// Specify line width.
	glColor3f (1.0, 0.0, 0.0);			// Specify line color to red.
	glLineStipple (1, 0xFFFF);   
	drawOneLine (50.0, 25.0, 350.0, 25.0);

//	2nd row — dotted line with factor = 10 
	glLineStipple (10, 0xFFFF);
    drawOneLine (50.0, 50.0, 350.0, 50.0);
//	3rd row — dashed line with factor = 1 
	glLineStipple (1, 0x00FF);
    	drawOneLine (50.0, 75.0, 350.0, 75.0);

//	4th row — dashed line with factor = 5 
	glLineStipple (5, 0x00FF);
    	drawOneLine (50.0, 100.0, 350.0, 100.0);

//	5th row — dotted line with factor = 1 
	glColor3f (0.0, 0.0, 1.0);			// Set line color to blue.
	glLineStipple (1, 0xAAAA);
    	drawOneLine (50.0, 125.0, 350.0, 125.0);

//	6th row — dotted line with factor = 5 to be dashed 
	glLineStipple (5, 0xAAAA);
    	drawOneLine (50.0, 150.0, 350.0, 150.0);

//	7th row — dotted - dashed with factor = 1 
	glLineStipple (1, 0x0C0F);
    	drawOneLine (50.0, 175.0, 350.0, 175.0);

//	8th row — dotted - dashed with factor = 5 
	glLineStipple (5, 0x0C0F);
    	drawOneLine (50.0, 200.0, 350.0, 200.0);

//	9th row — dotted - dashed with factor = 5 and line width = 5
    	glLineWidth (5.0);
	glLineStipple (5, 0x0C0F);
    	drawOneLine (50.0, 225.0, 350.0, 225.0);

//  10th row — another dotted - dashed with factor = 5 
	glLineWidth (1.0);    
	glColor3f (1.0, 0.0, 0.0);			// Set line color to red
	glLineStipple (5, 0x1C47);
	drawOneLine (50.0, 250.0, 350.0, 250.0); 

//  11th row — another dotted - dashed with factor = 5 
	glLineWidth (5.0);
	glLineStipple (5, 0x1C47);
	drawOneLine (50.0, 275.0, 350.0, 275.0); 

//  12th row — 3 lines each with a different stipple with line Width = 1  
	glLineWidth (1.0);
	glLineStipple (1, 0x0101);   			//  dotted   
	drawOneLine (50.0, 300.0, 150.0, 300.0);
	glLineStipple (1, 0x00FF);   			//  dashed   
	drawOneLine (150.0, 300.0, 250.0, 300.0);

	glLineStipple (1, 0x1C47);   			//  dash/dot/dash   
	drawOneLine (250.0, 300.0, 350.0, 300.0);

//  13th row — 3 lines each with a different stipple with line Width = 5   
	glLineWidth (5.0);
	glLineStipple (1, 0x0101);
	drawOneLine (50.0, 325.0, 150.0, 325.0);
	glLineStipple (1, 0x00FF);
	drawOneLine (150.0, 325.0, 250.0, 325.0);
	glLineStipple (1, 0x1C47);
	drawOneLine (250.0, 325.0, 350.0, 325.0);

//  14th row — 3 lines each with a different stipple with line Width = 10   
	glLineWidth (10.0);
	glLineStipple (1, 0x0101);
	drawOneLine (50.0, 350.0, 150.0, 350.0);
	glLineStipple (1, 0x00FF);
	drawOneLine (150.0, 350.0, 250.0, 350.0);
	glLineStipple (1, 0x1C47);
	drawOneLine (250.0, 350.0, 350.0, 350.0);

glFlush ();
}

int main (int argc, char** argv)
{
	glutInit (&argc, argv);                         			
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);   	
	glutInitWindowPosition (100, 50);			
	glutInitWindowSize (400, 400);			
	glutCreateWindow ("Stripple line in OpenGL Program"); 
	init ( );					
	glutDisplayFunc (myDisplay);		
	glutMainLoop ( );
    return 0;	
}		
