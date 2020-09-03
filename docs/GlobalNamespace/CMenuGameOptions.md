# class CMenuGameOptions

*Defined at line 31 of ./mainui/menus/GameOptions.cpp*

Inherits from CMenuFramework



## Members

CMenuSpinControl maxFPS

CMenuCheckBox allowDownload

CMenuCheckBox cl_predict

CMenuCheckBox cl_lw

CMenuSpinControl maxpacket

CMenuSpinControl maxpayload

CMenuSpinControl cmdrate

CMenuSpinControl updaterate

CMenuSpinControl rate

CMenuAction networkMode

CMenuCheckBox normal

CMenuCheckBox dsl

CMenuCheckBox slowest

CMenuCheckBox split

CMenuCheckBox compress



## Functions

### CMenuGameOptions

*public void CMenuGameOptions()*

*Defined at line 34 of ./mainui/menus/GameOptions.cpp*

### KeyDown

*public _Bool KeyDown(int key)*

*Defined at line 64 of ./mainui/menus/GameOptions.cpp*

=================UI_GameOptions_KeyFunc=================

### SetNetworkMode

*public void SetNetworkMode(int maxpacket, int maxpayload, int cmdrate, int updaterate, int rate)*

*Defined at line 71 of ./mainui/menus/GameOptions.cpp*

### _Init

*private void _Init()*

*Defined at line 130 of ./mainui/menus/GameOptions.cpp*

=================UI_GameOptions_Init=================

### SaveCb

*private void SaveCb()*

*Defined at line 85 of ./mainui/menus/GameOptions.cpp*

### RestoreCb

*private void RestoreCb()*

*Defined at line 119 of ./mainui/menus/GameOptions.cpp*

### Restore

*private void Restore()*

*Defined at line 103 of ./mainui/menus/GameOptions.cpp*

### GetConfig

*private void GetConfig()*



