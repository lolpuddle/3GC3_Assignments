// 
// Ocean Cheung
// 1316057
// Assignment 1
// Oct 5, 2017
// 

#include <stdio.h>
#include <stdlib.h>

#ifdef __APPLE__
#  include <OpenGL/gl.h>
#  include <OpenGL/glu.h>
#  include <GLUT/glut.h>
#else
#  include <GL/gl.h>
#  include <GL/glu.h>
#  include <GL/freeglut.h>
#endif

#include "objects.cpp"
#include "draw.cpp"
#include "selectMenu.cpp"

//OpenGL functions
void keyboard(unsigned char key, int xIn, int yIn) {
	int mod = glutGetModifiers();
	switch (key) {
		case 'q':
		case 27:	//27 is the esc key
			exit(0);
			break;
	}
}

void init(void) {
	glClearColor(0, 0, 0, 0);
	glColor3f(1, 1, 1);
}

void display(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	int w = glutGet(GLUT_WINDOW_WIDTH);
	int h = glutGet(GLUT_WINDOW_HEIGHT);

	gluOrtho2D(0.0, w, 0.0, h);

	for(Point i : points) {
		glBegin(GL_POINTS);
		glColor3f(i.r, i.g, i.b);
		glVertex2f(i.x, i.y);
		glEnd();
	}

	glutSwapBuffers();
}

void FPSTimer(int value) {
	glutTimerFunc(17, FPSTimer, 0);
	glutPostRedisplay();
}

/* main function - program entry point */
int main(int argc, char** argv) {
	glutInit(&argc, argv);		//starts up GLUT
	glutInitDisplayMode(GLUT_DOUBLE);

	glutInitWindowSize(500, 500);
	glutInitWindowPosition(50, 50);

	glutCreateWindow("Assignment 1");

	glutDisplayFunc(display);

	// keyboard callbacks
	glutKeyboardFunc(keyboard);

	// mouse callbacks
	glutMouseFunc(mouse);
	glutMotionFunc(mouseMotion);

	createMenu();

	glutTimerFunc(17, FPSTimer, 0);
	init();

	glutMainLoop();
	return(0);
}
