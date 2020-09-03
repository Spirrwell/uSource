# class CBaseAnimating

*Defined at line 26 of ./game/shared/c_base_animating.h*

Inherits from CBaseDelay



## Members

public float m_flFrameRate

public float m_flGroundSpeed

public float m_flLastEventCheck

public BOOL m_fSequenceFinished

public BOOL m_fSequenceLoops



## Functions

### Save

*public int Save(class CSave & save)*

*Defined at line 52 of ./game/client/hl/hl_baseentity.cpp*

### Restore

*public int Restore(class CRestore & restore)*

*Defined at line 51 of ./game/client/hl/hl_baseentity.cpp*

 CBaseAnimating Stubs

### StudioFrameAdvance

*public float StudioFrameAdvance(float flInterval)*

*Defined at line 109 of ./game/client/hl/hl_baseentity.cpp*

 Basic Monster Animation functions

========================================================= StudioFrameAdvance - advance the animation frame up to the current time if an flInterval is passed in, only advance animation that number of seconds=========================================================

### GetSequenceFlags

*public int GetSequenceFlags()*

*Defined at line 165 of ./game/client/hl/hl_baseentity.cpp*

==================================================================================================================

### LookupActivity

*public int LookupActivity(int activity)*

*Defined at line 160 of ./game/client/hl/hl_baseentity.cpp*

========================================================= LookupActivity=========================================================

### LookupActivityHeaviest

*public int LookupActivityHeaviest(int activity)*

*Defined at line 161 of ./game/client/hl/hl_baseentity.cpp*

========================================================= LookupActivityHeaviest

 Get activity with highest 'weight'

=========================================================

### LookupSequence

*public int LookupSequence(const char * label)*

*Defined at line 163 of ./game/client/hl/hl_baseentity.cpp*

==================================================================================================================

### ResetSequenceInfo

*public void ResetSequenceInfo()*

*Defined at line 164 of ./game/client/hl/hl_baseentity.cpp*

==================================================================================================================

### DispatchAnimEvents

*public void DispatchAnimEvents(float flFutureInterval)*

*Defined at line 166 of ./game/client/hl/hl_baseentity.cpp*

========================================================= DispatchAnimEvents=========================================================

### HandleAnimEvent

*public void HandleAnimEvent(MonsterEvent_t * pEvent)*

*Defined at line 41 of ./game/shared/c_base_animating.h*

### SetBoneController

*public float SetBoneController(int iController, float flValue)*

*Defined at line 168 of ./game/client/hl/hl_baseentity.cpp*

==================================================================================================================

### InitBoneControllers

*public void InitBoneControllers()*

*Defined at line 169 of ./game/client/hl/hl_baseentity.cpp*

==================================================================================================================

### SetBlending

*public float SetBlending(int iBlender, float flValue)*

*Defined at line 170 of ./game/client/hl/hl_baseentity.cpp*

==================================================================================================================

### GetBonePosition

*public void GetBonePosition(int iBone, class Vector & origin, class Vector & angles)*

*Defined at line 171 of ./game/client/hl/hl_baseentity.cpp*

==================================================================================================================

### GetAutomovement

*public void GetAutomovement(class Vector & origin, class Vector & angles, float flInterval)*

*Defined at line 174 of ./game/client/hl/hl_baseentity.cpp*

==================================================================================================================

### FindTransition

*public int FindTransition(int iEndingSequence, int iGoalSequence, int * piDir)*

*Defined at line 173 of ./game/client/hl/hl_baseentity.cpp*

==================================================================================================================

### GetAttachment

*public void GetAttachment(int iAttachment, class Vector & origin, class Vector & angles)*

*Defined at line 172 of ./game/client/hl/hl_baseentity.cpp*

==================================================================================================================

### SetBodygroup

*public void SetBodygroup(int iGroup, int iValue)*

*Defined at line 175 of ./game/client/hl/hl_baseentity.cpp*

### GetBodygroup

*public int GetBodygroup(int iGroup)*

*Defined at line 176 of ./game/client/hl/hl_baseentity.cpp*

### ExtractBbox

*public int ExtractBbox(int sequence, float * mins, float * maxs)*

*Defined at line 244 of ./game/server/animating.cpp*

### SetSequenceBox

*public void SetSequenceBox()*

*Defined at line 252 of ./game/server/animating.cpp*

==================================================================================================================



