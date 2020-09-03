# class CBaseMonster

*Defined at line 13 of ./game/shared/c_base_monster.h*

 generic Monster



Inherits from CBaseToggle



## Members

private int m_afConditions

EHANDLE m_hEnemy

EHANDLE m_hTargetEnt

public class EHANDLE [4] m_hOldEnemy

public class Vector [4] m_vecOldEnemy

public float m_flFieldOfView

public float m_flWaitFinished

public float m_flMoveWaitFinished

public Activity m_Activity

public Activity m_IdealActivity

public int m_LastHitGroup

public MONSTERSTATE m_MonsterState

public MONSTERSTATE m_IdealMonsterState

public int m_iTaskStatus

public struct Schedule_t * m_pSchedule

public int m_iScheduleIndex

public struct WayPoint_t [8] m_Route

public int m_movementGoal

public int m_iRouteIndex

public float m_moveWaitTime

Vector m_vecMoveGoal

public Activity m_movementActivity

public int m_iAudibleList

public int m_afSoundTypes

Vector m_vecLastPosition

public int m_iHintNode

public int m_afMemory

public int m_iMaxHealth

Vector m_vecEnemyLKP

public int m_cAmmoLoaded

public int m_afCapability

public float m_flNextAttack

public int m_bitsDamageType

public BYTE [8] m_rgbTimeBasedDamage

public int m_lastDamageAmount

public int m_bloodColor

public int m_failSchedule

public float m_flHungryTime

public float m_flDistTooFar

public float m_flDistLook

public int m_iTriggerCondition

public string_t m_iszTriggerTarget

Vector m_HackedGunPos

public CBaseMonster::SCRIPTSTATE m_scriptState

public class CCineMonster * m_pCine



## Functions

### Save

*public int Save(class CSave & save)*

*Defined at line 218 of ./game/client/hl/hl_baseentity.cpp*

IMPLEMENT_SAVERESTORE( CBaseMonster, CBaseToggle )

### Restore

*public int Restore(class CRestore & restore)*

*Defined at line 217 of ./game/client/hl/hl_baseentity.cpp*

### KeyValue

*public void KeyValue(KeyValueData * pkvd)*

*Defined at line 182 of ./game/client/hl/hl_baseentity.cpp*

========================================================= KeyValue

 !!! netname entvar field is used in squadmonster for groupname!!!=========================================================

### MonsterUse

*public void MonsterUse(class CBaseEntity * pActivator, class CBaseEntity * pCaller, USE_TYPE useType, float value)*

*Defined at line 111 of ./game/client/hl/hl_baseentity.cpp*

 monster use function

========================================================= CBaseMonster - USE - will make a monster angry at whomever activated it.=========================================================

### CorpseUse

*public void CorpseUse(class CBaseEntity * pActivator, class CBaseEntity * pCaller, USE_TYPE useType, float value)*

### BloodColor

*public int BloodColor()*

*Defined at line 111 of ./game/shared/c_base_monster.h*

 overrideable Monster member functions

### MyMonsterPointer

*public class CBaseMonster * MyMonsterPointer()*

*Defined at line 113 of ./game/shared/c_base_monster.h*

### Look

*public void Look(int iDistance)*

*Defined at line 105 of ./game/client/hl/hl_baseentity.cpp*

========================================================= Look - Base class monster function to find enemies or  food by sight. iDistance is distance ( in units ) that the  monster can see.

 Sets the sight bits of the m_afConditions mask to indicate which types of entities were sighted. Function also sets the Looker's m_pLink  to the head of a link list that contains all visible ents. (linked via each ent's m_pLink field)

=========================================================

### RunAI

*public void RunAI()*

*Defined at line 213 of ./game/client/hl/hl_baseentity.cpp*

========================================================= RunAI=========================================================

### Listen

*public void Listen()*

*Defined at line 102 of ./game/client/hl/hl_baseentity.cpp*

========================================================= Listen - monsters dig through the active sound list for any sounds that may interest them. (smells, too!)=========================================================

### IsAlive

*public _Bool IsAlive()*

*Defined at line 118 of ./game/shared/c_base_monster.h*

### ShouldFadeOnDeath

*public BOOL ShouldFadeOnDeath()*

*Defined at line 198 of ./game/client/hl/hl_baseentity.cpp*

### ChangeYaw

*public float ChangeYaw(int speed)*

*Defined at line 158 of ./game/client/hl/hl_baseentity.cpp*

 Basic Monster AI functions

========================================================= Changeyaw - turns a monster towards its ideal_yaw=========================================================

### VecToYaw

*public float VecToYaw(Vector vecDir)*

*Defined at line 159 of ./game/client/hl/hl_baseentity.cpp*

========================================================= VecToYaw - turns a directional vector into a yaw value that points down that vector.=========================================================

### FlYawDiff

