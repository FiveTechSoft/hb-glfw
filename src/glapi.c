/*
   GLAPI
   https://www.khronos.org/registry/OpenGL-Refpages/gl4/html/index.php

*/

#include "hbglfw.h"

/* void glActiveTexture(GLenum texture) */
HB_FUNC(GLACTIVETEXTURE)
{
   if (HB_ISNUM(1))
   {
      GLenum texture = hb_parni(1);
      glActiveTexture(texture);
   }
   else
   {
      hb_errRT_BASE_SubstR(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
   }
}

/* void glAttachShader(GLuint program, GLuint shader) */
HB_FUNC(GLATTACHSHADER)
{
   if (HB_ISNUM(1) && HB_ISNUM(2))
   {
      GLuint program = hb_parni(1);
      GLuint shader = hb_parni(2);
      glAttachShader(program, shader);
   }
   else
   {
      hb_errRT_BASE_SubstR(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
   }
}

/* void glBindBuffer(GLenum target, GLuint buffer) */
HB_FUNC(GLBINDBUFFER)
{
   if (HB_ISNUM(1) && HB_ISNUM(2))
   {
      GLenum target = hb_parni(1);
      GLuint buffer = hb_parni(2);
      glBindBuffer(target, buffer);
   }
   else
   {
      hb_errRT_BASE_SubstR(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
   }
}

/* void glBindVertexArray(GLuint array) */
HB_FUNC(GLBINDVERTEXARRAY)
{
   if (HB_ISNUM(1))
   {
      GLuint array = hb_parni(1);
      glBindVertexArray(array);
   }
   else
   {
      hb_errRT_BASE_SubstR(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
   }
}

/* void glClear(GLbitfield mask) */
HB_FUNC(GLCLEAR)
{
   GLbitfield mask = hb_parni(1);
   glClear(mask);
}

/* void glClearColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) */
HB_FUNC(GLCLEARCOLOR)
{
   if (HB_ISNUM(1) && HB_ISNUM(2) && HB_ISNUM(3) && HB_ISNUM(4))
   {
      glClearColor((float)hb_parnd(1), (float)hb_parnd(2), (float)hb_parnd(3), (float)hb_parnd(4));
   }
   else
   {
      hb_errRT_BASE_SubstR(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
   }
}

/* GLuint glCreateProgram(void) */
HB_FUNC(GLCREATEPROGRAM)
{
   hb_retni(glCreateProgram());
}

/* GLuint glCreateShader(GLenum type) */
HB_FUNC(GLCREATESHADER)
{
   if (HB_ISNUM(1))
   {
      GLenum type = hb_parni(1);
      hb_retni(glCreateShader(type));
   }
   else
   {
      hb_errRT_BASE_SubstR(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
   }
}

/* void glCompileShader(GLuint shader) */
HB_FUNC(GLCOMPILESHADER)
{
   if (HB_ISNUM(1))
   {
      GLuint shader = hb_parni(1);
      glCompileShader(shader);
   }
   else
   {
      hb_errRT_BASE_SubstR(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
   }
}

/* void glDeleteShader(GLuint shader) */
HB_FUNC(GLDELETESHADER)
{
   if (HB_ISNUM(1))
   {
      GLuint shader = hb_parni(1);
      glDeleteShader(shader);
   }
   else
   {
      hb_errRT_BASE_SubstR(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
   }
}

/* void glDrawArrays(GLenum mode, GLint first, GLsizei count) */
HB_FUNC(GLDRAWARRAYS)
{
   if (HB_ISNUM(1) && HB_ISNUM(2) && HB_ISNUM(3))
   {
      GLenum mode = hb_parni(1);
      GLint first = hb_parni(2);
      GLsizei count = hb_parni(3);
      glDrawArrays(mode, first, count);
   }
   else
   {
      hb_errRT_BASE_SubstR(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
   }
}

/* void glEnableVertexAttribArray(GLuint index) */
HB_FUNC(GLENABLEVERTEXATTRIBARRAY)
{
   if (HB_ISNUM(1))
   {
      GLuint index = hb_parni(1);
      glEnableVertexAttribArray(index);
   }
   else
   {
      hb_errRT_BASE_SubstR(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
   }
}

/* void glGenBuffers(GLsizei n, GLuint *buffers) */
HB_FUNC(GLGENBUFFERS)
{
   if (HB_ISNUM(1) && HB_ISBYREF(2))
   {
      GLuint i;
      glGenBuffers(hb_parni(1), &i);
      hb_storni(i, 2);
   }
   else
   {
      hb_errRT_BASE_SubstR(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
   }
}

/* void glGenVertexArrays(GLsizei n, GLuint *arrays) */
HB_FUNC(GLGENVERTEXARRAYS)
{
   if (HB_ISNUM(1) && HB_ISARRAY(2))
   {
      GLuint i;
      glGenVertexArrays(hb_parni(1), &i);
      hb_storni(i, 2);
   }
   else
   {
      hb_errRT_BASE_SubstR(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
   }
}

/* GLint glGetAttribLocation(GLuint program, const GLchar *name) */
HB_FUNC(GLGETATTRIBLOCATION)
{
   if (HB_ISNUM(1) && HB_ISCHAR(2))
   {
      GLuint program = hb_parni(1);
      const GLchar *name = hb_parc(2);
      hb_retni(glGetAttribLocation(program, name));
   }
   else
   {
      hb_errRT_BASE_SubstR(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
   }
}

/* GLint glGetUniformLocation(GLuint program, const GLchar *name) */
HB_FUNC(GLGETUNIFORMLOCATION)
{
   if (HB_ISNUM(1) && HB_ISCHAR(2))
   {
      GLuint program = hb_parni(1);
      const GLchar *name = hb_parc(2);
      hb_retni(glGetUniformLocation(program, name));
   }
   else
   {
      hb_errRT_BASE_SubstR(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
   }
}

/* void glLinkProgram(GLuint program) */
HB_FUNC(GLLINKPROGRAM)
{
   if (HB_ISNUM(1))
   {
      GLuint program = hb_parni(1);
      glLinkProgram(program);
   }
   else
   {
      hb_errRT_BASE_SubstR(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
   }
}

/* void glShaderSource(GLuint shader, GLsizei count, const GLchar *const*string, const GLint *length) */
HB_FUNC(GLSHADERSOURCE)
{
   GLuint shader = hb_parni(1);
   GLsizei count = hb_parni(2);
   const char *string = hb_parc(3);
   glShaderSource(shader, count, &string, NULL);
}

/* void glUseProgram(GLuint program) */
HB_FUNC(GLUSEPROGRAM)
{
   if (HB_ISNUM(1))
   {
      GLuint program = hb_parni(1);
      glUseProgram(program);
   }
   else
   {
      hb_errRT_BASE_SubstR(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
   }
}

/* void glViewport(GLint x, GLint y, GLsizei width, GLsizei height) */
HB_FUNC(GLVIEWPORT)
{
   if (HB_ISNUM(1) && HB_ISNUM(2) && HB_ISNUM(3) && HB_ISNUM(4))
   {
      GLint x = hb_parni(1);
      GLint y = hb_parni(2);
      GLsizei width = hb_parni(3);
      GLsizei height = hb_parni(4);
      glViewport(x, y, width, height);
   }
   else
   {
      hb_errRT_BASE_SubstR(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
   }
}
