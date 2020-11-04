#pragma once

namespace cppobj
{
  class UPtrExtArray
  {
    void* m_object = nullptr; ///< @brief ��������� �� ������ TPtrExtArray (Delphi)
  public:
    /** @brief ����������� */
    explicit UPtrExtArray(void* object);
    /** @brief ���������� */
    virtual ~UPtrExtArray();
    /** @brief ���������� ����������� ������ 
      * @param channel ����� (��������, ����) 
      * @param index ����� ������� � ������ (���� ������ ��������, �� ������������ ���������� std::out_of_range) */
    double& data(unsigned int channel, int index);
  };

}
