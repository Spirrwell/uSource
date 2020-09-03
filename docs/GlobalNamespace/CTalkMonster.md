# class CTalkMonster

*Defined at line 98 of ./game/server/ai/ai_talkmonster.h*

Inherits from CBaseMonster



## Members

public int m_bitsSaid

public int m_nSpeak

public int m_voicePitch

public const char *[18] m_szGrp

public float m_useTime

public string_t m_iszUse

public string_t m_iszUnUse

public float m_flLastSaidSmelled

public float m_flStopTalkTime

EHANDLE m_hTalkTarget



## Functions

### TalkInit

*public void TalkInit()*

*Defined at line 745 of ./game/server/ai/ai_talkmonster.cpp*

 monsters derived from ctalkmonster should call this in precache()

### FindNearestFriend

*public class CBaseEntity * FindNearestFriend(BOOL fPlayer)*

*Defined at line 758 of ./game/server/ai/ai_talkmonster.cpp*

========================================================= FindNearestFriend Scan for nearest, visible friend. If fPlayer is true, look for nearest player=========================================================

### TargetDistance

*public float TargetDistance()*

*Defined at line 712 of ./game/server/ai/ai_talkmonster.cpp*

### StopTalking

*public void StopTalking()*

*Defined at line 104 of ./game/server/ai/ai_talkmonster.h*

### Precache

*public void Precache()*

*Defined at line 1405 of ./game/server/ai/ai_talkmonster.cpp*

 Base Monster functions

### TakeDamage

*public int TakeDamage(entvars_t * pevInflictor, entvars_t * pevAttacker, float flDamage, int bitsDamageType)*

*Defined at line 1143 of ./game/server/ai/ai_talkmonster.cpp*

### Touch

*public void Touch(class CBaseEntity * pOther)*

*Defined at line 829 of ./game/server/ai/ai_talkmonster.cpp*

### Killed

*public void Killed(entvars_t * pevAttacker, int iGib)*

*Defined at line 597 of ./game/server/ai/ai_talkmonster.cpp*

### IRelationship

*public int IRelationship(class CBaseEntity * pTarget)*

*Defined at line 1298 of ./game/server/ai/ai_talkmonster.cpp*

### CanPlaySentence

*public int CanPlaySentence(BOOL fDisregardState)*

*Defined at line 899 of ./game/server/ai/ai_talkmonster.cpp*

### PlaySentence

*public void PlaySentence(const char * pszSentence, float duration, float volume, float attenuation)*

*Defined at line 1101 of ./game/server/ai/ai_talkmonster.cpp*

### PlayScriptedSentence

*public void PlayScriptedSentence(const char * pszSentence, float duration, float volume, float attenuation, BOOL bConcurrent, class CBaseEntity * pListener)*

*Defined at line 1089 of ./game/server/ai/ai_talkmonster.cpp*

### KeyValue

*public void KeyValue(KeyValueData * pkvd)*

*Defined at line 1389 of ./game/server/ai/ai_talkmonster.cpp*

### SetActivity

*public void SetActivity(Activity newActivity)*

*Defined at line 350 of ./game/server/ai/ai_talkmonster.cpp*

 AI functions

### GetScheduleOfType

*public struct Schedule_t * GetScheduleOfType(int Type)*

*Defined at line 1163 of ./game/server/ai/ai_talkmonster.cpp*

### StartTask

*public void StartTask(struct Task_t * pTask)*

*Defined at line 361 of ./game/server/ai/ai_talkmonster.cpp*

### RunTask

*public void RunTask(struct Task_t * pTask)*

*Defined at line 467 of ./game/server/ai/ai_talkmonster.cpp*

### HandleAnimEvent

*public void HandleAnimEvent(MonsterEvent_t * pEvent)*

*Defined at line 725 of ./game/server/ai/ai_talkmonster.cpp*

========================================================= HandleAnimEvent - catches the monster-specific messages that occur when tagged animation frames are played.=========================================================

### PrescheduleThink

*public void PrescheduleThink()*

*Defined at line 1268 of ./game/server/ai/ai_talkmonster.cpp*

========================================================= If there's a player around, watch him.=========================================================

### GetVoicePitch

*public int GetVoicePitch()*

*Defined at line 824 of ./game/server/ai/ai_talkmonster.cpp*

 Conversations / communication

### IdleRespond

*public void IdleRespond()*

