#ifndef COLLISION_H_INCLUDED
#define COLLISION_H_INCLUDED

#include "gobal_vars.h"

/**< Creates Axis Aligned Bounding Box around target geometry*/
void createAABB(Angle *objAngle, Vector *posit, Vector *vertices, CollisionMeshes *meshData, int numofVertices, bool pushUp);

/**< Sets the number of active AABBs in scene */
void setActiveMeshes(CollisionMeshes *meshData, int newActiveMeshes);

/**< Checks if player is colliding with AABB */
bool isColliding(Vector *position, CollisionMeshes *meshData, bool isPlayer);

#endif // COLLISION_H_INCLUDED
