#ifndef SCENE2_H_INCLUDED
#define SCENE2_H_INCLUDED

#include "gobal_vars.h"
#include <stdlib.h>
#include "transformation.h"
#include "player.h"
#include "collision.h"
#include "portal.h"
#include "loadObj.h"
#include "ball.h"

void scene2_main(CollisionMeshes *meshData, PortalBuffer *scenePorts, ButtonBuffer *sceneButtons, Ball *plyBall);

void loadScene2Geometry();

void loadScene2Button(ButtonBuffer *button);

void loadScene2Portals(PortalBuffer *portal);

#endif // SCENE2_H_INCLUDED
