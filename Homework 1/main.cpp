#include <iostream>
#include "BMP.h"
#include <cmath>

//unused for my solution
//taken from textbook
void generateShape(int x, int y, BMP bmpNew) {
    bmpNew.set_pixel(x + 1000, y + 1000, 255, 255, 255, 0);
    bmpNew.set_pixel(y + 1000, x + 1000, 255, 255, 255, 0);
    bmpNew.set_pixel(y + 1000, -x + 1000, 255, 255, 255, 0);
    bmpNew.set_pixel(x + 1000, -y + 1000, 255, 255, 255, 0);
    bmpNew.set_pixel(-x + 1000, -y + 1000, 255, 255, 255, 0);
    bmpNew.set_pixel(-y + 1000, -x + 1000, 255, 255, 255, 0);
    bmpNew.set_pixel(-y + 1000, x + 1000, 255, 255, 255, 0);
    bmpNew.set_pixel(-x + 1000, y + 1000, 255, 255, 255, 0);
}

int main() {

    BMP bmpNew(2000,2000,false);
    //2000, 2000 is width, height
    bmpNew.fill_region(0, 0, 2000, 2000, 0, 0, 0, 0);
    for(int i=0;i<bmpNew.bmp_info_header.width;i++)
    {
        bmpNew.set_pixel(i, 1000, 255, 255, 255, 0);
    }

    
    //simple solution
    
    float y_t;
    for (float x = -768; x <= 768; x++) {
        y_t = sqrt(pow(64.0, 2.0) - pow(x/12.0, 2.0))*6;
        bmpNew.set_pixel(x + 1000, y_t + 1000, 255, 255, 255, 0);
    }
    

    //example for circle taken from textbook (modified)
    /*
    int x = 0;
    int y = 768;
    int d = 1 - 768;
    int deltaE = 3;
    int deltaSE = -2*768 + 5;
    bmpNew.set_pixel(x + 1000, y + 1000, 255, 255, 255, 0);
    bmpNew.set_pixel(y + 1000, x + 1000, 255, 255, 255, 0);
    bmpNew.set_pixel(-y + 1000, x + 1000, 255, 255, 255, 0);
    bmpNew.set_pixel(-x + 1000, y + 1000, 255, 255, 255, 0);
    while (y > x) {
        if (d < 0) {
            d += deltaE;
            deltaE += 2;
            deltaSE += 2;
        } else {
            d += deltaSE;
            deltaE += 2;
            deltaSE += 4;
            y--;
        }
        x++;
        bmpNew.set_pixel(x + 1000, y + 1000, 255, 255, 255, 0);
        bmpNew.set_pixel(y + 1000, x + 1000, 255, 255, 255, 0);
        bmpNew.set_pixel(-y + 1000, x + 1000, 255, 255, 255, 0);
        bmpNew.set_pixel(-x + 1000, y + 1000, 255, 255, 255, 0);
    }
    */

    bmpNew.write("output.bmp");
}