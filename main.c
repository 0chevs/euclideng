/*
Authors: Clint Del Borrello, Nazier Roumani
Date: 3/06/2021
*/

#include "gobal_vars.h"
#include <stdlib.h>
#include <stdbool.h>
#include "scene1.h"
#include "scene2.h"
#include "scene3.h"
#include "scene4.h"
#include "ball.h"
#include "player.h"
#include "transformation.h"
#include "loadImage.h"

void mainDisplay();
void reshape(int w,int h);
void timer();
int window;

int currentScene = 2;

CollisionMeshes collisionContainer;

PortalBuffer scenePortals =
{
    .activePortals = 0,

};

ButtonBuffer sceneButton =
{
    .objectData.fileNotOpen = true,

    .activeButtons = 0,

};

Ball playerBall;

void myMouseFunc(int button, int state, int x, int y)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
            spawnBall(&playerBall);

	}

}


void loadGeometry()
{
    loadScene2Geometry();

    loadScene2Button(&sceneButton);

    loadScene2Portals(&scenePortals);

    loadScene3Geometry();

    loadScene3Portals(&scenePortals);

    loadScene3Button(&sceneButton);

    loadScene4Geometry();

    loadScene4Button(&sceneButton);

    loadScene4Portals(&scenePortals);

}

void init()
{
    load_image("Data/Group.bmp");
    readOFFModel("models/button.off", &sceneButton.objectData);
    glClearColor(0.5,0.5,0.5,1);

    glutSetCursor(GLUT_CURSOR_NONE);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glutWarpPointer(width/2,height/2);

    loadGeometry();
}

void ButtonUp(Vector *posit)
{

    for(int i = 0; i <= sceneButton.activeButtons; i++)
    {
        if(sceneButton.buttons[i].inbounds == true)
        {
            if(currentScene == sceneButton.buttons[i].scene)
                currentScene++;

                if(currentScene == 3)
                {
                    posit->x = 3;
                    posit->y = 0.0;
                    posit->z = 4.0;
                }

                if(currentScene == 4)
                {
                    posit->x = 10;
                    posit->y = 0.0;
                    posit->z = 30.0;
                }

                if(currentScene == 5)
                {
                    quit_main();
                    exit(0);
                    glutDestroyWindow(window);
                }
        }
    }
}

void ButtonPress()
{

    ButtonPressMain(&sceneButton, currentScene);

}

void ballAnimate()
{
    glutTimerFunc(TIMESEC, ballAnimate, 0);
    float GRAVITY = 0.02;
    float AIR_FRICTION = 0.01;
    float BOUNCINESS = 1.5;
    float SURFACE_FRICTION = 1.05;

    playerBall.pos.x-=playerBall.velVector.x*playerBall.energy.x;
    playerBall.pos.z-=playerBall.velVector.z*playerBall.energy.z;

    playerBall.pos.y= playerBall.pos.y-playerBall.velVector.y;
    playerBall.velVector.y= playerBall.velVector.y + GRAVITY;

    if(playerBall.energy.x <= 0 && playerBall.energy.z <= 0)
    {
        playerBall.energy.x = 0.0;
        playerBall.energy.z = 0.0;
    }
    else
    {
        playerBall.energy.x = playerBall.energy.x-AIR_FRICTION;
        playerBall.energy.z = playerBall.energy.z-AIR_FRICTION;
    }

    Vector pos = {playerBall.pos.x+1, playerBall.pos.y+1, playerBall.pos.z+1};
    AABB collidedMesh;
    bool collide = BallisColliding(&pos, &collisionContainer, &collidedMesh);

    if(collide)
    {
        if(collidedMesh.angle.xAng == 90 || collidedMesh.angle.xAng == -90 )
        {
            playerBall.energy.y = playerBall.energy.y/BOUNCINESS;
            playerBall.velVector.y = playerBall.energy.y;

            playerBall.energy.x = playerBall.energy.x/SURFACE_FRICTION;

            playerBall.energy.z = playerBall.energy.z/SURFACE_FRICTION;
        }
        else
        {
            playerBall.velVector.x = -playerBall.velVector.x*playerBall.energy.x/SURFACE_FRICTION;

            playerBall.velVector.z = -playerBall.velVector.z*playerBall.energy.z/SURFACE_FRICTION;
        }

    }
    else
    {
        playerBall.energy.y = -playerBall.velVector.y;
    }

    glutPostRedisplay();
}

int main(int argc,char**argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(width, height);
    window = glutCreateWindow("ICT289 Project");

    init();
    glutDisplayFunc(mainDisplay);
    glutReshapeFunc(reshape);
    glutPassiveMotionFunc(playerCameraControl);
    glutTimerFunc(0,timer,0);
    glutTimerFunc(TIMESEC, ballAnimate, 0);
    glutKeyboardFunc(playerControls);
    glutKeyboardUpFunc(playerControlsUp);
    glutMouseFunc(myMouseFunc);

    glutMainLoop();
    return 0;
}

void mainDisplay()
{

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    positionCamera(&collisionContainer, &scenePortals, &sceneButton);

    setActiveMeshes(&collisionContainer, 0);

    switch(currentScene)
    {
        case 2:
            scene2_main(&collisionContainer, &scenePortals, &sceneButton, &playerBall);
            break;

        case 3:
            scene3_main(&collisionContainer, &scenePortals, &sceneButton, &playerBall);
            break;

        case 4:
            scene4_main(&collisionContainer, &scenePortals, &sceneButton, &playerBall);
            break;
    }
    glutSwapBuffers();
}

void reshape(int w,int h)
{
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60,16.0/9.0,1,800);
    glMatrixMode(GL_MODELVIEW);

}

void timer()
{
    glutPostRedisplay();
    glutWarpPointer(width/2,height/2);
    glutTimerFunc(1000/FPS,timer,0);
}





