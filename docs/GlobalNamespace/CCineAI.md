# class CCineAI

*Defined at line 47 of ./game/server/ai/ai_scripted.h*

Inherits from CCineMonster



## Functions

### StartSequence

*private BOOL StartSequence(class CBaseMonster * pTarget, int iszSeq, BOOL completeOnEmpty)*

*Defined at line 506 of ./game/server/ai/ai_scripted.cpp*

 lookup a sequence name and setup the target monster to play it overridden for CCineAI because it's ok for them to not have an animation sequence for the monster to play. For a regular Scripted Sequence, that situation is an error.

### PossessEntity

*private void PossessEntity()*

*Defined at line 380 of ./game/server/ai/ai_scripted.cpp*

 make the entity carry out the scripted sequence instructions, but without  destroying the monster's state.

### FCanOverrideState

*private BOOL FCanOverrideState()*

*Defined at line 165 of ./game/server/ai/ai_scripted.cpp*

========================================================= FCanOverrideState - returns true because scripted AI can possess entities regardless of their state.=========================================================

### FixScriptMonsterSchedule

*private void FixScriptMonsterSchedule(class CBaseMonster * pMonster)*

*Defined at line 589 of ./game/server/ai/ai_scripted.cpp*

========================================================= When a monster finishes a scripted sequence, we have to  fix up its state and schedule for it to return to a  normal AI monster. 

 AI Scripted sequences will, depending on what the level designer selects:

 -Dirty the monster's schedule and drop out of the   sequence in their current state.

 -Select a specific AMBUSH schedule, regardless of state.=========================================================



