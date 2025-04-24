
#include "portal.h"

void setupPortalCollision(Portal *targetPortal)
{
    targetPortal->maxX = 0;
    targetPortal->minX = 0;

    targetPortal->maxY = 0;
    targetPortal->minY = 0;

    targetPortal->maxZ = 0;
    targetPortal->minZ = 0;

    for(int i = 0; i < 4; i++)
    {

        if(targetPortal->vertices[i].x > targetPortal->maxX) {targetPortal->maxX = targetPortal->vertices[i].x;}
        if(targetPortal->vertices[i].x < targetPortal->minX) { targetPortal->minX = targetPortal->vertices[i].x; }

        if(targetPortal->vertices[i].y > targetPortal->maxY) { targetPortal->maxY = targetPortal->vertices[i].y; }
        if(targetPortal->vertices[i].y < targetPortal->minY) { targetPortal->minY = targetPortal->vertices[i].y; }

        if(targetPortal->vertices[i].z > targetPortal->maxZ) { targetPortal->maxZ = targetPortal->vertices[i].z; }
        if(targetPortal->vertices[i].z < targetPortal->minZ) { targetPortal->minZ = targetPortal->vertices[i].z; }

    }


}

bool portalCollide(Vector *position, PortalBuffer *targetPortal, bool isAlreadyTeleporting)
{

    for(int i =0; i<targetPortal->activePortals; i++)
    {
        bool xOverlap = ((int)position->x) <= (targetPortal->portals[i].pos.x + targetPortal->portals[i].maxX) && ((int)position->x) >= (targetPortal->portals[i].pos.x + targetPortal->portals[i].minX);
        bool yOverlap = ((int)position->y) <= (targetPortal->portals[i].pos.y + targetPortal->portals[i].maxY) && ((int)position->y) >= (targetPortal->portals[i].pos.y + targetPortal->portals[i].minY);
        bool zOverlap = ((int)position->z) <= (targetPortal->portals[i].pos.z + targetPortal->portals[i].maxZ) && ((int)position->z) >= (targetPortal->portals[i].pos.z + targetPortal->portals[i].minZ);
        if(xOverlap && yOverlap && zOverlap)
        {
            if(!isAlreadyTeleporting)
            {
                position->x = targetPortal->portals[i].teleportToPositon.x;
                position->y = targetPortal->portals[i].teleportToPositon.y;
                position->z = targetPortal->portals[i].teleportToPositon.z;
            }
            return true;
        }
    }

    return false;
}

void loadPortal(CollisionMeshes *meshData, Portal *targetPortal)
{

    glPushMatrix();
        glTranslatef(targetPortal->pos.x,targetPortal->pos.y,targetPortal->pos.z);


        if (!debugMode)
            glColorMask(GL_FALSE, GL_FALSE, GL_FALSE, GL_FALSE);

        glBegin(GL_POLYGON);
            glColor3f(1.0,0.0,1.0);
            glVertex3f(  targetPortal->vertices[0].x, targetPortal->vertices[0].y, targetPortal->vertices[0].z );
            glVertex3f(  targetPortal->vertices[1].x, targetPortal->vertices[1].y, targetPortal->vertices[1].z );
            glVertex3f(  targetPortal->vertices[2].x, targetPortal->vertices[2].y, targetPortal->vertices[2].z );
            glVertex3f(  targetPortal->vertices[3].x, targetPortal->vertices[3].y, targetPortal->vertices[3].z );
        glEnd();


        glColorMask(GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE);

        setupPortalCollision(targetPortal);

    glPopMatrix();

}
