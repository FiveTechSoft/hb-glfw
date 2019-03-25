#include "hbglfw.h"

static HB_GARBAGE_FUNC(hb_glfw_destructor)
{
   PHB_GLFW phb = Cargo;

   if (phb && phb->p)
   {
      glfwDestroyWindow(phb->p);
      phb->p = NULL;
   }
}

static const HB_GC_FUNCS s_gc_glfw_funcs = {
    hb_glfw_destructor,
    hb_gcDummyMark};

PHB_GLFW hbglfw_dataContainer(hbglfw type, void *p)
{
   if (p)
   {
      PHB_GLFW phb = hb_gcAllocate(sizeof(HB_GLFW), &s_gc_glfw_funcs);
      phb->type = type;
      phb->p = p;
      return phb;
   }
   else
   {
      hb_errRT_BASE_SubstR(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
   }
   return NULL;
}

PHB_GLFW hbglfw_param(int iParam, hbglfw type)
{
   PHB_GLFW phb = hb_parptrGC(&s_gc_glfw_funcs, iParam);

   if (phb && phb->type == type)
   {
      return phb;
   }
   else
   {
      return NULL;
   }
}
