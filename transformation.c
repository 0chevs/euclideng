#include "transformation.h"
#include<math.h>

void createGeometryData(GeometryBuffer *sceneGeo, Vector position, bool collideOn, Angle geoAng, float geoWidth, float geoHeight, Colour m_colour, bool pushUp)
{
    geoHeight = geoHeight/2;
    geoWidth = geoWidth/2;
    int index = sceneGeo->activeMeshes;

    _4PointGeometry tempGeometry =
    {
        .pos.x = position.x,
        .pos.y = position.y,
        .pos.z = position.z,

        .collisionOn = collideOn,

        .angle.xAng = geoAng.xAng,
        .angle.yAng = geoAng.yAng,
        .angle.zAng = geoAng.zAng,

        .vertices =
        {
            {geoWidth,0.0,0.0,1.0},
            {geoWidth,geoHeight,0.0,1.0},
            {0.0,geoHeight,0.0,1},
            {0.0,0.0,0.0,1.0},
        },

        .TransformationComplete = false,

        .pushPlayerUp = pushUp,
    };

    for(int i = 0; i < 5; i++)
    {
        tempGeometry.vertices[i] = rotateVector(tempGeometry.vertices[i], tempGeometry.angle.yAng, 1,0,0);
        tempGeometry.vertices[i] = rotateVector(tempGeometry.vertices[i], tempGeometry.angle.zAng, 0,0,1);
        tempGeometry.vertices[i] = rotateVector(tempGeometry.vertices[i], tempGeometry.angle.xAng, 0,1,0);

    }

    sceneGeo->mesh[index] = tempGeometry;

    sceneGeo->mesh[index].geoColour.r = m_colour.r;
    sceneGeo->mesh[index].geoColour.g = m_colour.g;
    sceneGeo->mesh[index].geoColour.b = m_colour.b;

    sceneGeo->activeMeshes = sceneGeo->activeMeshes + 1;

}

void draw4PointGeometry(_4PointGeometry *target, CollisionMeshes *meshData )
{
    glPushMatrix();
        glTranslatef(target->pos.x,target->pos.y,target->pos.z);
        glBegin(GL_POLYGON);
            glColor3f(target->geoColour.r,target->geoColour.g, target->geoColour.b);
            glVertex3f(  target->vertices[0].x, target->vertices[0].y, target->vertices[0].z );
            glVertex3f(  target->vertices[1].x, target->vertices[1].y, target->vertices[1].z );
            glVertex3f(  target->vertices[2].x, target->vertices[2].y, target->vertices[2].z );
            glVertex3f(  target->vertices[3].x, target->vertices[3].y, target->vertices[3].z );
        glEnd();

        if(target->collisionOn == true)
            createAABB(&target->angle, &target->pos, target->vertices,meshData,4, target->pushPlayerUp );

    glPopMatrix();
}

