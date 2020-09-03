# class COsprey

*Defined at line 38 of ./game/server/npc/npc_osprey.cpp*

Inherits from CBaseMonster



## Members

public class CBaseEntity * m_pGoalEnt

Vector m_vel1

Vector m_vel2

Vector m_pos1

Vector m_pos2

Vector m_ang1

Vector m_ang2

public float m_startTime

public float m_dTime

Vector m_velocity

public float m_flIdealtilt

public float m_flRotortilt

public float m_flRightHealth

public float m_flLeftHealth

public int m_iUnits

public class EHANDLE [24] m_hGrunt

public class Vector [24] m_vecOrigin

public class EHANDLE [4] m_hRepel

public int m_iSoundState

public int m_iSpriteTexture

public int m_iPitch

public int m_iExplode

public int m_iTailGibs

public int m_iBodyGibs

public int m_iEngineGibs

public int m_iDoLeftSmokePuff

public int m_iDoRightSmokePuff



## Functions

### Save

*public int Save(class CSave & save)*

*Defined at line 141 of ./game/server/npc/npc_osprey.cpp*

### Restore

*public int Restore(class CRestore & restore)*

*Defined at line 141 of ./game/server/npc/npc_osprey.cpp*

### ObjectCaps

*public int ObjectCaps()*

*Defined at line 44 of ./game/server/npc/npc_osprey.cpp*

### Spawn

*public void Spawn()*

*Defined at line 143 of ./game/server/npc/npc_osprey.cpp*

### Precache

*public void Precache()*

*Defined at line 181 of ./game/server/npc/npc_osprey.cpp*

### Classify

*public int Classify()*

*Defined at line 48 of ./game/server/npc/npc_osprey.cpp*

### BloodColor

*public int BloodColor()*

*Defined at line 49 of ./game/server/npc/npc_osprey.cpp*

### Killed

*public void Killed(entvars_t * pevAttacker, int iGib)*

*Defined at line 496 of ./game/server/npc/npc_osprey.cpp*

int COsprey::TakeDamage( entvars_t *pevInflictor, entvars_t *pevAttacker, float flDamage, int bitsDamageType ){	if( m_flRotortilt <= -90 )	{		m_flRotortilt = 0;	}	else	{		m_flRotortilt -= 45;	}	SetBoneController( 0, m_flRotortilt );	return 0;}

### UpdateGoal

*public void UpdateGoal()*

*Defined at line 339 of ./game/server/npc/npc_osprey.cpp*

### HasDead

*public BOOL HasDead()*

*Defined at line 260 of ./game/server/npc/npc_osprey.cpp*

### FlyThink

*public void FlyThink()*

*Defined at line 374 of ./game/server/npc/npc_osprey.cpp*

### DeployThink

*public void DeployThink()*

*Defined at line 230 of ./game/server/npc/npc_osprey.cpp*

### Flight

*public void Flight()*

*Defined at line 401 of ./game/server/npc/npc_osprey.cpp*

### HitTouch

*public void HitTouch(class CBaseEntity * pOther)*

*Defined at line 475 of ./game/server/npc/npc_osprey.cpp*

### FindAllThink

*public void FindAllThink()*

*Defined at line 204 of ./game/server/npc/npc_osprey.cpp*

### HoverThink

*public void HoverThink()*

*Defined at line 317 of ./game/server/npc/npc_osprey.cpp*

### MakeGrunt

*public class CBaseMonster * MakeGrunt(Vector vecSrc)*

*Defined at line 276 of ./game/server/npc/npc_osprey.cpp*

### CrashTouch

*public void CrashTouch(class CBaseEntity * pOther)*

*Defined at line 514 of ./game/server/npc/npc_osprey.cpp*

### DyingThink

*public void DyingThink()*

*Defined at line 526 of ./game/server/npc/npc_osprey.cpp*

### CommandUse

*public void CommandUse(class CBaseEntity * pActivator, class CBaseEntity * pCaller, USE_TYPE useType, float value)*

*Defined at line 199 of ./game/server/npc/npc_osprey.cpp*

### TraceAttack

*public void TraceAttack(entvars_t * pevAttacker, float flDamage, Vector vecDir, TraceResult * ptr, int bitsDamageType)*

*Defined at line 743 of ./game/server/npc/npc_osprey.cpp*

 int TakeDamage( entvars_t *pevInflictor, entvars_t *pevAttacker, float flDamage, int bitsDamageType );

### ShowDamage

*public void ShowDamage()*

*Defined at line 709 of ./game/server/npc/npc_osprey.cpp*



