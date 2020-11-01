#pragma once

#include <mutex>
#include <queue>

#include "UConstants.h"

/** @class ULogger 
  * @brief �������� ��� ������ ���������� ���������� */
class ULogger
{
  static ULogger* m_logger; ///< @brief �������� ������
  static std::mutex m_mutex; ///< @brief ��� ����������� ������ � ���������� �������

  ELogLevel m_logLevel = LLInfo; ///< @brief �������� ������� ����������
  std::queue<TLoggerData> m_datas;  ///< @brief ������ �� ��������
  /** @brief ����������� ��������, ��� ������ ���� ������� */
  explicit ULogger();
public:
  /** @brief �������� ����������� ����������� */
  ULogger(ULogger& other) = delete;
  /** @brief �������� ������ ����� ���������� */
  void operator=(const ULogger&) = delete;
  /** @brief ���������� ��������� �� ������ */
  static ULogger* instance();
  /** @brief �������� ��� ������������� */
  static void reset();

  //----- ������� ������ -----
  /** @brief ������ ������� ������ �������������� */
  void setLevel(ELogLevel level) { m_logLevel = level; }
  /** @brief ���������� ��������� ���������
    * @return ���������� ���������� ������ */
  int last(TLoggerData & data);
  /** @brief ����� ���������� */
  void info(const std::string & text);
  /** @brief ����� �������������� */
  void warning(const std::string& text);
  /** @brief ����� ������ */
  void error(const std::string& text);
  /** @brief ����� �������� ��������� */
  void hidden(const std::string& text);

};

