
#include "scene3.h"

GeometryBuffer scene3Geometry =
{
    .activeMeshes = 0,
};

void loadScene3Portals(PortalBuffer *portal)
{
    float hei;
    float wid;

    int index = portal->activePortals;

    hei = 8;
    wid = 12.5;
    /////////////////////PORTAL 1/////////////////////////////
    portal->portals[index].pos.x = -15;
    portal->portals[index].pos.y = -10;
    portal->portals[index].pos.z = 70;
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

    portal->portals[index].scene = 3,

    portal->portals[index].teleportToPositon.x = 85;
    portal->portals[index].teleportToPositon.y = -10;
    portal->portals[index].teleportToPositon.z = 66;
    portal->portals[index].teleportToPositon.w = 1;

    for(int i = 0; i < 5; i++)
    {
        portal->portals[index].vertices[i]= rotateVector(portal->portals[index].vertices[i], portal->portals[index].angle.yAng, 1,0,0);
        portal->portals[index].vertices[i] = rotateVector(portal->portals[index].vertices[i], portal->portals[index].angle.xAng, 0,1,0);
        portal->portals[index].vertices[i] = rotateVector(portal->portals[index].vertices[i], portal->portals[index].angle.zAng, 0,0,1);
    }

    portal->activePortals = portal->activePortals+ 1;
    index = portal->activePortals;

    /////////////////////////PORTAL 2///////////////////////////

    portal->portals[index].pos.x = 85;
    portal->portals[index].pos.y = -10;
    portal->portals[index].pos.z = 70;
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

    portal->portals[index].scene = 3,

    portal->portals[index].teleportToPositon.x = -15;
    portal->portals[index].teleportToPositon.y = -10;
    portal->portals[index].teleportToPositon.z = 66;
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

void loadScene3Button(ButtonBuffer *button)
{
    int index = button->activeButtons;

    button->buttons[index].pos.x = 80.1;
    button->buttons[index].pos.y = -6.5;
    button->buttons[index].pos.z = 43.0;

    button->buttons[index].sizeX = 10.0;
    button->buttons[index].sizeY = 10.0;
    button->buttons[index].sizeZ = 10.0;

    button->buttons[index].scene = 3;
    button->buttons[index].hasPressed = false;
    button->buttons[index].inbounds = false;
    button->buttons[index].maxPushDepth = 0.78;
    button->buttons[index].currentPushProgress = 0.0;
    button->buttons[index].buttonUnpushing = false;

    button->activeButtons +=1;
}

void loadScene3Geometry()
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
    hei = 40;
    wid = 18;
    col.r = 1.0f;
    col.g = 1.0;
    col.b = 0.0;
    createGeometryData(&scene3Geometry, pos,collide, ang, wid, hei, col, true );

    //box 1 floor
    pos.x = -41.0;
    pos.y = -10.0;
    pos.z = 20.0;
    collide = true;
    ang.xAng = 90.0;
    ang.yAng = 0.0;
    ang.zAng = 0.0;
    hei = 100;
    wid = 100;
    col.r = 1.0f;
    col.g = 1.0;
    col.b = 0.0;
    createGeometryData(&scene3Geometry, pos,collide, ang, wid, hei, col, true );

    //box 1 roof
    pos.x = -41.0;
    pos.y = 2.5;
    pos.z = 20.0;
    collide = true;
    ang.xAng = 90.0;
    ang.yAng = 0.0;
    ang.zAng = 0.0;
    hei = 100;
    wid = 100;
    col.r = 0.0;
    col.g = 0.0;
    col.b = 1.0;
    createGeometryData(&scene3Geometry, pos,collide, ang, wid, hei, col, true );

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
    createGeometryData(&scene3Geometry, pos,collide, ang, wid, hei, col, false );

    //right wall segment 1
    pos.x = 0.0;
    pos.y = -10.0;
    pos.z = 0.0;
    collide = true;
    ang.xAng = 0.0;
    ang.yAng = -90.0;
    ang.zAng = 0.0;
    hei = 25;
    wid = 40;
    col.r = 0.0;
    col.g = 1.0;
    col.b = 0.0;
    createGeometryData(&scene3Geometry, pos,collide, ang, wid, hei, col, false );

    //left wall segment 1
    pos.x = 9.0;
    pos.y = -10.0;
    pos.z = 0.0;
    collide = true;
    ang.xAng = 0.0;
    ang.yAng = -90.0;
    ang.zAng = 0.0;
    hei = 25;
    wid = 140;
    col.r = 0.0;
    col.g = 1.0;
    col.b = 0.0;
    createGeometryData(&scene3Geometry, pos,collide, ang, wid, hei, col, false );

    //spawn roof
    pos.x = 0.0;
    pos.y = 2.5;
    pos.z = 0.0;
    collide = true;
    ang.xAng = 90.0;
    ang.yAng = 0.0;
    ang.zAng = 0.0;
    hei = 40;
    wid = 18;
    col.r = 0.0;
    col.g = 0.0;
    col.b = 1.0;
    createGeometryData(&scene3Geometry, pos,collide, ang, wid, hei, col, false );

    //middle wall 1
    pos.x = -33.5;
    pos.y = -10.0;
    pos.z = 45.0;
    collide = true;
    ang.xAng = 0.0;
    ang.yAng = 0.0;
    ang.zAng = 0.0;
    hei = 25;
    wid = 70;
    col.r = 0.0;
    col.g = 1.0;
    col.b = 0.0;
    createGeometryData(&scene3Geometry, pos,collide, ang, wid, hei, col, false );

    //middle wall 2
    pos.x = -15;
    pos.y = -10.0;
    pos.z = 62;
    collide = true;
    ang.xAng = 0.0;
    ang.yAng = 90.0;
    ang.zAng = 0.0;
    hei = 25;
    wid = 70;
    col.r = 0.0;
    col.g = 1.0;
    col.b = 0.0;
    createGeometryData(&scene3Geometry, pos,collide, ang, wid, hei, col, false );


    //box wall 1
    pos.x = 0.0;
    pos.y = -10.0;
    pos.z = 20.0;
    collide = true;
    ang.xAng = 0.0;
    ang.yAng = 180.0;
    ang.zAng = 0.0;
    hei = 25;
    wid = 82;
    col.r = 0.0;
    col.g = 1.0;
    col.b = 0.0;
    createGeometryData(&scene3Geometry, pos,collide, ang, wid, hei, col, false );

    //box wall 2
    pos.x = -41;
    pos.y = -10.0;
    pos.z = 20.0;
    collide = true;
    ang.xAng = 0.0;
    ang.yAng = -90.0;
    ang.zAng = 0.0;
    hei = 25;
    wid = 100;
    col.r = 0.0;
    col.g = 1.0;
    col.b = 0.0;
    createGeometryData(&scene3Geometry, pos,collide, ang, wid, hei, col, false );

    //front wall
    pos.x = -41.0;
    pos.y = -10.0;
    pos.z = 70.0;
    collide = true;
    ang.xAng = 0.0;
    ang.yAng = 0.0;
    ang.zAng = 0.0;
    hei = 25;
    wid = 100;
    col.r = 0.0;
    col.g = 1.0;
    col.b = 0.0;
    createGeometryData(&scene3Geometry, pos,collide, ang, wid, hei, col, false );


    ////////////////////////////////////////BOX2//////////////////////////////////////////////////
    float mover = 100.0;


    //box 1 floor
    pos.x = -41.0+mover;
    pos.y = -10.0;
    pos.z = 20.0;
    collide = true;
    ang.xAng = 90.0;
    ang.yAng = 0.0;
    ang.zAng = 0.0;
    hei = 100;
    wid = 100;
    col.r = 1.0f;
    col.g = 1.0;
    col.b = 0.0;
    createGeometryData(&scene3Geometry, pos,collide, ang, wid, hei, col, true );

    //box 1 roof
    pos.x = -41.0+mover;
    pos.y = 2.5;
    pos.z = 20.0;
    collide = true;
    ang.xAng = 90.0;
    ang.yAng = 0.0;
    ang.zAng = 0.0;
    hei = 100;
    wid = 100;
    col.r = 0.0;
    col.g = 0.0;
    col.b = 1.0;
    createGeometryData(&scene3Geometry, pos,collide, ang, wid, hei, col, true );

    //left wall segment 1
    pos.x = 9.0+mover;
    pos.y = -10.0;
    pos.z = 20.0;
    collide = true;
    ang.xAng = 0.0;
    ang.yAng = -90.0;
    ang.zAng = 0.0;
    hei = 25;
    wid = 100;
    col.r = 0.0;
    col.g = 1.0;
    col.b = 0.0;
    createGeometryData(&scene3Geometry, pos,collide, ang, wid, hei, col, false );


    //middle wall 1
    pos.x = -33.5+mover;
    pos.y = -10.0;
    pos.z = 45.0;
    collide = true;
    ang.xAng = 0.0;
    ang.yAng = 0.0;
    ang.zAng = 0.0;
    hei = 25;
    wid = 70;
    col.r = 0.0;
    col.g = 1.0;
    col.b = 0.0;
    createGeometryData(&scene3Geometry, pos,collide, ang, wid, hei, col, false );

    //middle wall 2
    pos.x = -15+mover;
    pos.y = -10.0;
    pos.z = 62;
    collide = true;
    ang.xAng = 0.0;
    ang.yAng = 90.0;
    ang.zAng = 0.0;
    hei = 25;
    wid = 70;
    col.r = 0.0;
    col.g = 1.0;
    col.b = 0.0;
    createGeometryData(&scene3Geometry, pos,collide, ang, wid, hei, col, false );


    //box wall 1
    pos.x = 10.0+mover;
    pos.y = -10.0;
    pos.z = 20.0;
    collide = true;
    ang.xAng = 0.0;
    ang.yAng = 180.0;
    ang.zAng = 0.0;
    hei = 25;
    wid = 102;
    col.r = 0.0;
    col.g = 1.0;
    col.b = 0.0;
    createGeometryData(&scene3Geometry, pos,collide, ang, wid, hei, col, false );

    //box wall 2
    pos.x = -41+mover;
    pos.y = -10.0;
    pos.z = 20.0;
    collide = true;
    ang.xAng = 0.0;
    ang.yAng = -90.0;
    ang.zAng = 0.0;
    hei = 25;
    wid = 100;
    col.r = 0.0;
    col.g = 1.0;
    col.b = 0.0;
    createGeometryData(&scene3Geometry, pos,collide, ang, wid, hei, col, false );

    //front wall
    pos.x = -41.0+mover;
    pos.y = -10.0;
    pos.z = 70.0;
    collide = true;
    ang.xAng = 0.0;
    ang.yAng = 0.0;
    ang.zAng = 0.0;
    hei = 25;
    wid = 100;
    col.r = 0.0;
    col.g = 1.0;
    col.b = 0.0;
    createGeometryData(&scene3Geometry, pos,collide, ang, wid, hei, col, false );

    ///////////////////////////BUTTON BOX///////////////////
        pos.x = -10+mover-10;
        pos.y = -10.0;
        pos.z = 42.0;
        collide = true;
        ang.xAng = 0.0;
        ang.yAng = 0.0;
        ang.zAng = 0.0;
        hei = 8;
        wid = 6;
        col.r = 1.0;
        col.g = 0.0;
        col.b = 1.0;
        createGeometryData(&scene3Geometry, pos,collide, ang, wid, hei, col, false );

        pos.x = -10+mover-10;
        pos.y = -10.0;
        pos.z = 42.0;
        collide = true;
        ang.xAng = 0.0;
        ang.yAng = -90.0;
        ang.zAng = 0.0;
        hei = 8;
        wid = 6;
        col.r = 1.0;
        col.g = 0.0;
        col.b = 1.0;
        createGeometryData(&scene3Geometry, pos,collide, ang, wid, hei, col, false );

        pos.x = -7+mover-10;
        pos.y = -10.0;
        pos.z = 42.0;
        collide = true;
        ang.xAng = 0.0;
        ang.yAng = -90.0;
        ang.zAng = 0.0;
        hei = 8;
        wid = 6;
        col.r = 1.0;
        col.g = 0.0;
        col.b = 1.0;
        createGeometryData(&scene3Geometry, pos,collide, ang, wid, hei, col, false );

        pos.x = -10+mover-10;
        pos.y = -6.0;
        pos.z = 42.0;
        collide = true;
        ang.xAng = 90.0;
        ang.yAng = 0.0;
        ang.zAng = 0.0;
        hei = 6;
        wid = 6;
        col.r = 1.0;
        col.g = 0.0;
        col.b = 1.0;
        createGeometryData(&scene3Geometry, pos,collide, ang, wid, hei, col, false );

    ///////////////////////////////////////////////////////


}

void scene3_main(CollisionMeshes *meshData, PortalBuffer *scenePorts, ButtonBuffer *sceneButtons, Ball *plyBall)
{
    for(int i = 0; i<=scene3Geometry.activeMeshes; i++)
    {
       draw4PointGeometry(&scene3Geometry.mesh[i], meshData);
    }

    for(int i = 0; i<=sceneButtons->activeButtons; i++)
    {
        if(sceneButtons->buttons[i].scene == 3)
            DrawButton(&sceneButtons->buttons[i], &sceneButtons->objectData);
    }

    for(int i = 0; i<=scenePorts->activePortals; i++)
    {
        if(scenePorts->portals[i].scene == 3)
        {
            loadPortal(meshData, &scenePorts->portals[i]);

        }

    }

    drawBall(plyBall, meshData);
}
