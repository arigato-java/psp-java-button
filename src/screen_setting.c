#include "dxlibp.h"

void screen_setting() {
  SetDisplayFormat(DXP_FMT_8888);  //画面のピクセルフォーマットを32Bit色モードに
  SetWaitVSyncFlag(TRUE);  // 画面更新の際、垂直同期待ちをしてから行なう様に
  SetDrawArea(0, 0, 480, 272);  // 描画可能領域を全領域に設定
  SetDrawMode(DX_DRAWMODE_NEAREST);  // 描画モードを高速なNEARESTにセットする
  // ↓ 描画の際のブレンドモードを、標準モードに
  SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
  SetDrawBright(255, 255, 255);          // 描画する色の輝度を最大に
  SetGraphMode(480, 272, DXP_FMT_8888);  // フル画面サイズ ＆ 32Bit色モード
  ClearDrawScreen();  // 描画先のグラフィックスをクリアする
  ChangeFont("jpn0.pgf", DXP_CP_UTF8);
  ChangeFontType(DX_FONTTYPE_NORMAL);
  SetCodepoint(DXP_CP_UTF8);
}
