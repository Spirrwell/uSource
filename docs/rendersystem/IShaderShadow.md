# class IShaderShadow

*Defined at line 217 of ./rendersystem/ishader.h*

 IShaderShadow 	Backend management class that goes with each shader. 	The rendersystem calls each of the internal methods. Ideally this will only be called in one thread, so maintaining 	state should be OK. However, this isn't 100% guaranteed in the future.



## Functions

### Init

*public void Init(class rendersystem::IShaderProgram * pShader)*

 Called to initialize the shader program. This is only called once. In here, you'll want to call SetupParams, SetupUniforms, SetupOutputs and SetupTextureUniforms

**pShader**

### PreDraw

*public void PreDraw(class IMesh * pDrawMesh, class rendersystem::IShaderProgram * pShader)*

 Called immediately before drawing with the shader. Here you'll want to be setting the uniforms and other params.

**pDrawMesh**

**pShader**

### PostDraw

*public void PostDraw(class IMesh * pDrawMesh, class rendersystem::IShaderProgram * pShader)*

 Called after drawing with the shader.

**pDrawMesh**

**pShader**

### Shutdown

*public void Shutdown()*

 Called to destroy the shader. Cleanup goes here



