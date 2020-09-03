# class CBeam

*Defined at line 123 of ./game/server/effects.h*

Inherits from CBaseEntity



## Functions

### Spawn

*public void Spawn()*

*Defined at line 161 of ./game/server/effects.cpp*

 --------------------------------------------------

 Beams

 --------------------------------------------------

### Precache

*public void Precache()*

*Defined at line 167 of ./game/server/effects.cpp*

### ObjectCaps

*public int ObjectCaps()*

*Defined at line 128 of ./game/server/effects.h*

### TriggerTouch

*public void TriggerTouch(class CBaseEntity * pOther)*

*Defined at line 310 of ./game/server/effects.cpp*

### SetType

*public void SetType(int type)*

*Defined at line 140 of ./game/server/effects.h*

 These functions are here to show the way beams are encoded as entities. Encoding beams as entities simplifies their management in the client/server architecture

### SetFlags

*public void SetFlags(int flags)*

*Defined at line 145 of ./game/server/effects.h*

### SetStartPos

*public void SetStartPos(const class Vector & pos)*

*Defined at line 150 of ./game/server/effects.h*

### SetEndPos

*public void SetEndPos(const class Vector & pos)*

*Defined at line 155 of ./game/server/effects.h*

### SetStartEntity

*public void SetStartEntity(int entityIndex)*

*Defined at line 175 of ./game/server/effects.cpp*

### SetEndEntity

*public void SetEndEntity(int entityIndex)*

*Defined at line 181 of ./game/server/effects.cpp*

### SetStartAttachment

*public void SetStartAttachment(int attachment)*

*Defined at line 163 of ./game/server/effects.h*

### SetEndAttachment

*public void SetEndAttachment(int attachment)*

*Defined at line 168 of ./game/server/effects.h*

### SetTexture

*public void SetTexture(int spriteIndex)*

*Defined at line 173 of ./game/server/effects.h*

### SetWidth

*public void SetWidth(int width)*

*Defined at line 178 of ./game/server/effects.h*

### SetNoise

*public void SetNoise(int amplitude)*

*Defined at line 183 of ./game/server/effects.h*

### SetColor

*public void SetColor(int r, int g, int b)*

*Defined at line 188 of ./game/server/effects.h*

### SetBrightness

*public void SetBrightness(int brightness)*

*Defined at line 195 of ./game/server/effects.h*

### SetFrame

*public void SetFrame(float frame)*

*Defined at line 200 of ./game/server/effects.h*

### SetScrollRate

*public void SetScrollRate(int speed)*

*Defined at line 205 of ./game/server/effects.h*

### GetType

*public int GetType()*

*Defined at line 210 of ./game/server/effects.h*

### GetFlags

*public int GetFlags()*

*Defined at line 215 of ./game/server/effects.h*

### GetStartEntity

*public int GetStartEntity()*

*Defined at line 220 of ./game/server/effects.h*

### GetEndEntity

*public int GetEndEntity()*

*Defined at line 225 of ./game/server/effects.h*

### GetStartPos

*public const class Vector & GetStartPos()*

*Defined at line 188 of ./game/server/effects.cpp*

 These don't take attachments into account

### GetEndPos

*public const class Vector & GetEndPos()*

*Defined at line 198 of ./game/server/effects.cpp*

### Center

*public Vector Center()*

*Defined at line 233 of ./game/server/effects.h*

### GetTexture

*public int GetTexture()*

*Defined at line 235 of ./game/server/effects.h*

### GetWidth

*public int GetWidth()*

*Defined at line 240 of ./game/server/effects.h*

### GetNoise

*public int GetNoise()*

*Defined at line 245 of ./game/server/effects.h*

### GetBrightness

*public int GetBrightness()*

*Defined at line 257 of ./game/server/effects.h*

 inline void GetColor( int r, int g, int b )	{		pev->rendercolor.x = r;		pev->rendercolor.y = g;		pev->rendercolor.z = b;	}

### GetFrame

*public int GetFrame()*

*Defined at line 262 of ./game/server/effects.h*

### GetScrollRate

*public int GetScrollRate()*

*Defined at line 267 of ./game/server/effects.h*

### RelinkBeam

*public void RelinkBeam()*

*Defined at line 279 of ./game/server/effects.cpp*

 Call after you change start/end positions

### DoSparks

*public void DoSparks(const class Vector & start, const class Vector & end)*

*Defined at line 338 of ./game/server/effects.cpp*

void		SetObjectCollisionBox( void );

### RandomTargetname

*public class CBaseEntity * RandomTargetname(const char * szName)*

*Defined at line 323 of ./game/server/effects.cpp*

### BeamDamage

*public void BeamDamage(TraceResult * ptr)*

*Defined at line 717 of ./game/server/effects.cpp*

### BeamInit

*public void BeamInit(const char * pSpriteName, int width)*

*Defined at line 223 of ./game/server/effects.cpp*

 Init after BeamCreate()

### PointsInit

*public void PointsInit(const class Vector & start, const class Vector & end)*

*Defined at line 239 of ./game/server/effects.cpp*

### PointEntInit

*public void PointEntInit(const class Vector & start, int endIndex)*

*Defined at line 93 of ./game/client/hl/hl_baseentity.cpp*

### EntsInit

*public void EntsInit(int startIndex, int endIndex)*

*Defined at line 269 of ./game/server/effects.cpp*

### HoseInit

*public void HoseInit(const class Vector & start, const class Vector & direction)*

*Defined at line 249 of ./game/server/effects.cpp*

### BeamCreate

*public class CBeam * BeamCreate(const char * pSpriteName, int width)*

*Defined at line 94 of ./game/client/hl/hl_baseentity.cpp*

### LiveForTime

*public void LiveForTime(float time)*

*Defined at line 288 of ./game/server/effects.h*

### BeamDamageInstant

*public void BeamDamageInstant(TraceResult * ptr, float damage)*

*Defined at line 294 of ./game/server/effects.h*



