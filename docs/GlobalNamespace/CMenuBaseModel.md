# class CMenuBaseModel

*Defined at line 30 of ./mainui/model/BaseModel.h*

## Functions

### ~CMenuBaseModel

*public void ~CMenuBaseModel()*

*Defined at line 33 of ./mainui/model/BaseModel.h*

### Update

*public void Update()*

 every model must implement these methods

### GetColumns

*public int GetColumns()*

### GetRows

*public int GetRows()*

### GetCellText

*public const char * GetCellText(int line, int column)*

### OnDeleteEntry

*public void OnDeleteEntry(int line)*

*Defined at line 42 of ./mainui/model/BaseModel.h*

 customization

### OnActivateEntry

*public void OnActivateEntry(int line)*

*Defined at line 43 of ./mainui/model/BaseModel.h*

### GetAlignmentForColumn

*public unsigned int GetAlignmentForColumn(int column)*

*Defined at line 44 of ./mainui/model/BaseModel.h*

### GetCellType

*public enum ECellType GetCellType(int line, int column)*

*Defined at line 45 of ./mainui/model/BaseModel.h*

### GetLineColor

*public _Bool GetLineColor(int line, unsigned int & fillColor, _Bool & force)*

*Defined at line 46 of ./mainui/model/BaseModel.h*

### GetCellColors

*public _Bool GetCellColors(int line, int column, unsigned int & textColor, _Bool & force)*

*Defined at line 47 of ./mainui/model/BaseModel.h*

### IsCellTextWrapped

*public _Bool IsCellTextWrapped(int line, int column)*

*Defined at line 48 of ./mainui/model/BaseModel.h*

### Sort

*public _Bool Sort(int column, _Bool ascend)*

*Defined at line 52 of ./mainui/model/BaseModel.h*

 sorting



