#ifndef TRANSFORMATION_H_INCLUDED
#define TRANSFORMATION_H_INCLUDED

#include "gobal_vars.h"
#include <stdlib.h>
#include "transformation.h"
#include "player.h"
#include "collision.h"
#include "portal.h"
#include "loadObj.h"

/**< Conducts a rotation on a set of vertices */
Vector rotateVector(Vector vertex, GLfloat angle, GLint yRo, GLint xRo, GLint zRo);

/**< compares to floats */
int compare_float(float f1, float f2);

/**< renders 4 point geometry */
void draw4PointGeometry(_4PointGeometry *target, CollisionMeshes *meshData );

/**< Creates geometric data for later rendering */
void createGeometryData(GeometryBuffer *sceneGeo, Vector position, bool collideOn, Angle geoAng, float geoWidth, float geoHeight, Colour m_colour, bool pushUp);

#endif // TRANSFORMATION_H_INCLUDED
