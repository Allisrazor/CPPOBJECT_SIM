#pragma once

#include <string>
#include <vector>

#include "UConstants.h"
#include "UMultiSelect.h"

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
    /** @brief ���������� ���������� ����������� ������������� */
    int getMultiselectQty() { return m_multiselectQty; }
    /** @brief ������� ���������� ������������� */
    void addMultiselect(void* multiselect);
    /** @brief ���������� ��������� ������������ ��� nullptr */
    void* getMultiselect(int number);

  protected:
    int m_multiselectQty = 0; ///< @brief ���������� ����������� ��������������
    std::vector<UMultiSelect* > m_multiselects; ///< @brief ����� ��������������
  };
  /** @brief ������� �������� ������� - �� ����� ���� 2 ����� */
  extern BlockInterface * CreateBlockObject();
}



