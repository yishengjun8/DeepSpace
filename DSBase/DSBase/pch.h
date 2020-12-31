#ifndef PCH_H
#define PCH_H

/* Windows 头文件 */
#include <windows.h>
/**/

/* 可变参数 - 类型获取 */
#include <stdarg.h>
#include <typeinfo>
/**/

/* 数学库 */
#include <cmath>
/**/

/* STL模板库 */
#include <map>
#include <string>
#include <vector>
#include <utility>
#include <iostream>
#include <algorithm>
/**/

/* Direct2D1 */
#include <d2d1.h>
#include <d2d1helper.h>
#include <dwrite.h>
#include <wincodec.h>
#include <dwmapi.h>

#pragma comment(lib, "D2D1.lib")
#pragma comment(lib, "DWrite.lib")
/**/

/* DSBase */
#define DS_BUILDING
/**/

#endif
