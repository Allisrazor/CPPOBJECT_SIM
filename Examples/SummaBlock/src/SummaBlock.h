#pragma once
#include <string>
#include <limits.h>

#include "BlockInterface.h"

namespace cppobj
{
  namespace cppobjsum
  {
    class SummaBlock : public BlockInterface
    {
      double m_valReal = 0.0;
      int m_valInt = 0;
      bool m_valBool = false;
      char16_t * m_valString; // Delphi-������ ���� ������� ������ � ������ ��
      int m_valColor = 0;
      char16_t* m_valText;
      NATIVEINT m_valLineStyle;
      NATIVEINT m_valBrushStyle;
      NATIVEINT m_valFloatFormat;
      TMyPoint m_valPoint;
      NATIVEINT m_valEnum;
      char16_t* m_valFileName;
      char16_t* m_valFileNameDB;
      UMultiSelect* m_multiSelect = nullptr;

    public:
      /** @brief ����������� */
      explicit SummaBlock(void *);
      /** @brief ���������� */
      virtual ~SummaBlock() override;
      /** @brief �������������� �������� ��������� ������ */
      virtual NATIVEINT infoFunc(int Action, NATIVEINT aParameter) override final;
      /** @brief �������� ��� � ������������� ��������� - �� ��������� ������������ ������ ���������, ��� - ������������; Result = - 1 - �������� �� ������ */
      virtual NATIVEINT getParamID(const std::string& paramName, TDataType& dataType, bool& isConst);
      /** @brief ������� ��� ����������� ��������� ���������� ���������� ����� */
      virtual void editFunc() override final;
      /** @brief RUN-������� ����� */
      virtual NATIVEINT run(double& at, double& h, EWorkState workState) override final;
    };
  }
}



