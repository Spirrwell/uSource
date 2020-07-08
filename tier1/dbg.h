/**
 * dbg.h
 * 
 * Common debug functions
 */ 
#pragma once 

#include "tier1.h"

#ifndef NDEBUG
#define Assert(_x)
#define AssertMsg(_x, ...) 
#else
#define Assert(_x)
#define AssertMsg(_x, ...)
#endif 

/* Absolutely fatal assertions */
#define AssertF(_x)
#define AssertFMsg(_x, ...) 