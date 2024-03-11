#include "raylib.h"
#include "button.h"
#include <string.h>

#define BTN_NUM 10
#define SCRN_SIZE 30

int main(void){
	int width = 800;
	int height = 450;
	struct button btns[BTN_NUM];
	int i;
	bool overButton;
	bool closeWindow = false;
	bool exitState = false;
	int frameCounter = 0;
	char scrnVal[SCRN_SIZE];
	
	InitWindow(width, height, "TODO - Change Window Title");
	
	SetTargetFPS(60);
	
	Rectangle screen = {width / 2, height / 2, width / 4, 80};
	
	for(i = 0; i < BTN_NUM; i++){
		btns[i] = (struct button){"Test", {i * 70, 70, 40, 40}, i, i * 70, 70, 0};
	}
	
	while(!closeWindow){
		
		if(WindowShouldClose() || exitState){
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
			if(frameCounter >= 120){
				frameCounter = 0;
			}
			
			overButton = false;
			
			BeginDrawing();
			ClearBackground(WHITE);
			
			for(i = 0; i < BTN_NUM; i++){
				if(btns[i].clickDelay){
					btns[i].clickDelay++;
					DrawRectangleRec(btns[i].shape, GREEN);
					if(btns[i].clickDelay == 60){
						btns[i].clickDelay = 0;
					}
				}	
				if(CheckCollisionPointRec(GetMousePosition(), btns[i].shape)){
					overButton = true;
					if(!btns[i].clickDelay){
						DrawRectangleRec(btns[i].shape, LIGHTGRAY);
					}
					if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && !btns[i].clickDelay){
						DrawRectangleRec(btns[i].shape, GREEN);
						btns[i].clickDelay++;
						if(!(strlen(scrnVal) + strlen(btns[i].label) >= SCRN_SIZE)){
							strcat(scrnVal, btns[i].label);		//Need to implement the selecting value function
						}
					}
				}
				DrawRectangleLinesEx(btns[i].shape, 1.0, BLACK);
				DrawText(btns[i].label, btns[i].posX, btns[i].posY, 20, BLACK);
			}
			
			if(overButton){
				SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
			}
			else{
				SetMouseCursor(MOUSE_CURSOR_DEFAULT);
			}
			
			DrawRectangleLinesEx(screen, 1.0, BLACK);
			DrawText(scrnVal, width / 2, height / 2, 20, BLACK);
			
			DrawFPS(720, 0);
			
			DrawText(TextFormat("frameCounter: %d", frameCounter), 610, 40, 20, BLACK);
			
			EndDrawing();
			++frameCounter;
		}
	}
	
	CloseWindow();
	
	return 0;
}