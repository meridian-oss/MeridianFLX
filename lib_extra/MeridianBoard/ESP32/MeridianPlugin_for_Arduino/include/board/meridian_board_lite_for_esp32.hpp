/**
 * @file meridian_board_lite_for_esp32.hpp
 * @brief "Meridian Board -Lite- for ESP32"のための定義をまとめたヘッダファイル
 * @version 1.0.0
 * @date 2025-04-27
 * @copyright Copyright (c) 2025 by Meridian Team. All rights reserved.
 * @note MIT LICENSE
 */
#ifndef __MERIDIAN_BOARD_MERIDIAN_BOARD_LITE_FOR_ESP32_HPP__
#define __MERIDIAN_BOARD_MERIDIAN_BOARD_LITE_FOR_ESP32_HPP__
// ヘッダファイルの読み込み
#include "meridian_plugin_settings.hpp"
// ライブラリ導入
#include <Arduino.h>
#include <MeridianCore.hpp>

namespace meridian {
namespace board {

class MeridianBoardLiteForEsp32 : public IMrdBoard {
public:
  class Parameter {
  public:
    int duration_us = 10 * 1000;            // 10ms
    uint64_t timer_section_us = 100 * 1000; // 100ms
    float delay_rate = 0.9;                 // 待機時間の減衰率
  };
  Parameter parameter;

protected:
  /// @brief ループ時の待機処理
  int waiting() override {
    int wait_time_ms = SETTING_DEFAULT_DELAY_TIME_MS;
    delayMicroseconds(wait_time_ms * 1000); // 追加の待機（マイクロ秒単位）
    return wait_time_ms * 1000;
  }
};

} // namespace board
} // namespace meridian

#endif // __MERIDIAN_BOARD_MERIDIAN_BOARD_LITE_FOR_ESP32_HPP__
