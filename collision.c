#include "collision.h"

void createAABB(Angle *objAngle, Vector *posit, Vector *vertices, CollisionMeshes *meshData, int numofVertices, bool pushUp)
{
    int activeMeshes = meshData->activeMeshes;

    meshData->mesh[activeMeshes].maxX = 0.0;
    meshData->mesh[activeMeshes].maxY = 0.0;
    meshData->mesh[activeMeshes].maxZ = 0.0;

    meshData->mesh[activeMeshes].minX = 0.0;
    meshData->mesh[activeMeshes].minY = 0.0;
    meshData->mesh[activeMeshes].minZ = 0.0;

    for(int i = 0; i <= numofVertices; i++)
    {

        if(vertices[i].x > meshData->mesh[activeMeshes].maxX) { meshData->mesh[activeMeshes].maxX = vertices[i].x; }
        if(vertices[i].x < meshData->mesh[activeMeshes].minX) { meshData->mesh[activeMeshes].minX = vertices[i].x; }

        if(vertices[i].y > meshData->mesh[activeMeshes].maxY) { meshData->mesh[activeMeshes].maxY = vertices[i].y; }
        if(vertices[i].y < meshData->mesh[activeMeshes].minY) { meshData->mesh[activeMeshes].minY = vertices[i].y; }

        if(vertices[i].z > meshData->mesh[activeMeshes].maxZ) { meshData->mesh[activeMeshes].maxZ = vertices[i].z; }
        if(vertices[i].z < meshData->mesh[activeMeshes].minZ) { meshData->mesh[activeMeshes].minZ = vertices[i].z; }

    }

    meshData->mesh[activeMeshes].pos.x = posit->x;
    meshData->mesh[activeMeshes].pos.y = posit->y;
    meshData->mesh[activeMeshes].pos.z = posit->z;

    meshData->mesh[activeMeshes].angle.xAng = objAngle->xAng;
    meshData->mesh[activeMeshes].angle.yAng = objAngle->yAng;
    meshData->mesh[activeMeshes].angle.zAng = objAngle->zAng;

    meshData->mesh[activeMeshes].pushPlayerUp = pushUp;

    //if (!debugMode)
       glColorMask(GL_FALSE, GL_FALSE, GL_FALSE, GL_FALSE);

    glBegin(GL_POLYGON);
        glColor3f(1.0,1.0,0.0);
        glVertex3f(  vertices[0].x, vertices[0].y, vertices[0].z);
        glVertex3f(  vertices[1].x, vertices[1].y, vertices[1].z);
        glVertex3f(  vertices[2].x, vertices[2].y, vertices[2].z);
        glVertex3f(  vertices[3].x, vertices[3].y, vertices[3].z);
    glEnd();


    glColorMask(GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE);

    setActiveMeshes(meshData, activeMeshes+1);
}

void setActiveMeshes(CollisionMeshes *meshData, int newActiveMeshes)
{
    meshData->activeMeshes = newActiveMeshes;
}

bool isColliding(Vector *position, CollisionMeshes *meshData, bool isPlayer)
{

    int activeMeshes = meshData->activeMeshes;

    for(int i =0; i<activeMeshes; i++)
    {
        bool xOverlap = ((int)position->x) <= (meshData->mesh[i].pos.x + meshData->mesh[i].maxX+1) && ((int)position->x) >= (meshData->mesh[i].pos.x + meshData->mesh[i].minX-1);
        bool yOverlap = ((int)position->y) <= (meshData->mesh[i].pos.y + meshData->mesh[i].maxY+1) && ((int)position->y) >= (meshData->mesh[i].pos.y + meshData->mesh[i].minY-1);
        bool zOverlap = ((int)position->z) <= (meshData->mesh[i].pos.z + meshData->mesh[i].maxZ+1) && ((int)position->z) >= (meshData->mesh[i].pos.z + meshData->mesh[i].minZ-1);

        if(meshData->mesh[i].pushPlayerUp && isPlayer)
        {
            bool ytouch = ((int)position->y-6) <= (meshData->mesh[i].pos.y + meshData->mesh[i].maxY+1) && ((int)position->y) >= (meshData->mesh[i].pos.y + meshData->mesh[i].minY-1);

            if(xOverlap && ytouch && zOverlap)
            {
                position->y = meshData->mesh[i].pos.y +6;
            }
        }

        if(xOverlap && yOverlap && zOverlap)
        {
            return true;
        }

    }

    return false;
}

