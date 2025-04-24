#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include "gobal_vars.h"
#include "transformation.h"
#include "player.h"
#include "collision.h"
#include "portal.h"
#include "loadObj.h"


_4PointGeometry floor =
{
    .pos.x = 0.0,
    .pos.y = -10.0,
    .pos.z = 0.0,

    .collisionOn = true,

    .angle.xAng = 90.0,
    .angle.yAng = 0.0,
    .angle.zAng = 0.0,

    .vertices =
    {
        {50,-50,0,50},
        {50,50,0,50},
        {-50,50,0,50},
        {-50,-50,0,50},
    },

    .TransformationComplete = false,
};

_4PointGeometry wallTest =
{
    .pos.x = 0.0,
    .pos.y = 0.0,
    .pos.z = 20.0,

    .collisionOn = true,

    .angle.xAng = 0.0,
    .angle.yAng = 0.0,
    .angle.zAng = 0.0,

    .vertices =
    {
        {10,-10,0,10},
        {10,10,0,10},
        {-10,10,0,10},
        {-10,-10,0,10},
    },

    .TransformationComplete = false,
};

void scene1_main(CollisionMeshes *meshData, PortalBuffer *testPort, ButtonBuffer *sceneButtons)
{

    glPushMatrix();
        glTranslatef(floor.pos.x,floor.pos.y,floor.pos.z);

        if(floor.TransformationComplete == false)
        {
            floor.TransformationComplete = true;
            for(int i = 0; i < 5; i++)
            {
                floor.vertices[i] = rotateVector(floor.vertices[i], floor.angle.yAng, 1,0,0);
                floor.vertices[i] = rotateVector(floor.vertices[i], floor.angle.xAng, 0,1,0);
                floor.vertices[i] = rotateVector(floor.vertices[i], floor.angle.zAng, 0,0,1);
            }
        }

        glBegin(GL_POLYGON);
            glColor3f(1.0,0.0,0.0);
            glVertex3f(  floor.vertices[0].x, floor.vertices[0].y, floor.vertices[0].z );
            glVertex3f(  floor.vertices[1].x, floor.vertices[1].y, floor.vertices[1].z );
            glVertex3f(  floor.vertices[2].x, floor.vertices[2].y, floor.vertices[2].z );
            glVertex3f(  floor.vertices[3].x, floor.vertices[3].y, floor.vertices[3].z );
        glEnd();

        if(floor.collisionOn == true)
            createAABB(&floor.angle, &floor.pos, floor.vertices,meshData,4, false );

    glPopMatrix();

    /////////////////////////////////////////////////////////////////////
    glPushMatrix();
        glTranslatef(wallTest.pos.x,wallTest.pos.y,wallTest.pos.z);

        if(wallTest.TransformationComplete == false)
        {
            wallTest.TransformationComplete = true;
            for(int i = 0; i < 5; i++)
            {
                wallTest.vertices[i] = rotateVector(wallTest.vertices[i], wallTest.angle.yAng, 1,0,0);
                wallTest.vertices[i] = rotateVector(wallTest.vertices[i], wallTest.angle.xAng, 0,1,0);
                wallTest.vertices[i] = rotateVector(wallTest.vertices[i], wallTest.angle.zAng, 0,0,1);
            }
        }

        glBegin(GL_POLYGON);
            glColor3f(1.0,0.0,0.0);
            glVertex3f(  wallTest.vertices[0].x, wallTest.vertices[0].y, wallTest.vertices[0].z );
            glVertex3f(  wallTest.vertices[1].x, wallTest.vertices[1].y, wallTest.vertices[1].z );
            glVertex3f(  wallTest.vertices[2].x, wallTest.vertices[2].y, wallTest.vertices[2].z );
            glVertex3f(  wallTest.vertices[3].x, wallTest.vertices[3].y, wallTest.vertices[3].z );
        glEnd();

        if(floor.collisionOn == true)
            createAABB(&wallTest.angle, &wallTest.pos, wallTest.vertices,meshData,4, false );

    glPopMatrix();


}

