#include "raylib.h"
#include "button.h"
#include <string.h>
#include <stdio.h>

#define BTN_NUM 12
#define SCRN_SIZE 30

int main(void){
	//Variables delcaration and initialisation 
	int width = 800;
	int height = 450;
	struct button btns[BTN_NUM];
	int i, left, right;
	char operation;
	bool overButton;
	bool closeWindow = false;
	bool exitState = false;
	int frameCounter = 0;
	char scrnVal[SCRN_SIZE];
	
	InitWindow(width, height, "Raylib Calculator");
	
	SetTargetFPS(60);
	
	Rectangle screen = {width / 3, height / 6, width / 4, 40};
	
	//Initialise Buttons
	btns[0] = (struct button){"1", {0, 70, 40, 40}, 1, 0, 70, 0};
	btns[1] = (struct button){"2", {70, 70, 40, 40}, 2, 70, 70, 0};
	btns[2] = (struct button){"3", {140, 70, 40, 40}, 3, 140, 70, 0};
	btns[3] = (struct button){"4", {0, 130, 40, 40}, 4, 0, 130, 0};
	btns[4] = (struct button){"5", {70, 130, 40, 40}, 5, 70, 130, 0};
	btns[5] = (struct button){"6", {140, 130, 40, 40}, 6, 140, 130, 0};
	btns[6] = (struct button){"7", {0, 190, 40, 40}, 7, 0, 190, 0};
	btns[7] = (struct button){"8", {70, 190, 40, 40}, 8, 70, 190, 0};
	btns[8] = (struct button){"9", {140, 190, 40, 40}, 9, 140, 190, 0};
	btns[9] = (struct button){"+", {0, 250, 40, 40}, -2, 0, 250, 0};
	btns[10] = (struct button){"0", {70, 250, 40, 40}, 0, 70, 250, 0};
	btns[11] = (struct button){"=", {140, 250, 40, 40}, -1, 140, 250, 0};
	
	//Main application loop
	while(!closeWindow){
		
		//Catches if the window should close 
		if(WindowShouldClose() || exitState || IsKeyPressed(KEY_Q)){
			exitState = true;
			BeginDrawing();
			ClearBackground(WHITE);
			DrawText("For Real?!", width / 2, height / 2, 30, BLACK);
			
			if(IsKeyPressed(KEY_Y)){
				closeWindow = true;
			}
			else if (IsKeyPressed(KEY_N)){
				exitState = false;
			}
			EndDrawing();
		}
		else{
			//Reset the frame counter
			if(frameCounter >= 120){
				frameCounter = 0;
			}
			
			overButton = false;
			
			BeginDrawing();
			ClearBackground(WHITE);
			
			//Iterate through each button
			for(i = 0; i < BTN_NUM; i++){
				//Testing if the button is still in delay from being clicked
				if(btns[i].clickDelay){
					btns[i].clickDelay++;
					DrawRectangleRec(btns[i].shape, GREEN);
					//Button has stayed active for long enough
					if(btns[i].clickDelay == 30){
						btns[i].clickDelay = 0;
					}
				}	
				//Checking if the mouse is over the button
				if(CheckCollisionPointRec(GetMousePosition(), btns[i].shape)){
					overButton = true;
					//Button is grey if not in clicked state
					if(!btns[i].clickDelay){
						DrawRectangleRec(btns[i].shape, LIGHTGRAY);
					}
					//Checking if the button is clicked
					if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && !btns[i].clickDelay){
						DrawRectangleRec(btns[i].shape, GREEN);
						btns[i].clickDelay++;
						click(btns[i], scrnVal, &left, &right, &operation);
					}
				}
				//Draw the button
				DrawRectangleLinesEx(btns[i].shape, 1.0, BLACK);
				DrawText(btns[i].label, btns[i].posX, btns[i].posY, 20, BLACK);
			}
			
			//Setting the cursor if the mouse is over a button
			if(overButton){
				SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
			}
			else{
				SetMouseCursor(MOUSE_CURSOR_DEFAULT);
			}
			
			//Draw the input box
			DrawRectangleLinesEx(screen, 1.0, BLACK);
			DrawText(scrnVal, width / 3, height / 6, 20, BLACK);
			
			DrawFPS(720, 0);
			
			DrawText(TextFormat("frameCounter: %d", frameCounter), 610, 40, 20, BLACK);
			
			EndDrawing();
			++frameCounter;
		}
	}
	
	CloseWindow();
	
	return 0;
}