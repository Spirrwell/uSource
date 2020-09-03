# class IShader

*Defined at line 88 of ./rendersystem/ishader.h*

 This is the base class for all shaders.  Note that this is pretty similar to OpenGL's shader pipeline. APIs that use pre-compiled bytecode,  such as Vulkan and DirectX will basically just stub out Compile(). SetSourceCode should still be implemented as the rendersystem will still pass it a buffer containing the bytecode. 



## Functions

### SetSourceCode

*public void SetSourceCode(void * pbuf, size_t buflen, enum rendersystem::ESourceCodeType type)*

 For binary code, pbuf will just be raw bytes. if the code type is GLSL, it's gonna be GLSL 

### Compile

*public _Bool Compile()*

 For binary code, compilation is not always required. You can optionally stub this guy out 

### GetInfoLog

*public const char * GetInfoLog()*

 Returns an info log if the compilation failed. 