*Defined at line 856 of ./game/server/ai/ai_talkmonster.cpp*

========================================================= IdleRespond Respond to a previous question=========================================================

### FIdleSpeak

*public int FIdleSpeak()*

*Defined at line 977 of ./game/server/ai/ai_talkmonster.cpp*

========================================================= FIdleSpeak ask question of nearby friend, or make statement=========================================================

### FIdleStare

*public int FIdleStare()*

*Defined at line 909 of ./game/server/ai/ai_talkmonster.cpp*

========================================================= FIdleStare=========================================================

### FIdleHello

*public int FIdleHello()*

*Defined at line 924 of ./game/server/ai/ai_talkmonster.cpp*

========================================================= IdleHello Try to greet player first time he's seen=========================================================

### IdleHeadTurn

*public void IdleHeadTurn(class Vector & vecFriend)*

*Defined at line 956 of ./game/server/ai/ai_talkmonster.cpp*

 turn head towards supplied origin

### FOkToSpeak

*public int FOkToSpeak()*

*Defined at line 864 of ./game/server/ai/ai_talkmonster.cpp*

### TrySmellTalk

*public void TrySmellTalk()*

*Defined at line 1277 of ./game/server/ai/ai_talkmonster.cpp*

 try to smell something

### EnumFriends

*public class CBaseEntity * EnumFriends(class CBaseEntity * pentPrevious, int listNumber, BOOL bTrace)*

*Defined at line 613 of ./game/server/ai/ai_talkmonster.cpp*

### AlertFriends

*public void AlertFriends()*

*Defined at line 645 of ./game/server/ai/ai_talkmonster.cpp*

### ShutUpFriends

*public void ShutUpFriends()*

*Defined at line 665 of ./game/server/ai/ai_talkmonster.cpp*

### IsTalking

*public BOOL IsTalking()*

*Defined at line 1255 of ./game/server/ai/ai_talkmonster.cpp*

========================================================= IsTalking - am I saying a sentence right now?=========================================================

### Talk

*public void Talk(float flDuration)*

*Defined at line 1122 of ./game/server/ai/ai_talkmonster.cpp*

========================================================= Talk - set a timer that tells us when the monster is done talking.=========================================================

### CanFollow

*public BOOL CanFollow()*

*Defined at line 1341 of ./game/server/ai/ai_talkmonster.cpp*

 For following

### IsFollowing

*public BOOL IsFollowing()*

*Defined at line 142 of ./game/server/ai/ai_talkmonster.h*

### StopFollowing

*public void StopFollowing(BOOL clearSchedule)*

*Defined at line 1306 of ./game/server/ai/ai_talkmonster.cpp*

### StartFollowing

*public void StartFollowing(class CBaseEntity * pLeader)*

*Defined at line 1326 of ./game/server/ai/ai_talkmonster.cpp*

### DeclineFollowing

*public void DeclineFollowing()*

*Defined at line 145 of ./game/server/ai/ai_talkmonster.h*

### LimitFollowers

*public void LimitFollowers(class CBaseEntity * pPlayer, int maxFollowers)*

*Defined at line 686 of ./game/server/ai/ai_talkmonster.cpp*

 UNDONE: Keep a follow time in each follower, make a list of followers in this function and do LRU UNDONE: Check this in Restore to keep restored monsters from joining a full list of followers

### FollowerUse

*public void FollowerUse(class CBaseEntity * pActivator, class CBaseEntity * pCaller, USE_TYPE useType, float value)*

*Defined at line 1357 of ./game/server/ai/ai_talkmonster.cpp*

### SetAnswerQuestion

*public void SetAnswerQuestion(class CTalkMonster * pSpeaker)*

*Defined at line 1136 of ./game/server/ai/ai_talkmonster.cpp*

 Prepare this talking monster to answer question

### FriendNumber

*public int FriendNumber(int arrayNumber)*

*Defined at line 151 of ./game/server/ai/ai_talkmonster.h*

### Save

*public int Save(class CSave & save)*

*Defined at line 51 of ./game/server/ai/ai_talkmonster.cpp*

### Restore

*public int Restore(class CRestore & restore)*

*Defined at line 51 of ./game/server/ai/ai_talkmonster.cpp*

### ScheduleFromName

*public struct Schedule_t * ScheduleFromName(const char * pName)*

*Defined at line 348 of ./game/server/ai/ai_talkmonster.cpp*