*public float FlYawDiff()*

*Defined at line 157 of ./game/client/hl/hl_baseentity.cpp*

========================================================= FlYawDiff - returns the difference ( in degrees ) between monster's current yaw and ideal_yaw

 Positive result is left turn, negative is right turn=========================================================

### DamageForce

*public float DamageForce(float damage)*

*Defined at line 1000 of ./game/server/combat.cpp*

### MonsterThink

*public void MonsterThink()*

*Defined at line 110 of ./game/client/hl/hl_baseentity.cpp*

 stuff written for new state machine

========================================================= Monster Think - calls out to core AI functions and handles this monster's specific animation events=========================================================

### CallMonsterThink

*public void CallMonsterThink()*

*Defined at line 130 of ./game/shared/c_base_monster.h*

### IRelationship

*public int IRelationship(class CBaseEntity * pTarget)*

*Defined at line 150 of ./game/client/hl/hl_baseentity.cpp*

========================================================= IRelationship - returns an integer that describes the  relationship between two types of monster.=========================================================

### MonsterInit

*public void MonsterInit()*

*Defined at line 145 of ./game/client/hl/hl_baseentity.cpp*

========================================================= MonsterInit - after a monster is spawned, it needs to  be dropped into the world, checked for mobility problems, and put on the proper path, if any. This function does all of those things after the monster spawns. Any initialization that should take place for all monsters goes here.=========================================================

### MonsterInitDead

*public void MonsterInitDead()*

*Defined at line 193 of ./game/client/hl/hl_baseentity.cpp*

 Call after animation/pose is set up

### BecomeDead

*public void BecomeDead()*

*Defined at line 212 of ./game/client/hl/hl_baseentity.cpp*

### CorpseFallThink

*public void CorpseFallThink()*

*Defined at line 192 of ./game/client/hl/hl_baseentity.cpp*

### MonsterInitThink

*public void MonsterInitThink()*

*Defined at line 146 of ./game/client/hl/hl_baseentity.cpp*

========================================================= MonsterInitThink - Calls StartMonster. Startmonster is  virtual, but this function cannot be =========================================================

### StartMonster

*public void StartMonster()*

*Defined at line 147 of ./game/client/hl/hl_baseentity.cpp*

========================================================= StartMonster - final bit of initization before a monster  is turned over to the AI. =========================================================

### BestVisibleEnemy

*public class CBaseEntity * BestVisibleEnemy()*

*Defined at line 153 of ./game/client/hl/hl_baseentity.cpp*

========================================================= BestVisibleEnemy - this functions searches the link list whose head is the caller's m_pLink field, and returns a pointer to the enemy entity in that list that is nearest the  caller.

 !!!UNDONE - currently, this only returns the closest enemy. we'll want to consider distance, relationship, attack types, back turned, etc.=========================================================

### FInViewCone

*public BOOL FInViewCone(class CBaseEntity * pEntity)*

*Defined at line 154 of ./game/client/hl/hl_baseentity.cpp*

========================================================= FInViewCone - returns true is the passed ent is in the caller's forward view cone. The dot product is performed in 2d, making the view cone infinitely tall. =========================================================

### FInViewCone

*public BOOL FInViewCone(class Vector * pOrigin)*

*Defined at line 155 of ./game/client/hl/hl_baseentity.cpp*

========================================================= FInViewCone - returns true is the passed vector is in the caller's forward view cone. The dot product is performed in 2d, making the view cone infinitely tall. =========================================================

### HandleAnimEvent

*public void HandleAnimEvent(MonsterEvent_t * pEvent)*

*Defined at line 167 of ./game/client/hl/hl_baseentity.cpp*

### CheckLocalMove

*public int CheckLocalMove(const class Vector & vecStart, const class Vector & vecEnd, class CBaseEntity * pTarget, float * pflDist)*

*Defined at line 135 of ./game/client/hl/hl_baseentity.cpp*

### Move

*public void Move(float flInterval)*

*Defined at line 142 of ./game/client/hl/hl_baseentity.cpp*

### MoveExecute

*public void MoveExecute(class CBaseEntity * pTargetEnt, const class Vector & vecDir, float flInterval)*

*Defined at line 144 of ./game/client/hl/hl_baseentity.cpp*

### ShouldAdvanceRoute

*public BOOL ShouldAdvanceRoute(float flWaypointDist)*

*Defined at line 143 of ./game/client/hl/hl_baseentity.cpp*

### GetStoppedActivity

*public Activity GetStoppedActivity()*

*Defined at line 149 of ./game/shared/c_base_monster.h*

### Stop

*public void Stop()*

*Defined at line 150 of ./game/shared/c_base_monster.h*

### StopAnimation

*public void StopAnimation()*

*Defined at line 153 of ./game/shared/c_base_monster.h*

 This will stop animation until you call ResetSequenceInfo() at some point in the future

