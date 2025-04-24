#include "button.h"

void DrawButton(Button *targetButton, Objects *objectData)
{

    glPushMatrix();
    glColor3f(1, 0, 0);

    if(targetButton->hasPressed == true)
    {
        targetButton->pos.y -= BUTTON_PUSH_SPEED;
        targetButton->currentPushProgress += BUTTON_PUSH_SPEED;
        if(compare_float(targetButton->maxPushDepth, targetButton->currentPushProgress))
        {
            targetButton->hasPressed = false;
            targetButton->buttonUnpushing = true;
        }
    }

    if(targetButton->buttonUnpushing)
    {
        targetButton->pos.y += BUTTON_PUSH_SPEED;
        targetButton->currentPushProgress -= BUTTON_PUSH_SPEED;

        if(compare_float(targetButton->currentPushProgress, 0.0f))
        {
            targetButton->buttonUnpushing = false;
        }
    }

    glTranslatef(targetButton->pos.x, targetButton->pos.y, targetButton->pos.z);
    glScalef(targetButton->sizeX, targetButton->sizeY, targetButton->sizeZ);
    glRotatef(-90, 0.0,0.0, 1.0);
    drawOFFFile(objectData);

    glPopMatrix();
}

void inButtonBounds(ButtonBuffer *sceneButtons, Vector *pos)
{
    for(int i = 0; i <= sceneButtons->activeButtons; i++)
    {
        float buttonZ = sceneButtons->buttons[i].pos.z;
        float buttonX = sceneButtons->buttons[i].pos.x;
        if( pos->z <= buttonZ + 5.0 && pos->z >= buttonZ - 5.0 && buttonX - 5.0 <= pos->x  && pos->x <= buttonX + 5.0)
        {
            sceneButtons->buttons[i].inbounds = true;
        }
        else
        {
            sceneButtons->buttons[i].inbounds = false;
        }

    }

}

void ButtonPressMain(ButtonBuffer *sceneButtons, int curScene)
{
    for(int i = 0; i <= sceneButtons->activeButtons; i++)
    {
        if(!sceneButtons->buttons[i].hasPressed && sceneButtons->buttons[i].inbounds == true && sceneButtons->buttons[i].buttonUnpushing == false)
        {
            if(curScene == sceneButtons->buttons[i].scene)
                sceneButtons->buttons[i].hasPressed = true;

        }
    }
}
