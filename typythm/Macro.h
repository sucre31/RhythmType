#pragma once

#include "Error.h"
#include <Dxlib.h>

#define ERR(str) Error::finish(str,_T(__FUNCTION__), __LINE__)