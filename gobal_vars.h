#ifndef GOBAL_VARS_H_INCLUDED
#define GOBAL_VARS_H_INCLUDED\

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdbool.h>


///////////////////////////////////////////////////////////////////
//Data Structures
typedef struct Vector3{double x, y, z;} Vector3;
extern int window;
extern int window2;
//Type for FaceVector coordinate
typedef struct FaceVecor{
    int faceType;
    Vector3 coordinates1, coordinates2, coordinates3;
} FaceVecor;

//Type for drawing lines for object model using the coordinates
typedef struct Objects{
    Vector3 *coordinates;
    FaceVecor *faces;
    int vertexLines, faceLines, uVLines;
    bool fileNotOpen;
} Objects;

/**< Basic vector struct */
typedef struct
{
    GLfloat x,y,z,w;
}Vector;

/**< Basic angle struct */
typedef struct
{
    GLfloat xAng, yAng, zAng;
}Angle;

/**< Basic colour struct */
typedef struct
{
    GLfloat r, g, b, a;
}Colour;

/**< Structure used to store geometry with 4 vertices */
typedef struct
{
    Vector pos;
    GLfloat sizeX, sizeY, sizeZ;

    bool collisionOn;

    Angle angle;

    Vector vertices[4];

    bool TransformationComplete;

    Colour geoColour;

    bool pushPlayerUp;

}_4PointGeometry;

/**< Struct used to store AABB information */
typedef struct
{
    Vector pos;

    GLfloat maxX,minX;
    GLfloat maxY,minY;
    GLfloat maxZ,minZ;

    bool collisionOn;

    Angle angle;

    bool TransformationComplete;

    bool parentIsPortal;

    bool pushPlayerUp;

}AABB;

/**< Stores all AABB mesh data  */
typedef struct
{
    AABB mesh[200];

    int activeMeshes;

}CollisionMeshes;

/**< Struct that represents player */
typedef struct
{
    bool moveForward;
    bool moveBackward;
    bool moveLeft;
    bool moveRight;

    Vector pos;

    GLfloat camPitch, camYaw;

    GLfloat sizeX, sizeY, sizeZ;

    bool isTeleporting;

}Player;

/**< Holds all data relating to a portal */
typedef struct
{
    Vector pos;

    Vector vertices[4];

    bool collisionOn; //portal off/on

    Angle angle;

    bool TransformationComplete;

    int scene;

    Vector teleportToPositon;

    GLfloat maxX,minX;
    GLfloat maxY,minY;
    GLfloat maxZ,minZ;

}Portal;

/**< Buffer object for all portals in scene */
typedef struct
{
    int activePortals;

    Portal portals[20];

}PortalBuffer;

/**< Holds all information for a single button object */
typedef struct
{
    Vector pos;

    GLfloat sizeX, sizeY, sizeZ;

    bool fileNotOpen;
    bool hasPressed;

    bool inbounds;

    int scene;

    float maxPushDepth;
    float currentPushProgress;

    bool buttonUnpushing;

}Button;

/**< Buffer object to hold all button info */
typedef struct
{
    Button buttons[10];

    Objects objectData;

    int activeButtons;

}ButtonBuffer;

/**< Buffer object to hold all geometry data for a scene */
typedef struct
{
    _4PointGeometry mesh[200];

    int activeMeshes;

}GeometryBuffer;

/**< Ball object */
typedef struct
{
    Vector pos;

    bool collisionOn;

    bool TransformationComplete;

    GLfloat radius;

    Vector energy;

    Vector initVel;

    Vector velVector;

}Ball;

///////////////////////////////////////////////////////////////////
//Global Variables
static const int FPS = 60;
static const float TO_RADIANS = 3.141592654/180.0;

static const int width = 16*50;
static const int height = 9*50;

static const float BUTTON_PUSH_SPEED = 0.02f;

static const bool debugMode = false;

static const int TIMESEC = 10;

#endif // GOBAL_VARS_H_INCLUDED
