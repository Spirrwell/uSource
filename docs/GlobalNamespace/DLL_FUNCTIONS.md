# struct DLL_FUNCTIONS

*Defined at line 403 of ./engine/eiface.h*

## Members

public void (*)(void) pfnGameInit

public int (*)(edict_t *) pfnSpawn

public void (*)(edict_t *) pfnThink

public void (*)(edict_t *, edict_t *) pfnUse

public void (*)(edict_t *, edict_t *) pfnTouch

public void (*)(edict_t *, edict_t *) pfnBlocked

public void (*)(edict_t *, KeyValueData *) pfnKeyValue

public void (*)(edict_t *, SAVERESTOREDATA *) pfnSave

public int (*)(edict_t *, SAVERESTOREDATA *, int) pfnRestore

public void (*)(edict_t *) pfnSetAbsBox

public void (*)(SAVERESTOREDATA *, const char *, void *, TYPEDESCRIPTION *, int) pfnSaveWriteFields

public void (*)(SAVERESTOREDATA *, const char *, void *, TYPEDESCRIPTION *, int) pfnSaveReadFields

public void (*)(SAVERESTOREDATA *) pfnSaveGlobalState

public void (*)(SAVERESTOREDATA *) pfnRestoreGlobalState

public void (*)(void) pfnResetGlobalState

public qboolean (*)(edict_t *, const char *, const char *, char *) pfnClientConnect

public void (*)(edict_t *) pfnClientDisconnect

public void (*)(edict_t *) pfnClientKill

public void (*)(edict_t *) pfnClientPutInServer

public void (*)(edict_t *) pfnClientCommand

public void (*)(edict_t *, char *) pfnClientUserInfoChanged

public void (*)(edict_t *, int, int) pfnServerActivate

public void (*)(void) pfnServerDeactivate

public void (*)(edict_t *) pfnPlayerPreThink

public void (*)(edict_t *) pfnPlayerPostThink

public void (*)(void) pfnStartFrame

public void (*)(void) pfnParmsNewLevel

public void (*)(void) pfnParmsChangeLevel

public const char *(*)(void) pfnGetGameDescription

public void (*)(edict_t *, customization_t *) pfnPlayerCustomization

public void (*)(edict_t *) pfnSpectatorConnect

public void (*)(edict_t *) pfnSpectatorDisconnect

public void (*)(edict_t *) pfnSpectatorThink

public void (*)(const char *) pfnSys_Error

public void (*)(struct playermove_s *, qboolean) pfnPM_Move

public void (*)(struct playermove_s *) pfnPM_Init

public char (*)(char *) pfnPM_FindTextureType

public void (*)(struct edict_s *, struct edict_s *, unsigned char **, unsigned char **) pfnSetupVisibility

public void (*)(const struct edict_s *, int, struct clientdata_s *) pfnUpdateClientData

public int (*)(struct entity_state_s *, int, edict_t *, edict_t *, int, int, unsigned char *) pfnAddToFullPack

public void (*)(int, int, struct entity_state_s *, struct edict_s *, int, vec_t *, vec_t *) pfnCreateBaseline

public void (*)(void) pfnRegisterEncoders

public int (*)(struct edict_s *, struct weapon_data_s *) pfnGetWeaponData

public void (*)(const edict_t *, const struct usercmd_s *, unsigned int) pfnCmdStart

public void (*)(const edict_t *) pfnCmdEnd

public int (*)(const struct netadr_s *, const char *, char *, int *) pfnConnectionlessPacket

public int (*)(int, float *, float *) pfnGetHullBounds

public void (*)(void) pfnCreateInstancedBaselines

public int (*)(const struct edict_s *, const char *, char *) pfnInconsistentFile

public int (*)(void) pfnAllowLagCompensation



