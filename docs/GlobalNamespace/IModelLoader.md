# class IModelLoader

*Defined at line 121 of ./engine/common/mod_local.h*

 Custom model loader class 

 Not actually a pure interface! be sure to call the default constructor! 



## Functions

### IModelLoader

*public void IModelLoader(const char *const * extensions, int nextensions)*

*Defined at line 54 of ./engine/common/model.cpp*

### ~IModelLoader

*public void ~IModelLoader()*

*Defined at line 66 of ./engine/common/model.cpp*

### CheckBuffer

*public _Bool CheckBuffer(const void * buf, size_t len)*

 This function should check if the specified buffer is of this format 	you'll usually want to check signatures and versions in here 	This is pretty much to remedy issues of files with multiple versions and the same extension 	(e.g. bsp which has versions 20, 21, 22, etc.)

**buf**

**len**

**return**

### LoadModel

*public _Bool LoadModel(model_t * mod, const void * buffer, size_t length)*



