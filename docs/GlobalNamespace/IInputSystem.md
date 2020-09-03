# class IInputSystem

*Defined at line 362 of ./common/../engine/client_int.h*

Inherits from IAppInterface



## Functions

### InitInput

*public void InitInput()*

### ShutdownInput

*public void ShutdownInput()*

### ActivateMouse

*public void ActivateMouse()*

### DeactivateMouse

*public void DeactivateMouse()*

### MouseEvent

*public void MouseEvent(int mstate)*

### ClearStates

*public void ClearStates()*

### Accumulate

*public void Accumulate()*

### TouchEvent

*public int TouchEvent(int type, int fingerID, float x, float y, float dx, float dy)*

### MoveEvent

*public void MoveEvent(float forwardmove, float sidemove)*

### LookEvent

*public void LookEvent(float relyaw, float relpitch)*

### KB_Find

*public void * KB_Find(const char * name)*

### KeyEvent

*public int KeyEvent(int evcode, int keynum, const char * bind)*



