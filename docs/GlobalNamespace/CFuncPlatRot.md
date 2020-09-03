# class CFuncPlatRot

*Defined at line 495 of ./game/server/plats.cpp*

Inherits from CFuncPlat



## Members

Vector m_end

Vector m_start



## Functions

### Spawn

*public void Spawn()*

*Defined at line 542 of ./game/server/plats.cpp*

### SetupRotation

*public void SetupRotation()*

*Defined at line 523 of ./game/server/plats.cpp*

### GoUp

*public void GoUp()*

*Defined at line 567 of ./game/server/plats.cpp*

 Platform is at bottom, now starts moving up

### GoDown

*public void GoDown()*

*Defined at line 548 of ./game/server/plats.cpp*

### HitTop

*public void HitTop()*

*Defined at line 576 of ./game/server/plats.cpp*

 Platform has hit top. Pauses, then starts back down again.

### HitBottom

*public void HitBottom()*

*Defined at line 557 of ./game/server/plats.cpp*

 Platform has hit bottom. Stops and waits forever.

### RotMove

*public void RotMove(class Vector & destAngle, float time)*

*Defined at line 583 of ./game/server/plats.cpp*

### Save

*public int Save(class CSave & save)*

*Defined at line 521 of ./game/server/plats.cpp*

### Restore

*public int Restore(class CRestore & restore)*

*Defined at line 521 of ./game/server/plats.cpp*



