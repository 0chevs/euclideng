
#include "scene2.h"

GeometryBuffer scene2Geometry =
{
    .activeMeshes = 0,
};

void loadScene2Portals(PortalBuffer *portal)
{
    float hei;
    float wid;

    int index = portal->activePortals;


    /////////////////////PORTAL 1/////////////////////////////
    hei = 9;
    wid = 12.5;

    portal->portals[index].pos.x = -22;
    portal->portals[index].pos.y = -32;
    portal->portals[index].pos.z = 24;
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

    portal->portals[index].scene = 2,

    portal->portals[index].teleportToPositon.x = 9;
    portal->portals[index].teleportToPositon.y = -9;
    portal->portals[index].teleportToPositon.z = 85+wid/2;
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
    hei = 9;
    wid = 12.5;

    portal->portals[index].pos.x = 9;
    portal->portals[index].pos.y = -10;
    portal->portals[index].pos.z = 85;
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
    portal->portals[index].angle.yAng = -90;
    portal->portals[index].angle.zAng = 0;

    portal->portals[index].TransformationComplete = false,

    portal->portals[index].scene = 2,

    portal->portals[index].teleportToPositon.x = -22;
    portal->portals[index].teleportToPositon.y = -32;
    portal->portals[index].teleportToPositon.z = 20;
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

void loadScene2Button(ButtonBuffer *button)
{
    int index = button->activeButtons;

    button->buttons[index].pos.x = 3.15;
    button->buttons[index].pos.y = -6.5;
    button->buttons[index].pos.z = 124;

    button->buttons[index].sizeX = 10.0;
    button->buttons[index].sizeY = 10.0;
    button->buttons[index].sizeZ = 10.0;

    button->buttons[index].scene = 2;
    button->buttons[index].hasPressed = false;
    button->buttons[index].inbounds = false;
    button->buttons[index].maxPushDepth = 0.78;
    button->buttons[index].currentPushProgress = 0.0;
    button->buttons[index].buttonUnpushing = false;

    button->activeButtons +=1;
}

void loadScene2Geometry()
{
    Vector pos = {0,0,0,1};
    bool collide;
    Angle ang;
    float hei;
    float wid;
    Colour col;
    //NOTE: Scene 1 is test level
    //////////////////SCENE 2/////////////////////////////////////////
    //Floor
    pos.x = 0.0;
    pos.y = -10.0;
    pos.z = 0.0;
    collide = true;
    ang.xAng = 90.0;
    ang.yAng = 0.0;
    ang.zAng = 0.0;
    hei = 250;
    wid = 18;
    col.r = 1.0f;
    col.g = 1.0;
    col.b = 0.0;
    createGeometryData(&scene2Geometry, pos,collide, ang, wid, hei, col, true );

    ///////////////////////////BUTTON  BOX///////////////////
        pos.x = 3;
        pos.y = -10.0;
        pos.z = 123.0;
        collide = true;
        ang.xAng = 0.0;
        ang.yAng = 0.0;
        ang.zAng = 0.0;
        hei = 8;
        wid = 6;
        col.r = 1.0;
        col.g = 0.0;
        col.b = 1.0;
        createGeometryData(&scene2Geometry, pos,collide, ang, wid, hei, col, false );

        pos.x = 3;
        pos.y = -10.0;
        pos.z = 123.0;
        collide = true;
        ang.xAng = 0.0;
        ang.yAng = -90.0;
        ang.zAng = 0.0;
        hei = 8;
        wid = 6;
        col.r = 1.0;
        col.g = 0.0;
        col.b = 1.0;
        createGeometryData(&scene2Geometry, pos,collide, ang, wid, hei, col, false );

        pos.x = 6;
        pos.y = -10.0;
        pos.z = 123.0;
        collide = true;
        ang.xAng = 0.0;
        ang.yAng = -90.0;
        ang.zAng = 0.0;
        hei = 8;
        wid = 6;
        col.r = 1.0;
        col.g = 0.0;
        col.b = 1.0;
        createGeometryData(&scene2Geometry, pos,collide, ang, wid, hei, col, false );

        pos.x = 3;
        pos.y = -6.0;
        pos.z = 123.0;
        collide = true;
        ang.xAng = 90.0;
        ang.yAng = 0.0;
        ang.zAng = 0.0;
        hei = 6;
        wid = 6;
        col.r = 1.0;
        col.g = 0.0;
        col.b = 1.0;
        createGeometryData(&scene2Geometry, pos,collide, ang, wid, hei, col, false );

    ///////////////////////////////////////////////////////

    //main roof
    pos.x = 0.0;
    pos.y = 2.5;
    pos.z = 0.0;
    collide = true;
    ang.xAng = 90.0;
    ang.yAng = 0.0;
    ang.zAng = 0.0;
    hei = 250;
    wid = 18;
    col.r = 0.0;
    col.g = 0.0;
    col.b = 1.0;
    createGeometryData(&scene2Geometry, pos,collide, ang, wid, hei, col, false );

    //Back wall
    pos.x = 0.0;
    pos.y = -10.0;
    pos.z = 0.0;
    collide = true;
    ang.xAng = 0.0;
    ang.yAng = 0.0;
    ang.zAng = 0.0;
    hei = 25;
    wid = 18;
    col.r = 0.0;
    col.g = 1.0;
    col.b = 0.0;
    createGeometryData(&scene2Geometry, pos,collide, ang, wid, hei, col, false );

    //front wall
    pos.x = 0.0;
    pos.y = -10.0;
    pos.z = 125.0;
    collide = true;
    ang.xAng = 0.0;
    ang.yAng = 0.0;
    ang.zAng = 0.0;
    hei = 25;
    wid = 18;
    col.r = 0.0;
    col.g = 1.0;
    col.b = 0.0;
    createGeometryData(&scene2Geometry, pos,collide, ang, wid, hei, col, false );

    //left wall segment 1
    pos.x = 9.0;
    pos.y = -10.0;
    pos.z = 0.0;
    collide = true;
    ang.xAng = 0.0;
    ang.yAng = -90.0;
    ang.zAng = 0.0;
    hei = 25;
    wid = 170;
    col.r = 0.0;
    col.g = 1.0;
    col.b = 0.0;
    createGeometryData(&scene2Geometry, pos,collide, ang, wid, hei, col, false );

    //left wall segment 2
    pos.x = 9.0;
    pos.y = -10.0;
    pos.z = 94.0;
    collide = true;
    ang.xAng = 0.0;
    ang.yAng = -90.0;
    ang.zAng = 0.0;
    hei = 25;
    wid = 62;
    col.r = 0.0;
    col.g = 1.0;
    col.b = 0.0;
    createGeometryData(&scene2Geometry, pos,collide, ang, wid, hei, col, false );

    //right wall segment 1
    pos.x = 0.0;
    pos.y = -10.0;
    pos.z = 0.0;
    collide = true;
    ang.xAng = 0.0;
    ang.yAng = -90.0;
    ang.zAng = 0.0;
    hei = 25;
    wid = 30;
    col.r = 0.0;
    col.g = 1.0;
    col.b = 0.0;
    createGeometryData(&scene2Geometry, pos,collide, ang, wid, hei, col, false );

    //right wall segment 2
    pos.x = 0.0;
    pos.y = -10.0;
    pos.z = 24.0;
    collide = true;
    ang.xAng = 0.0;
    ang.yAng = -90.0;
    ang.zAng = 0.0;
    hei = 25;
    wid = 202;
    col.r = 0.0;
    col.g = 1.0;
    col.b = 0.0;
    createGeometryData(&scene2Geometry, pos,collide, ang, wid, hei, col, false );

    ///////////////////STAIRS/////////////////////////////

    for(int i = 0; i<=10; i++)
    {
        pos.x = 0.0 - (2.0*i);
        pos.y = -12.0 - (2.0*i);
        pos.z = 15.0;
        collide = true;
        ang.xAng = 0.0;
        ang.yAng = -90.0;
        ang.zAng = 90.0;
        hei = 4;
        wid = 18;
        col.r = 0.0;
        col.g = 0.0;
        col.b = 0.0;
        createGeometryData(&scene2Geometry, pos,collide, ang, wid, hei, col, true );
    }

    for(int i = 0; i<=10; i++)
    {
        //right stairs 5
        pos.x = 0.00 - (2.0*i);
        pos.y = -10.0 - (2.0*i);
        pos.z = 15.0;
        collide = true;
        ang.xAng = 0.0;
        ang.yAng = -90.0;
        ang.zAng = 180.0;
        hei = 4;
        wid = 18;
        col.r = 0.0;
        col.g = 0.0;
        col.b = 0.0;
        createGeometryData(&scene2Geometry, pos,collide, ang, wid, hei, col, false );

    }

    //right lower floor
    pos.x = -22;
    pos.y = -32;
    pos.z = -20.0;
    collide = true;
    ang.xAng = 0.0;
    ang.yAng = -90.0;
    ang.zAng = 90.0;
    hei = 18;
    wid = 158;
    col.r = 1.0;
    col.g = 1.0;
    col.b = 0.0;
    createGeometryData(&scene2Geometry, pos,collide, ang, wid, hei, col, true );

    //right stairs roof
    pos.x = 0;
    pos.y = 2.5;
    pos.z = 15.0;
    collide = false;
    ang.xAng = 0.0;
    ang.yAng = -90.0;
    ang.zAng = 135.0;
    hei = 62.3;
    wid = 18;
    col.r = 0.0;
    col.g = 0.0;
    col.b = 1.0;
    createGeometryData(&scene2Geometry, pos,collide, ang, wid, hei, col, false );

    //right stairs right wall
    pos.x = -22;
    pos.y = -32;
    pos.z = 15.0;
    collide = true;
    ang.xAng = 0.0;
    ang.yAng = 0.0;
    ang.zAng = 0.0;
    hei = 69;
    wid = 44;
    col.r = 0.0;
    col.g = 1.0;
    col.b = 0.0;
    createGeometryData(&scene2Geometry, pos,collide, ang, wid, hei, col, false );

    //right stairs left wall
    pos.x = -22;
    pos.y = -32;
    pos.z = 24.0;
    collide = true;
    ang.xAng = 0.0;
    ang.yAng = 0.0;
    ang.zAng = 0.0;
    hei = 69;
    wid = 44;
    col.r = 0.0;
    col.g = 1.0;
    col.b = 0.0;
    createGeometryData(&scene2Geometry, pos,collide, ang, wid, hei, col, false );

    //right lower floor - left wall - seg 1
    pos.x = -22;
    pos.y = -32;
    pos.z = -20.0;
    collide = true;
    ang.xAng = 0.0;
    ang.yAng = -90.0;
    ang.zAng = 0.0;
    hei = 25;
    wid = 70;
    col.r = 0.0;
    col.g = 1.0;
    col.b = 0.0;
    createGeometryData(&scene2Geometry, pos,collide, ang, wid, hei, col, false );

    //right lower floor - left wall - seg 2
    pos.x = -22;
    pos.y = -32;
    pos.z = 24.0;
    collide = true;
    ang.xAng = 0.0;
    ang.yAng = -90.0;
    ang.zAng = 0.0;
    hei = 25;
    wid = 70;
    col.r = 0.0;
    col.g = 1.0;
    col.b = 0.0;
    createGeometryData(&scene2Geometry, pos,collide, ang, wid, hei, col, false );

    //right lower floor - right wall - seg 1
    pos.x = -31;
    pos.y = -32;
    pos.z = -20.0;
    collide = true;
    ang.xAng = 0.0;
    ang.yAng = -90.0;
    ang.zAng = 0.0;
    hei = 25;
    wid = 158;
    col.r = 0.0;
    col.g = 1.0;
    col.b = 0.0;
    createGeometryData(&scene2Geometry, pos,collide, ang, wid, hei, col, false );

    //right lower floor - backwall
    pos.x = -31;
    pos.y = -32;
    pos.z = -20.0;
    collide = true;
    ang.xAng = 0.0;
    ang.yAng = 0.0;
    ang.zAng = 0.0;
    hei = 25;
    wid = 18;
    col.r = 0.0;
    col.g = 1.0;
    col.b = 0.0;
    createGeometryData(&scene2Geometry, pos,collide, ang, wid, hei, col, false );

    //right lower floor - frontwall
    pos.x = -31;
    pos.y = -32;
    pos.z = 58.0;
    collide = true;
    ang.xAng = 0.0;
    ang.yAng = 0.0;
    ang.zAng = 0.0;
    hei = 25;
    wid = 18;
    col.r = 0.0;
    col.g = 1.0;
    col.b = 0.0;
    createGeometryData(&scene2Geometry, pos,collide, ang, wid, hei, col, false );

    //right lower floor - roof
    pos.x = -22;
    pos.y = -19.5;
    pos.z = -20.0;
    collide = false;
    ang.xAng = 0.0;
    ang.yAng = -90.0;
    ang.zAng = 90.0;
    hei = 18;
    wid = 158;
    col.r = 0.0;
    col.g = 0.0;
    col.b = 1.0;
    createGeometryData(&scene2Geometry, pos,collide, ang, wid, hei, col, true );

    //////////////////Second Stairs/////////////////////////////

    for(int i = 0; i<=10; i++)
    {
        pos.x = 11.0 + (2.0*i);
        pos.y = -10.0 + (2.0*i);
        pos.z = 85.0;
        collide = true;
        ang.xAng = 0.0;
        ang.yAng = -90.0;
        ang.zAng = 90.0;
        hei = 4;
        wid = 18;
        col.r = 0.0;
        col.g = 0.0;
        col.b = 0.0;
        createGeometryData(&scene2Geometry, pos,collide, ang, wid, hei, col, true );
    }

    for(int i = 0; i<=10; i++)
    {
        //right stairs 5
        pos.x = 11.0 + (2.0*i);
        pos.y = -8.0 + (2.0*i);
        pos.z = 85.0;
        collide = true;
        ang.xAng = 0.0;
        ang.yAng = -90.0;
        ang.zAng = 180.0;
        hei = 4;
        wid = 18;
        col.r = 0.0;
        col.g = 0.0;
        col.b = 0.0;
        createGeometryData(&scene2Geometry, pos,collide, ang, wid, hei, col, false );

    }

    //right lower floor
    pos.x = 31;
    pos.y = 12;
    pos.z = 50;
    collide = true;
    ang.xAng = 0.0;
    ang.yAng = -90.0;
    ang.zAng = -90.0;
    hei = 18;
    wid = 158;
    col.r = 1.0;
    col.g = 1.0;
    col.b = 0.0;
    createGeometryData(&scene2Geometry, pos,collide, ang, wid, hei, col, true );

    //right stairs roof
    pos.x = 9;
    pos.y = 2.5;
    pos.z = 85.0;
    collide = false;
    ang.xAng = 0.0;
    ang.yAng = -90.0;
    ang.zAng = 315.0;
    hei = 62.3;
    wid = 18;
    col.r = 0.0;
    col.g = 0.0;
    col.b = 1.0;
    createGeometryData(&scene2Geometry, pos,collide, ang, wid, hei, col, false );

    //right stairs right wall
    pos.x = 9;
    pos.y = -10;
    pos.z = 85.0;
    collide = true;
    ang.xAng = 0.0;
    ang.yAng = 0.0;
    ang.zAng = 0.0;
    hei = 69;
    wid = 44;
    col.r = 0.0;
    col.g = 1.0;
    col.b = 0.0;
    createGeometryData(&scene2Geometry, pos,collide, ang, wid, hei, col, false );

    //right stairs left wall
    pos.x = 9;
    pos.y = -10;
    pos.z = 94;
    collide = true;
    ang.xAng = 0.0;
    ang.yAng = 0.0;
    ang.zAng = 0.0;
    hei = 69;
    wid = 44;
    col.r = 0.0;
    col.g = 1.0;
    col.b = 0.0;
    createGeometryData(&scene2Geometry, pos,collide, ang, wid, hei, col, false );

    //right lower floor - left wall - seg 1
    pos.x = 31;
    pos.y = 12;
    pos.z = 94;
    collide = true;
    ang.xAng = 0.0;
    ang.yAng = -90.0;
    ang.zAng = 0.0;
    hei = 25;
    wid = 70;
    col.r = 0.0;
    col.g = 1.0;
    col.b = 0.0;
    createGeometryData(&scene2Geometry, pos,collide, ang, wid, hei, col, false );

    //right lower floor - left wall - seg 2
    pos.x = 31;
    pos.y = 12;
    pos.z = 50;
    collide = true;
    ang.xAng = 0.0;
    ang.yAng = -90.0;
    ang.zAng = 0.0;
    hei = 25;
    wid = 70;
    col.r = 0.0;
    col.g = 1.0;
    col.b = 0.0;
    createGeometryData(&scene2Geometry, pos,collide, ang, wid, hei, col, false );

    //right lower floor - right wall - seg 1
    pos.x = 40;
    pos.y = 12;
    pos.z = 50;
    collide = true;
    ang.xAng = 0.0;
    ang.yAng = -90.0;
    ang.zAng = 0.0;
    hei = 25;
    wid = 158;
    col.r = 0.0;
    col.g = 1.0;
    col.b = 0.0;
    createGeometryData(&scene2Geometry, pos,collide, ang, wid, hei, col, false );

    //right lower floor - backwall
    pos.x = 40;
    pos.y = 12;
    pos.z = 50;
    collide = true;
    ang.xAng = 0.0;
    ang.yAng = 180.0;
    ang.zAng = 0.0;
    hei = 25;
    wid = 18;
    col.r = 0.0;
    col.g = 1.0;
    col.b = 0.0;
    createGeometryData(&scene2Geometry, pos,collide, ang, wid, hei, col, false );

    //right lower floor - frontwall
    pos.x = 40;
    pos.y = 12;
    pos.z = 128.0;
    collide = true;
    ang.xAng = 0.0;
    ang.yAng = 180.0;
    ang.zAng = 0.0;
    hei = 25;
    wid = 18;
    col.r = 0.0;
    col.g = 1.0;
    col.b = 0.0;
    createGeometryData(&scene2Geometry, pos,collide, ang, wid, hei, col, false );

    //right lower floor - roof
    pos.x = 40;
    pos.y = 24.5;
    pos.z = 50.0;
    collide = true;
    ang.xAng = 0.0;
    ang.yAng = -90.0;
    ang.zAng = 90.0;
    hei = 18;
    wid = 158;
    col.r = 0.0;
    col.g = 0.0;
    col.b = 1.0;
    createGeometryData(&scene2Geometry, pos,collide, ang, wid, hei, col, true );
}

void scene2_main(CollisionMeshes *meshData, PortalBuffer *scenePorts, ButtonBuffer *sceneButtons, Ball *plyBall)
{
    for(int i = 0; i<=scene2Geometry.activeMeshes; i++)
    {
       draw4PointGeometry(&scene2Geometry.mesh[i], meshData);
    }

    for(int i = 0; i<=sceneButtons->activeButtons; i++)
    {
        if(sceneButtons->buttons[i].scene == 2)
            DrawButton(&sceneButtons->buttons[i], &sceneButtons->objectData);
    }

    for(int i = 0; i<=scenePorts->activePortals; i++)
    {
        if(scenePorts->portals[i].scene == 2)
            loadPortal(meshData, &scenePorts->portals[i]);
    }

    drawBall(plyBall, meshData);
}
