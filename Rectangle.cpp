#include "Rectangle.h"

int Rectangle::m_count = 0;

Rectangle::Rectangle(double left, double top, double width, double height, int color) {

    _topLeft = new Point(left, top);
    _bottomRight = new Point(left + width, top + height);
    m_count++;
    _color = color;
}

int Rectangle::getColor() const {
    return _color;
}

void Rectangle::setColor(int color) {
    _color = color;
}

Point& Rectangle::getTopLeftPoint() {
    return *_topLeft;
}

Point& Rectangle::getBottomRightPoint() {
    return *_bottomRight;
}

bool Rectangle::contains(const Point& p) {
    return (p.getX() >= _topLeft->getX() && p.getX() <= _bottomRight->getX()
            && p.getY() >= _topLeft->getY() && p.getY() <= _bottomRight->getY());
}

void Rectangle::moveRect(double deltaLeft, double deltaTop) {
    _topLeft->setX(_topLeft->getX() + deltaLeft);
    _topLeft->setY(_topLeft->getY() + deltaTop);
    _bottomRight->setX(_bottomRight->getX() + deltaLeft);
    _bottomRight->setY(_bottomRight->getY() + deltaTop);
}

void Rectangle::scaleRect(double rectWidth, double rectHeight) {
    double currentScaleX = _bottomRight->getX() - _topLeft->getX();
    double currentScaleY = _bottomRight->getY() - _topLeft->getY();
    _topLeft->setScaleX(rectWidth / currentScaleX);
    _topLeft->setScaleY(rectHeight / currentScaleY);
    _bottomRight->setScaleX(rectWidth / currentScaleX);
    _bottomRight->setScaleY(rectHeight / currentScaleY);
}

