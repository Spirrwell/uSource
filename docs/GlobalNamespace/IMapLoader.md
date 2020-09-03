# class IMapLoader

*Defined at line 143 of ./engine/common/mod_local.h*

 Custom map loader class 



## Functions

### IMapLoader

*public void IMapLoader(const char *const * extensions, int nextensions)*

*Defined at line 88 of ./engine/common/model.cpp*

### ~IMapLoader

*public void ~IMapLoader()*

*Defined at line 100 of ./engine/common/model.cpp*

### CheckBuffer

*public _Bool CheckBuffer(const void * buf, size_t len)*

 This function should check if the specified buffer is of this format 	you'll usually want to check signatures and versions in here 	This is pretty much to remedy issues of files with multiple versions and the same extension 	(e.g. bsp which has versions 20, 21, 22, etc.)

**buf**

**len**

**return**

### LoadMap

*public _Bool LoadMap(model_t * map_model, const void * buffer, size_t length)*



