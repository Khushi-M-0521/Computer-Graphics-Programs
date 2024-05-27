#include<GL/glut.h>
#include<stdio.h>
void init(void){
	glClearColor(0,0,0,0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-10,10,-10,10,-10,10);
	glMatrixMode(GL_MODELVIEW);
}
void display(void){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glColor3f(0,1,0);
	glutWireCube(1);
	glutSwapBuffers();
	
	glTranslatef(0,3,0);
	glRotatef(30,1,0,0);
	glRotatef(30,0,1,0);
	glutWireCube(1);
	glutSwapBuffers();
	
	glLoadIdentity();
	glutWireCube(1);
	glTranslatef(3,0,0);
	glRotatef(30,1,0,0);
	glRotatef(30,0,1,0);
	glScalef(1,1,2);
	glColor3f(0,1,1);
	glutWireCube(1);
	glutSwapBuffers();
	
	glLoadIdentity();
	glutWireCube(1);
	glTranslatef(-5,0,0);
	glRotatef(30,1,0,0);
	glRotatef(30,0,1,0);
	glScalef(4,4,4);
	glColor3f(1,1,0);
	glutWireCube(1);
	glutSwapBuffers();
}
int main(int argc,char** argv){
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(100,100);
	glutCreateWindow("WireCube");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
