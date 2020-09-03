# class CHGrunt

*Defined at line 123 of ./game/server/npc/npc_hgrunt.cpp*

Inherits from CSquadMonster



## Members

public float m_flNextGrenadeCheck

public float m_flNextPainTime

public float m_flLastEnemySightTime

Vector m_vecTossVelocity

public BOOL m_fThrowGrenade

public BOOL m_fStanding

public BOOL m_fFirstEncounter

public int m_cClipSize

public int m_voicePitch

public int m_iBrassShell

public int m_iShotgunShell

public int m_iSentence



## Functions

### Spawn

*public void Spawn()*

*Defined at line 973 of ./game/server/npc/npc_hgrunt.cpp*

========================================================= Spawn=========================================================

### Precache

*public void Precache()*

*Defined at line 1040 of ./game/server/npc/npc_hgrunt.cpp*

========================================================= Precache - precaches all resources this monster needs=========================================================

### SetYawSpeed

*public void SetYawSpeed()*

*Defined at line 640 of ./game/server/npc/npc_hgrunt.cpp*

========================================================= SetYawSpeed - allows each sequence to have a different turn rate associated with it.=========================================================

### Classify

*public int Classify()*

*Defined at line 743 of ./game/server/npc/npc_hgrunt.cpp*

========================================================= Classify - indicates this monster's place in the  relationship table.=========================================================

### ISoundMask

*public int ISoundMask()*

*Defined at line 323 of ./game/server/npc/npc_hgrunt.cpp*

========================================================= ISoundMask - Overidden for human grunts because they  hear the DANGER sound that is made by hand grenades and other dangerous items.=========================================================

### HandleAnimEvent

*public void HandleAnimEvent(MonsterEvent_t * pEvent)*

*Defined at line 844 of ./game/server/npc/npc_hgrunt.cpp*

========================================================= HandleAnimEvent - catches the monster-specific messages that occur when tagged animation frames are played.=========================================================

### FCanCheckAttacks

*public BOOL FCanCheckAttacks()*

*Defined at line 400 of ./game/server/npc/npc_hgrunt.cpp*

========================================================= FCanCheckAttacks - this is overridden for human grunts because they can throw/shoot grenades when they can't see their target and the base class doesn't check attacks if the monster cannot see its enemy.

 !!!BUGBUG - this gets called before a 3-round burst is fired which means that a friendly can still be hit with up to 2 rounds.  ALSO, grenades will not be tossed if there is a friendly in front, this is a bad bug. Friendly machine gun fire avoidance will unecessarily prevent the throwing of a grenade as well.=========================================================

### CheckMeleeAttack1

*public BOOL CheckMeleeAttack1(float flDot, float flDist)*

*Defined at line 415 of ./game/server/npc/npc_hgrunt.cpp*

========================================================= CheckMeleeAttack1=========================================================

### CheckRangeAttack1

*public BOOL CheckRangeAttack1(float flDot, float flDist)*

*Defined at line 446 of ./game/server/npc/npc_hgrunt.cpp*

========================================================= CheckRangeAttack1 - overridden for HGrunt, cause  FCanCheckAttacks() doesn't disqualify all attacks based on whether or not the enemy is occluded because unlike the base class, the HGrunt can attack when the enemy is occluded (throw grenade over wall, etc). We must  disqualify the machine gun attack if the enemy is occluded.=========================================================

### CheckRangeAttack2

*public BOOL CheckRangeAttack2(float flDot, float flDist)*

*Defined at line 476 of ./game/server/npc/npc_hgrunt.cpp*

========================================================= CheckRangeAttack2 - this checks the Grunt's grenade attack. =========================================================

### CheckAmmo

*public void CheckAmmo()*

*Defined at line 731 of ./game/server/npc/npc_hgrunt.cpp*

