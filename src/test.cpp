#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#include <vector>
using namespace std;
//#include <iostream>


vector<vector<int>> mapping = {{8, 9, 10, 11, 12, 13, 14, 15}, {7, 6, 5, 4, 3, 2, 1, 0}, {0, 1, 2, 3, 4, 5, 6}};

struct Lights{
    

};

struct Bar{
    vector<Lights> l;
};

class Neopixels {
    array<Bar, 5> bars;

};







