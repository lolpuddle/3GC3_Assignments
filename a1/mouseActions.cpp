int mouse_x;
int mouse_y;

void drawPoint(int x, int y) {
    Point point;
    point.x = x;
    point.y = y;
    point.r = brush.r;
    point.g = brush.g;
    point.b = brush.b;
    points.push_back(point);
}

void drawLine(int x, int y) {}
void drawRectangle(int x, int y) {}
void drawCircle(int x, int y) {}

void mouse(int btn, int state, int x, int y) {
    switch(brush.brushType) {
        case 1: drawPoint(x, glutGet(GLUT_WINDOW_HEIGHT) - y);
            break;
        case 2: drawLine(x, y);
            break;
        case 3: drawRectangle(x, y);
            break;
        case 4: drawCircle(x, y);
            break;
    }
}

void mouseMotion(int x, int y) {
    switch(brush.brushType) {
        case 1: drawPoint(x, glutGet(GLUT_WINDOW_HEIGHT) - y);
            break;
        case 2: drawLine(x, y);
            break;
        case 3: drawRectangle(x, y);
            break;
        case 4: drawCircle(x, y);
            break;
    }
}

void mousePassiveMotion(int x, int y) {
    mouse_x = x;
    mouse_y = y;
}