========================================================= CheckAmmo - overridden for the grunt because he actually uses ammo! (base class doesn't)=========================================================

### SetActivity

*public void SetActivity(Activity NewActivity)*

*Defined at line 1836 of ./game/server/npc/npc_hgrunt.cpp*

========================================================= SetActivity =========================================================

### StartTask

*public void StartTask(struct Task_t * pTask)*

*Defined at line 1078 of ./game/server/npc/npc_hgrunt.cpp*

========================================================= start task=========================================================

### RunTask

*public void RunTask(struct Task_t * pTask)*

*Defined at line 1123 of ./game/server/npc/npc_hgrunt.cpp*

========================================================= RunTask=========================================================

### DeathSound

*public void DeathSound()*

*Defined at line 1192 of ./game/server/npc/npc_hgrunt.cpp*

========================================================= DeathSound =========================================================

### PainSound

*public void PainSound()*

*Defined at line 1150 of ./game/server/npc/npc_hgrunt.cpp*

========================================================= PainSound=========================================================

### IdleSound

*public void IdleSound()*

*Defined at line 683 of ./game/server/npc/npc_hgrunt.cpp*

### GetGunPosition

*public Vector GetGunPosition()*

*Defined at line 774 of ./game/server/npc/npc_hgrunt.cpp*

========================================================= GetGunPosition	return the end of the barrel=========================================================

### Shoot

*public void Shoot()*

*Defined at line 789 of ./game/server/npc/npc_hgrunt.cpp*

========================================================= Shoot=========================================================

### Shotgun

*public void Shotgun()*

*Defined at line 816 of ./game/server/npc/npc_hgrunt.cpp*

========================================================= Shoot=========================================================

### PrescheduleThink

*public void PrescheduleThink()*

*Defined at line 368 of ./game/server/npc/npc_hgrunt.cpp*

========================================================= PrescheduleThink - this function runs after conditions are collected and before scheduling code is run.=========================================================

### GibMonster

*public void GibMonster()*

*Defined at line 277 of ./game/server/npc/npc_hgrunt.cpp*

========================================================= GibMonster - make gun fly through the air.=========================================================

### SpeakSentence

*public void SpeakSentence()*

*Defined at line 245 of ./game/server/npc/npc_hgrunt.cpp*

========================================================= Speak Sentence - say your cued up sentence.

 Some grunt sentences (take cover and charge) rely on actually being able to execute the intended action. It's really lame when a grunt says 'COVER ME' and then doesn't move. The problem is that the sentences were played when the decision to TRY to move to cover was made. Now the sentence is played after  we know for sure that there is a valid path. The schedule may still fail but in most cases, well after the grunt has  started moving.=========================================================

### Save

*public int Save(class CSave & save)*

*Defined at line 208 of ./game/server/npc/npc_hgrunt.cpp*

### Restore

*public int Restore(class CRestore & restore)*

*Defined at line 208 of ./game/server/npc/npc_hgrunt.cpp*

### Kick

*public class CBaseEntity * Kick()*

*Defined at line 750 of ./game/server/npc/npc_hgrunt.cpp*

==================================================================================================================

### GetSchedule

*public struct Schedule_t * GetSchedule()*

*Defined at line 1945 of ./game/server/npc/npc_hgrunt.cpp*

========================================================= Get Schedule!=========================================================

### GetScheduleOfType

*public struct Schedule_t * GetScheduleOfType(int Type)*

*Defined at line 2193 of ./game/server/npc/npc_hgrunt.cpp*

==================================================================================================================

### TraceAttack

*public void TraceAttack(entvars_t * pevAttacker, float flDamage, Vector vecDir, TraceResult * ptr, int bitsDamageType)*

*Defined at line 602 of ./game/server/npc/npc_hgrunt.cpp*

========================================================= TraceAttack - make sure we're not taking it in the helmet=========================================================

### TakeDamage

*public int TakeDamage(entvars_t * pevInflictor, entvars_t * pevAttacker, float flDamage, int bitsDamageType)*

*Defined at line 629 of ./game/server/npc/npc_hgrunt.cpp*

========================================================= TakeDamage - overridden for the grunt because the grunt needs to forget that he is in cover if he's hurt. (Obviously not in a safe place anymore).=========================================================

### IRelationship

*public int IRelationship(class CBaseEntity * pTarget)*

*Defined at line 264 of ./game/server/npc/npc_hgrunt.cpp*

========================================================= IRelationship - overridden because Alien Grunts are  Human Grunt's nemesis.=========================================================

### FOkToSpeak

*public BOOL FOkToSpeak()*

*Defined at line 334 of ./game/server/npc/npc_hgrunt.cpp*

========================================================= someone else is talking - don't speak=========================================================

### JustSpoke

*public void JustSpoke()*

*Defined at line 358 of ./game/server/npc/npc_hgrunt.cpp*

==================================================================================================================

### ScheduleFromName

*public struct Schedule_t * ScheduleFromName(const char * pName)*

*Defined at line 1831 of ./game/server/npc/npc_hgrunt.cpp*



