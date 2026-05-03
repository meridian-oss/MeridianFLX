/**
 * @file mrd_diagnostic_uart.hpp
 * @brief
 * @version 1.0.0
 * @date 2025-01-24
 *
 * @copyright Copyright (c) 2025-.
 *
 */
#ifndef __MERIDIAN_COMMUNICATION_MRD_DIAGNOSTIC_UART_HPP__
#define __MERIDIAN_COMMUNICATION_MRD_DIAGNOSTIC_UART_HPP__
// ヘッダファイルの読み込み
// ライブラリ導入
#include <Arduino.h>
#include <MeridianCore.hpp>

namespace meridian {
namespace communication {

class MrdDiagnosticUart : public IMrdDiagnostic {
public:
  /// @brief コンストラクタ
  MrdDiagnosticUart(HardwareSerial *a_serial, uint32_t a_baudrate = 115200) {
    this->disable();
    this->_serial = a_serial;
    this->_baudrate = a_baudrate;
  }

public:
  const char *get_category() override { return "Conversation/Diagnostic"; }
  /// @brief 区別させるための名前
  const char *get_name() override { return "UART"; }

protected:
  /// @brief 初期化を実行する
  bool setup() override {
    if (nullptr != this->_serial) {
      this->_serial->begin(this->_baudrate);
      this->enable();
      return true;
    }
    return false;
  }

  /// @brief メッセージを出力
  size_t message(OUTPUT_LOG_LEVEL a_level, bool a_newline, const char *a_message) override {
    if (nullptr != this->_serial) {
      char data[255] = {0};
      if (OUTPUT_LOG_LEVEL::LEVEL_OPERATIONAL == a_level) {
        snprintf(data, sizeof(data), "%s%s", a_message, a_newline ? "\n" : "");
        return this->_serial->write(data, strlen(data));
      } else {
#if DEBUG_MERIDIAN_CORE
        snprintf(data, sizeof(data), "[%9.3f][%s] %s%s", millis() / 1000.0f, this->get_text_level(a_level), a_message, a_newline ? "\n" : "");
        return this->_serial->write(data, strlen(data));
#else
        snprintf(data, sizeof(data), "[%s] %s%s", this->get_text_level(a_level), a_message, a_newline ? "\n" : "");
        return this->_serial->write(data, strlen(data));
#endif
      }
    }
    return 0;
  }

private:
  HardwareSerial *_serial;     ///! シリアルポート
  uint32_t _baudrate = 115200; ///! ボーレート
};

} // namespace communication
} // namespace meridian

#endif // __MERIDIAN_COMMUNICATION_MRD_DIAGNOSTIC_UART_HPP__