### CheckRangeAttack1

*public BOOL CheckRangeAttack1(float flDot, float flDist)*

*Defined at line 124 of ./game/client/hl/hl_baseentity.cpp*

 these functions will survey conditions and set appropriate conditions bits for attack types.

========================================================= CheckRangeAttack1=========================================================

### CheckRangeAttack2

*public BOOL CheckRangeAttack2(float flDot, float flDist)*

*Defined at line 125 of ./game/client/hl/hl_baseentity.cpp*

========================================================= CheckRangeAttack2=========================================================

### CheckMeleeAttack1

*public BOOL CheckMeleeAttack1(float flDot, float flDist)*

*Defined at line 126 of ./game/client/hl/hl_baseentity.cpp*

========================================================= CheckMeleeAttack1=========================================================

### CheckMeleeAttack2

*public BOOL CheckMeleeAttack2(float flDot, float flDist)*

*Defined at line 127 of ./game/client/hl/hl_baseentity.cpp*

========================================================= CheckMeleeAttack2=========================================================

### FHaveSchedule

*public BOOL FHaveSchedule()*

*Defined at line 36 of ./game/server/ai/ai_schedule.cpp*

========================================================= FHaveSchedule - Returns TRUE if monster's m_pSchedule is anything other than NULL.=========================================================

### FScheduleValid

*public BOOL FScheduleValid()*

*Defined at line 174 of ./game/server/ai/ai_schedule.cpp*

========================================================= FScheduleValid - returns TRUE as long as the current schedule is still the proper schedule to be executing, taking into account all conditions=========================================================

### ClearSchedule

*public void ClearSchedule()*

*Defined at line 50 of ./game/server/ai/ai_schedule.cpp*

========================================================= ClearSchedule - blanks out the caller's schedule pointer and index.=========================================================

### FScheduleDone

*public BOOL FScheduleDone()*

*Defined at line 61 of ./game/server/ai/ai_schedule.cpp*

========================================================= FScheduleDone - Returns TRUE if the caller is on the last task in the schedule=========================================================

### ChangeSchedule

*public void ChangeSchedule(struct Schedule_t * pNewSchedule)*

*Defined at line 78 of ./game/server/ai/ai_schedule.cpp*

========================================================= ChangeSchedule - replaces the monster's schedule pointer with the passed pointer, and sets the ScheduleIndex back to 0=========================================================

### NextScheduledTask

*public void NextScheduledTask()*

*Defined at line 138 of ./game/server/ai/ai_schedule.cpp*

========================================================= NextScheduledTask - increments the ScheduleIndex=========================================================

### ScheduleInList

*public struct Schedule_t * ScheduleInList(const char * pName, struct Schedule_t ** pList, int listCount)*

*Defined at line 1013 of ./game/server/ai/ai_defaultai.cpp*

### ScheduleFromName

*public struct Schedule_t * ScheduleFromName(const char * pName)*

*Defined at line 211 of ./game/client/hl/hl_baseentity.cpp*

### MaintainSchedule

*public void MaintainSchedule()*

*Defined at line 207 of ./game/server/ai/ai_schedule.cpp*

========================================================= MaintainSchedule - does all the per-think schedule maintenance. ensures that the monster leaves this function with a valid schedule!=========================================================

### StartTask

*public void StartTask(struct Task_t * pTask)*

*Defined at line 210 of ./game/client/hl/hl_baseentity.cpp*

========================================================= Start task - selects the correct activity and performs any necessary calculations to start the next task on the schedule. =========================================================

### RunTask

*public void RunTask(struct Task_t * pTask)*

*Defined at line 209 of ./game/client/hl/hl_baseentity.cpp*

========================================================= RunTask =========================================================

### GetScheduleOfType

*public struct Schedule_t * GetScheduleOfType(int Type)*

*Defined at line 207 of ./game/client/hl/hl_baseentity.cpp*

========================================================= GetScheduleOfType - returns a pointer to one of the  monster's available schedules of the indicated type.=========================================================

### GetSchedule

*public struct Schedule_t * GetSchedule()*

*Defined at line 208 of ./game/client/hl/hl_baseentity.cpp*

========================================================= GetSchedule - Decides which type of schedule best suits the monster's current state and conditions. Then calls monster's member function to get a pointer to a schedule of the proper type.=========================================================

### ScheduleChange

*public void ScheduleChange()*

*Defined at line 177 of ./game/shared/c_base_monster.h*

### CanPlaySequence

*public int CanPlaySequence(BOOL fDisregardState, int interruptLevel)*

*Defined at line 184 of ./game/client/hl/hl_baseentity.cpp*

 virtual int CanPlaySequence( void ) { return ((m_pCine == NULL) && (m_MonsterState == MONSTERSTATE_NONE || m_MonsterState == MONSTERSTATE_IDLE || m_IdealMonsterState == MONSTERSTATE_IDLE)); }

