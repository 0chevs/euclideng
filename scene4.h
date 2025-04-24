#ifndef SCENE4_H_INCLUDED
#define SCENE4_H_INCLUDED

#include "gobal_vars.h"
#include <stdlib.h>
#include "transformation.h"
#include "player.h"
#include "collision.h"
#include "portal.h"
#include "loadObj.h"

void loadScene4Geometry();

void loadScene4Button(ButtonBuffer *button);

void loadScene4Portals(PortalBuffer *portal);

void scene4_main(CollisionMeshes *meshData, PortalBuffer *scenePorts, ButtonBuffer *sceneButtons, Ball *plyBall);

#endif // SCENE4_H_INCLUDED
