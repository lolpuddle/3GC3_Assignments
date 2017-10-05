
void menu(int value){

    switch(value) {
        case 1 :
            brush.r = 1.0;
            brush.g = 0.0;
            brush.b = 0.0;
            break;
        case 2 :
            brush.r = 0.0;
            brush.g = 0.0;
            brush.b = 1.0;
            break;
        case 3 :
            brush.r = 0.0;
            brush.g = 1.0;
            brush.b = 0.0;
            break;
        case 4 :
            brush.r = 1.0;
            brush.g = 0.0;
            brush.b = 1.0;
            break;
        case 5 :
            brush.r = 1.0;
            brush.g = 1.0;
            brush.b = 0.0;
            break;
        case 6 :
            brush.r = ((float) rand() / (RAND_MAX));
            brush.g = ((float) rand() / (RAND_MAX));
            brush.b = ((float) rand() / (RAND_MAX));
            break;
        case 7 : printf("Point\n");
            brush.brushType = 1;
            break;
        case 8 : printf("Line\n");
            brush.brushType = 2;
            break;
        case 9 : printf("Rectangle\n");
            brush.brushType = 3;
            break;
        case 10 : printf("Circle\n");
            brush.brushType = 4;
            break;
        case 11 : printf("Radial\n");
            brush.brushType = 5;
            break;
        case 12 : printf("Clear\n");
            points.clear();
            break;
        case 13 : exit(0); //exit
            break;
    }
}

void createMenu() {

    int colourMenu = glutCreateMenu(menu);
    glutAddMenuEntry("Red", 1);
    glutAddMenuEntry("Blue", 2);
    glutAddMenuEntry("Green", 3);
    glutAddMenuEntry("Purple", 4);
    glutAddMenuEntry("Yellow", 5);
    glutAddMenuEntry("Random", 6);

    int shapeMenu = glutCreateMenu(menu);
    glutAddMenuEntry("Point", 7);
    glutAddMenuEntry("Line", 8);
    glutAddMenuEntry("Rectangle", 9);
    glutAddMenuEntry("Circle", 10);
    glutAddMenuEntry("Radial", 11);

    int mainMenu = glutCreateMenu(menu);
    glutAddSubMenu("Colour", colourMenu);
    glutAddSubMenu("Shape", shapeMenu);
    glutAddMenuEntry("Clear", 12);
    glutAddMenuEntry("Quit", 13);

    glutAttachMenu(GLUT_RIGHT_BUTTON);
}