=========================================================	 CanPlaySequence - determines whether or not the monster can play the scripted sequence or AI sequence that is  trying to possess it. If DisregardState is set, the monster will be sucked into the script no matter what state it is in. ONLY Scripted AI ents should allow this.=========================================================	

### CanPlaySentence

*public int CanPlaySentence(BOOL fDisregardState)*

*Defined at line 180 of ./game/shared/c_base_monster.h*

### PlaySentence

*public void PlaySentence(const char * pszSentence, float duration, float volume, float attenuation)*

*Defined at line 189 of ./game/client/hl/hl_baseentity.cpp*

### PlayScriptedSentence

*public void PlayScriptedSentence(const char * pszSentence, float duration, float volume, float attenuation, BOOL bConcurrent, class CBaseEntity * pListener)*

*Defined at line 190 of ./game/client/hl/hl_baseentity.cpp*

### SentenceStop

*public void SentenceStop()*

*Defined at line 191 of ./game/client/hl/hl_baseentity.cpp*

### GetTask

*public struct Task_t * GetTask()*

*Defined at line 1321 of ./game/server/ai/ai_schedule.cpp*

========================================================= GetTask - returns a pointer to the current  scheduled task. NULL if there's a problem.=========================================================

### GetIdealState

*public MONSTERSTATE GetIdealState()*

*Defined at line 206 of ./game/client/hl/hl_baseentity.cpp*

========================================================= GetIdealState - surveys the Conditions information available and finds the best new state for a monster.=========================================================

### SetActivity

*public void SetActivity(Activity NewActivity)*

*Defined at line 133 of ./game/client/hl/hl_baseentity.cpp*

========================================================= SetActivity =========================================================

### SetSequenceByName

*public void SetSequenceByName(const char * szSequence)*

*Defined at line 134 of ./game/client/hl/hl_baseentity.cpp*

========================================================= SetSequenceByName=========================================================

### SetState

*public void SetState(MONSTERSTATE State)*

*Defined at line 32 of ./game/server/ai/ai_monsterstate.cpp*

========================================================= SetState=========================================================

### ReportAIState

*public void ReportAIState()*

*Defined at line 181 of ./game/client/hl/hl_baseentity.cpp*

### CheckAttacks

*public void CheckAttacks(class CBaseEntity * pTarget, float flDist)*

*Defined at line 128 of ./game/client/hl/hl_baseentity.cpp*

========================================================= CheckAttacks - sets all of the bits for attacks that the monster is capable of carrying out on the passed entity.=========================================================

### CheckEnemy

*public int CheckEnemy(class CBaseEntity * pEnemy)*

*Defined at line 130 of ./game/client/hl/hl_baseentity.cpp*

========================================================= CheckEnemy - part of the Condition collection process, gets and stores data and conditions pertaining to a monster's enemy. Returns TRUE if Enemy LKP was updated.=========================================================

### PushEnemy

*public void PushEnemy(class CBaseEntity * pEnemy, class Vector & vecLastKnownPos)*

*Defined at line 131 of ./game/client/hl/hl_baseentity.cpp*

========================================================= PushEnemy - remember the last few enemies, always remember the player=========================================================

### PopEnemy

*public BOOL PopEnemy()*

*Defined at line 132 of ./game/client/hl/hl_baseentity.cpp*

========================================================= PopEnemy - try remembering the last few enemies=========================================================

### FGetNodeRoute

*public BOOL FGetNodeRoute(Vector vecDest)*

*Defined at line 179 of ./game/client/hl/hl_baseentity.cpp*

========================================================= FGetNodeRoute - tries to build an entire node path from the callers origin to the passed vector. If this is  possible, ROUTE_SIZE waypoints will be copied into the callers m_Route. TRUE is returned if the operation  succeeds (path is valid) or FALSE if failed (no path  exists )=========================================================

### TaskComplete

*public void TaskComplete()*

*Defined at line 200 of ./game/shared/c_base_monster.h*

### MovementComplete

*public void MovementComplete()*

*Defined at line 148 of ./game/client/hl/hl_baseentity.cpp*

### TaskFail

*public void TaskFail()*

*Defined at line 202 of ./game/shared/c_base_monster.h*

### TaskBegin

*public void TaskBegin()*

*Defined at line 203 of ./game/shared/c_base_monster.h*

### TaskIsRunning

*public int TaskIsRunning()*

*Defined at line 149 of ./game/client/hl/hl_baseentity.cpp*

### TaskIsComplete

*public int TaskIsComplete()*

*Defined at line 205 of ./game/shared/c_base_monster.h*

### MovementIsComplete

*public int MovementIsComplete()*

*Defined at line 206 of ./game/shared/c_base_monster.h*

### IScheduleFlags

*public int IScheduleFlags()*

