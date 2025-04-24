#ifndef BALL_H_INCLUDED
#define BALL_H_INCLUDED

#include "gobal_vars.h"
#include "player.h"
#include "transformation.h"
#include "collision.h"

/**< Sets up the initial ball parameters */
void spawnBall(Ball *target);

/**< Draws the ball geometry in the scene */
void drawBall(Ball *target, CollisionMeshes *meshData);

/**< Checks if the ball is colliding with other geometry */
bool BallisColliding(Vector *position, CollisionMeshes *meshData, AABB *collidedCallback);


#endif // BALL_H_INCLUDED
