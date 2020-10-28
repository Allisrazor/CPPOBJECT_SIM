#pragma once

#include <string>

#include "UConstants.h"

#ifdef CPPBLOCK_EXPORTS
#define SUMMABLOCK_API __declspec(dllexport)
#else
#define SUMMABLOCK_API __declspec(dllimport)
#endif // CPPBLOCK_EXPORTS

extern "C" 
{
  /** @brief �������� ������ (���������� ID ������)*/
  SUMMABLOCK_API int createModule();
  /** @brief �������� ������ */
  SUMMABLOCK_API void destroyModule(int);
  /** @brief �������������� �������� ��������� ������ */
  SUMMABLOCK_API NATIVEINT infoFunc(int index, int Action, NATIVEINT aParameter);
  /** @brief �������� ��� � ������������� ��������� - �� ��������� ������������ ������ ���������, ��� - ������������; Result = - 1 - �������� �� ������ */
  SUMMABLOCK_API NATIVEINT getParamID(int index, const char * ParamName, TDataType& DataType, bool& IsConst);
}

