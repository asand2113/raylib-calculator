#ifndef BUTTON_H
#define BUTTON_H

#include "raylib.h"

typedef enum {
	zero = 0,
	one = 1,
	two = 2,
	three = 3,
	four = 4,
	five = 5,
	six = 6,
	seven = 7,
	eight = 8,
	nine = 9,
	count = 1
}test;

struct button{
	char label[10];
	Rectangle shape;
	int value;
	int posX;
	int posY;
	int clickDelay;
};

#endif