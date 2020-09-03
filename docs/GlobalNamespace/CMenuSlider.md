# class CMenuSlider

*Defined at line 23 of ./mainui/controls/Slider.h*

Inherits from CMenuEditable



## Members

private float m_flMinValue

private float m_flMaxValue

private float m_flCurValue

private float m_flDrawStep

private int m_iNumSteps

private float m_flRange

private int m_iKeepSlider

private int m_iSliderOutlineWidth

Size m_scCenterBox



## Functions

### CMenuSlider

*public void CMenuSlider()*

*Defined at line 22 of ./mainui/controls/Slider.cpp*

### VidInit

*public void VidInit()*

*Defined at line 44 of ./mainui/controls/Slider.cpp*

=================CMenuSlider::Init=================

### KeyUp

*public _Bool KeyUp(int key)*

*Defined at line 62 of ./mainui/controls/Slider.cpp*

### KeyDown

*public _Bool KeyDown(int key)*

*Defined at line 80 of ./mainui/controls/Slider.cpp*

=================CMenuSlider::Key=================

### Draw

*public void Draw()*

*Defined at line 146 of ./mainui/controls/Slider.cpp*

=================CMenuSlider::Draw=================

### UpdateEditable

*public void UpdateEditable()*

*Defined at line 205 of ./mainui/controls/Slider.cpp*

### LinkCvar

*public void LinkCvar(const char * name)*

*Defined at line 34 of ./mainui/controls/Slider.h*

### Setup

*public void Setup(float minValue, float maxValue, float range)*

*Defined at line 39 of ./mainui/controls/Slider.h*

### SetCurrentValue

*public void SetCurrentValue(float curValue)*

*Defined at line 45 of ./mainui/controls/Slider.h*

### GetCurrentValue

*public float GetCurrentValue()*

*Defined at line 51 of ./mainui/controls/Slider.h*

### SetKeepSlider

*public void SetKeepSlider(int keepSlider)*

*Defined at line 54 of ./mainui/controls/Slider.h*

 void SetDrawStep( float drawStep, int numSteps );