*Defined at line 158 of ./game/server/ai/ai_schedule.cpp*

========================================================= IScheduleFlags - returns an integer with all Conditions bits that are currently set and also set in the current schedule's Interrupt mask.=========================================================

### FRefreshRoute

*public BOOL FRefreshRoute()*

*Defined at line 116 of ./game/client/hl/hl_baseentity.cpp*

========================================================= FRefreshRoute - after calculating a path to the monster's target, this function copies as many waypoints as possible from that path to the monster's Route array=========================================================

### FRouteClear

*public BOOL FRouteClear()*

*Defined at line 115 of ./game/client/hl/hl_baseentity.cpp*

========================================================= FRouteClear - returns TRUE is the Route is cleared out ( invalid )=========================================================

### RouteSimplify

*public void RouteSimplify(class CBaseEntity * pTargetEnt)*

*Defined at line 122 of ./game/client/hl/hl_baseentity.cpp*

========================================================= RouteSimplify

 Attempts to make the route more direct by cutting out unnecessary nodes & cutting corners.

=========================================================

### AdvanceRoute

*public void AdvanceRoute(float distance)*

*Defined at line 137 of ./game/client/hl/hl_baseentity.cpp*

========================================================= AdvanceRoute - poorly named function that advances the  m_iRouteIndex. If it goes beyond ROUTE_SIZE, the route  is refreshed. =========================================================

### FTriangulate

*public BOOL FTriangulate(const class Vector & vecStart, const class Vector & vecEnd, float flDist, class CBaseEntity * pTargetEnt, class Vector * pApex)*

*Defined at line 141 of ./game/client/hl/hl_baseentity.cpp*

========================================================= FTriangulate - tries to overcome local obstacles by  triangulating a path around them.

 iApexDist is how far the obstruction that we are trying to triangulate around is from the monster.=========================================================

### MakeIdealYaw

*public void MakeIdealYaw(Vector vecTarget)*

*Defined at line 156 of ./game/client/hl/hl_baseentity.cpp*

========================================================= MakeIdealYaw - gets a yaw value for the caller that would face the supplied vector. Value is stuffed into the monster's ideal_yaw=========================================================

### SetYawSpeed

*public void SetYawSpeed()*

*Defined at line 215 of ./game/shared/c_base_monster.h*

### BuildRoute

*public BOOL BuildRoute(const class Vector & vecGoal, int iMoveFlag, class CBaseEntity * pTarget)*

*Defined at line 139 of ./game/client/hl/hl_baseentity.cpp*

========================================================= BuildRoute=========================================================

### BuildNearestRoute

*public BOOL BuildNearestRoute(Vector vecThreat, Vector vecViewOffset, float flMinDist, float flMaxDist)*

*Defined at line 152 of ./game/client/hl/hl_baseentity.cpp*

========================================================= BuildNearestRoute - tries to build a route as close to the target as possible, even if there isn't a path to the final point.

 If supplied, search will return a node at least as far away as MinDist from vecThreat, but no farther than MaxDist.  if MaxDist isn't supplied, it defaults to a reasonable  value=========================================================

### RouteClassify

*public int RouteClassify(int iMoveFlag)*

*Defined at line 138 of ./game/client/hl/hl_baseentity.cpp*

### InsertWaypoint

*public void InsertWaypoint(Vector vecLocation, int afMoveFlags)*

*Defined at line 140 of ./game/client/hl/hl_baseentity.cpp*

========================================================= InsertWaypoint - Rebuilds the existing route so that the supplied vector and moveflags are the first waypoint in the route, and fills the rest of the route with as much of the pre-existing route as possible=========================================================

### FindLateralCover

*public BOOL FindLateralCover(const class Vector & vecThreat, const class Vector & vecViewOffset)*

*Defined at line 185 of ./game/client/hl/hl_baseentity.cpp*

### FindCover

*public BOOL FindCover(Vector vecThreat, Vector vecViewOffset, float flMinDist, float flMaxDist)*

*Defined at line 151 of ./game/client/hl/hl_baseentity.cpp*

float CGraph::PathLength( int iStart, int iDest, int iHull, int afCapMask )

### FValidateCover

*public BOOL FValidateCover(const class Vector & vecCoverLocation)*

*Defined at line 223 of ./game/shared/c_base_monster.h*

### CoverRadius

*public float CoverRadius()*

*Defined at line 224 of ./game/shared/c_base_monster.h*

### FCanCheckAttacks

*public BOOL FCanCheckAttacks()*

*Defined at line 129 of ./game/client/hl/hl_baseentity.cpp*

========================================================= CanCheckAttacks - prequalifies a monster to do more fine checking of potential attacks. =========================================================

### CheckAmmo

*public void CheckAmmo()*

*Defined at line 227 of ./game/shared/c_base_monster.h*

### IgnoreConditions

