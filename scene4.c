#include "scene4.h"

GeometryBuffer scene4Geometry =
{
    .activeMeshes = 0,
};

void loadScene4Portals(PortalBuffer *portal)
{
    float hei;
    float wid;

    int index = portal->activePortals;

    hei = 8;
    wid = 12.5;
    /////////////////////PORTAL 1/////////////////////////////
    portal->portals[index].pos.x = 13;
    portal->portals[index].pos.y = -10;
    portal->portals[index].pos.z = 60;
    portal->portals[index].pos.w = 1;

    portal->portals[index].vertices[0].x = hei;
    portal->portals[index].vertices[0].y = 0;
    portal->portals[index].vertices[0].z = 0;

    portal->portals[index].vertices[1].x = hei;
    portal->portals[index].vertices[1].y = wid;
    portal->portals[index].vertices[1].z = 0;

    portal->portals[index].vertices[2].x = 0;
    portal->portals[index].vertices[2].y = wid;
    portal->portals[index].vertices[2].z = 0;

    portal->portals[index].vertices[3].x = 0;
    portal->portals[index].vertices[3].y = 0;
    portal->portals[index].vertices[3].z = 0;

    portal->portals[index].collisionOn = true;

    portal->portals[index].angle.xAng = 0;
    portal->portals[index].angle.yAng = 90;
    portal->portals[index].angle.zAng = 0;

    portal->portals[index].TransformationComplete = false,

    portal->portals[index].scene = 4,

    portal->portals[index].teleportToPositon.x = 63.0;
    portal->portals[index].teleportToPositon.y = -10;
    portal->portals[index].teleportToPositon.z = 57.5;
    portal->portals[index].teleportToPositon.w = 1;

    for(int i = 0; i < 5; i++)
    {
        portal->portals[index].vertices[i]= rotateVector(portal->portals[index].vertices[i], portal->portals[index].angle.yAng, 1,0,0);
        portal->portals[index].vertices[i] = rotateVector(portal->portals[index].vertices[i], portal->portals[index].angle.xAng, 0,1,0);
        portal->portals[index].vertices[i] = rotateVector(portal->portals[index].vertices[i], portal->portals[index].angle.zAng, 0,0,1);
    }

    portal->activePortals = portal->activePortals+ 1;
    index = portal->activePortals;

    /////////////////////PORTAL 2/////////////////////////////
    portal->portals[index].pos.x = 13+50.0;
    portal->portals[index].pos.y = -10;
    portal->portals[index].pos.z = 60;
    portal->portals[index].pos.w = 1;

    portal->portals[index].vertices[0].x = hei;
    portal->portals[index].vertices[0].y = 0;
    portal->portals[index].vertices[0].z = 0;

    portal->portals[index].vertices[1].x = hei;
    portal->portals[index].vertices[1].y = wid;
    portal->portals[index].vertices[1].z = 0;

    portal->portals[index].vertices[2].x = 0;
    portal->portals[index].vertices[2].y = wid;
    portal->portals[index].vertices[2].z = 0;

    portal->portals[index].vertices[3].x = 0;
    portal->portals[index].vertices[3].y = 0;
    portal->portals[index].vertices[3].z = 0;

    portal->portals[index].collisionOn = true;

    portal->portals[index].angle.xAng = 0;
    portal->portals[index].angle.yAng = 90;
    portal->portals[index].angle.zAng = 0;

    portal->portals[index].TransformationComplete = false,

    portal->portals[index].scene = 4,

    portal->portals[index].teleportToPositon.x = 113;
    portal->portals[index].teleportToPositon.y = -10;
    portal->portals[index].teleportToPositon.z = 57.5;
    portal->portals[index].teleportToPositon.w = 1;

    for(int i = 0; i < 5; i++)
    {
        portal->portals[index].vertices[i]= rotateVector(portal->portals[index].vertices[i], portal->portals[index].angle.yAng, 1,0,0);
        portal->portals[index].vertices[i] = rotateVector(portal->portals[index].vertices[i], portal->portals[index].angle.xAng, 0,1,0);
        portal->portals[index].vertices[i] = rotateVector(portal->portals[index].vertices[i], portal->portals[index].angle.zAng, 0,0,1);
    }

    portal->activePortals = portal->activePortals+ 1;
    index = portal->activePortals;

    /////////////////////PORTAL 3/////////////////////////////
    portal->portals[index].pos.x = 13+100.0;
    portal->portals[index].pos.y = -10;
    portal->portals[index].pos.z = 60;
    portal->portals[index].pos.w = 1;

    portal->portals[index].vertices[0].x = hei;
    portal->portals[index].vertices[0].y = 0;
    portal->portals[index].vertices[0].z = 0;

    portal->portals[index].vertices[1].x = hei;
    portal->portals[index].vertices[1].y = wid;
    portal->portals[index].vertices[1].z = 0;

    portal->portals[index].vertices[2].x = 0;
    portal->portals[index].vertices[2].y = wid;
    portal->portals[index].vertices[2].z = 0;

    portal->portals[index].vertices[3].x = 0;
    portal->portals[index].vertices[3].y = 0;
    portal->portals[index].vertices[3].z = 0;

    portal->portals[index].collisionOn = true;

    portal->portals[index].angle.xAng = 0;
    portal->portals[index].angle.yAng = 90;
    portal->portals[index].angle.zAng = 0;

    portal->portals[index].TransformationComplete = false,

    portal->portals[index].scene = 4,

    portal->portals[index].teleportToPositon.x = 163;
    portal->portals[index].teleportToPositon.y = -10;
    portal->portals[index].teleportToPositon.z = 57.5;
    portal->portals[index].teleportToPositon.w = 1;

    for(int i = 0; i < 5; i++)
    {
        portal->portals[index].vertices[i]= rotateVector(portal->portals[index].vertices[i], portal->portals[index].angle.yAng, 1,0,0);
        portal->portals[index].vertices[i] = rotateVector(portal->portals[index].vertices[i], portal->portals[index].angle.xAng, 0,1,0);
        portal->portals[index].vertices[i] = rotateVector(portal->portals[index].vertices[i], portal->portals[index].angle.zAng, 0,0,1);
    }

    portal->activePortals = portal->activePortals+ 1;
    index = portal->activePortals;


}

