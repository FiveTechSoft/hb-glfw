#include "hbglfw.h"

/* GLFWAPI void glfwMakeContextCurrent(GLFWwindow* handle) */
HB_FUNC(GLFWMAKECONTEXTCURRENT)
{
   PHB_GLFW phb = hbglfw_param(1, hbglfw_window);

   if (phb)
   {
      glfwMakeContextCurrent(phb->p);
   }
   else
   {
      hb_errRT_BASE_SubstR(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
   }
}

/* GLFWAPI GLFWwindow* glfwGetCurrentContext(void) */
HB_FUNC(GLFWGETCURRENTCONTEXT)
{
   GLFWwindow *window = glfwGetCurrentContext();

   if (window)
   {
      PHB_GLFW phb = hbglfw_dataContainer(hbglfw_window, window);
      hb_retptrGC(phb);
   }
   else
   {
      hb_ret();
   }
}

/* GLFWAPI void glfwSwapBuffers(GLFWwindow* handle) */
HB_FUNC(GLFWSWAPBUFFERS)
{
   PHB_GLFW phb = hbglfw_param(1, hbglfw_window);

   if (phb)
   {
      glfwSwapBuffers(phb->p);
   }
   else
   {
      hb_errRT_BASE_SubstR(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
   }
}

/* GLFWAPI void glfwSwapInterval(int interval) */
HB_FUNC(GLFWSWAPINTERVAL)
{
   if (hb_param(1, HB_IT_INTEGER) != NULL)
   {
      int interval = hb_parni(1);
      glfwSwapInterval(interval);
   }
   else
   {
      hb_errRT_BASE_SubstR(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
   }
}

/* GLFWAPI int glfwExtensionSupported(const char* extension) */
HB_FUNC(GLFWEXTENSIONSUPPORTED)
{
   if (hb_param(1, HB_IT_STRING) != NULL)
   {
      const char *extension = hb_parc(1);
      int result = glfwExtensionSupported(extension);
      hb_retl(result);
   }
   else
   {
      hb_errRT_BASE_SubstR(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
   }
}

/* GLFWAPI GLFWglproc glfwGetProcAddress(const char* procname) */
HB_FUNC(GLFWGETPROCADDRESS)
{
}
