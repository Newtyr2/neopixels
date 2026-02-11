#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#include <vector>
using namespace std;
//#include <iostream>


vector<int> mapping = {8, 9, 10, 11, 12, 13, 14, 15, 7, 6, 5, 4, 3, 2, 1, 0, 0, 1, 2, 3, 4, 5, 6, -1, 7, 6, 5, 4, 3, 2, 1, 0, 8, 9, 10, 11, 12, 13, 14, 15};

struct Color {
    float r, g, b, a, c;
};

// struct Lights{
//     Color a;
// };

struct Bar{
    vector<Color> l;
};

class Neopixels {
    array<Bar, 5> bars;

    int rightIndex(int bar, int index){
        return mapping[bar*8 + index];
    }
};







