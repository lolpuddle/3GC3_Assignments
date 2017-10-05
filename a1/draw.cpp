#include <math.h>

int first_x;
int first_y;
bool firstClick = true;

void drawPoint(int x, int y) {
    Point point;
    point.x = x;
    point.y = y;
    point.r = brush.r;
    point.g = brush.g;
    point.b = brush.b;
    points.push_back(point);
}

// void drawLineUp(int x, int y, int x2, int y2) {
//     int dx = abs(x2 - x); int dy = abs(y2 - y);
//     int d = 2*dy - dx;
//     int incrE = dy*2;
//     int incrNE = dy*2 - dx*2;
//     drawPoint(x, glutGet(GLUT_WINDOW_HEIGHT) - y);

//     while((x < x2) && (y < y2)) {
//         if (d > 0) {
//             d += incrE;
//             x++;
//         } else {
//             d += incrNE;
//             x++;
//             y--;
//         }
//         drawPoint(x, glutGet(GLUT_WINDOW_HEIGHT) - y);
//     }
// }

// void drawLineDown(int x, int y, int x2, int y2) {
//     int dx = x2 - x; int dy = y2 - y;
//     int d = 2*dy - dx;
//     int incrE = dy*2;
//     int incrSE = dy*2 - dx*2;
//     drawPoint(x, glutGet(GLUT_WINDOW_HEIGHT) - y);

//     while(x < x2) {
//         if (d <= 0) {
//             d += incrE;
//             x++;
//         } else {
//             d += incrSE;
//             x++;
//             y++;
//         }
//         drawPoint(x, glutGet(GLUT_WINDOW_HEIGHT) - y);
//     }
// }

// void drawLine( int x, int y, int x2, int y2) {
//     int point1_x = x;
//     int point1_y = y;
//     int point2_x = x2;
//     int point2_y = y2;
    
//     if (x > x2) {
//         point1_x = x2;
//         point1_y = y2;
//         point2_x = x;
//         point2_y = y;
//     }

//     if (point1_y > point2_y) {
//         drawLineUp(point1_x, point1_y, point2_x, point2_y);
//     } else {
//         drawLineDown(point1_x, point1_y, point2_x, point2_y);
//     }
// }


// Found pseudocode explanation online in "Optimization" section
// Of the page below:
// http://dictionnaire.sensagent.leparisien.fr/Bresenham's%20algorithm/en-en/
void drawLine(int x, int y, int x2, int y2) {
    bool steepSlope = abs(y2 - y) > abs(x2 - x);
    if (steepSlope) {
        int temp = x;
        x = y;
        y = temp;

        temp = x2;
        x2 = y2;
        y2 = temp;
    }

    if (x > x2) {
        int tempX = x;
        int tempY = y;
        x = x2;
        y = y2;
        x2 = tempX;
        y2 = tempY;
    }

    int dx = x2 - x;
    int dy = abs(y2 - y);
    int err = 0;
    int ystep = -1;
    int y3 = y;
    if (y < y2) {
        ystep = 1;
    } 
    for (int x3 = x; x3 < x2; x3++) {
        if (steepSlope) {
            drawPoint(y3, glutGet(GLUT_WINDOW_HEIGHT) - x3);
        } else {
            drawPoint(x3, glutGet(GLUT_WINDOW_HEIGHT) - y3);
        }
        err -= dy;
        if (err < 0) {
            y3 += ystep;
            err += dx;
        }
    }
}


void drawRectangle(int x, int y, int x2, int y2) {
    int startX = x;
    int endX = x2;
    int startY = y;
    int endY = y2;
    if (x > x2) {
        startX = x2;
        endX = x;
    }
    if (y > y2) {
        startY = y2;
        endY = y;
    }
    int originalX = startX;
    while (startY <= endY) {
        int countX = originalX;
        while (countX <= endX) {
            drawPoint(countX, glutGet(GLUT_WINDOW_HEIGHT) - startY);
            countX++;
        }
        startX++;
        startY++;
    }
}


// With help from John Kennedy's Paper:
// "A Fast Bresenham Type Algorithm For Drawing Circles"
// http://web.engr.oregonstate.edu/~sllu/bcircle.pdf
void drawCircle(int x, int y, int x2, int y2) {
    int r = (int) sqrt(pow((double) (y2 - y), 2.0) + pow((double) (x2 - x), 2.0));
    int x3 = r;
    int y3 = 0;
    int dx = 1 - 2*r;
    int dy = 1;
    int re = 0;

    while (x3 >= y3) {
        drawPoint(x + x3, glutGet(GLUT_WINDOW_HEIGHT) - y - y3);
        drawPoint(x - x3, glutGet(GLUT_WINDOW_HEIGHT) - y - y3);
        drawPoint(x - x3, glutGet(GLUT_WINDOW_HEIGHT) - y + y3);
        drawPoint(x + x3, glutGet(GLUT_WINDOW_HEIGHT) - y + y3);
        drawPoint(x + y3, glutGet(GLUT_WINDOW_HEIGHT) - y - x3);
        drawPoint(x - y3, glutGet(GLUT_WINDOW_HEIGHT) - y - x3);
        drawPoint(x - y3, glutGet(GLUT_WINDOW_HEIGHT) - y + x3);   
        drawPoint(x + y3, glutGet(GLUT_WINDOW_HEIGHT) - y + x3);
        y3++;
        re += dy;
        dy += 2;
        if ((2*re + dx) > 0) {
            x3--;
            re += dx;
            dx += 2;
        }
    }
}

void drawRadial(int x, int y) {
    
}

void mouse(int btn, int state, int x, int y) {
    if (brush.brushType == 1) {
        drawPoint(x, glutGet(GLUT_WINDOW_HEIGHT) - y);
    } else if (brush.brushType == 5) (
        drawRadial(x, y);
    )
    if(btn == GLUT_LEFT_BUTTON) {
        if(state == GLUT_DOWN) {
            if (firstClick) {
                first_x = x;
                first_y = y;
                firstClick = false;
            } else {
                firstClick = true;
                switch(brush.brushType) {
                    case 2 :
                        drawLine(first_x, first_y, x, y);
                        break;
                    case 3 :
                        drawRectangle(first_x, first_y, x, y);
                        break;
                    case 4 :
                        drawCircle(first_x, first_y, x, y);
                        break;
                }
            }
        }
    }
}

void mouseMotion(int x, int y) {
    if (brush.brushType == 1) {
        drawPoint(x, glutGet(GLUT_WINDOW_HEIGHT) - y);
    } else if (brush.brushType == 5) {
        drawRadial(x, y);
    }
}
