# class CFuncTrackChange

*Defined at line 1586 of ./game/server/plats.cpp*

Inherits from CFuncPlatRot



## Members

public class CPathTrack * m_trackTop

public class CPathTrack * m_trackBottom

public class CFuncTrackTrain * m_train

public string_t m_trackTopName

public string_t m_trackBottomName

public string_t m_trainName

public TRAIN_CODE m_code

public int m_targetState

public int m_use



## Functions

### Spawn

*public void Spawn()*

*Defined at line 1647 of ./game/server/plats.cpp*

### Precache

*public void Precache()*

*Defined at line 1676 of ./game/server/plats.cpp*

### GoUp

*public void GoUp()*

*Defined at line 1849 of ./game/server/plats.cpp*

 Platform is at bottom, now starts moving up

virtual void Blocked( void );

### GoDown

*public void GoDown()*

*Defined at line 1814 of ./game/server/plats.cpp*

### KeyValue

*public void KeyValue(KeyValueData * pkvd)*

*Defined at line 1693 of ./game/server/plats.cpp*

### Use

*public void Use(class CBaseEntity * pActivator, class CBaseEntity * pCaller, USE_TYPE useType, float value)*

*Defined at line 1898 of ./game/server/plats.cpp*

### Find

*public void Find()*

*Defined at line 1722 of ./game/server/plats.cpp*

### EvaluateTrain

*public TRAIN_CODE EvaluateTrain(class CPathTrack * pcurrent)*

*Defined at line 1764 of ./game/server/plats.cpp*

### UpdateTrain

*public void UpdateTrain(class Vector & dest)*

*Defined at line 1789 of ./game/server/plats.cpp*

### HitBottom

*public void HitBottom()*

*Defined at line 1930 of ./game/server/plats.cpp*

 Platform has hit bottom.  Stops and waits forever.

### HitTop

*public void HitTop()*

*Defined at line 1949 of ./game/server/plats.cpp*

 Platform has hit bottom.  Stops and waits forever.

### Touch

*public void Touch(class CBaseEntity * pOther)*

*Defined at line 1685 of ./game/server/plats.cpp*

 UNDONE: Filter touches before re-evaluating the train.

### UpdateAutoTargets

*public void UpdateAutoTargets(int toggleState)*

*Defined at line 1882 of ./game/server/plats.cpp*

 Normal track change

### IsTogglePlat

*public BOOL IsTogglePlat()*

*Defined at line 1605 of ./game/server/plats.cpp*

### DisableUse

*public void DisableUse()*

*Defined at line 1607 of ./game/server/plats.cpp*

### EnableUse

*public void EnableUse()*

*Defined at line 1608 of ./game/server/plats.cpp*

### UseEnabled

*public int UseEnabled()*

*Defined at line 1609 of ./game/server/plats.cpp*

### Save

*public int Save(class CSave & save)*

*Defined at line 1645 of ./game/server/plats.cpp*

### Restore

*public int Restore(class CRestore & restore)*

*Defined at line 1645 of ./game/server/plats.cpp*

### OverrideReset

*public void OverrideReset()*

*Defined at line 1716 of ./game/server/plats.cpp*



