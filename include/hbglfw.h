#ifndef HBGLFW_H_
#define HBGLFW_H_

#include <stdbool.h>

#include <glad/gl.h>
#include <GLFW/glfw3.h>

#include "hbapi.h"
#include "hbapierr.h"

typedef enum
{
   hbglfw_window,
} hbglfw;

typedef struct _HB_GLFW
{
   hbglfw type;
   void *p;
} HB_GLFW, *PHB_GLFW;

PHB_GLFW hbglfw_dataContainer(hbglfw type, void *p);
PHB_GLFW hbglfw_param(int iParam, hbglfw type);

typedef struct
{
   size_t index;
   bool used;
   PHB_GLFW phb_glfw;
   PHB_ITEM pCallback;
} CALLBACK_ITEM, *PCALLBACK_ITEM;

typedef struct
{
   size_t capacity;
   CALLBACK_ITEM *callbackItems;
} CALLBACK;

void initialize_dynList(void);
void dynListSet(PHB_GLFW phb_glfw, PHB_ITEM pCallback);
PCALLBACK_ITEM dynListFind(GLFWwindow *window);
void dynListDelete(GLFWwindow *window);

#endif /* HBGLFW_H_ */
