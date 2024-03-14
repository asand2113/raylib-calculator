#include "raylib.h"
#include "button.h"
#include <string.h>

void click(struct button btn, char scrnVal[], int *left, int *right, char *operation){
	//Testing if the value of the button is a number
	if(btn.value > -1 && btn.value < 10){
		//Testing if there is an operation yet
		if(!*operation){
			//Left side
			
		}
		else{
			//Right side
			
		}
		//Debug
		strcat(scrnVal, btn.label);
	}
	
}