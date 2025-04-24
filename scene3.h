#ifndef SCENE3_H_INCLUDED
#define SCENE3_H_INCLUDED

#include "gobal_vars.h"
#include <stdlib.h>
#include "transformation.h"
#include "player.h"
#include "collision.h"
#include "portal.h"
#include "loadObj.h"

void scene3_main(CollisionMeshes *meshData, PortalBuffer *scenePorts, ButtonBuffer *sceneButtons, Ball *plyBall);

void loadScene3Geometry();

void loadScene3Portals(PortalBuffer *portal);

void loadScene3Button(ButtonBuffer *button);

#endif // SCENE3_H_INCLUDED