Vector rotateVector(Vector vertex, GLfloat angle, GLint yRo, GLint xRo, GLint zRo)
{
    GLfloat verMat[4][1];


    if(xRo == 1)
    {
        GLfloat rotXMat[4][4] =
        {
            {1, 0, 0, 0 },
            {0, -1, -1, 0 },
            {0, -1, -1, 0 },
            {0, 0, 0, 1 },
        };

        verMat[0][0] = vertex.x;
        verMat[1][0] = vertex.y;
        verMat[2][0] = vertex.z;
        verMat[3][0] = 1;

        rotXMat[1][1] = cos(angle*TO_RADIANS);
        rotXMat[1][2] = -sin(angle*TO_RADIANS);

        rotXMat[2][1] = sin(angle*TO_RADIANS);
        rotXMat[2][2] = cos(angle*TO_RADIANS);

        vertex.x = rotXMat[0][0]*verMat[0][0]+rotXMat[0][1]*verMat[1][0]
                        +rotXMat[0][2]*verMat[2][0]+rotXMat[0][3]*verMat[3][0];

        vertex.y = rotXMat[1][0]*verMat[0][0]+rotXMat[1][1]*verMat[1][0]
                        +rotXMat[1][2]*verMat[2][0]+rotXMat[1][3]*verMat[3][0];

        vertex.z = rotXMat[2][0]*verMat[0][0]+rotXMat[2][1]*verMat[1][0]
                        +rotXMat[2][2]*verMat[2][0]+rotXMat[2][3]*verMat[3][0];

        vertex.w = rotXMat[3][0]*verMat[0][0]+rotXMat[3][1]*verMat[1][0]
                        +rotXMat[3][2]*verMat[2][0]+rotXMat[3][3]*verMat[3][0];


    }

    if(yRo == 1)
    {

        GLfloat rotYMat[4][4] =
        {
            {-1, 0, -1, 0 },
             {0, 1, 0, 0 },
            {-1, 0, -1, 0 },
             {0, 0, 0, 1 },
        };


        verMat[0][0] = vertex.x;
        verMat[1][0] = vertex.y;
        verMat[2][0] = vertex.z;
        verMat[3][0] = 1;

        rotYMat[0][0] = cos(angle*TO_RADIANS);
        rotYMat[0][2] = sin(angle*TO_RADIANS);

        rotYMat[2][0] = -sin(angle*TO_RADIANS);
        rotYMat[2][2] = cos(angle*TO_RADIANS);

        vertex.x = rotYMat[0][0]*verMat[0][0]+rotYMat[0][1]*verMat[1][0]
                        +rotYMat[0][2]*verMat[2][0]+rotYMat[0][3]*verMat[3][0];

        vertex.y = rotYMat[1][0]*verMat[0][0]+rotYMat[1][1]*verMat[1][0]
                        +rotYMat[1][2]*verMat[2][0]+rotYMat[1][3]*verMat[3][0];

        vertex.z = rotYMat[2][0]*verMat[0][0]+rotYMat[2][1]*verMat[1][0]
                        +rotYMat[2][2]*verMat[2][0]+rotYMat[2][3]*verMat[3][0];

        vertex.w = rotYMat[3][0]*verMat[0][0]+rotYMat[3][1]*verMat[1][0]
                        +rotYMat[3][2]*verMat[2][0]+rotYMat[3][3]*verMat[3][0];
    }

    if(zRo == 1)
    {

        GLfloat rotZMat[4][4] =
        {
            {-1, -1, 0, 0 },
            {-1, -1, 0, 0 },
             {0, 0, 1, 0 },
             {0, 0, 0, 1 },
        };

        verMat[0][0] = vertex.x;
        verMat[1][0] = vertex.y;
        verMat[2][0] = vertex.z;
        verMat[3][0] = 1;

        rotZMat[0][0] = cos(angle*TO_RADIANS);
        rotZMat[0][1] = -sin(angle*TO_RADIANS);

        rotZMat[1][0] = sin(angle*TO_RADIANS);
        rotZMat[1][1] = cos(angle*TO_RADIANS);

        vertex.x = rotZMat[0][0]*verMat[0][0]+rotZMat[0][1]*verMat[1][0]
                        +rotZMat[0][2]*verMat[2][0]+rotZMat[0][3]*verMat[3][0];

        vertex.y = rotZMat[1][0]*verMat[0][0]+rotZMat[1][1]*verMat[1][0]
                        +rotZMat[1][2]*verMat[2][0]+rotZMat[1][3]*verMat[3][0];

        vertex.z = rotZMat[2][0]*verMat[0][0]+rotZMat[2][1]*verMat[1][0]
                        +rotZMat[2][2]*verMat[2][0]+rotZMat[2][3]*verMat[3][0];

        vertex.w = rotZMat[3][0]*verMat[0][0]+rotZMat[3][1]*verMat[1][0]
                        +rotZMat[3][2]*verMat[2][0]+rotZMat[3][3]*verMat[3][0];


    }

    return vertex;

}

 int compare_float(float f1, float f2)
 {
      float precision = 0.00001;
      if (((f1 - precision) < f2) &&((f1 + precision) > f2))
       {
            return 1;
       }
        else
       {
            return 0;
       }
 }
