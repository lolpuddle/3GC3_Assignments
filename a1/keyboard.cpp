
void keyboard(unsigned char key, int xIn, int yIn) {
	int mod = glutGetModifiers();
	switch (key) {
		case 'q':
		case 27:	//27 is the esc key
			exit(0);
			break;
		case 'w':
			brush.brushType = 1;
			break;
		case 'e':
			brush.brushType = 2;
			break;
		case 'r':
			brush.brushType = 3;
			break;
		case 't':
			brush.brushType = 4;
			break;
		case 'y':
			brush.brushType = 5;
			break;
		case 'c':
			points.clear();
			break;
	}
}
