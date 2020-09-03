# class CGMan

*Defined at line 29 of ./game/server/npc/npc_gman.cpp*

========================================================= Monster's Anim Events Go Here=========================================================



Inherits from CBaseMonster



## Members

EHANDLE m_hPlayer

EHANDLE m_hTalkTarget

public float m_flTalkTime



## Functions

### Spawn

*public void Spawn()*

*Defined at line 118 of ./game/server/npc/npc_gman.cpp*

========================================================= Spawn=========================================================

### Precache

*public void Precache()*

*Defined at line 138 of ./game/server/npc/npc_gman.cpp*

========================================================= Precache - precaches all resources this monster needs=========================================================

### SetYawSpeed

*public void SetYawSpeed()*

*Defined at line 78 of ./game/server/npc/npc_gman.cpp*

========================================================= SetYawSpeed - allows each sequence to have a different turn rate associated with it.=========================================================

### Classify

*public int Classify()*

*Defined at line 69 of ./game/server/npc/npc_gman.cpp*

========================================================= Classify - indicates this monster's place in the  relationship table.=========================================================

### HandleAnimEvent

*public void HandleAnimEvent(MonsterEvent_t * pEvent)*

*Defined at line 96 of ./game/server/npc/npc_gman.cpp*

========================================================= HandleAnimEvent - catches the monster-specific messages that occur when tagged animation frames are played.=========================================================

### ISoundMask

*public int ISoundMask()*

*Defined at line 110 of ./game/server/npc/npc_gman.cpp*

========================================================= ISoundMask - generic monster can't hear.=========================================================

### Save

*public int Save(class CSave & save)*

*Defined at line 63 of ./game/server/npc/npc_gman.cpp*

### Restore

*public int Restore(class CRestore & restore)*

*Defined at line 63 of ./game/server/npc/npc_gman.cpp*

### StartTask

*public void StartTask(struct Task_t * pTask)*

*Defined at line 147 of ./game/server/npc/npc_gman.cpp*

========================================================= AI Schedules Specific to this monster=========================================================

### RunTask

*public void RunTask(struct Task_t * pTask)*

*Defined at line 161 of ./game/server/npc/npc_gman.cpp*

### TakeDamage

*public int TakeDamage(entvars_t * pevInflictor, entvars_t * pevAttacker, float flDamage, int bitsDamageType)*

*Defined at line 208 of ./game/server/npc/npc_gman.cpp*

========================================================= Override all damage=========================================================

### TraceAttack

*public void TraceAttack(entvars_t * pevAttacker, float flDamage, Vector vecDir, TraceResult * ptr, int bitsDamageType)*

*Defined at line 224 of ./game/server/npc/npc_gman.cpp*

### PlayScriptedSentence

*public void PlayScriptedSentence(const char * pszSentence, float duration, float volume, float attenuation, BOOL bConcurrent, class CBaseEntity * pListener)*

*Defined at line 230 of ./game/server/npc/npc_gman.cpp*