void loadScene4Button(ButtonBuffer *button)
{
    int index = button->activeButtons;

    button->buttons[index].pos.x = 161.6;
    button->buttons[index].pos.y = -6.5;
    button->buttons[index].pos.z = 1.0;

    button->buttons[index].sizeX = 10.0;
    button->buttons[index].sizeY = 10.0;
    button->buttons[index].sizeZ = 10.0;

    button->buttons[index].scene = 4;
    button->buttons[index].hasPressed = false;
    button->buttons[index].inbounds = false;
    button->buttons[index].maxPushDepth = 0.78;
    button->buttons[index].currentPushProgress = 0.0;
    button->buttons[index].buttonUnpushing = false;

    button->activeButtons +=1;
}

void loadScene4Geometry()
{
    Vector pos = {0,0,0,1};
    bool collide;
    Angle ang;
    float hei;
    float wid;
    Colour col;

    /////////////////BOX 1/////////////////////////////
    //entry floor
    pos.x = 0.0;
    pos.y = -10.0;
    pos.z = 0.0;
    collide = true;
    ang.xAng = 90.0;
    ang.yAng = 0.0;
    ang.zAng = 0.0;
    hei = 120;
    wid = 50;
    col.r = 1.0;
    col.g = 1.0;
    col.b = 0.0;
    createGeometryData(&scene4Geometry, pos,collide, ang, wid, hei, col, true );

    //roof floor
    pos.x = 0.0;
    pos.y = 2.5;
    pos.z = 0;
    collide = true;
    ang.xAng = 90.0;
    ang.yAng = 0.0;
    ang.zAng = 0.0;
    hei = 120;
    wid = 50;
    col.r = 0.0;
    col.g = 0.0;
    col.b = 1.0;
    createGeometryData(&scene4Geometry, pos,collide, ang, wid, hei, col, true );

    //Back wall
    pos.x = 0.0;
    pos.y = -10.0;
    pos.z = 0.0;
    collide = true;
    ang.xAng = 0.0;
    ang.yAng = 0.0;
    ang.zAng = 0.0;
    hei = 25;
    wid = 50;
    col.r = 0.0;
    col.g = 1.0;
    col.b = 0.0;
    createGeometryData(&scene4Geometry, pos,collide, ang, wid, hei, col, false );

    //front wall
    pos.x = 0.0;
    pos.y = -10.0;
    pos.z = 60.0;
    collide = true;
    ang.xAng = 0.0;
    ang.yAng = 0.0;
    ang.zAng = 0.0;
    hei = 25;
    wid = 50;
    col.r = 0.0;
    col.g = 1.0;
    col.b = 0.0;
    createGeometryData(&scene4Geometry, pos,collide, ang, wid, hei, col, false );

    //right wall segment 1
    pos.x = 0.0;
    pos.y = -10.0;
    pos.z = 0.0;
    collide = true;
    ang.xAng = 0.0;
    ang.yAng = -90.0;
    ang.zAng = 0.0;
    hei = 25;
    wid = 120;
    col.r = 0.0;
    col.g = 1.0;
    col.b = 0.0;
    createGeometryData(&scene4Geometry, pos,collide, ang, wid, hei, col, false );

    //left wall segment 1
    pos.x = 25;
    pos.y = -10.0;
    pos.z = 0.0;
    collide = true;
    ang.xAng = 0.0;
    ang.yAng = -90.0;
    ang.zAng = 0.0;
    hei = 25;
    wid = 120;
    col.r = 0.0;
    col.g = 1.0;
    col.b = 0.0;
    createGeometryData(&scene4Geometry, pos,collide, ang, wid, hei, col, false );

    ///////PILLAR/////////
    pos.x = 10;
    pos.y = -10.0;
    pos.z = 46.0;
    collide = true;
    ang.xAng = 0.0;
    ang.yAng = -90.0;
    ang.zAng = 0.0;
    hei = 25;
    wid = 12;
    col.r = 0.5;
    col.g = 1.0;
    col.b = 0.0;
    createGeometryData(&scene4Geometry, pos,collide, ang, wid, hei, col, false );

    pos.x = 16;
    pos.y = -10.0;
    pos.z = 46.0;
    collide = true;
    ang.xAng = 0.0;
    ang.yAng = -90.0;
    ang.zAng = 0.0;
    hei = 25;
    wid = 12;
    col.r = 0.5;
    col.g = 1.0;
    col.b = 0.0;
    createGeometryData(&scene4Geometry, pos,collide, ang, wid, hei, col, false );

    //back
    pos.x = 10;
    pos.y = -10.0;
    pos.z = 46.0;
    collide = true;
    ang.xAng = 0.0;
    ang.yAng = 0.0;
    ang.zAng = 0.0;
    hei = 25;
    wid = 12;
    col.r = 0.5;
    col.g = 1.0;
    col.b = 0.0;
    createGeometryData(&scene4Geometry, pos,collide, ang, wid, hei, col, false );

    //front
    pos.x = 10;
    pos.y = -10.0;
    pos.z = 52.0;
    collide = true;
    ang.xAng = 0.0;
    ang.yAng = 0.0;
    ang.zAng = 0.0;
    hei = 25;
    wid = 12;
    col.r = 0.5;
    col.g = 1.0;
    col.b = 0.0;
    createGeometryData(&scene4Geometry, pos,collide, ang, wid, hei, col, false );

    /////////////////BOX 2/////////////////////////////
    float mover = 50.0;
    //entry floor
    pos.x = 0.0+mover;
    pos.y = -10.0;
    pos.z = 0.0;
    collide = true;
    ang.xAng = 90.0;
    ang.yAng = 0.0;
    ang.zAng = 0.0;
    hei = 120;
    wid = 50;
    col.r = 1.0;
    col.g = 1.0;
    col.b = 0.0;
    createGeometryData(&scene4Geometry, pos,collide, ang, wid, hei, col, true );

    //roof floor
    pos.x = 0.0+mover;
    pos.y = 2.5;
    pos.z = 0;
    collide = true;
    ang.xAng = 90.0;
    ang.yAng = 0.0;
    ang.zAng = 0.0;
    hei = 120;
    wid = 50;
    col.r = 0.0;
    col.g = 0.0;
    col.b = 1.0;
    createGeometryData(&scene4Geometry, pos,collide, ang, wid, hei, col, true );

    //Back wall
    pos.x = 0.0+mover;
    pos.y = -10.0;
    pos.z = 0.0;
    collide = true;
    ang.xAng = 0.0;
    ang.yAng = 0.0;
    ang.zAng = 0.0;
    hei = 25;
    wid = 50;
    col.r = 0.0;
    col.g = 1.0;
    col.b = 0.0;
    createGeometryData(&scene4Geometry, pos,collide, ang, wid, hei, col, false );

    //front wall
    pos.x = 0.0+mover;
    pos.y = -10.0;
    pos.z = 60.0;
    collide = true;
    ang.xAng = 0.0;
    ang.yAng = 0.0;
    ang.zAng = 0.0;
    hei = 25;
    wid = 50;
    col.r = 0.0;
    col.g = 1.0;
    col.b = 0.0;
    createGeometryData(&scene4Geometry, pos,collide, ang, wid, hei, col, false );

    //right wall segment 1
    pos.x = 0.0+mover;
    pos.y = -10.0;
    pos.z = 0.0;
    collide = true;
    ang.xAng = 0.0;
    ang.yAng = -90.0;
    ang.zAng = 0.0;
    hei = 25;
    wid = 120;
    col.r = 0.0;
    col.g = 1.0;
    col.b = 0.0;
    createGeometryData(&scene4Geometry, pos,collide, ang, wid, hei, col, false );

    //left wall segment 1
    pos.x = 25+mover;
    pos.y = -10.0;
    pos.z = 0.0;
    collide = true;
    ang.xAng = 0.0;
    ang.yAng = -90.0;
    ang.zAng = 0.0;
    hei = 25;
    wid = 120;
    col.r = 0.0;
    col.g = 1.0;
    col.b = 0.0;
    createGeometryData(&scene4Geometry, pos,collide, ang, wid, hei, col, false );

    ///////PILLAR/////////
    pos.x = 10+mover;
    pos.y = -10.0;
    pos.z = 46.0;
    collide = true;
    ang.xAng = 0.0;
    ang.yAng = -90.0;
    ang.zAng = 0.0;
    hei = 25;
    wid = 12;
    col.r = 0.5;
    col.g = 1.0;
    col.b = 0.0;
    createGeometryData(&scene4Geometry, pos,collide, ang, wid, hei, col, false );

    pos.x = 16+mover;
    pos.y = -10.0;
    pos.z = 46.0;
    collide = true;
    ang.xAng = 0.0;
    ang.yAng = -90.0;
    ang.zAng = 0.0;
    hei = 25;
    wid = 12;
    col.r = 0.5;
    col.g = 1.0;
    col.b = 0.0;
    createGeometryData(&scene4Geometry, pos,collide, ang, wid, hei, col, false );

    //back
    pos.x = 10+mover;
    pos.y = -10.0;
    pos.z = 46.0;
    collide = true;
    ang.xAng = 0.0;
    ang.yAng = 0.0;
    ang.zAng = 0.0;
    hei = 25;
    wid = 12;
    col.r = 0.5;
    col.g = 1.0;
    col.b = 0.0;
    createGeometryData(&scene4Geometry, pos,collide, ang, wid, hei, col, false );

    //front
    pos.x = 10+mover;
    pos.y = -10.0;
    pos.z = 52.0;
    collide = true;
    ang.xAng = 0.0;
    ang.yAng = 0.0;
    ang.zAng = 0.0;
    hei = 25;
    wid = 12;
    col.r = 0.5;
    col.g = 1.0;
    col.b = 0.0;
    createGeometryData(&scene4Geometry, pos,collide, ang, wid, hei, col, false );

    /////////////////BOX 3/////////////////////////////
    mover = 100.0;
    //entry floor
    pos.x = 0.0+mover;
    pos.y = -10.0;
    pos.z = 0.0;
    collide = true;
    ang.xAng = 90.0;
    ang.yAng = 0.0;
    ang.zAng = 0.0;
    hei = 120;
    wid = 50;
    col.r = 1.0;
    col.g = 1.0;
    col.b = 0.0;
    createGeometryData(&scene4Geometry, pos,collide, ang, wid, hei, col, true );

    //roof floor
    pos.x = 0.0+mover;
    pos.y = 2.5;
    pos.z = 0;
    collide = true;
    ang.xAng = 90.0;
    ang.yAng = 0.0;
    ang.zAng = 0.0;
    hei = 120;
    wid = 50;
    col.r = 0.0;
    col.g = 0.0;
    col.b = 1.0;
    createGeometryData(&scene4Geometry, pos,collide, ang, wid, hei, col, true );

    //Back wall
    pos.x = 0.0+mover;
    pos.y = -10.0;
    pos.z = 0.0;
    collide = true;
    ang.xAng = 0.0;
    ang.yAng = 0.0;
    ang.zAng = 0.0;
    hei = 25;
    wid = 50;
    col.r = 0.0;
    col.g = 1.0;
    col.b = 0.0;
    createGeometryData(&scene4Geometry, pos,collide, ang, wid, hei, col, false );

    //front wall
    pos.x = 0.0+mover;
    pos.y = -10.0;
    pos.z = 60.0;
    collide = true;
    ang.xAng = 0.0;
    ang.yAng = 0.0;
    ang.zAng = 0.0;
    hei = 25;
    wid = 50;
    col.r = 0.0;
    col.g = 1.0;
    col.b = 0.0;
    createGeometryData(&scene4Geometry, pos,collide, ang, wid, hei, col, false );

    //right wall segment 1
    pos.x = 0.0+mover;
    pos.y = -10.0;
    pos.z = 0.0;
    collide = true;
    ang.xAng = 0.0;
    ang.yAng = -90.0;
    ang.zAng = 0.0;
    hei = 25;
    wid = 120;
    col.r = 0.0;
    col.g = 1.0;
    col.b = 0.0;
    createGeometryData(&scene4Geometry, pos,collide, ang, wid, hei, col, false );

    //left wall segment 1
    pos.x = 25+mover;
    pos.y = -10.0;
    pos.z = 0.0;
    collide = true;
    ang.xAng = 0.0;
    ang.yAng = -90.0;
    ang.zAng = 0.0;
    hei = 25;
    wid = 120;
    col.r = 0.0;
    col.g = 1.0;
    col.b = 0.0;
    createGeometryData(&scene4Geometry, pos,collide, ang, wid, hei, col, false );

    ///////PILLAR/////////
    pos.x = 10+mover;
    pos.y = -10.0;
    pos.z = 46.0;
    collide = true;
    ang.xAng = 0.0;
    ang.yAng = -90.0;
    ang.zAng = 0.0;
    hei = 25;
    wid = 12;
    col.r = 0.5;
    col.g = 1.0;
    col.b = 0.0;
    createGeometryData(&scene4Geometry, pos,collide, ang, wid, hei, col, false );

    pos.x = 16+mover;
    pos.y = -10.0;
    pos.z = 46.0;
    collide = true;
    ang.xAng = 0.0;
    ang.yAng = -90.0;
    ang.zAng = 0.0;
    hei = 25;
    wid = 12;
    col.r = 0.5;
    col.g = 1.0;
    col.b = 0.0;
    createGeometryData(&scene4Geometry, pos,collide, ang, wid, hei, col, false );

    //back
    pos.x = 10+mover;
    pos.y = -10.0;
    pos.z = 46.0;
    collide = true;
    ang.xAng = 0.0;
    ang.yAng = 0.0;
    ang.zAng = 0.0;
    hei = 25;
    wid = 12;
    col.r = 0.5;
    col.g = 1.0;
    col.b = 0.0;
    createGeometryData(&scene4Geometry, pos,collide, ang, wid, hei, col, false );

    //front
    pos.x = 10+mover;
    pos.y = -10.0;
    pos.z = 52.0;
    collide = true;
    ang.xAng = 0.0;
    ang.yAng = 0.0;
    ang.zAng = 0.0;
    hei = 25;
    wid = 12;
    col.r = 0.5;
    col.g = 1.0;
    col.b = 0.0;
    createGeometryData(&scene4Geometry, pos,collide, ang, wid, hei, col, false );

    /////////////////BOX 4/////////////////////////////
    mover = 150.0;
    //entry floor
    pos.x = 0.0+mover;
    pos.y = -10.0;
    pos.z = 0.0;
    collide = true;
    ang.xAng = 90.0;
    ang.yAng = 0.0;
    ang.zAng = 0.0;
    hei = 120;
    wid = 50;
    col.r = 1.0;
    col.g = 1.0;
    col.b = 0.0;
    createGeometryData(&scene4Geometry, pos,collide, ang, wid, hei, col, true );

    //roof floor
    pos.x = 0.0+mover;
    pos.y = 2.5;
    pos.z = 0;
    collide = true;
    ang.xAng = 90.0;
    ang.yAng = 0.0;
    ang.zAng = 0.0;
    hei = 120;
    wid = 50;
    col.r = 0.0;
    col.g = 0.0;
    col.b = 1.0;
    createGeometryData(&scene4Geometry, pos,collide, ang, wid, hei, col, true );

    //Back wall
    pos.x = 0.0+mover;
    pos.y = -10.0;
    pos.z = 0.0;
    collide = true;
    ang.xAng = 0.0;
    ang.yAng = 0.0;
    ang.zAng = 0.0;
    hei = 25;
    wid = 50;
    col.r = 0.0;
    col.g = 1.0;
    col.b = 0.0;
    createGeometryData(&scene4Geometry, pos,collide, ang, wid, hei, col, false );

    //front wall
    pos.x = 0.0+mover;
    pos.y = -10.0;
    pos.z = 60.0;
    collide = true;
    ang.xAng = 0.0;
    ang.yAng = 0.0;
    ang.zAng = 0.0;
    hei = 25;
    wid = 50;
    col.r = 0.0;
    col.g = 1.0;
    col.b = 0.0;
    createGeometryData(&scene4Geometry, pos,collide, ang, wid, hei, col, false );

    //right wall segment 1
    pos.x = 0.0+mover;
    pos.y = -10.0;
    pos.z = 0.0;
    collide = true;
    ang.xAng = 0.0;
    ang.yAng = -90.0;
    ang.zAng = 0.0;
    hei = 25;
    wid = 120;
    col.r = 0.0;
    col.g = 1.0;
    col.b = 0.0;
    createGeometryData(&scene4Geometry, pos,collide, ang, wid, hei, col, false );

    //left wall segment 1
    pos.x = 25+mover;
    pos.y = -10.0;
    pos.z = 0.0;
    collide = true;
    ang.xAng = 0.0;
    ang.yAng = -90.0;
    ang.zAng = 0.0;
    hei = 25;
    wid = 120;
    col.r = 0.0;
    col.g = 1.0;
    col.b = 0.0;
    createGeometryData(&scene4Geometry, pos,collide, ang, wid, hei, col, false );

    ///////PILLAR/////////
    pos.x = 10+mover;
    pos.y = -10.0;
    pos.z = 46.0;
    collide = true;
    ang.xAng = 0.0;
    ang.yAng = -90.0;
    ang.zAng = 0.0;
    hei = 25;
    wid = 12;
    col.r = 0.5;
    col.g = 1.0;
    col.b = 0.0;
    createGeometryData(&scene4Geometry, pos,collide, ang, wid, hei, col, false );

    pos.x = 16+mover;
    pos.y = -10.0;
    pos.z = 46.0;
    collide = true;
    ang.xAng = 0.0;
    ang.yAng = -90.0;
    ang.zAng = 0.0;
    hei = 25;
    wid = 12;
    col.r = 0.5;
    col.g = 1.0;
    col.b = 0.0;
    createGeometryData(&scene4Geometry, pos,collide, ang, wid, hei, col, false );

    //back
    pos.x = 10+mover;
    pos.y = -10.0;
    pos.z = 46.0;
    collide = true;
    ang.xAng = 0.0;
    ang.yAng = 0.0;
    ang.zAng = 0.0;
    hei = 25;
    wid = 12;
    col.r = 0.5;
    col.g = 1.0;
    col.b = 0.0;
    createGeometryData(&scene4Geometry, pos,collide, ang, wid, hei, col, false );

    //front
    pos.x = 10+mover;
    pos.y = -10.0;
    pos.z = 52.0;
    collide = true;
    ang.xAng = 0.0;
    ang.yAng = 0.0;
    ang.zAng = 0.0;
    hei = 25;
    wid = 12;
    col.r = 0.5;
    col.g = 1.0;
    col.b = 0.0;
    createGeometryData(&scene4Geometry, pos,collide, ang, wid, hei, col, false );

    ///////////////////////////BUTTON BOX///////////////////
        pos.x = 11.5+mover;
        pos.y = -10.0;
        pos.z = 45.0-42;
        collide = true;
        ang.xAng = 0.0;
        ang.yAng = 0.0;
        ang.zAng = 0.0;
        hei = 8;
        wid = 6;
        col.r = 1.0;
        col.g = 0.0;
        col.b = 1.0;
        createGeometryData(&scene4Geometry, pos,collide, ang, wid, hei, col, false );

        pos.x = 11.5+mover;
        pos.y = -10.0;
        pos.z = 42.0-42;
        collide = true;
        ang.xAng = 0.0;
        ang.yAng = -90.0;
        ang.zAng = 0.0;
        hei = 8;
        wid = 6;
        col.r = 1.0;
        col.g = 0.0;
        col.b = 1.0;
        createGeometryData(&scene4Geometry, pos,collide, ang, wid, hei, col, false );

        pos.x = 14.5+mover;
        pos.y = -10.0;
        pos.z = 42.0-42;
        collide = true;
        ang.xAng = 0.0;
        ang.yAng = -90.0;
        ang.zAng = 0.0;
        hei = 8;
        wid = 6;
        col.r = 1.0;
        col.g = 0.0;
        col.b = 1.0;
        createGeometryData(&scene4Geometry, pos,collide, ang, wid, hei, col, false );

        pos.x = 11.5+mover;
        pos.y = -6.0;
        pos.z = 42.0-42;
        collide = true;
        ang.xAng = 90.0;
        ang.yAng = 0.0;
        ang.zAng = 0.0;
        hei = 6;
        wid = 6;
        col.r = 1.0;
        col.g = 0.0;
        col.b = 1.0;
        createGeometryData(&scene4Geometry, pos,collide, ang, wid, hei, col, false );

    ///////////////////////////////////////////////////////
}

