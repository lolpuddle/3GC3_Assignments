#define _USE_MATH_DEFINES
#include <math.h>

int first_x;
int first_y;
bool firstClick = true;
int width;
int height;

void drawPoint(int x, int y) {
    Point point;
    point.x = x;
    point.y = y;
    point.r = brush.r;
    point.g = brush.g;
    point.b = brush.b;
    points.push_back(point);
}

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
            drawPoint(y3, height - x3);
        } else {
            drawPoint(x3, height - y3);
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
            drawPoint(countX, height - startY);
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
        drawPoint(x + x3, height - y - y3);
        drawPoint(x - x3, height - y - y3);
        drawPoint(x - x3, height - y + y3);
        drawPoint(x + x3, height - y + y3);
        drawPoint(x + y3, height - y - x3);
        drawPoint(x - y3, height - y - x3);
        drawPoint(x - y3, height - y + x3);   
        drawPoint(x + y3, height - y + x3);
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
    int mid_x = width/2;
    int mid_y = height/2;
    int r = (int) sqrt(pow((double) (mid_y - y), 2.0) + pow((double) (mid_x - x), 2.0));
    int repeat = 16;
    float radsPerPoint = (2 * M_PI) / repeat;
    float dy = abs(y - mid_y);
    float dx = abs(x - mid_x);
    float offset = dy/dx;

    drawPoint(x, height - y);
    
    for (int i = 1; i < repeat; i++) {
        int y2 = mid_y + sin(radsPerPoint*i + offset)*r;
        int x2 = mid_x + cos(radsPerPoint*i + offset)*r;
        drawPoint(x2, y2);
    }
}

void mouse(int btn, int state, int x, int y) {
    height = glutGet(GLUT_WINDOW_HEIGHT);
    width = glutGet(GLUT_WINDOW_WIDTH);
    if (brush.brushType == 1) {
        drawPoint(x, height - y);
    } else if (brush.brushType == 5) {
        drawRadial(x, y);
    }
    if(btn == GLUT_LEFT_BUTTON) {
        if(state == GLUT_DOWN) {
            if (firstClick && brush.brushType != 1) {
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
        drawPoint(x, height - y);
    } else if (brush.brushType == 5) {
        drawRadial(x, y);
    }
}