*public int IgnoreConditions()*

*Defined at line 112 of ./game/client/hl/hl_baseentity.cpp*

========================================================= Ignore conditions - before a set of conditions is allowed to interrupt a monster's schedule, this function removes conditions that we have flagged to interrupt the current schedule, but may not want to interrupt the schedule every time. (Pain, for instance)=========================================================

### SetConditions

*public void SetConditions(int iConditions)*

*Defined at line 230 of ./game/shared/c_base_monster.h*

### ClearConditions

*public void ClearConditions(int iConditions)*

*Defined at line 231 of ./game/shared/c_base_monster.h*

### HasConditions

*public BOOL HasConditions(int iConditions)*

*Defined at line 232 of ./game/shared/c_base_monster.h*

### HasAllConditions

*public BOOL HasAllConditions(int iConditions)*

*Defined at line 233 of ./game/shared/c_base_monster.h*

### FValidateHintType

*public BOOL FValidateHintType(short sHint)*

*Defined at line 104 of ./game/client/hl/hl_baseentity.cpp*

========================================================= FValidateHintType - tells use whether or not the monster cares about the type of Hint Node given=========================================================

### FindHintNode

*public int FindHintNode()*

*Defined at line 180 of ./game/client/hl/hl_baseentity.cpp*

========================================================= FindHintNode=========================================================

### FCanActiveIdle

*public BOOL FCanActiveIdle()*

*Defined at line 188 of ./game/client/hl/hl_baseentity.cpp*

========================================================= FCanActiveIdle=========================================================

### SetTurnActivity

*public void SetTurnActivity()*

*Defined at line 547 of ./game/server/ai/ai_schedule.cpp*

========================================================= SetTurnActivity - measures the difference between the way the monster is facing and determines whether or not to select one of the 180 turn animations.=========================================================

### FLSoundVolume

*public float FLSoundVolume(class CSound * pSound)*

*Defined at line 103 of ./game/client/hl/hl_baseentity.cpp*

========================================================= FLSoundVolume - subtracts the volume of the given sound from the distance the sound source is from the caller,  and returns that value, which is considered to be the 'local'  volume of the sound. =========================================================

### MoveToNode

*public BOOL MoveToNode(Activity movementAct, float waitTime, const class Vector & goal)*

*Defined at line 120 of ./game/client/hl/hl_baseentity.cpp*

### MoveToTarget

*public BOOL MoveToTarget(Activity movementAct, float waitTime)*

*Defined at line 119 of ./game/client/hl/hl_baseentity.cpp*

### MoveToLocation

*public BOOL MoveToLocation(Activity movementAct, float waitTime, const class Vector & goal)*

*Defined at line 118 of ./game/client/hl/hl_baseentity.cpp*

### MoveToEnemy

*public BOOL MoveToEnemy(Activity movementAct, float waitTime)*

*Defined at line 117 of ./game/client/hl/hl_baseentity.cpp*

### OpenDoorAndWait

*public float OpenDoorAndWait(entvars_t * pevDoor)*

*Defined at line 136 of ./game/client/hl/hl_baseentity.cpp*

 Returns the time when the door will be open

### ISoundMask

*public int ISoundMask()*

*Defined at line 106 of ./game/client/hl/hl_baseentity.cpp*

========================================================= ISoundMask - returns a bit mask indicating which types of sounds this monster regards. In the base class implementation, monsters care about all sounds, but no scents.=========================================================

### PBestSound

*public class CSound * PBestSound()*

*Defined at line 107 of ./game/client/hl/hl_baseentity.cpp*

========================================================= PBestSound - returns a pointer to the sound the monster  should react to. Right now responds only to nearest sound.=========================================================

### PBestScent

*public class CSound * PBestScent()*

*Defined at line 108 of ./game/client/hl/hl_baseentity.cpp*

========================================================= PBestScent - returns a pointer to the scent the monster  should react to. Right now responds only to nearest scent=========================================================

### HearingSensitivity

*public float HearingSensitivity()*

*Defined at line 252 of ./game/shared/c_base_monster.h*

### FBecomeProne

*public _Bool FBecomeProne()*

*Defined at line 123 of ./game/client/hl/hl_baseentity.cpp*

========================================================= FBecomeProne - tries to send a monster into PRONE state. right now only used when a barnacle snatches someone, so  may have some special case stuff for that.=========================================================

### BarnacleVictimBitten

*public void BarnacleVictimBitten(entvars_t * pevBarnacle)*

*Defined at line 100 of ./game/client/hl/hl_baseentity.cpp*

========================================================= BarnacleVictimBitten - called by Barnacle victims when the barnacle pulls their head into its mouth=========================================================

### BarnacleVictimReleased

*public void BarnacleVictimReleased()*

*Defined at line 101 of ./game/client/hl/hl_baseentity.cpp*