void scene4_main(CollisionMeshes *meshData, PortalBuffer *scenePorts, ButtonBuffer *sceneButtons, Ball *plyBall)
{
    for(int i = 0; i<=scene4Geometry.activeMeshes; i++)
    {
       draw4PointGeometry(&scene4Geometry.mesh[i], meshData);
    }

    for(int i = 0; i<=sceneButtons->activeButtons; i++)
    {
        if(sceneButtons->buttons[i].scene == 4)
            DrawButton(&sceneButtons->buttons[i], &sceneButtons->objectData);
    }

    for(int i = 0; i<=scenePorts->activePortals; i++)
    {
        if(scenePorts->portals[i].scene == 4)
        {
            loadPortal(meshData, &scenePorts->portals[i]);

        }

    }

    drawBall(plyBall, meshData);

    glPushMatrix();
        glTranslatef(12.5, -6.0 ,8.0 );
        glColor3f(1.0,0.0, 0.0);
        glutSolidTeapot(5);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(12.5+50, -6.0 ,8.0 );
        glColor3f(0.0,0.5, 0.5);
        glutSolidTeapot(5);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(12.5+100, -6.0 ,8.0 );
        glColor3f(0.5,0.5, 0.5);
        glutSolidTeapot(5);
    glPopMatrix();
}
