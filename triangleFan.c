#include<stdio.h>
#include<GL/glut.h>
void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1.0,0.0,0.0);
	glVertex3f(4.0,4.0,0.0);
	glVertex3f(3.0,6.0,0.0);
	glVertex3f(5.0,6.0,0.0);

	glColor3f(0.0,1.0,0.0);
	glVertex3f(4.0,4.0,0.0);
	glVertex3f(5.0,6.0,0.0);
	glVertex3f(7.0,4.5,0.0);
	
	glColor3f(0.0,0.0,1.0);
	glVertex3f(4.0,4.0,0.0);
	glVertex3f(7.0,4.5,0.0);
	glVertex3f(7.0,3.5,0.0);

	glColor3f(1.0,0.0,0.0);
	glVertex3f(4.0,4.0,0.0);
	glVertex3f(7.0,3.5,0.0);
	glVertex3f(5.0,2.0,0.0);

	glColor3f(0.0,1.0,0.0);
	glVertex3f(4.0,4.0,0.0);
	glVertex3f(5.0,2.0,0.0);
	glVertex3f(3.0,2.0,0.0);

	glColor3f(0.0,0.0,1.0);
	glVertex3f(4.0,4.0,0.0);
	glVertex3f(3.0,2.0,0.0);
	glVertex3f(1.0,3.5,0.0);
	
	glColor3f(1.0,0.0,0.0);
	glVertex3f(4.0,4.0,0.0);
	glVertex3f(1.0,3.5,0.0);
	glVertex3f(1.0,4.5,0.0);

	glColor3f(0.0,1.0,0.0);
	glVertex3f(4.0,4.0,0.0);
	glVertex3f(1.0,4.5,0.0);
	glVertex3f(3.0,6.0,0.0);
	glEnd();
	glFlush();
}
int main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(600,600);
	glutCreateWindow("TriangleFan");
	glClearColor(0.0,0.0,0.0,1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0,10.0,0.0,10.0,-1.0,1.0);
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
