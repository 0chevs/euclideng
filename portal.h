#ifndef PORTAL_H_INCLUDED
#define PORTAL_H_INCLUDED

#include "gobal_vars.h"
#include "transformation.h"

/**< sets up portal collision box */
void setupPortalCollision(Portal *targetPortal);

/**< check is the portal is colliding with player */
bool portalCollide(Vector *position, PortalBuffer *targetPortal, bool isAlreadyTeleporting);

/**< renders portal into scene */
void loadPortal(CollisionMeshes *meshData, Portal *targetPortal);
#endif // PORTAL_H_INCLUDED
