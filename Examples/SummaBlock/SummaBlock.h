#pragma once
#include "BlockInterface.h"

namespace cppobj
{
  namespace cppobjsum
  {
    class SummaBlock : public BlockInterface
    {
    public:
      /** @brief ����������� */
      explicit SummaBlock();
      /** @brief ���������� */
      virtual ~SummaBlock() override;
      /** @brief �������������� �������� ��������� ������ */
      virtual NATIVEINT infoFunc(int Action, NATIVEINT aParameter) override final;
    };
  }
}



