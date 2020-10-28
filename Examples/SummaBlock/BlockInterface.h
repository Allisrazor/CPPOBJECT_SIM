#pragma once

#include <string>

#include "UConstants.h"

namespace cppobj 
{

  /** @class BlockInterface
  * @brief ��������� ��� ������ */
  class BlockInterface
  {
  public:
    /** @brief ����������� */
    explicit BlockInterface();
    /** @brief ���������� */
    virtual ~BlockInterface();
    /** @brief �������������� �������� ��������� ������ */
    virtual NATIVEINT infoFunc(int Action, NATIVEINT aParameter) = 0;
    /** @brief �������� ��� � ������������� ��������� - �� ��������� ������������ ������ ���������, ��� - ������������; Result = - 1 - �������� �� ������ */
    virtual NATIVEINT getParamID(const std::string & paramName, TDataType& dataType, bool& isConst) = 0;
  };
  /** @brief ������� �������� ������� - �� ����� ���� 2 ����� */
  extern BlockInterface * CreateBlockObject();
}



