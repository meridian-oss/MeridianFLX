# src フォルダ構成

このフォルダには、各ボード向けのテンプレートコードが格納されています。

## ディレクトリ構成

### Meridian LITE

ホビーロボット向けの軽量な実装です。主にシングルCPUで動作します。

- **Meridian_LITE_ESP32/** - ESP32 用テンプレート
- **Meridian_LITE_M5StackAtomLite/** - M5Stack Atom Lite 用テンプレート
- **Meridian_LITE_M5StackAtomS3/** - M5Stack Atom S3 用テンプレート
- **Meridian_Lite_RaspberryPiPico/** - Raspberry Pi Pico 用テンプレート

### Meridian TWIN

複数CPU構成による双CPU制御システムです。高度な制御が必要な場合に使用します。

- **Meridian_TWIN_ESP32/** - 2つの ESP32 を使用した構成用テンプレート
- **Meridian_TWIN_Teensy/** - Teensy 4.0 + ESP32 を使用した構成用テンプレート

## ファイル構成

各ボード用フォルダには以下のファイルが含まれています：

- `main_*.cpp` - メインプログラムファイル
- `app_*.hpp` - アプリケーション実装ファイル
- `board_*.hpp` - ボード固有の設定ファイル
- `meridian_network_keys.hpp` - ネットワークキー定義
- `meridian_parameter.hpp` - パラメータ設定ファイル

## 役割分担

- **src/（このフォルダ）** - 各ボード用のテンプレートコード（スタートポイント）
- **lib_extra/Meridian/** - CPU/プラットフォーム別の実装コア（共有ライブラリ）
- **lib/** - サードパーティーライブラリの格納（Arduino互換ライブラリなど）

新規開発の際は、対象ボードに対応するテンプレートフォルダをコピーして利用してください。
