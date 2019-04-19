#include "hbglfw.h"
#include "hbapi.h"
#include "hbapiitm.h"
#include <stdbool.h>

#define INITIAL_DYNLIST_LEN 5

static CALLBACK callback;

void dynListDelete(GLFWwindow *window)
{
   PCALLBACK_ITEM pItem = dynListFind(window);
   if (pItem)
   {
      pItem->pCallback = NULL;
      pItem->phb_glfw = NULL;
      pItem->used = false;
   }
}

PCALLBACK_ITEM dynListFindUnusedSlot()
{
   initialize_dynList();
   for (size_t i = 0; i < callback.capacity; i++)
   {
      PCALLBACK_ITEM pItem = &callback.callbackItems[i];
      if (!pItem->used)
      {
         return pItem;
      }
   }
   return NULL;
}

PCALLBACK_ITEM dynListFind(GLFWwindow *window)
{
   initialize_dynList();
   for (size_t i = 0; i < callback.capacity; i++)
   {
      PCALLBACK_ITEM pItem = &callback.callbackItems[i];
      if (pItem->used && (window == pItem->phb_glfw->p))
      {
         return pItem;
      }
   }
   return NULL;
}

void initialize_dynList()
{
   if (callback.callbackItems == NULL)
   {
      callback.capacity = INITIAL_DYNLIST_LEN;
      callback.callbackItems = malloc(sizeof(CALLBACK_ITEM) * callback.capacity);
      for (size_t i = 0; i < callback.capacity; i++)
      {
         PCALLBACK_ITEM pItem = &callback.callbackItems[i];
         pItem->index = i;
         pItem->used = false;
         pItem->phb_glfw = NULL;
         pItem->pCallback = NULL;
      }
   }
}

void dynListSet(PHB_GLFW phb_glfw, PHB_ITEM pCallback)
{
   initialize_dynList();

   PCALLBACK_ITEM pItem = dynListFind(phb_glfw->p);
   if (pItem == NULL)
   {
      pItem = dynListFindUnusedSlot();
      if (pItem != NULL)
      {
         pItem->used = true;
         pItem->phb_glfw = phb_glfw;
         pItem->pCallback = hb_itemNew(pCallback);
      }
   }
   else
   {
      pItem->pCallback = hb_itemNew(pCallback);
   }
   if (pItem == NULL)
   {
      size_t actualSize = callback.capacity;
      callback.capacity += INITIAL_DYNLIST_LEN;
      callback.callbackItems = realloc(callback.callbackItems, sizeof(CALLBACK_ITEM) + callback.capacity);
      for (size_t i = actualSize; i < callback.capacity; i++)
      {
         PCALLBACK_ITEM pItem = &callback.callbackItems[i];
         pItem->index = i;
         pItem->used = false;
         pItem->phb_glfw = NULL;
         pItem->pCallback = NULL;
      }
      pItem = &callback.callbackItems[actualSize];
      pItem->used = true;
      pItem->phb_glfw = phb_glfw;
      pItem->pCallback = hb_itemNew(pCallback);
   }
}
