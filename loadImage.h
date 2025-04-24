#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <GL/glext.h>

/**< loads the bmp image */
void load_image(const char * image_path);

/**< renders the bmp image */
void renderBMP(float x, float y, void *font, char *string);

/**< dislays end window */
void displayEnd(void);

/**< draws image */
void drawImage();

/**< Draws text */
void drawText();

void quit_main();
