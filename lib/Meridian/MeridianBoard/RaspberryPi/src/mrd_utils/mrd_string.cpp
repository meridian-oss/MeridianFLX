/**
 * @file mrd_string.cpp
 * @brief
 * @version 1.0.0
 * @date 2025-05-11
 *
 * @copyright Copyright (c) 2025
 *
 */
#include "mrd_utils/mrd_string.hpp"

#include <Arduino.h>

#ifndef MRD_UTIL_BUFFER_SIZE
#define MRD_UTIL_BUFFER_SIZE 128
#endif

namespace meridian {

String mrd_time_to_string(int unixTime) {
  // UnixTimeが指定している`MERIDIAN_BUILD_TIME`をyyyy/mm/dd hh:mm:ss形式に変換する
  time_t buildTime = (time_t)unixTime; // MERIDIAN_BUILD_TIMEはUnixTime形式で定義されていると仮定
  struct tm *timeInfo = gmtime(&buildTime);
  char formattedTime[100];
  snprintf(formattedTime, sizeof(formattedTime), "%04d/%02d/%02d %02d:%02d:%02d",
           (timeInfo->tm_year + 1900), // yy
           timeInfo->tm_mon + 1,       // mm
           timeInfo->tm_mday,          // dd
           timeInfo->tm_hour,          // hh
           timeInfo->tm_min,           // mm
           timeInfo->tm_sec);          // ss
  return String(formattedTime);
}

/// @brief フォーマットされた文字列を返す
String mrd_format(const char *format, ...) {
  char loc_buf[MRD_UTIL_BUFFER_SIZE];

  __builtin_va_list args;
  __builtin_va_start(args, format);
  vsnprintf(loc_buf, sizeof(loc_buf), format, args);
  __builtin_va_end(args);

  return String(loc_buf);
}

} // namespace meridian
