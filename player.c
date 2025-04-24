#include "player.h"
#include "collision.h"
#include "portal.h"
#include "GL/glut.h"
#include "loadImage.h"

Player ply = {
    .moveForward = false,
    .moveBackward = false,
    .moveLeft = false,
    .moveRight = false,

    .pos.x = 3,
    .pos.y = 0.0,
    .pos.z = 4.0,

    .camPitch = 0.0,
    .camYaw = 180.0,

    .sizeX = 2,
    .sizeY = 5,
    .sizeZ = 2,

    .isTeleporting = false,
};

Player getPlayer()
{
    return ply;
}

void playerControls(unsigned char key,int x,int y)
{
    switch(key)
    {
    case 'W':
    case 'w':
        ply.moveForward = true;
        break;
    case 'A':
    case 'a':
        ply.moveLeft = true;
        break;
    case 'S':
    case 's':
        ply.moveBackward = true;
        break;
    case 'D':
    case 'd':
        ply.moveRight = true;
        break;
    case 'E':
    case 'e':
        ButtonPress();
        break;
    case 'u':
        ply.pos.x = 10;
        ply.pos.y = 10;
        break;
    case 27:
        glutDestroyWindow(window);
        quit_main();
        exit(0);
        break;
    }
}
void playerControlsUp(unsigned char key,int x,int y)
{
    switch(key)
    {
    case 'W':
    case 'w':
        ply.moveForward = false;
        break;
    case 'A':
    case 'a':
        ply.moveLeft = false;
        break;
    case 'S':
    case 's':
        ply.moveBackward = false;
        break;
    case 'D':
    case 'd':
        ply.moveRight = false;
        break;
    case 'E':
    case 'e':
        ButtonUp(&ply.pos);
        break;
    case 27:;
        glutDestroyWindow(window);
        quit_main();
        exit(0);
        break;
    }
}

void playerCameraControl(int x,int y)
{

    int dev_x,dev_y;
    dev_x = (800/2)-x;
    dev_y = (450/2)-y;

    ply.camYaw+=(float)dev_x/10.0;
    ply.camPitch+=(float)dev_y/10.0;
}

void positionCamera(CollisionMeshes *meshData, PortalBuffer *scenePortals, ButtonBuffer *sceneButtons)
{
    if(ply.moveForward)
    {
        ply.pos.x += cos((ply.camYaw+90)*TO_RADIANS)/5.0;
        ply.pos.z -= sin((ply.camYaw+90)*TO_RADIANS)/5.0;

        if(isColliding(&ply.pos, meshData, true))
        {
            ply.pos.x -= cos((ply.camYaw+90)*TO_RADIANS)/5.0;
            ply.pos.z += sin((ply.camYaw+90)*TO_RADIANS)/5.0;
        }
    }
    if(ply.moveBackward)
    {
        ply.pos.x += cos((ply.camYaw+90+180)*TO_RADIANS)/5.0;
        ply.pos.z -= sin((ply.camYaw+90+180)*TO_RADIANS)/5.0;

        if(isColliding(&ply.pos, meshData, true))
        {
            ply.pos.x -= cos((ply.camYaw+90+180)*TO_RADIANS)/5.0;
            ply.pos.z += sin((ply.camYaw+90+180)*TO_RADIANS)/5.0;
        }

    }
    if(ply.moveLeft)
    {
        ply.pos.x += cos((ply.camYaw+90+90)*TO_RADIANS)/5.0;
        ply.pos.z -= sin((ply.camYaw+90+90)*TO_RADIANS)/5.0;

        if(isColliding(&ply.pos, meshData, true))
        {
            ply.pos.x -= cos((ply.camYaw+90+90)*TO_RADIANS)/5.0;
            ply.pos.z += sin((ply.camYaw+90+90)*TO_RADIANS)/5.0;
        }
    }
    if(ply.moveRight)
    {
        ply.pos.x += cos((ply.camYaw+90-90)*TO_RADIANS)/5.0;
        ply.pos.z -= sin((ply.camYaw+90-90)*TO_RADIANS)/5.0;

        if(isColliding(&ply.pos, meshData, true))
        {
            ply.pos.x -= cos((ply.camYaw+90-90)*TO_RADIANS)/5.0;
            ply.pos.z += sin((ply.camYaw+90-90)*TO_RADIANS)/5.0;
        }

    }

    if(ply.camPitch>=70)
        ply.camPitch = 70;
    if(ply.camPitch<=-60)
        ply.camPitch=-60;

    inButtonBounds(sceneButtons, &ply.pos);

    glRotatef(-ply.camPitch,1.0,0.0,0.0); // Along X axis
    glRotatef(-ply.camYaw,0.0,1.0,0.0);    //Along Y axis

    ////////////
    // Check for collision with portal and execute teleport
    if(portalCollide(&ply.pos, scenePortals, ply.isTeleporting))
    {
        ply.isTeleporting = true;
    }
    else
    {
        ply.isTeleporting = false;
    }


    ////////////////////////////
    //GRAVITY
    Vector tempPosition = ply.pos;
    tempPosition.y -= 6;

    if(!isColliding(&tempPosition, meshData, true))
    {
        ply.pos.y -= 0.25;
    }
    ////////////////////////////////

    glTranslatef(-ply.pos.x,-ply.pos.y,-ply.pos.z);

}

