/*
CG Assignment #2

By  Noravee     Sungpuag    50051291
    Passarapa   Kerdinntra  50051374
*/
#include<GL/glut.h> 
#include <stdio.h>
#include <conio.h>
#include <time.h>

int xCenter,yCenter,radius; 
int x=0;
int y=0;

 
void setPixel(int xC, int yC) 
{  
     glBegin(GL_POINTS); 
     glVertex2i(xC, yC); 
     glEnd(); 
     glFlush(); 
} 
 
void circleMidPoint(int xc, int yc, int radius) 
{ 
     int h = 1-radius; 
     x=0;
     y=radius;
     void circlePlotPoints(int, int, int, int); 
     circlePlotPoints(xc, yc, x, y); 
     
     while(x < y) 
     { 
      x++; 
      if(h < 0) 
      { 
           h += 2 * x + 3; 
      }
      else
      { 
       y--;
       h += 2 * (x - y) + 5; 
      } 
      circlePlotPoints(xc, yc, x, y); 
     } 
} 
 
void circlePlotPoints(int xc, int yc, int x ,int y) 
{ 
 // Eight-Way Symmetry
 setPixel(xc + x , yc + y); 
 setPixel(xc - x , yc + y); 
 setPixel(xc + x , yc - y); 
 setPixel(xc - x , yc - y); 
 setPixel(xc + y , yc + x); 
 setPixel(xc - y , yc + x); 
 setPixel(xc + y , yc - x); 
 setPixel(xc - y , yc - x); 
} 


void init(void) 
{ 
 glClearColor(0.0,0.0,0.0,0.0); 
 glMatrixMode(GL_PROJECTION);
 gluOrtho2D(0.0,400.0,0.0,400.0);  
} 
 
void drawMyCircle(void) 
{ 
 glClear(GL_COLOR_BUFFER_BIT);
 glColor3f(1.0,0.0,0.0);
 glPointSize(3.0); 
 //set corodinate at (200,200)
 circleMidPoint(xCenter+200, yCenter+200, radius); 
} 
void input()
{
 scanf ("%d %d %d",&xCenter,&yCenter,&radius);     
} 
 
int main(int argc, char**argv) 
{ 
 input(); //xcenter ycenter radius
 clock_t cstart, cend;
 cstart = clock();
 
 glutInit(&argc, argv);  
 //glutInitWindowPosition(0,0);
 glutInitWindowSize(400,400); 
 glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
 glutCreateWindow("Circle with Midpoint algorithm"); 
 init(); 
 glutDisplayFunc(drawMyCircle); 

 cend = clock();
 //printf("%d second(s)\n", cstart);
 //printf("%d second(s)\n", cend);
 //printf("%e second(s)\n", CLK_TCK);
 float dif = difftime(cend,cstart);
 printf("%.2f time\n",dif/CLK_TCK);
 glutMainLoop(); 
 return 0;
 
} 


