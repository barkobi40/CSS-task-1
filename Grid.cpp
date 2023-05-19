#include "Grid.h"

// Grid constructor
Grid::Grid(double tileW, double tileH, int width, int height, int color) {
    // Set the number of rectangles in the array
    _numOfRecs = width * height;

    _Recarr = new Rectangle * [_numOfRecs];

    int newX;
    int newY;
    int currentIndex = 0;

    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            newX = tileW * i;
            newY = tileH * j;
            _Recarr[currentIndex] = new Rectangle(newX, newY, tileW, tileH, color);
            currentIndex++;
        }
    }
}

// Grid destructor
Grid::~Grid(){
    for (int i = 0; i < _numOfRecs; i++) {
        delete this->_Recarr[i];
    }
}

Rectangle* Grid::getRectAtPoint(const Point & p){
    for (int i = 0; i < _numOfRecs; i++) {
        if (_Recarr[i]->contains(p)) {
            return _Recarr[i];
        }
    }
}

Rectangle* Grid::getRectAtIndex(int i) {
    return _Recarr[i];
}

void Grid::moveGrid(double deltaLeft, double deltaTop) {
    for (int i = 0; i < _numOfRecs; i++) {
        _Recarr[i]->moveRect(deltaLeft, deltaTop);
    }
}

void Grid::scaleGrid(double rectWidth, double rectHeight) {
    for (int i = 0; i < _numOfRecs; i++) {
        _Recarr[i]->scaleRect(rectWidth, rectHeight);
    }
}
