#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include "gobal_vars.h"

/**< All player controls */
void playerControls(unsigned char key,int x,int y);

/**< When a player releases a key */
void playerControlsUp(unsigned char key,int x,int y);

/**< Handles player positioning */
void positionCamera(CollisionMeshes *meshData, PortalBuffer *scenePortals, ButtonBuffer *sceneButtons);

/**< Handles camera direction */
void playerCameraControl(int x,int y);

/**< returns player object */
Player getPlayer();


#endif // PLAYER_H_INCLUDED
