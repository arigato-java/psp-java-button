/*
 * PSP Software Development Kit - https://github.com/pspdev
 * -----------------------------------------------------------------------
 * Licensed under the BSD license, see LICENSE in PSPSDK root for details.
 *
 * main.c - Basic Input demo -- reads from control pad and indicates button
 *          presses.
 *
 * Copyright (c) 2005 Marcus R. Brown <mrbrown@ocgnet.org>
 * Copyright (c) 2005 James Forshaw <tyranid@gmail.com>
 * Copyright (c) 2005 John Kelley <ps2dev@kelley.ca>
 * Copyright (c) 2005 Donour Sizemore <donour@uchicago.edu>
 *
 */
#include <dxlibp.h>
#include <pspctrl.h>
#include <pspdebug.h>
#include <pspkernel.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

PSP_MODULE_INFO("JAVA_BUTTON", 0, 1, 1);
PSP_MAIN_THREAD_ATTR(THREAD_ATTR_USER | THREAD_ATTR_VFPU);

void dump_threadstatus(void);
void screen_setting(void);

int done = 0;

/* Exit callback */
int exit_callback(int arg1, int arg2, void *common) {
  done = 1;
  return 0;
}

/* Callback thread */
int CallbackThread(SceSize args, void *argp) {
  int cbid;

  cbid = sceKernelCreateCallback("Exit Callback", exit_callback, NULL);
  sceKernelRegisterExitCallback(cbid);
  sceKernelSleepThreadCB();

  return 0;
}

/* Sets up the callback thread and returns its thread id */
int SetupCallbacks(void) {
  int thid = 0;

  thid =
      sceKernelCreateThread("update_thread", CallbackThread, 0x11, 0xFA0, 0, 0);
  if (thid >= 0) {
    sceKernelStartThread(thid, 0, 0);
  }

  return thid;
}

// カーソルの初期座標
int cursor_x = 350;
int cursor_y = 240;
int cursor_move = 5;
int button_x = (480 - 160) / 2;
int java = 19;

void error(int index) {
  ClearDrawScreen();
  DrawString(0, 0, "Asset Error!", DXP_COLOR_WHITE, DXP_COLOR_WHITE);
  DrawString(0, 20, "アセットファイルが不足しています。", DXP_COLOR_WHITE,
             DXP_COLOR_WHITE);
  DrawString(0, 40, "本ソフトウェアは10秒後に終了します。", DXP_COLOR_WHITE,
             DXP_COLOR_WHITE);
  DrawFormatString(0, 60, DXP_COLOR_WHITE, "%d", index);
  ScreenFlip();
  Sleep(10000);
  DxLib_End();
}

int main() {
  SetupCallbacks();
  DxLib_Init();
  ChangeRandMode(DXP_RANDMODE_HW);
  SetCreateSoundDataType(DX_SOUNDDATATYPE_FILE);
  screen_setting();
  /*
    ロード
  */
  ClearDrawScreen();
  int happy_java = LoadGraph("assets/happy_java.png");
  DrawExtendGraph(150, 50, 480 - 150, 272 - 50, happy_java, TRUE);
  DrawString(300, 230, "Now loading...", DXP_COLOR_WHITE, DXP_COLOR_WHITE);
  ScreenFlip();
  int button_png = LoadGraph("assets/button.png");
  int button_clicked_png = LoadGraph("assets/button_clicked.png");
  int cursor_off_png = LoadGraph("assets/cursor_off.png");
  int cursor_on_png = LoadGraph("assets/cursor_on.png");

  if (button_png == -1 || button_clicked_png == -1 || cursor_off_png == -1 ||
      cursor_on_png == -1) {
    error(-1);
    return 1;
  }
  /*
    メインループ
  */
  int old_state = 0;
  int last_java = -1;
  int sound = 0;
  while (ProcessMessage() != -1) {
    sound = 0;
    ClearDrawScreen();
    /*
      操作
    */
    int state = GetInputState();
    if (state & DXP_INPUT_DOWN) {
      cursor_y += cursor_move;
    }
    if (state & DXP_INPUT_UP) {
      cursor_y -= cursor_move;
    }
    if (state & DXP_INPUT_RIGHT) {
      cursor_x += cursor_move;
    }
    if (state & DXP_INPUT_LEFT) {
      cursor_x -= cursor_move;
    }
    // 壁
    if (cursor_x < 0) {
      cursor_x = 0;
    }
    if (cursor_y < 0) {
      cursor_y = 0;
    }
    if (cursor_x > 470) {
      cursor_x = 470;
    }
    if (cursor_y > 262) {
      cursor_y = 262;
    }

    /*
      背景の描画
    */
    DrawBox(0, 0, 480, 272, DXP_COLOR_WHITE, 1);

    /*
      文字列の描画
    */
    SetFontSize(40);
    // First Line
    int width = GetDrawStringWidth("あなたとJAVA,", sizeof "あなたとJAVA,");
    DrawString((480 - width) / 2, 30, "あなたとJAVA,", DXP_COLOR_BLACK,
               DXP_COLOR_WHITE);
    width = GetDrawStringWidth("今すぐダウンロー", sizeof "今すぐダウンロー");
    DrawString((480 - width) / 2, 80, "今すぐダウンロー", DXP_COLOR_BLACK,
               DXP_COLOR_WHITE);
    width = GetDrawStringWidth("ド", sizeof "ド");
    DrawString((480 - width) / 2, 130, "ド", DXP_COLOR_BLACK, DXP_COLOR_WHITE);

    /*
      カーソルの描画 10x10
      ボタンに被っているときはonを描画する それ以外ではoff
    */
    if (cursor_x >= button_x && cursor_y >= 190 && cursor_x <= button_x + 160 &&
        cursor_y <= 190 + 36) {
      // 丸が押下された際にJavaる
      if (state & DXP_INPUT_CIRCLE) {
        if (!(old_state & DXP_INPUT_CIRCLE)) {
          sound = 1;
        }
        DrawExtendGraph(button_x, 190, button_x + 160, 190 + 36,
                        button_clicked_png, TRUE);
      } else {
        DrawExtendGraph(button_x, 190, button_x + 160, 190 + 36, button_png,
                        TRUE);
      }
      DrawExtendGraph(cursor_x, cursor_y, cursor_x + 10, cursor_y + 10,
                      cursor_on_png, TRUE);
    } else {
      DrawExtendGraph(button_x, 190, button_x + 160, 190 + 36, button_png,
                      TRUE);
      DrawExtendGraph(cursor_x, cursor_y, cursor_x + 10, cursor_y + 10,
                      cursor_off_png, TRUE);
    }
    old_state = state;
    ScreenFlip();
    if (sound == 1) {
      int index = GetRand(java - 1) + 1;
      char filename[256];
      sprintf(filename, "assets/JAVA_%d.mp3", index);
      if (last_java != -1) {
        StopSoundMem(last_java);
        DeleteSoundMem(last_java);
      }
      int javaHandle = LoadSoundMem(filename);
      PlaySoundMem(javaHandle, DX_PLAYTYPE_BACK, 1);
      last_java = javaHandle;
    }
  }
  DxLib_End();
  return 0;
}
