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

#include "selectMenu.cpp"

//Globals
float camPos[] = {0, 0, 3.42f};	//where the camera is
float angle = 0.0f;
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

void special(int key, int xIN, int yIN) {
	switch (key) {
		case GLUT_KEY_DOWN:
			printf("arrow down\n");
			break;
		case GLUT_KEY_UP:
		printf("up arrow pressed\n");
		break;
	}
}

void mouse(int btn, int state, int x, int y) {
	printf("mouseFunc coords: %i, %i\n", x, y);

	if (btn == GLUT_LEFT_BUTTON) {
		printf("Left buton\n");

		if (state == GLUT_UP) {
			printf("Released\n");
		}

		if (state == GLUT_DOWN) {
			printf("Pressed\n");
		}
	}

	if (btn == GLUT_RIGHT_BUTTON) {
		printf("Right Button\n");
	}
}

void mouseMotion(int x, int y) {
	printf("mouseMotion coords: %i, %i \n", x, y);
}

void mousePassiveMotion(int x, int y) {

}

void init(void) {
	glClearColor(0, 0, 0, 0);
	glColor3f(1, 1, 1);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45, 1, 1, 100);
}

/* display function - GLUT display callback function
 *		clears the screen, sets the camera position, draws the ground plane and movable box
 */
void display(void) {
	glClear(GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glColor3f(1,1,1);

	//flush out to single buffer
	glFlush();
}

void reshape(int w, int h) {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	// gluOrtho2D(o, w, 0, h);
	// gluPerspective(45, (float)(w+0.0f)/h), 1, 100);

	glMatrixMode(GL_MODELVIEW);
	glViewport(0, 0, w, h);
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

	glutCreateWindow("Assignment 1");	//creates the window

	glutDisplayFunc(display);	//registers "display" as the display callback function

	// keyboard callbacks
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(special);

	// mouse callbacks
	glutMouseFunc(mouse);
	glutMotionFunc(mouseMotion);
	glutPassiveMotionFunc(mousePassiveMotion);

	createMenu();

	glutTimerFunc(17, FPSTimer, 0);
	init();

	glutMainLoop();				//starts the event glutMainLoop
	return(0);					//return may not be necessary on all compilers
}
