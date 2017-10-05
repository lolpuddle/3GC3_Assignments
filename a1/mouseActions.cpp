int x1;
int y1;

void drawPoint(int x, int y) {
    Point point;
    point.x = x;
    point.y = y;
    point.r = brush.r;
    point.g = brush.g;
    point.b = brush.b;
    points.push_back(point);
}

void drawLineUp(int x, int y, int x2, int y2) {
    int dx = x2 - x; int dy = y2 - y;
    int d = 2*dy - dx;
    int incrE = dy*2;
    int incrNE = dy*2 - dx*2;
    drawPoint(x, glutGet(GLUT_WINDOW_HEIGHT) - y);

    while(x < x2) {
        if (d > 0) {
            d += incrE;
            x++;
        } else {
            d += incrNE;
            x++;
            y--;
        }
        drawPoint(x, glutGet(GLUT_WINDOW_HEIGHT) - y);
    }
}

void drawLineDown(int x, int y, int x2, int y2) {
    int dx = x2 - x; int dy = y2 - y;
    int d = 2*dy - dx;
    int incrE = dy*2;
    int incrSE = dy*2 - dx*2;
    drawPoint(x, glutGet(GLUT_WINDOW_HEIGHT) - y);

    while(x < x2) {
        if (d <= 0) {
            d += incrE;
            x++;
        } else {
            d += incrSE;
            x++;
            y++;
        }
        drawPoint(x, glutGet(GLUT_WINDOW_HEIGHT) - y);
    }
}

void drawLine( int x, int y, int x2, int y2) {
    int point1_x = x;
    int point1_y = y;
    int point2_x = x2;
    int point2_y = y2;
    
    if (x > x2) {
        point1_x = x2;
        point1_y = y2;
        point2_x = x;
        point2_y = y;
    }

    if (point1_y > point2_y) {
        drawLineUp(point1_x, point1_y, point2_x, point2_y);
    } else {
        drawLineDown(point1_x, point1_y, point2_x, point2_y);
    }
}


void drawRectangle(int x, int y) {}
void drawCircle(int x, int y) {}

void mouse(int btn, int state, int x, int y) {
    if (brush.brushType == 1) {
        drawPoint(x, glutGet(GLUT_WINDOW_HEIGHT) - y);
    }
    if(btn == GLUT_LEFT_BUTTON) {
        if(state == GLUT_DOWN) {
            int x1 = x;
            int x2 = x;
        } else if(state == GLUT_UP) {
            switch(brush.brushType) {
                case 2 :
                    drawLine(x1, y1, x, y);
                    break;
                case 3 :
                    drawRectangle(x, y);
                    break;
                case 4 :
                    drawCircle(x, y);
                    break;
            }
        }
    }
}

void mouseMotion(int x, int y) {
    if (brush.brushType == 1) {
        drawPoint(x, glutGet(GLUT_WINDOW_HEIGHT) - y);
    }
}

void mousePassiveMotion(int x, int y) {
    x1 = x;
    y1 = y;
}
