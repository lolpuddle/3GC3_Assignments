
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
        case 6 : printf("Random\n");
            break;
        case 7 : printf("Point\n");
            break;
        case 8 : printf("Line\n");
            break;
        case 9 : printf("Rectangle\n");
            break;
        case 10 : printf("Circle\n");
            break;
        case 11 : printf("Radial\n");
            break;
        case 12 : printf("Clear\n");
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
