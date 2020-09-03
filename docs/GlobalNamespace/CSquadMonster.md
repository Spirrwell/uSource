# class CSquadMonster

*Defined at line 58 of ./game/server/ai/ai_squadmonster.h*

========================================================= CSquadMonster - for any monster that forms squads.=========================================================



Inherits from CBaseMonster



## Members

EHANDLE m_hSquadLeader

public class EHANDLE [4] m_hSquadMember

public int m_afSquadSlots

public float m_flLastEnemySightTime

public BOOL m_fEnemyEluded

public int m_iMySlot



## Functions

### CheckEnemy

*public int CheckEnemy(class CBaseEntity * pEnemy)*

*Defined at line 382 of ./game/server/ai/ai_squadmonster.cpp*

========================================================= CheckEnemy=========================================================

### StartMonster

*public void StartMonster()*

*Defined at line 409 of ./game/server/ai/ai_squadmonster.cpp*

========================================================= StartMonster=========================================================

### VacateSlot

*public void VacateSlot()*

*Defined at line 102 of ./game/server/ai/ai_squadmonster.cpp*

========================================================= VacateSlot=========================================================

### ScheduleChange

*public void ScheduleChange()*

*Defined at line 115 of ./game/server/ai/ai_squadmonster.cpp*

========================================================= ScheduleChange=========================================================

### Killed

*public void Killed(entvars_t * pevAttacker, int iGib)*

*Defined at line 123 of ./game/server/ai/ai_squadmonster.cpp*

========================================================= Killed=========================================================

### OccupySlot

*public BOOL OccupySlot(int iDesiredSlot)*

*Defined at line 50 of ./game/server/ai/ai_squadmonster.cpp*

========================================================= OccupySlot - if any slots of the passed slots are  available, the monster will be assigned to one.=========================================================

### NoFriendlyFire

*public BOOL NoFriendlyFire()*

*Defined at line 446 of ./game/server/ai/ai_squadmonster.cpp*

========================================================= NoFriendlyFire - checks for possibility of friendly fire

 Builds a large box in front of the grunt and checks to see  if any squad members are in that box. =========================================================

### MySquadLeader

*public class CSquadMonster * MySquadLeader()*

*Defined at line 80 of ./game/server/ai/ai_squadmonster.h*

 squad functions still left in base class

### MySquadMember

*public class CSquadMonster * MySquadMember(int i)*

*Defined at line 87 of ./game/server/ai/ai_squadmonster.h*

### InSquad

*public int InSquad()*

*Defined at line 94 of ./game/server/ai/ai_squadmonster.h*

### IsLeader

*public int IsLeader()*

*Defined at line 95 of ./game/server/ai/ai_squadmonster.h*

### SquadJoin

*public int SquadJoin(int searchRadius)*

### SquadRecruit

*public int SquadRecruit(int searchRadius, int maxMembers)*

*Defined at line 303 of ./game/server/ai/ai_squadmonster.cpp*

=========================================================

 SquadRecruit(), get some monsters of my classification and link them as a group.  returns the group size

=========================================================

### SquadCount

*public int SquadCount()*

*Defined at line 281 of ./game/server/ai/ai_squadmonster.cpp*

=========================================================

 SquadCount(), return the number of members of this squad callable from leaders & followers

=========================================================

### SquadRemove

*public void SquadRemove(class CSquadMonster * pRemove)*

*Defined at line 144 of ./game/server/ai/ai_squadmonster.cpp*

=========================================================

 SquadRemove(), remove pRemove from my squad. If I am pRemove, promote m_pSquadNext to leader

=========================================================

### SquadUnlink

*public void SquadUnlink()*

### SquadAdd

*public BOOL SquadAdd(class CSquadMonster * pAdd)*

*Defined at line 187 of ./game/server/ai/ai_squadmonster.cpp*

=========================================================

 SquadAdd(), add pAdd to my squad

=========================================================

### SquadDisband

*public void SquadDisband()*

### SquadAddConditions

*public void SquadAddConditions(int iConditions)*

### SquadMakeEnemy

*public void SquadMakeEnemy(class CBaseEntity * pEnemy)*

*Defined at line 241 of ./game/server/ai/ai_squadmonster.cpp*

=========================================================

 SquadMakeEnemy - makes everyone in the squad angry at the same entity.

=========================================================

### SquadPasteEnemyInfo

*public void SquadPasteEnemyInfo()*

*Defined at line 213 of ./game/server/ai/ai_squadmonster.cpp*

=========================================================

 SquadPasteEnemyInfo - called by squad members that have current info on the enemy so that it can be stored for  members who don't have current info.

=========================================================

### SquadCopyEnemyInfo

*public void SquadCopyEnemyInfo()*

*Defined at line 228 of ./game/server/ai/ai_squadmonster.cpp*

=========================================================

 SquadCopyEnemyInfo - called by squad members who don't have current info on the enemy. Reads from the same fields in the leader's data that other squad members write to, so the most recent data is always available here.

=========================================================

### SquadEnemySplit

*public BOOL SquadEnemySplit()*

*Defined at line 555 of ./game/server/ai/ai_squadmonster.cpp*

========================================================= SquadEnemySplit- returns TRUE if not all squad members are fighting the same enemy. =========================================================

### SquadMemberInRange

*public BOOL SquadMemberInRange(const class Vector & vecLocation, float flDist)*

*Defined at line 579 of ./game/server/ai/ai_squadmonster.cpp*

========================================================= FValidateCover - determines whether or not the chosen cover location is a good one to move to. (currently based on proximity to others in the squad)=========================================================

### MySquadMonsterPointer

*public class CSquadMonster * MySquadMonsterPointer()*

*Defined at line 110 of ./game/server/ai/ai_squadmonster.h*

### Save

*public int Save(class CSave & save)*

*Defined at line 44 of ./game/server/ai/ai_squadmonster.cpp*

### Restore

*public int Restore(class CRestore & restore)*

*Defined at line 44 of ./game/server/ai/ai_squadmonster.cpp*

### FValidateCover

*public BOOL FValidateCover(const class Vector & vecCoverLocation)*

*Defined at line 535 of ./game/server/ai/ai_squadmonster.cpp*

========================================================= FValidateCover - determines whether or not the chosen cover location is a good one to move to. (currently based on proximity to others in the squad)=========================================================

### GetIdealState

*public MONSTERSTATE GetIdealState()*

*Defined at line 509 of ./game/server/ai/ai_squadmonster.cpp*

========================================================= GetIdealState - surveys the Conditions information available and finds the best new state for a monster.=========================================================

### GetScheduleOfType

*public struct Schedule_t * GetScheduleOfType(int iType)*

*Defined at line 597 of ./game/server/ai/ai_squadmonster.cpp*



