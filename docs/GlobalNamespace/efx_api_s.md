# struct efx_api_s

*Defined at line 118 of ./common/r_efx.h*

## Members

public particle_t *(*)(void (*)(struct particle_s *, float)) R_AllocParticle

public void (*)(const float *) R_BlobExplosion

public void (*)(const float *, const float *, int, int) R_Blood

public void (*)(const float *, int, int, int, float) R_BloodSprite

public void (*)(const float *, const float *, int, int) R_BloodStream

public void (*)(const float *, const float *, const float *, float, float, int, int, char) R_BreakModel

public void (*)(const float *, const float *, float, int, int, float) R_Bubbles

public void (*)(const float *, const float *, float, int, int, float) R_BubbleTrail

public void (*)(const float *) R_BulletImpactParticles

public void (*)(struct cl_entity_s *) R_EntityParticles

public void (*)(float *, int, float, float, int) R_Explosion

public void (*)(struct cl_entity_s *, int, int) R_FizzEffect

public void (*)(float *, int, int, int, int, float) R_FireField

public void (*)(const float *) R_FlickerParticles

public void (*)(const float *, int, int) R_FunnelSprite

public void (*)(const float *, float, int, float) R_Implosion

public void (*)(const float *, int) R_LargeFunnel

public void (*)(const float *) R_LavaSplash

public void (*)(const float *, const float *, const float *, int, int, int *) R_MultiGunshot

public void (*)(const float *, int) R_MuzzleFlash

public void (*)(const float *, const float *, unsigned char, unsigned char, unsigned char, float) R_ParticleBox

public void (*)(const float *, int, int, float) R_ParticleBurst

public void (*)(const float *) R_ParticleExplosion

public void (*)(const float *, int, int) R_ParticleExplosion2

public void (*)(const float *, const float *, unsigned char, unsigned char, unsigned char, float) R_ParticleLine

public void (*)(int, int, int, int) R_PlayerSprites

public void (*)(const float *, const float *, int, int, int, void (*)(struct tempent_s *, struct pmtrace_s *)) R_Projectile

public void (*)(const float *) R_RicochetSound

public void (*)(const float *, struct model_s *, float, float) R_RicochetSprite

public void (*)(const float *) R_RocketFlare

public void (*)(float *, float *, int) R_RocketTrail

public void (*)(const float *, const float *, int, int) R_RunParticleEffect

public void (*)(const float *, const float *) R_ShowLine

public void (*)(const float *, int, int, int) R_SparkEffect

public void (*)(const float *) R_SparkShower

public void (*)(const float *, int, int, int) R_SparkStreaks

public void (*)(const float *, const float *, int, int, int, int, int) R_Spray

public void (*)(TEMPENTITY *, float, int) R_Sprite_Explode

public void (*)(TEMPENTITY *, float) R_Sprite_Smoke

public void (*)(const float *, const float *, int, int, int, int) R_Sprite_Spray

public void (*)(int, float *, float *, int, int, float, float, float, int, float) R_Sprite_Trail

public void (*)(TEMPENTITY *, float) R_Sprite_WallPuff

public void (*)(const float *, const float *, int, int, float, int, int) R_StreakSplash

public void (*)(const float *, const float *) R_TracerEffect

public void (*)(float *, float *, float, int, float, unsigned char, void (*)(struct particle_s *)) R_UserTracerParticle

public particle_t *(*)(float *, float *, float) R_TracerParticles

public void (*)(const float *) R_TeleportSplash

public void (*)(const float *, float, float, int, int) R_TempSphereModel

public TEMPENTITY *(*)(const float *, const float *, const float *, float, int, int) R_TempModel

public TEMPENTITY *(*)(const float *, int, float) R_DefaultSprite

public TEMPENTITY *(*)(float *, const float *, float, int, int, int, float, float, int) R_TempSprite

public int (*)(int) Draw_DecalIndex

public int (*)(const char *) Draw_DecalIndexFromName

public void (*)(int, int, int, float *, int) R_DecalShoot

public void (*)(int, int, float, float) R_AttachTentToPlayer

public void (*)(int) R_KillAttachedTents

public BEAM *(*)(int, float *, float *, int, float, float, float, float, float, int, float, float, float, float) R_BeamCirclePoints

public BEAM *(*)(int, float *, int, float, float, float, float, float, int, float, float, float, float) R_BeamEntPoint

public BEAM *(*)(int, int, int, float, float, float, float, float, int, float, float, float, float) R_BeamEnts

public BEAM *(*)(int, int, float, float, float, float, float, float) R_BeamFollow

public void (*)(int) R_BeamKill

public BEAM *(*)(float *, float *, int, float, float, float, float, float) R_BeamLightning

public BEAM *(*)(float *, float *, int, float, float, float, float, float, int, float, float, float, float) R_BeamPoints

public BEAM *(*)(int, int, int, float, float, float, float, float, int, float, float, float, float) R_BeamRing

public dlight_t *(*)(int) CL_AllocDlight

public dlight_t *(*)(int) CL_AllocElight

public TEMPENTITY *(*)(const float *, struct model_s *) CL_TempEntAlloc

public TEMPENTITY *(*)(const float *) CL_TempEntAllocNoModel

public TEMPENTITY *(*)(const float *, struct model_s *) CL_TempEntAllocHigh

public TEMPENTITY *(*)(const float *, struct model_s *, int, void (*)(struct tempent_s *, float, float)) CL_TentEntAllocCustom

public void (*)(short *, short) R_GetPackedColor

public short (*)(unsigned char, unsigned char, unsigned char) R_LookupColor

public void (*)(int) R_DecalRemoveAll

public void (*)(int, int, int, float *, int, float) R_FireCustomDecal



