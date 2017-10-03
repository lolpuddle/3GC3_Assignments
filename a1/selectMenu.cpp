
void menu(int value){

    switch(value) {
        case 1 : printf("Red\n");
            break;
        case 2 : printf("Blue\n");
            break;
        case 3 : printf("Green\n");
            break;
        case 4 : printf("Purple\n");
            break;
        case 5 : printf("Yellow\n");
            break;
        case 6 : printf("Point\n");
            break;
        case 7 : printf("Line\n");
            break;
        case 8 : printf("Rectangle\n");
            break;
        case 9 : printf("Circle\n");
            break;
        case 10 : exit(0); //exit
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

    int shapeMenu = glutCreateMenu(menu);
    glutAddMenuEntry("Point", 6);
    glutAddMenuEntry("Line", 7);
    glutAddMenuEntry("Rectangle", 8);
    glutAddMenuEntry("Circle", 9);

    int mainMenu = glutCreateMenu(menu);
    glutAddSubMenu("Colour", colourMenu);
    glutAddSubMenu("Shape", shapeMenu);
    glutAddMenuEntry("Quit", 10);

    glutAttachMenu(GLUT_RIGHT_BUTTON);
}