========================================================= BarnacleVictimReleased - called by barnacle victims when the host barnacle is killed.=========================================================

### SetEyePosition

*public void SetEyePosition()*

*Defined at line 162 of ./game/client/hl/hl_baseentity.cpp*

========================================================= SetEyePosition

 queries the monster's model for $eyeposition and copies that vector to the monster's view_ofs

=========================================================

### FShouldEat

*public BOOL FShouldEat()*

*Defined at line 99 of ./game/client/hl/hl_baseentity.cpp*

========================================================= FShouldEat - returns true if a monster is hungry.=========================================================

### Eat

*public void Eat(float flFullDuration)*

*Defined at line 98 of ./game/client/hl/hl_baseentity.cpp*

========================================================= Eat - makes a monster full for a little while.=========================================================

### CheckTraceHullAttack

*public class CBaseEntity * CheckTraceHullAttack(float flDist, int iDamage, int iDmgType)*

*Defined at line 97 of ./game/client/hl/hl_baseentity.cpp*

========================================================= CheckTraceHullAttack - expects a length to trace, amount  of damage to do, and damage type. Returns a pointer to the damaged entity in case the monster wishes to do other stuff to the victim (punchangle, etc)

 Used for many contact-range melee attacks. Bites, claws, etc.=========================================================

### FacingIdeal

*public BOOL FacingIdeal()*

*Defined at line 187 of ./game/client/hl/hl_baseentity.cpp*

========================================================= FacingIdeal - tells us if a monster is facing its ideal yaw. Created this function because many spots in the  code were checking the yawdiff against this magic number. Nicer to have it in one place if we're gonna be stuck with it.=========================================================

### FCheckAITrigger

*public BOOL FCheckAITrigger()*

*Defined at line 183 of ./game/client/hl/hl_baseentity.cpp*

========================================================= FCheckAITrigger - checks the monster's AI Trigger Conditions, if there is a condition, then checks to see if condition is  met. If yes, the monster's TriggerTarget is fired.

 Returns TRUE if the target is fired.=========================================================

### NoFriendlyFire

*public BOOL NoFriendlyFire()*

### BBoxFlat

*public BOOL BBoxFlat()*

*Defined at line 194 of ./game/client/hl/hl_baseentity.cpp*

========================================================= BBoxIsFlat - check to see if the monster's bounding box is lying flat on a surface (traces from all four corners are same length.)=========================================================

### PrescheduleThink

*public void PrescheduleThink()*

*Defined at line 272 of ./game/shared/c_base_monster.h*

 PrescheduleThink

### GetEnemy

*public BOOL GetEnemy()*

*Defined at line 195 of ./game/client/hl/hl_baseentity.cpp*

========================================================= Get Enemy - tries to find the best suitable enemy for the monster.=========================================================

### MakeDamageBloodDecal

*public void MakeDamageBloodDecal(int cCount, float flNoise, TraceResult * ptr, const class Vector & vecDir)*

*Defined at line 178 of ./game/client/hl/hl_baseentity.cpp*

==================================================================================================================

### TraceAttack

*public void TraceAttack(entvars_t * pevAttacker, float flDamage, Vector vecDir, TraceResult * ptr, int bitsDamageType)*

*Defined at line 196 of ./game/client/hl/hl_baseentity.cpp*

========================================================= TraceAttack=========================================================

### UpdateTarget

*public float UpdateTarget(entvars_t * pevTarget)*

 combat functions

### GetDeathActivity

*public Activity GetDeathActivity()*

*Defined at line 205 of ./game/client/hl/hl_baseentity.cpp*

========================================================= GetDeathActivity - determines the best type of death anim to play.=========================================================

### GetSmallFlinchActivity

*public Activity GetSmallFlinchActivity()*

*Defined at line 459 of ./game/server/combat.cpp*

========================================================= GetSmallFlinchActivity - determines the best type of flinch anim to play.=========================================================

### Killed

*public void Killed(entvars_t * pevAttacker, int iGib)*

*Defined at line 214 of ./game/client/hl/hl_baseentity.cpp*

============Killed============

### GibMonster

*public void GibMonster()*

*Defined at line 202 of ./game/client/hl/hl_baseentity.cpp*

========================================================= GibMonster - create some gore and get rid of a monster's model.=========================================================

### ShouldGibMonster

*public BOOL ShouldGibMonster(int iGib)*

*Defined at line 523 of ./game/server/combat.cpp*

### CallGibMonster

*public void CallGibMonster()*

*Defined at line 531 of ./game/server/combat.cpp*

### HasHumanGibs

*public BOOL HasHumanGibs()*

*Defined at line 203 of ./game/client/hl/hl_baseentity.cpp*

### HasAlienGibs

*public BOOL HasAlienGibs()*

*Defined at line 204 of ./game/client/hl/hl_baseentity.cpp*

