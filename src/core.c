#include "hbglfw.h"

/* Object destructor, it's executed automatically */
static HB_GARBAGE_FUNC(hb_glfw_destructor)
{
   /* Retrieve object pointer holder */
   PHB_GLFW phb = Cargo;

   /* Check if pointer is not NULL to avoid multiple freeing */
   if (phb && phb->p)
   {
      /* Destroy the object */
      glfwDestroyWindow(phb->p);

      /* set pointer to NULL to avoid multiple freeing */
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
