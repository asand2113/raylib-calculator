#ifndef BUTTON_H
#define BUTTON_H

#include "raylib.h"

/*
Struct that holds the information for a generic button
*/
struct button{
	const char *label;
	Rectangle shape;
	int value;
	int posX;
	int posY;
	int clickDelay;
};

//Function Prototype for button clicking
void click(struct button btn, char scrnVal[], int *left, int *right, char *operation);

#endif