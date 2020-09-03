# class CSprite

*Defined at line 34 of ./game/server/effects.h*

Inherits from CPointEntity



## Members

private float m_lastTime

private float m_maxFrame



## Functions

### Spawn

*public void Spawn()*

*Defined at line 1137 of ./game/server/effects.cpp*

### Precache

*public void Precache()*

*Defined at line 1161 of ./game/server/effects.cpp*

### ObjectCaps

*public int ObjectCaps()*

*Defined at line 40 of ./game/server/effects.h*

### AnimateThink

*public void AnimateThink()*

*Defined at line 1196 of ./game/server/effects.cpp*

### ExpandThink

*public void ExpandThink()*

*Defined at line 1225 of ./game/server/effects.cpp*

### Use

*public void Use(class CBaseEntity * pActivator, class CBaseEntity * pCaller, USE_TYPE useType, float value)*

*Defined at line 1277 of ./game/server/effects.cpp*

### Animate

*public void Animate(float frames)*

*Defined at line 1242 of ./game/server/effects.cpp*

### Expand

*public void Expand(float scaleSpeed, float fadeSpeed)*

*Defined at line 95 of ./game/client/hl/hl_baseentity.cpp*

### SpriteInit

*public void SpriteInit(const char * pSpriteName, const class Vector & origin)*

*Defined at line 1176 of ./game/server/effects.cpp*

### SetAttachment

*public void SetAttachment(edict_t * pEntity, int attachment)*

*Defined at line 54 of ./game/server/effects.h*

### TurnOff

*public void TurnOff()*

*Defined at line 1259 of ./game/server/effects.cpp*

### TurnOn

*public void TurnOn()*

*Defined at line 1265 of ./game/server/effects.cpp*

### Frames

*public float Frames()*

*Defined at line 66 of ./game/server/effects.h*

### SetTransparency

*public void SetTransparency(int rendermode, int r, int g, int b, int a, int fx)*

*Defined at line 71 of ./game/server/effects.h*

### SetTexture

*public void SetTexture(int spriteIndex)*

*Defined at line 81 of ./game/server/effects.h*

### SetScale

*public void SetScale(float scale)*

*Defined at line 86 of ./game/server/effects.h*

### SetColor

*public void SetColor(int r, int g, int b)*

*Defined at line 91 of ./game/server/effects.h*

### SetBrightness

*public void SetBrightness(int brightness)*

*Defined at line 98 of ./game/server/effects.h*

### AnimateAndDie

*public void AnimateAndDie(float framerate)*

*Defined at line 103 of ./game/server/effects.h*

### AnimateUntilDead

*public void AnimateUntilDead()*

*Defined at line 1204 of ./game/server/effects.cpp*

### Save

*public int Save(class CSave & save)*

*Defined at line 1135 of ./game/server/effects.cpp*

### Restore

*public int Restore(class CRestore & restore)*

*Defined at line 1135 of ./game/server/effects.cpp*

### SpriteCreate

*public class CSprite * SpriteCreate(const char * pSpriteName, const class Vector & origin, BOOL animate)*

*Defined at line 92 of ./game/client/hl/hl_baseentity.cpp*



