#include <stdio.h>
#include <GL/glut.h>
void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0,1,0);
	glBegin(GL_LINES);
	glVertex3f(2,4,0);
	glVertex3f(8,4,0);
	glEnd();
	glFlush();
}
int main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(300,300);
	glutCreateWindow("Line");
	glClearColor(0,0,0,0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0,10,0,10,-1.0,1);
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
