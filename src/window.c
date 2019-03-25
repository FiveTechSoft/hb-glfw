#include "hbglfw.h"

/* GLFWAPI GLFWwindow* glfwCreateWindow(int width, int height, const char* title, GLFWmonitor* monitor, GLFWwindow* share) */
HB_FUNC(GLFWCREATEWINDOW)
{

   if (!(hb_pcount() < 3))
   {
      int width = hb_parni(1);
      int height = hb_parni(2);
      const char *title = hb_parc(3);

      GLFWmonitor *monitor = hb_parptr(4);
      GLFWwindow *share = hb_parptr(5);
      GLFWwindow *window = glfwCreateWindow(width, height, title, monitor, share);

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
   else
   {
      hb_errRT_BASE_SubstR(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
   }
}

/* void glfwDefaultWindowHints(void) */
HB_FUNC(GLFWDEFAULTWINDOWHINTS)
{
   glfwDefaultWindowHints();
}

/* GLFWAPI void glfwWindowHint(int hint, int value) */
HB_FUNC(GLFWWINDOWHINT)
{
   if (hb_param(1, HB_IT_INTEGER) != NULL && hb_param(2, HB_IT_INTEGER) != NULL)
   {
      int hint = hb_parni(1);
      int value = hb_parni(2);
      glfwWindowHint(hint, value);
   }
   else
   {
      hb_errRT_BASE_SubstR(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
   }
}

/* GLFWAPI void glfwWindowHintString(int hint, const char* value) */
HB_FUNC(GLFWWINDOWHINTSTRING)
{
   if (hb_param(1, HB_IT_INTEGER) != NULL && hb_param(2, HB_IT_STRING) != NULL)
   {
      int hint = hb_parni(1);
      const char *value = hb_parc(2);
      glfwWindowHintString(hint, value);
   }
   else
   {
      hb_errRT_BASE_SubstR(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
   }
}

/* GLFWAPI void glfwDestroyWindow(GLFWwindow* handle) */
HB_FUNC(GLFWDESTROYWINDOW)
{
   PHB_GLFW phb = hbglfw_param(1, hbglfw_window);

   if (phb)
   {
      glfwDestroyWindow(phb->p);
      phb->p = NULL;
   }
   else
   {
      hb_errRT_BASE_SubstR(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
   }
}

/* GLFWAPI int glfwWindowShouldClose(GLFWwindow* handle) */
HB_FUNC(GLFWWINDOWSHOULDCLOSE)
{
   PHB_GLFW phb = hbglfw_param(1, hbglfw_window);

   if (phb)
   {
      int result = glfwWindowShouldClose(phb->p);
      hb_retl(result);
   }
   else
   {
      hb_errRT_BASE_SubstR(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
   }
}

/* GLFWAPI void glfwSetWindowShouldClose(GLFWwindow* handle, int value) */
HB_FUNC(GLFWSETWINDOWSHOULDCLOSE)
{
   PHB_GLFW phb = hbglfw_param(1, hbglfw_window);

   if (phb && hb_param(2, HB_IT_INTEGER) != NULL)
   {
      int value = hb_parni(2);
      glfwSetWindowShouldClose(phb->p, value);
   }
   else
   {
      hb_errRT_BASE_SubstR(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
   }
}

/* GLFWAPI void glfwSetWindowTitle(GLFWwindow* handle, const char* title) */
HB_FUNC(GLFWSETWINDOWTITLE)
{
   PHB_GLFW phb = hbglfw_param(1, hbglfw_window);

   if (phb && hb_param(2, HB_IT_STRING) != NULL)
   {
      const char *title = hb_parc(2);
      glfwSetWindowTitle(phb->p, title);
   }
   else
   {
      hb_errRT_BASE_SubstR(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
   }
}

/* GLFWAPI void glfwSetWindowIcon(GLFWwindow* handle, int count, const GLFWimage* images) */
HB_FUNC(GLFWSETWINDOWICON)
{
}

/* GLFWAPI void glfwGetWindowPos(GLFWwindow* handle, int* xpos, int* ypos) */
HB_FUNC(GLFWGETWINDOWPOS)
{
   PHB_GLFW phb = hbglfw_param(1, hbglfw_window);

   if (phb && HB_ISBYREF(2) && HB_ISBYREF(3))
   {
      int xpos, ypos;
      glfwGetWindowPos(phb->p, &xpos, &ypos);
      hb_storni(xpos, 2);
      hb_storni(ypos, 3);
   }
   else
   {
      hb_errRT_BASE_SubstR(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
   }
}

/* GLFWAPI void glfwSetWindowPos(GLFWwindow* handle, int xpos, int ypos) */
HB_FUNC(GLFWSETWINDOWPOS)
{
   PHB_GLFW phb = hbglfw_param(1, hbglfw_window);

   if (phb && hb_param(2, HB_IT_INTEGER) != NULL && hb_param(3, HB_IT_INTEGER) != NULL)
   {
      int xpos = hb_parni(2);
      int ypos = hb_parni(3);
      glfwSetWindowPos(phb->p, xpos, ypos);
   }
   else
   {
      hb_errRT_BASE_SubstR(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
   }
}

/* GLFWAPI void glfwGetWindowSize(GLFWwindow* handle, int* width, int* height) */
HB_FUNC(GLFWGETWINDOWSIZE)
{
   PHB_GLFW phb = hbglfw_param(1, hbglfw_window);

   if (phb && HB_ISBYREF(2) && HB_ISBYREF(3))
   {
      int width, height;
      glfwGetWindowSize(phb->p, &width, &height);
      hb_storni(width, 2);
      hb_storni(height, 3);
   }
   else
   {
      hb_errRT_BASE_SubstR(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
   }
}

/* GLFWAPI void glfwSetWindowSize(GLFWwindow* handle, int width, int height) */
HB_FUNC(GLFWSETWINDOWSIZE)
{
   PHB_GLFW phb = hbglfw_param(1, hbglfw_window);

   if (phb && hb_param(2, HB_IT_INTEGER) != NULL && hb_param(3, HB_IT_INTEGER) != NULL)
   {
      int width = hb_parni(2);
      int height = hb_parni(3);
      glfwSetWindowSize(phb->p, width, height);
   }
   else
   {
      hb_errRT_BASE_SubstR(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
   }
}

/* GLFWAPI void glfwSetWindowSizeLimits(GLFWwindow* handle, int minwidth, int minheight, int maxwidth, int maxheight) */
HB_FUNC(GLFWSETWINDOWSIZELIMITS)
{
   PHB_GLFW phb = hbglfw_param(1, hbglfw_window);

   if (phb && hb_param(2, HB_IT_INTEGER) != NULL && hb_param(3, HB_IT_INTEGER) != NULL && hb_param(4, HB_IT_INTEGER) != NULL && hb_param(5, HB_IT_INTEGER) != NULL)
   {
      int minwidth = hb_parni(2);
      int minheight = hb_parni(3);
      int maxwidth = hb_parni(4);
      int maxheight = hb_parni(5);
      glfwSetWindowSizeLimits(phb->p, minwidth, minheight, maxwidth, maxheight);
   }
   else
   {
      hb_errRT_BASE_SubstR(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
   }
}

/* GLFWAPI void glfwSetWindowAspectRatio(GLFWwindow* handle, int numer, int denom) */
HB_FUNC(GLFWSETWINDOWASPECTRATIO)
{
   PHB_GLFW phb = hbglfw_param(1, hbglfw_window);

   if (phb && hb_param(2, HB_IT_INTEGER) != NULL && hb_param(3, HB_IT_INTEGER) != NULL)
   {
      int numer = hb_parni(2);
      int denom = hb_parni(3);
      glfwSetWindowAspectRatio(phb->p, numer, denom);
   }
   else
   {
      hb_errRT_BASE_SubstR(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
   }
}

/* GLFWAPI void glfwGetFramebufferSize(GLFWwindow* handle, int* width, int* height) */
HB_FUNC(GLFWGETFRAMEBUFFERSIZE)
{
   PHB_GLFW phb = hbglfw_param(1, hbglfw_window);

   if (phb && HB_ISBYREF(2) && HB_ISBYREF(3))
   {
      int width, height;
      glfwGetFramebufferSize(phb->p, &width, &height);
      hb_storni(width, 2);
      hb_storni(height, 3);
   }
   else
   {
      hb_errRT_BASE_SubstR(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
   }
}

/* GLFWAPI void glfwGetWindowFrameSize(GLFWwindow* handle, int* left, int* top, int* right, int* bottom) */
HB_FUNC(GLFWGETWINDOWFRAMESIZE)
{
   PHB_GLFW phb = hbglfw_param(1, hbglfw_window);

   if (phb && HB_ISBYREF(2) && HB_ISBYREF(3) && HB_ISBYREF(4) && HB_ISBYREF(5))
   {
      int left, top, right, bottom;
      glfwGetWindowFrameSize(phb->p, &left, &top, &right, &bottom);
      hb_storni(left, 2);
      hb_storni(top, 3);
      hb_storni(right, 4);
      hb_storni(bottom, 5);
   }
   else
   {
      hb_errRT_BASE_SubstR(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
   }
}

/* GLFWAPI void glfwGetWindowContentScale(GLFWwindow* handle, float* xscale, float* yscale) */
HB_FUNC(GLFWGETWINDOWCONTENTSCALE)
{
}

/* GLFWAPI float glfwGetWindowOpacity(GLFWwindow* handle) */
HB_FUNC(GLFWGETWINDOWOPACITY)
{
   PHB_GLFW phb = hbglfw_param(1, hbglfw_window);

   if (phb)
   {
      float result = glfwGetWindowOpacity(phb->p);
      hb_retnd(result);
   }
   else
   {
      hb_errRT_BASE_SubstR(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
   }
}

/* GLFWAPI void glfwSetWindowOpacity(GLFWwindow* handle, float opacity) */
HB_FUNC(GLFWSETWINDOWOPACITY)
{
   PHB_GLFW phb = hbglfw_param(1, hbglfw_window);

   if (phb && hb_param(2, HB_IT_NUMERIC) != NULL)
   {
      glfwSetWindowOpacity(phb->p, (float)hb_parnd(2));
   }
   else
   {
      hb_errRT_BASE_SubstR(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
   }
}

/* GLFWAPI void glfwIconifyWindow(GLFWwindow* handle) */
HB_FUNC(GLFWICONIFYWINDOW)
{
   PHB_GLFW phb = hbglfw_param(1, hbglfw_window);

   if (phb)
   {
      glfwIconifyWindow(phb->p);
   }
   else
   {
      hb_errRT_BASE_SubstR(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
   }
}

/* GLFWAPI void glfwRestoreWindow(GLFWwindow* handle) */
HB_FUNC(GLFWRESTOREWINDOW)
{
   PHB_GLFW phb = hbglfw_param(1, hbglfw_window);

   if (phb)
   {
      glfwRestoreWindow(phb->p);
   }
   else
   {
      hb_errRT_BASE_SubstR(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
   }
}

/* GLFWAPI void glfwMaximizeWindow(GLFWwindow* handle) */
HB_FUNC(GLFWMAXIMIZEWINDOW)
{
   PHB_GLFW phb = hbglfw_param(1, hbglfw_window);

   if (phb)
   {
      glfwMaximizeWindow(phb->p);
   }
   else
   {
      hb_errRT_BASE_SubstR(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
   }
}

/* GLFWAPI void glfwShowWindow(GLFWwindow* handle) */
HB_FUNC(glfwShowWindow)
{
   PHB_GLFW phb = hbglfw_param(1, hbglfw_window);

   if (phb)
   {
      glfwShowWindow(phb->p);
   }
   else
   {
      hb_errRT_BASE_SubstR(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
   }
}

/* GLFWAPI void glfwRequestWindowAttention(GLFWwindow* handle) */
HB_FUNC(GLFWREQUESTWINDOWATTENTION)
{
   PHB_GLFW phb = hbglfw_param(1, hbglfw_window);

   if (phb)
   {
      glfwRequestWindowAttention(phb->p);
   }
   else
   {
      hb_errRT_BASE_SubstR(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
   }
}

/* GLFWAPI void glfwHideWindow(GLFWwindow* handle) */
HB_FUNC(GLFWHIDEWINDOW)
{
   PHB_GLFW phb = hbglfw_param(1, hbglfw_window);

   if (phb)
   {
      glfwHideWindow(phb->p);
   }
   else
   {
      hb_errRT_BASE_SubstR(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
   }
}

/* GLFWAPI void glfwFocusWindow(GLFWwindow* handle) */
HB_FUNC(GLFWFOCUSWINDOW)
{
   PHB_GLFW phb = hbglfw_param(1, hbglfw_window);

   if (phb)
   {
      glfwFocusWindow(phb->p);
   }
   else
   {
      hb_errRT_BASE_SubstR(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
   }
}

/* GLFWAPI int glfwGetWindowAttrib(GLFWwindow* handle, int attrib) */
HB_FUNC(GLFWGETWINDOWATTRIB)
{
   PHB_GLFW phb = hbglfw_param(1, hbglfw_window);

   if (phb && hb_param(2, HB_IT_INTEGER) != NULL)
   {
      int attrib = hb_parni(2);
      int result = glfwGetWindowAttrib(phb->p, attrib);
      hb_retni(result);
   }
   else
   {
      hb_errRT_BASE_SubstR(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
   }
}

/* GLFWAPI void glfwSetWindowAttrib(GLFWwindow* handle, int attrib, int value) */
HB_FUNC(GLFWSETWINDOWATTRIB)
{
   PHB_GLFW phb = hbglfw_param(1, hbglfw_window);

   if (phb && hb_param(2, HB_IT_INTEGER) != NULL && hb_param(3, HB_IT_INTEGER) != NULL)
   {
      int attrib = hb_parni(2);
      int value = hb_parni(3);
      glfwSetWindowAttrib(phb->p, attrib, value);
   }
   else
   {
      hb_errRT_BASE_SubstR(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
   }
}

/* GLFWAPI GLFWmonitor* glfwGetWindowMonitor(GLFWwindow* handle) */
HB_FUNC(GLFWGETWINDOWMONITOR)
{
}

/* GLFWAPI void glfwSetWindowMonitor(GLFWwindow* wh, GLFWmonitor* mh, int xpos, int ypos, int width, int height, int refreshRate) */
HB_FUNC(GLFWSETWINDOWMONITOR)
{
}

/* GLFWAPI void glfwSetWindowUserPointer(GLFWwindow* handle, void* pointer) */
HB_FUNC(GLFWSETWINDOWUSERPOINTER)
{
}

/* GLFWAPI void* glfwGetWindowUserPointer(GLFWwindow* handle) */
HB_FUNC(GLFWGETWINDOWUSERPOINTER)
{
}

/* GLFWAPI GLFWwindowposfun glfwSetWindowPosCallback(GLFWwindow* handle, GLFWwindowposfun cbfun) */
HB_FUNC(GLFWSETWINDOWPOSCALLBACK)
{
}

/* GLFWAPI GLFWwindowsizefun glfwSetWindowSizeCallback(GLFWwindow* handle, GLFWwindowsizefun cbfun) */
HB_FUNC(GLFWSETWINDOWSIZECALLBACK)
{
}

/* GLFWAPI GLFWwindowclosefun glfwSetWindowCloseCallback(GLFWwindow* handle, GLFWwindowclosefun cbfun) */
HB_FUNC(GLFWSETWINDOWCLOSECALLBACK)
{
}

/* GLFWAPI GLFWwindowrefreshfun glfwSetWindowRefreshCallback(GLFWwindow* handle, GLFWwindowrefreshfun cbfun) */
HB_FUNC(GLFWSETWINDOWREFRESHCALLBACK)
{
}

/* GLFWAPI GLFWwindowfocusfun glfwSetWindowFocusCallback(GLFWwindow* handle, GLFWwindowfocusfun cbfun) */
HB_FUNC(GLFWSETWINDOWFOCUSCALLBACK)
{
}

/* GLFWAPI GLFWwindowiconifyfun glfwSetWindowIconifyCallback(GLFWwindow* handle, GLFWwindowiconifyfun cbfun) */
HB_FUNC(GLFWSETWINDOWICONIFYCALLBACK)
{
}

/* GLFWAPI GLFWwindowmaximizefun glfwSetWindowMaximizeCallback(GLFWwindow* handle, GLFWwindowmaximizefun cbfun) */
HB_FUNC(GLFWSETWINDOWMAXIMIZECALLBACK)
{
}

/* GLFWAPI GLFWframebuffersizefun glfwSetFramebufferSizeCallback(GLFWwindow* handle, GLFWframebuffersizefun cbfun) */
HB_FUNC(GLFWSETFRAMEBUFFERSIZECALLBACK)
{
}

/* GLFWAPI GLFWwindowcontentscalefun glfwSetWindowContentScaleCallback(GLFWwindow* handle, GLFWwindowcontentscalefun cbfun) */
HB_FUNC(GLFWSETWINDOWCONTENTSCALECALLBACK)
{
}

/* GLFWAPI void glfwPollEvents(void) */
HB_FUNC(GLFWPOLLEVENTS)
{
   glfwPollEvents();
}

/* GLFWAPI void glfwWaitEvents(void) */
HB_FUNC(GLFWWAITEVENTS)
{
   glfwWaitEvents();
}

/* GLFWAPI void glfwWaitEventsTimeout(double timeout) */
HB_FUNC(GLFWWAITEVENTSTIMEOUT)
{
   if (hb_param(1, HB_IT_DOUBLE) != NULL)
   {
      double timeout = hb_parnd(1);
      glfwWaitEventsTimeout(timeout);
   }
   else
   {
      hb_errRT_BASE_SubstR(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
   }
}

/* GLFWAPI void glfwPostEmptyEvent(void) */
HB_FUNC(GLFWPOSTEMPTYEVENT)
{
   glfwPostEmptyEvent();
}
