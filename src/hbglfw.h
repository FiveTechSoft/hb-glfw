#ifndef HBGLFW_H_
#define HBGLFW_H_

#include <glad/glad.h>
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

#endif /* HBGLFW_H_ */