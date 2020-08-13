#include "reflection.h"

std::unordered_map<std::type_index, SStructInfo_t*>* reflection::g_pStructFieldInfos;