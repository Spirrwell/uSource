# namespace reflection



=====================================================================================//

 Use this to declare a primitive "struct" type that you wish to use as a reflected type



## Functions

### offset_of

*size_t offset_of(T1 T2::* member)*

*Defined at line 101 of ./public/reflection.h*

### ComputeTypeFlags

*unsigned int ComputeTypeFlags()*

*Defined at line 108 of ./public/reflection.h*

### RecursiveParameterUnpacker

*Array<struct SMethodParameterInfo_t> & RecursiveParameterUnpacker(Array<struct SMethodParameterInfo_t> & list)*

*Defined at line 118 of ./public/reflection.h*

### RecursiveParameterUnpacker

*Array<struct SMethodParameterInfo_t> & RecursiveParameterUnpacker(Array<struct SMethodParameterInfo_t> & list)*

*Defined at line 124 of ./public/reflection.h*

### GetMethodReturnType

*SMethodParameterInfo_t GetMethodReturnType(ReturnT (*)(ParamT...) fn)*

*Defined at line 132 of ./public/reflection.h*

### GetMethodParamTypes

*Array GetMethodParamTypes(ReturnT (*)(ParamT...) fn)*

*Defined at line 138 of ./public/reflection.h*

### Serialize

*void Serialize(_Bool b, Buffer & buffer)*

### Serialize

*void Serialize(short s, Buffer & buffer)*

### Serialize

*void Serialize(unsigned short s, Buffer & buffer)*

### Serialize

*void Serialize(int i, Buffer & buffer)*

### Serialize

*void Serialize(unsigned int i, Buffer & buffer)*

### Serialize

*void Serialize(long long l, Buffer & buffer)*

### Serialize

*void Serialize(unsigned long long l, Buffer & buffer)*

### Serialize

*void Serialize(float f, Buffer & buffer)*

### Serialize

*void Serialize(double d, Buffer & buffer)*

### Serialize

*void Serialize(float [3] f, Buffer & buffer)*

### ArrayToLittleEndian

*void ArrayToLittleEndian(void * dst, size_t sz)*

*Defined at line 160 of ./public/reflection.h*

### ArrayToBigEndian

*void ArrayToBigEndian(void * dst, size_t sz)*

*Defined at line 170 of ./public/reflection.h*

### Deserialize

*T Deserialize(Buffer & buffer)*

*Defined at line 180 of ./public/reflection.h*

### SerializeNetworkedFields

*void SerializeNetworkedFields(T * _class, Buffer & buffer)*

*Defined at line 17 of ./networksystem/netvar.h*

### DeserializeNetworkedFields

*void DeserializeNetworkedFields(T * _class, Buffer & buffer)*

*Defined at line 48 of ./networksystem/netvar.h*



## Enums

| enum ETypeFlags |

--

| TYPEFLAGS_CONST |
| TYPEFLAGS_NONTRIVIAL |
| TYPEFLAGS_CLASS |
| TYPEFLAGS_UNION |


*Defined at line 93 of ./public/reflection.h*



