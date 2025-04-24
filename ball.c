
#include "ball.h"

void spawnBall(Ball *target)
{
    Player thePlayer = getPlayer();
    target->pos.x = thePlayer.pos.x;
    target->pos.y = thePlayer.pos.y;
    target->pos.z = thePlayer.pos.z;

    target->collisionOn = true;
    target->TransformationComplete = false;

    target->radius = 1.0;

    //Init velocity
    target->initVel.x = 1;
    target->initVel.y = 0.0-(thePlayer.camPitch/25);
    target->initVel.z = 1;

    target->energy.x = target->initVel.x*1.2;
    target->energy.y = 0.01;
    target->energy.z = target->initVel.z*1.2;

    target->velVector = rotateVector(target->initVel, thePlayer.camYaw-45, 1,0,0);
}

bool BallisColliding(Vector *position, CollisionMeshes *meshData, AABB *collidedCallback)
{

    int activeMeshes = meshData->activeMeshes;

    for(int i =0; i<activeMeshes; i++)
    {
        bool xOverlap = ((int)position->x) <= (meshData->mesh[i].pos.x + meshData->mesh[i].maxX+1) && ((int)position->x) >= (meshData->mesh[i].pos.x + meshData->mesh[i].minX-1);
        bool yOverlap = ((int)position->y) <= (meshData->mesh[i].pos.y + meshData->mesh[i].maxY+1) && ((int)position->y) >= (meshData->mesh[i].pos.y + meshData->mesh[i].minY-1);
        bool zOverlap = ((int)position->z) <= (meshData->mesh[i].pos.z + meshData->mesh[i].maxZ+1) && ((int)position->z) >= (meshData->mesh[i].pos.z + meshData->mesh[i].minZ-1);

        if(xOverlap && yOverlap && zOverlap)
        {
            *collidedCallback = meshData->mesh[i];
            return true;
        }

    }

    return false;
}

void drawBall(Ball *target, CollisionMeshes *meshData)
{

    glPushMatrix();
        glTranslatef( target->pos.x,  target->pos.y,  target->pos.z);
        GLUquadric *quad;
        quad = gluNewQuadric();
        glColor3f(1.0,1.0,1.0);
        gluSphere(quad,target->radius,100,20);
    glPopMatrix();
}