### FadeMonster

*public void FadeMonster()*

*Defined at line 201 of ./game/client/hl/hl_baseentity.cpp*

### ShootAtEnemy

*public Vector ShootAtEnemy(const class Vector & shootOrigin)*

*Defined at line 186 of ./game/client/hl/hl_baseentity.cpp*

### BodyTarget

*public Vector BodyTarget(const class Vector & posSrc)*

*Defined at line 291 of ./game/shared/c_base_monster.h*

### GetGunPosition

*public Vector GetGunPosition()*

*Defined at line 177 of ./game/client/hl/hl_baseentity.cpp*

 Combat

### TakeHealth

*public int TakeHealth(float flHealth, int bitsDamageType)*

*Defined at line 215 of ./game/client/hl/hl_baseentity.cpp*

 take health

### TakeDamage

*public int TakeDamage(entvars_t * pevInflictor, entvars_t * pevAttacker, float flDamage, int bitsDamageType)*

*Defined at line 216 of ./game/client/hl/hl_baseentity.cpp*

============TakeDamage

The damage is coming from inflictor, but get mad at attackerThis should be the only function that ever reduces health.bitsDamageType indicates the type of damage sustained, ie: DMG_SHOCK

Time-based damage: only occurs while the monster is within the trigger_hurt.When a monster is poisoned via an arrow etc it takes all the poison damage at once.

GLOBALS ASSUMED SET:  g_iSkillLevel============

### DeadTakeDamage

*public int DeadTakeDamage(entvars_t * pevInflictor, entvars_t * pevAttacker, float flDamage, int bitsDamageType)*

*Defined at line 957 of ./game/server/combat.cpp*

========================================================= DeadTakeDamage - takedamage function called when a monster's corpse is damaged.=========================================================

### RadiusDamage

*public void RadiusDamage(entvars_t * pevInflictor, entvars_t * pevAttacker, float flDamage, int iClassIgnore, int bitsDamageType)*

*Defined at line 199 of ./game/client/hl/hl_baseentity.cpp*

### RadiusDamage

*public void RadiusDamage(Vector vecSrc, entvars_t * pevInflictor, entvars_t * pevAttacker, float flDamage, int iClassIgnore, int bitsDamageType)*

*Defined at line 200 of ./game/client/hl/hl_baseentity.cpp*

### IsMoving

*public int IsMoving()*

*Defined at line 301 of ./game/shared/c_base_monster.h*

### RouteClear

*public void RouteClear()*

*Defined at line 113 of ./game/client/hl/hl_baseentity.cpp*

========================================================= 	RouteClear - zeroes out the monster's route array and goal=========================================================

### RouteNew

*public void RouteNew()*

*Defined at line 114 of ./game/client/hl/hl_baseentity.cpp*

========================================================= Route New - clears out a route to be changed, but keeps				goal intact.=========================================================

### DeathSound

*public void DeathSound()*

*Defined at line 306 of ./game/shared/c_base_monster.h*

### AlertSound

*public void AlertSound()*

*Defined at line 307 of ./game/shared/c_base_monster.h*

### IdleSound

*public void IdleSound()*

*Defined at line 308 of ./game/shared/c_base_monster.h*

### PainSound

*public void PainSound()*

*Defined at line 309 of ./game/shared/c_base_monster.h*

### StopFollowing

*public void StopFollowing(BOOL clearSchedule)*

*Defined at line 311 of ./game/shared/c_base_monster.h*

### Remember

*public void Remember(int iMemory)*

*Defined at line 313 of ./game/shared/c_base_monster.h*

### Forget

*public void Forget(int iMemory)*

*Defined at line 314 of ./game/shared/c_base_monster.h*

### HasMemory

*public BOOL HasMemory(int iMemory)*

*Defined at line 315 of ./game/shared/c_base_monster.h*

### HasAllMemories

*public BOOL HasAllMemories(int iMemory)*

*Defined at line 316 of ./game/shared/c_base_monster.h*

### ExitScriptedSequence

*public BOOL ExitScriptedSequence()*

*Defined at line 606 of ./game/server/ai/ai_scripted.cpp*

### CineCleanup

*public BOOL CineCleanup()*

*Defined at line 768 of ./game/server/ai/ai_scripted.cpp*

### DropItem

*public class CBaseEntity * DropItem(const char * pszItemName, const class Vector & vecPos, const class Vector & vecAng)*

*Defined at line 197 of ./game/client/hl/hl_baseentity.cpp*

========================================================= DropItem - dead monster drops named item =========================================================



## Enums

| enum  |

--

| SCRIPT_PLAYING |
| SCRIPT_WAIT |
| SCRIPT_CLEANUP |
| SCRIPT_WALK_TO_MARK |
| SCRIPT_RUN_TO_MARK |


*Defined at line 19 of ./game/shared/c_base_monster.h*



