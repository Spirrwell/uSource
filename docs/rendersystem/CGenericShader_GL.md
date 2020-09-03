# class CGenericShader_GL

*Defined at line 20 of ./rendersystem/rendersystemgl/gl_shader.cpp*

 Avoiding a bit of code duplication here 



## Members

public GLuint m_shaderIndex

public _Bool m_init

public _Bool m_compiled

public GLenum m_type

public const char ** m_sourceCode

public unsigned long m_numLines

public unsigned long * m_lineLengths



## Functions

### CGenericShader_GL

*public void CGenericShader_GL(GLenum type)*

*Defined at line 223 of ./rendersystem/rendersystemgl/gl_shader.cpp*

=============================================================================================================================================// CGenericShader_GL

### ~CGenericShader_GL

*public void ~CGenericShader_GL()*

*Defined at line 236 of ./rendersystem/rendersystemgl/gl_shader.cpp*

### GLCompile

*public _Bool GLCompile()*

*Defined at line 251 of ./rendersystem/rendersystemgl/gl_shader.cpp*

### GLSetSourceCode

*public void GLSetSourceCode(void * pbuf, size_t buflen, enum rendersystem::ESourceCodeType type)*

*Defined at line 260 of ./rendersystem/rendersystemgl/gl_shader.cpp*

### GLGetInfoLog

*public const char * GLGetInfoLog()*

*Defined at line 301 of ./rendersystem/rendersystemgl/gl_shader.cpp*

### GLSetGLSL

*public void GLSetGLSL(const char * buf, size_t len)*

*Defined at line 275 of ./rendersystem/rendersystemgl/gl_shader.cpp*



