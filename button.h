#ifndef BUTTON_H_INCLUDED
#define BUTTON_H_INCLUDED

#include "gobal_vars.h"
#include "transformation.h"

/**< Draws the button in the scene and runs the animation */
void DrawButton(Button *targetButton, Objects *objectData);

/**< Checks if player is in bounds to any buttons */
void inButtonBounds(ButtonBuffer *sceneButtons, Vector *position);

/**< Signals the system to begin the push down animation */
void ButtonPressMain(ButtonBuffer *sceneButtons, int curScene);

#endif // BUTTON_H_INCLUDED
