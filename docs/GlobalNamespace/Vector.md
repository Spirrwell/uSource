# class Vector

*Defined at line 77 of ./common/../mathlib/vector.h*

========================================================================================================//========================================================= 3D Vector=========================================================



## Members

public vec_t x

public vec_t y

public vec_t z



## Functions

### Vector

*public void Vector()*

*Defined at line 81 of ./common/../mathlib/vector.h*

 Construction/destruction

### Vector

*public void Vector(float X, float Y, float Z)*

*Defined at line 82 of ./common/../mathlib/vector.h*

### Vector

*public void Vector(const class Vector & v)*

*Defined at line 85 of ./common/../mathlib/vector.h*

inline Vector( double X, double Y, double Z )		{ x = (float)X; y = (float)Y; z = (float)Z; }inline Vector( int X, int Y, int Z )			{ x = (float)X; y = (float)Y; z = (float)Z; }

### Vector

*public void Vector(float [3] rgfl)*

*Defined at line 86 of ./common/../mathlib/vector.h*

### operator-

*public Vector operator-()*

*Defined at line 89 of ./common/../mathlib/vector.h*

 Operators

### operator==

*public int operator==(const class Vector & v)*

*Defined at line 90 of ./common/../mathlib/vector.h*

### operator!=

*public int operator!=(const class Vector & v)*

*Defined at line 91 of ./common/../mathlib/vector.h*

### operator+

*public Vector operator+(const class Vector & v)*

*Defined at line 92 of ./common/../mathlib/vector.h*

### operator-

*public Vector operator-(const class Vector & v)*

*Defined at line 93 of ./common/../mathlib/vector.h*

### operator*

*public Vector operator*(float fl)*

*Defined at line 94 of ./common/../mathlib/vector.h*

### operator/

*public Vector operator/(float fl)*

*Defined at line 95 of ./common/../mathlib/vector.h*

### CopyToArray

*public void CopyToArray(float * rgfl)*

*Defined at line 98 of ./common/../mathlib/vector.h*

 Methods

### Length

*public float Length()*

*Defined at line 99 of ./common/../mathlib/vector.h*

### operator float *

*public float * operator float *()*

*Defined at line 100 of ./common/../mathlib/vector.h*

### operator const float *

*public const float * operator const float *()*

*Defined at line 101 of ./common/../mathlib/vector.h*

### Normalize

*public Vector Normalize()*

*Defined at line 103 of ./common/../mathlib/vector.h*

### Make2D

*public Vector2D Make2D()*

*Defined at line 111 of ./common/../mathlib/vector.h*

### Length2D

*public float Length2D()*

*Defined at line 121 of ./common/../mathlib/vector.h*

### operator=

*public class Vector & operator=(const class Vector & other)*

*Defined at line 129 of ./common/../mathlib/vector.h*



