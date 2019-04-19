#include "hbglfw.h"

HB_FUNC(GLADLOADGL_GLFWGETPROCADDRESS)
{
   hb_retni(gladLoadGL(glfwGetProcAddress));
}
