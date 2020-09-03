# class CEventCallback

*Defined at line 85 of ./mainui/EventSystem.h*

## Members

public void * pExtra

private enum (anonymous enum at ../mainui/EventSystem.h:129:2) type

private  u

private const char * szName



## Records





## Functions

### CEventCallback

*public void CEventCallback()*

*Defined at line 19 of ./mainui/EventSystem.cpp*

### CEventCallback

*public void CEventCallback(EventCallback cb, void * ex)*

*Defined at line 25 of ./mainui/EventSystem.cpp*

### CEventCallback

*public void CEventCallback(IHCallback cb, void * ex)*

*Defined at line 45 of ./mainui/EventSystem.cpp*

### CEventCallback

*public void CEventCallback(VoidCallback cb)*

*Defined at line 38 of ./mainui/EventSystem.cpp*

### CEventCallback

*public void CEventCallback(VoidIHCallback cb)*

*Defined at line 52 of ./mainui/EventSystem.cpp*

### CEventCallback

*public void CEventCallback(int execute_now, const char * sz)*

*Defined at line 32 of ./mainui/EventSystem.cpp*

### operator bool

*public _Bool operator bool()*

*Defined at line 98 of ./mainui/EventSystem.h*

 convert to boolean for easy check in conditionals

### operator()

*public void operator()(class CMenuBaseItem * pSelf)*

*Defined at line 59 of ./mainui/EventSystem.cpp*

### operator=

*public IHCallback operator=(IHCallback cb)*

*Defined at line 82 of ./mainui/EventSystem.cpp*

 ItemCallback operator =( ItemCallback cb );

### operator=

*public VoidCallback operator=(VoidCallback cb)*

*Defined at line 76 of ./mainui/EventSystem.cpp*

### operator=

*public EventCallback operator=(EventCallback cb)*

*Defined at line 70 of ./mainui/EventSystem.cpp*

### operator=

*public size_t operator=(size_t null)*

*Defined at line 106 of ./mainui/EventSystem.cpp*

 NULL assignment

### operator=

*public void * operator=(void * null)*

*Defined at line 111 of ./mainui/EventSystem.cpp*

### Reset

*public void Reset()*

*Defined at line 94 of ./mainui/EventSystem.cpp*

### SetCommand

*public void SetCommand(int execute_now, const char * sz)*

*Defined at line 100 of ./mainui/EventSystem.cpp*

### NoopCb

*public void NoopCb(class CMenuBaseItem * , void * )*

*Defined at line 126 of ./mainui/EventSystem.h*

### CmdExecuteNextFrameCb

*private void CmdExecuteNextFrameCb(class CMenuBaseItem * pSelf, void * pExtra)*

*Defined at line 150 of ./mainui/EventSystem.h*

### CmdExecuteNowCb

*private void CmdExecuteNowCb(class CMenuBaseItem * pSelf, void * pExtra)*

*Defined at line 155 of ./mainui/EventSystem.h*



## Enums

| enum  |

--

| CB_OLD_EXTRA |
| CB_OLD_VOID |
| CB_IH_EXTRA |
| CB_IH_VOID |


*Defined at line 129 of ./mainui/EventSystem.h*

 matches type in union



