/**
 * @file dxlibp.h
 * @mainpage

 * DXライブラリPortable @n
 * Ver0.5.7@n
 * 製作者：憂煉@n
 * このライブラリを使う際にこのライブラリの著作権表記は要りませんが、このライブラリが依存しているライブラリの著作権表記は行う必要があります。@n
 * また、このライブラリのソースコードの一部または全部を転載、引用、公開などする場合はこのライブラリの著作権表記が必要です。@n
 * 詳しくはreadme.txtを読んでください。@n
 * 説明に（本家互換）とある関数はDXライブラリと挙動がほぼ同じですので、本家の関数リファレンスも参考にしてください。
*/
#ifndef DXLIBP_H__
#define DXLIBP_H__

#include <pspuser.h>

/*DXPのコンパイルオプション*/
#define DXP_BUILDOPTION_FILEHANDLE_MAX		32		//FileRead系関数で同時に開けるファイルハンドルの数
#define DXP_BUILDOPTION_FILENAMELENGTH_MAX	260		//FileRead系関数で使えるファイル名の長さ
#define DXP_BUILDOPTION_TEXTURE_MAXNUM		512		//DXPが内部で持つテクスチャの最大枚数
#define DXP_BUILDOPTION_GHANDLE_MAXNUM		2048	//グラフィックスハンドルの最大数
#define DXP_BUILDOPTION_MODEL_MAXNUM		16		//3Dモデルの最大数
#define DXP_BUILDOPTION_FONTHANDLE_MAX		8

#define DXP_BUILDOPTION_NO3D						//3D機能の無効化。これをコメントアウトした場合、実装途中の3D関数が使用可能になりますが、libpspgumへの依存が発生します。

/*---定数とマクロ---*/

#define RUNCHECK {printfDx("%s,%s,%s,%d\n",__TIME__,__FILE__,__func__,__LINE__);ScreenCopy();/*AppLogAdd("%s,%s,%s,%d\n",__TIME__,__FILE__,__func__,__LINE__);*/}
#define FILETRACE {AppLogAdd("%s,%s,%s,%d\n",__TIME__,__FILE__,__func__,__LINE__);}

#ifndef	TRUE
#define	TRUE	(1)
#endif
#ifndef	FALSE
#define	FALSE	(0)
#endif
#ifndef	LONGLONG
#define LONGLONG u64
#endif


/*Windowsの定義をすこし流用*/
#define	BYTE	u8
#define	WORD	u16
#define	DWORD	u32

/* 文字コード定義 */
#define DXP_CP_SJIS			(0x0d)
#define DXP_CP_UTF8			(0xff)

/* PSPのボタン定義 */
#define DXP_INPUT_UP		(0x00000010)
#define DXP_INPUT_RIGHT		(0x00000020)
#define DXP_INPUT_DOWN		(0x00000040)
#define DXP_INPUT_LEFT		(0x00000080)
#define DXP_INPUT_TRIANGLE	(0x00001000)
#define DXP_INPUT_CIRCLE	(0x00002000)
#define DXP_INPUT_CROSS		(0x00004000)
#define DXP_INPUT_SQUARE	(0x00008000)
#define DXP_INPUT_LTRIGGER	(0x00000100)
#define DXP_INPUT_RTRIGGER	(0x00000200)
#define DXP_INPUT_START		(0x00000008)
#define DXP_INPUT_SELECT	(0x00000001)

/* ゲームパッド定義 */
#define DX_INPUT_PAD1								(1)	/* PSPの入力はPAD1入力として取得することができます。詳しくは本家ライブラリのマニュアルを参照してください。 */
#define DX_INPUT_PAD2								(0)
#define DX_INPUT_PAD3								(0)
#define DX_INPUT_PAD4								(0)
#define DX_INPUT_PAD5								(0)
#define DX_INPUT_PAD6								(0)
#define DX_INPUT_PAD7								(0)
#define DX_INPUT_PAD8								(0)
#define DX_INPUT_KEY								(0)
#define DX_INPUT_KEY_PAD1							(1)

/* ゲームパッドのボタン定義 */
#define PAD_INPUT_DOWN								(0x00000001)
#define PAD_INPUT_LEFT								(0x00000002)
#define PAD_INPUT_RIGHT								(0x00000004)
#define PAD_INPUT_UP								(0x00000008)
#define PAD_INPUT_A									(0x00000010)
#define PAD_INPUT_B									(0x00000020)
#define PAD_INPUT_C									(0x00000040)
#define PAD_INPUT_X									(0x00000080)
#define PAD_INPUT_Y									(0x00000100)
#define PAD_INPUT_Z									(0x00000200)
#define PAD_INPUT_L									(0x00000400)
#define PAD_INPUT_R									(0x00000800)
#define PAD_INPUT_START								(0x00001000)
#define PAD_INPUT_M									(0x00002000)
#define PAD_INPUT_D									(0x00004000)
#define PAD_INPUT_F									(0x00008000)
#define PAD_INPUT_G									(0x00010000)
#define PAD_INPUT_H									(0x00020000)
#define PAD_INPUT_I									(0x00040000)
#define PAD_INPUT_J									(0x00080000)
#define PAD_INPUT_K									(0x00100000)
#define PAD_INPUT_LL								(0x00200000)
#define PAD_INPUT_N									(0x00400000)
#define PAD_INPUT_O									(0x00800000)
#define PAD_INPUT_P									(0x01000000)
#define PAD_INPUT_RR								(0x02000000)
#define PAD_INPUT_S									(0x04000000)
#define PAD_INPUT_T									(0x08000000)
#define PAD_INPUT_U									(0x10000000)
#define PAD_INPUT_V									(0x20000000)
#define PAD_INPUT_W									(0x40000000)
#define PAD_INPUT_XX								(0x80000000)


/*
 * キー定義
 * PSPのボタン入力をキーボード入力として扱うことができます。詳しくは本家ライブラリのマニュアルを参照してください。
*/
#define KEY_INPUT_BACK								(0x0E)
#define KEY_INPUT_TAB								(0x0F)
#define KEY_INPUT_RETURN							(0x1C)

#define KEY_INPUT_LSHIFT							(0x2A)
#define KEY_INPUT_RSHIFT							(0x36)
#define KEY_INPUT_LCONTROL							(0x1D)
#define KEY_INPUT_RCONTROL							(0x9D)
#define KEY_INPUT_ESCAPE							(0x01)
#define KEY_INPUT_SPACE								(0x39)
#define KEY_INPUT_PGUP								(0xC9)
#define KEY_INPUT_PGDN								(0xD1)
#define KEY_INPUT_END								(0xCF)
#define KEY_INPUT_HOME								(0xC7)
#define KEY_INPUT_LEFT								(0xCB)
#define KEY_INPUT_UP								(0xC8)
#define KEY_INPUT_RIGHT								(0xCD)
#define KEY_INPUT_DOWN								(0xD0)
#define KEY_INPUT_INSERT							(0xD2)
#define KEY_INPUT_DELETE							(0xD3)

#define KEY_INPUT_MINUS								(0x0C)
#define KEY_INPUT_YEN								(0x7D)
#define KEY_INPUT_PREVTRACK							(0x90)
#define KEY_INPUT_PERIOD							(0x34)
#define KEY_INPUT_SLASH								(0x35)
#define KEY_INPUT_LALT								(0x38)
#define KEY_INPUT_RALT								(0xB8)
#define KEY_INPUT_SCROLL							(0x46)
#define KEY_INPUT_SEMICOLON							(0x27)
#define KEY_INPUT_COLON								(0x92)
#define KEY_INPUT_LBRACKET							(0x1A)
#define KEY_INPUT_RBRACKET							(0x1B)
#define KEY_INPUT_AT								(0x91)
#define KEY_INPUT_BACKSLASH							(0x2B)
#define KEY_INPUT_COMMA								(0x33)
#define KEY_INPUT_CAPSLOCK							(0x3A)
#define KEY_INPUT_SYSRQ								(0xB7)
#define KEY_INPUT_PAUSE								(0xC5)

#define KEY_INPUT_NUMPAD0							(0x52)
#define KEY_INPUT_NUMPAD1							(0x4F)
#define KEY_INPUT_NUMPAD2							(0x50)
#define KEY_INPUT_NUMPAD3							(0x51)
#define KEY_INPUT_NUMPAD4							(0x4B)
#define KEY_INPUT_NUMPAD5							(0x4C)
#define KEY_INPUT_NUMPAD6							(0x4D)
#define KEY_INPUT_NUMPAD7							(0x47)
#define KEY_INPUT_NUMPAD8							(0x48)
#define KEY_INPUT_NUMPAD9							(0x49)
#define KEY_INPUT_MULTIPLY							(0x37)
#define KEY_INPUT_ADD								(0x4E)
#define KEY_INPUT_SUBTRACT							(0x4A)
#define KEY_INPUT_DECIMAL							(0x53)
#define KEY_INPUT_DIVIDE							(0xB5)
#define KEY_INPUT_NUMPADENTER						(0x9C)

#define KEY_INPUT_F1								(0x3B)
#define KEY_INPUT_F2								(0x3C)
#define KEY_INPUT_F3								(0x3D)
#define KEY_INPUT_F4								(0x3E)
#define KEY_INPUT_F5								(0x3F)
#define KEY_INPUT_F6								(0x40)
#define KEY_INPUT_F7								(0x41)
#define KEY_INPUT_F8								(0x42)
#define KEY_INPUT_F9								(0x43)
#define KEY_INPUT_F10								(0x44)
#define KEY_INPUT_F11								(0x57)
#define KEY_INPUT_F12								(0x58)

#define KEY_INPUT_A									(0x1E)
#define KEY_INPUT_B									(0x30)
#define KEY_INPUT_C									(0x2E)
#define KEY_INPUT_D									(0x20)
#define KEY_INPUT_E									(0x12)
#define KEY_INPUT_F									(0x21)
#define KEY_INPUT_G									(0x22)
#define KEY_INPUT_H									(0x23)
#define KEY_INPUT_I									(0x17)
#define KEY_INPUT_J									(0x24)
#define KEY_INPUT_K									(0x25)
#define KEY_INPUT_L									(0x26)
#define KEY_INPUT_M									(0x32)
#define KEY_INPUT_N									(0x31)
#define KEY_INPUT_O									(0x18)
#define KEY_INPUT_P									(0x19)
#define KEY_INPUT_Q									(0x10)
#define KEY_INPUT_R									(0x13)
#define KEY_INPUT_S									(0x1F)
#define KEY_INPUT_T									(0x14)
#define KEY_INPUT_U									(0x16)
#define KEY_INPUT_V									(0x2F)
#define KEY_INPUT_W									(0x11)
#define KEY_INPUT_X									(0x2D)
#define KEY_INPUT_Y									(0x15)
#define KEY_INPUT_Z									(0x2C)

#define KEY_INPUT_0 								(0x0B)
#define KEY_INPUT_1									(0x02)
#define KEY_INPUT_2									(0x03)
#define KEY_INPUT_3									(0x04)
#define KEY_INPUT_4									(0x05)
#define KEY_INPUT_5									(0x06)
#define KEY_INPUT_6									(0x07)
#define KEY_INPUT_7									(0x08)
#define KEY_INPUT_8									(0x09)
#define KEY_INPUT_9									(0x0A)


/*オンスクリーンキーボードのモード指定*/
#define	DXP_OSK_ALL			(0x00000000)	//全て
#define	DXP_OSK_DIGIT		(0x00000001)	//半角数字
#define	DXP_OSK_SYMBOL		(0x00000002)	//半角記号
#define	DXP_OSK_SMALL		(0x00000004)	//半角小文字
#define	DXP_OSK_LARGE		(0x00000008)	//半角大文字
#define	DXP_OSK_DIGIT2		(0x00000100)	//全角数字
#define	DXP_OSK_SYMBOL2		(0x00000200)	//全角記号
#define	DXP_OSK_SMALL2		(0x00000400)	//全角小文字
#define	DXP_OSK_LARGE2		(0x00000800)	//全角大文字
#define	DXP_OSK_HIRAGANA	(0x00001000)	//ひらがな
#define	DXP_OSK_KATAKANA_H	(0x00002000)	//半角カタカナ
#define	DXP_OSK_KATAKANA	(0x00004000)	//全角カタカナ
#define	DXP_OSK_KANJI		(0x00008000)	//漢字
#define	DXP_OSK_URL			(0x00080000)	//URL入力支援


/* 乱数生成方法の定義。SetRandMode関数に渡します。 */
#define DXP_RANDMODE_MT	(0)	//メルセンヌ・ツイスター方式の乱数生成器を使います。おそらく、本家との互換性があります。
#define DXP_RANDMODE_HW	(1)	//PSPのハードウェアの乱数生成器を使います。高速です。

/* ちょっとした色の定数 */
#define DXP_COLOR_NONE		0x00000000
#define DXP_COLOR_BLACK		0xff000000
#define DXP_COLOR_RED 		0xff0000ff
#define DXP_COLOR_GREEN		0xff00ff00
#define DXP_COLOR_BLUE		0xffff0000
#define DXP_COLOR_WHITE		0xffffffff
#define DXP_COLOR_LITEGRAY	0xffbfbfbf
#define DXP_COLOR_GRAY		0xff7f7f7f
#define DXP_COLOR_DARKGRAY	0xff3f3f3f

/* フォント周り */
#define DXP_FONT_ALIGN_LEFT		0x0000		//左寄せ
#define DXP_FONT_ALIGN_CENTER	0x0200		//中央
#define DXP_FONT_ALIGN_RIGHT	0x0400		//右寄せ
#define DXP_FONT_WIDTH_FIX		0x0800		//等幅指定用
#define DXP_FONT_ALIGN_DEFAULT	(DXP_FONT_ALIGN_LEFT)
#define DXP_FONT_DEFAULT_SIZE	16

#define DX_FONTTYPE_NORMAL				0 
#define DX_FONTTYPE_EDGE				1 
#define DX_FONTTYPE_ANTIALIASING		2
#define DX_FONTTYPE_ANTIALIASING_EDGE	3

/*描画*/
#define DX_SCREEN_BACK		0xfffffffe
/*グラフィックのフォーマット定義*/
#define DXP_FMT_5650		(0)	/* テクスチャ、パレット、描画先*/
#define DXP_FMT_5551		(1)	/* テクスチャ、パレット、描画先*/
#define DXP_FMT_4444		(2)	/* テクスチャ、パレット、描画先*/
#define DXP_FMT_8888		(3)	/* テクスチャ、パレット、描画先*/
#define DXP_FMT_T4			(4) /* テクスチャのみ */
#define DXP_FMT_T8			(5) /* テクスチャのみ */
//#define DXP_FMT_DXT1		(8) /* テクスチャのみ */
//#define DXP_FMT_DXT3		(9) /* テクスチャのみ */
//#define DXP_FMT_DXT5		(10)/* テクスチャのみ */

/*描画モード定義*/
#define DX_DRAWMODE_NEAREST		0
#define DX_DRAWMODE_BILINEAR	1

/* 描画ブレンドモード定義 */
#define DX_BLENDMODE_NOBLEND						(0)				/* ノーブレンド*/
#define DX_BLENDMODE_ALPHA							(1)				/* αブレンド*/
#define DX_BLENDMODE_ADD							(2)				/* 加算ブレンド*/
#define DX_BLENDMODE_SUB							(3)				/* 減算ブレンド*/
#define DX_BLENDMODE_MUL							(4)				/* 乗算ブレンド*/
#define DX_BLENDMODE_DESTCOLOR						(8)				/* カラーは更新されない*/
#define DX_BLENDMODE_INVDESTCOLOR					(9)				/* 描画先の色の反転値を掛ける*/
#define DX_BLENDMODE_INVSRC							(10)			/* 描画元の色を反転する*/
/*#define DX_BLENDMODE_MULA							(11)		*/
	/* アルファチャンネル考慮付き乗算ブレンドはPSPの制限で実装できませんでした＞＜。*/

/* SetGraphModeの戻り値 */
#define DX_CHANGESCREEN_OK							(0)					// 画面変更は成功した
#define DX_CHANGESCREEN_RETURN						(-1)				// 画面の変更は失敗し、元の画面モードに戻された

/* 再生タイプ */
#define DX_PLAYTYPE_NORMAL	0
#define DX_PLAYTYPE_BACK	1
#define DX_PLAYTYPE_LOOP	3

/* 音楽 */
#define DX_SOUNDDATATYPE_MEMNOPRESS					(0)
//#define DX_SOUNDDATATYPE_MEMPRESS					(1)
#define DX_SOUNDDATATYPE_FILE						(3)


/* 構造体定義 */
typedef struct DATEDATA__
{
	int Year;
	int Mon;
	int Day;
	int Hour;
	int Min;
	int Sec;
}DATEDATA;


typedef ScePspFVector3 VECTOR;

typedef struct MATRIX
{
	union
	{
		float m[4][4];
		ScePspFMatrix4 pspm;
	};
}MATRIX;

typedef struct QUATERNION
{
	float x;
	float y;
	float z;
	float w;
}QUATERNION;

typedef struct COLOR_U8
{
	union
	{
		u32 code;
		struct
		{
			u8 r;
			u8 g;
			u8 b;
			u8 a;
		};
	};
}COLOR_U8;

typedef struct COLOR_F
{
	float r,g,b,a;
}COLOR_F;

typedef struct VERTEX3D
{
	// テクスチャ座標
	float u, v ;

	// ディフューズカラー
	COLOR_U8 dif ;

	// 法線
	VECTOR norm ;

	// 座標
	VECTOR pos ;
} VERTEX3D;



#ifdef	__cplusplus
#define	DXPDEFARG(ARG)	=(ARG)		/* C++言語のデフォルト引数を指定するためのマクロ */
extern "C" {
#else
#define	DXPDEFARG(ARG)
#endif

/** @defgroup 使用必須関数*/
/*@{*/
/**
 * ライブラリの初期化(本家互換)
 * 
 * DXPを使用可能な状態に初期化します。DXPを使用するソフトウェアはまずこの 関数を呼び出す必要があります。この関数を使ってもし-1（エラー）が返ってきた場合は直ちに ソフトを終了しなければなりません。
 * @retval 0 成功
 * @retval -1 失敗
 */
int DxLib_Init(void);
/**
 * ライブラリ使用の終了関数(本家互換)
 * 
 * DXPの使用を終了する関数です。DXPを使用しているソフトはすべてソフトを 終了させる前にこの関数を呼ぶ必要があります。
 * @retval 0 成功
 * @retval -1 失敗
 */
int DxLib_End(void);
/**
 * ライブラリが初期化済みかどうか調べる(本家互換)
 * 
 * DXPが初期化済みかどうかを取得します。
 * @retval 1 初期化済み
 * @retval 0 未初期化
*/
int DxLib_Isinit(void);
/**
 * 毎フレーム必要な処理を行う(本家互換)
 * 
 * ボタン入力状況の更新等を行います。ユーザーがHOMEボタンによる終了を行ったとき等、ゲームを終了すべき時に-1が返されます。
 * @retval 0 成功
 * @retval -1 失敗
*/
int ProcessMessage(void);
/*@}*/

/*@defgroup 文字コード関連*/
/*@{*/
/**
 * ライブラリが使う文字コードを変更する
 * 
 * プログラミングの環境によって文字コードが異なるので、その設定をします。OSKや文字列描画等で使われます。
 * 初期設定はSJISです。UTF-8環境の方はDXP_CP_UTF8を指定してください。
 * @retval 0 成功
 * @retval -1 失敗
*/
int SetCodepoint(int codepoint);
/*@}*/

/** @defgroup 時間関係*/
/*@{*/
/**
 * ミリ秒単位の精度を持つカウンタの現在値を得る(本家互換)
 * 
 * RTC(本体内蔵の時計)の値をミリ秒単位であらわした値が返ってきます。
 * @return RTCの値をミリ秒単位であらわした値
*/
int GetNowCount(void);
/**
 * マイクロ秒単位の精度を持つカウンタの現在値を得る(本家互換)
 * 
 * RTC(本体内蔵の時計)の値を返します。この関数の呼び出しに少なくとも30マイクロ秒ほどかかるようです。
 * @return RTCの値
*/
u64 GetNowHiPerformanceCount(void);
/**
 * 現在時刻を取得する(本家互換)
 * 
 * DXライブラリ独自のDATEDATA構造体に現在時刻を格納します。
 * @param datebuf : DXライブラリ独自のDATEDATA構造体へのポインタ
 * @retval 0 成功 
 * @retval -1 失敗
*/
int GetDateTime(DATEDATA *datebuf);
/**
 * 指定時間だけ処理を止める
 * 
 * Win32APIのSleep関数と同じです。
 * @param ms ミリ秒単位で処理を止める時間を指定します。
*/
void Sleep(int ms);
/*@}*/

/** @defgroup 乱数取得関数*/
/*@{*/
int SRand(int seed);							/**<本家互換関数*/
/**
 * 乱数を取得する(本家互換)
 * 
 * 乱数を得ます。この関数は0からmaxで指定した数値のどれかの数値を返します。
 * @param max 取得する乱数の最大値。
 * @return 0からmaxで指定した数値のどれかの数値。
**/
int GetRand(int max);
/**
 * 乱数生成器を変更する関数(DXP独自)
 * 
 * GetRandを実行したときに使われる乱数生成器を指定します。エラーが発生した場合、DXP_RANDMODE_HWが設定されます。デフォルトの設定はDXP_RANDMODE_MTです。
 * @par 指定可能な引数:
 * - DXP_RANDMODE_MT - メルセンヌ・ツイスター方式の乱数生成器を使います。おそらく、本家との互換性があります。低速です。
 * - DXP_RANDMODE_HW - PSPのハードウェアの乱数生成器を使います。高速です。
 * @param mode - 乱数生成器を指定します。
 * @retval 0 成功
 * @retval -1 失敗
**/
int ChangeRandMode(int mode);
/*@}*/
/** @defgroup PSP本体制御関連*/
/*@{*/
/**
 * PSPのCPUクロックを変更する
 * 
 * CPUのクロックを変更します。バスクロックは設定された数値の半分に設定されます。
 * 1〜333以外の値が指定された場合は単にCPUクロックを返すだけの動作になります。
 * @param freq 設定するクロック
 * @return 関数が呼ばれた時点でのCPUクロック
*/
int ChangeCpuSpeed(int freq);
/*@}*/

/** @defgroup 算術関連*/
/*@{*/

static inline VECTOR VGet(float x,float y,float z){VECTOR res = {x,y,z};return res;}
/**
 * 二つのベクトルを足し算します。
 *
 * @param v1 足されるベクトル
 * @param v2 足すベクトル
 * @return ベクトル同士を足した結果
*/
static inline VECTOR VAdd(VECTOR v1,VECTOR v2){__asm__ volatile ("ulv.q C000,%0\n	ulv.q C010,%1\n	vadd.t C000,C000,C010\n	sv.s S000,0 + %0\n	sv.s S001,4 + %0\n	sv.s S002,8 + %0\n":"+m"(v1):"m"(v2));return v1;}
/**
 * 二つのベクトルを引き算します。
 *
 * @param v1 引かれるベクトル
 * @param v2 引くベクトル
 * @return ベクトル同士を引き算した結果
*/
static inline VECTOR VSub(VECTOR v1,VECTOR v2){__asm__ volatile ("ulv.q C000,%0\n	ulv.q C010,%1\n	vsub.t C000,C000,C010\n	sv.s S000,0 + %0\n	sv.s S001,4 + %0\n	sv.s S002,8 + %0\n":"+m"(v1):"m"(v2));return v1;}
/**
 * 二つのベクトルの内積を計算します
 *
 * @param v1 ベクトル
 * @param v2 ベクトル
 * @return 二つのベクトルの内積
*/
static inline float VDot(VECTOR v1,VECTOR v2){register float res;__asm__ volatile ("ulv.q C000,%1\n	ulv.q C010,%2\n	vdot.t S020,C000,C010\nmfv %0,S020\n":"=r"(res):"m"(v1),"m"(v2));return res;}
/**
 * 二つのベクトルの外積を計算します
 *
 * @param v1 ベクトル
 * @param v2 ベクトル
 * @return 二つのベクトルの外積
*/
static inline VECTOR VCross(VECTOR v1,VECTOR v2){__asm__ volatile ("ulv.q C000,%0\nulv.q C010,%1\nvcrsp.t C000,C000,C010\nsv.s S000,0 + %0\nsv.s S001,4 + %0\nsv.s S002,8 + %0\n":"+m"(v1):"m"(v2));return v1;}
/**
 * ベクトルをスカラー倍します
 *
 * @param v ベクトル
 * @param scale スケーリングの値
 * @return 結果
*/
static inline VECTOR VScale(VECTOR v,float scale){__asm__ volatile ("ulv.q C000,%0\nmtv %1,S010\nvscl.t C000,C000,S010\nsv.s S000,0 + %0\nsv.s S001,4 + %0\nsv.s S002,8 + %0\n":"+m"(v):"r"(scale));return v;}
/**
 * ベクトルの大きさを計算します
 *
 * @param v ベクトル
 * @return ベクトルの大きさ
*/
static inline float VSize(VECTOR v){float res;__asm__ volatile ("ulv.q C000,%1\nvdot.t S010,C000,C000\nvsqrt.s S010,S010\nsv.s %0,S010\n":"=r"(res):"m"(v));return res;}
/**
 * ベクトルの大きさの二乗を計算します
 *
 * @param v ベクトル
 * @return ベクトルの大きさの二乗
*/
static inline float VSquareSize(VECTOR v){register float res;__asm__ volatile("ulv.q C000,%1\nvdot.t S010,C000,C000\nmfv %0,S010\n":"=r"(res):"m"(v));return res;}
/**
 * 正規ベクトル(長さが1となるようなベクトル)を求めます
 *
 * @param v ベクトル
 * @return 正規ベクトル
*/
static inline VECTOR VNorm(VECTOR v){__asm__ volatile("ulv.q C000,%0\nvdot.t S010,C000,C000\nvrsq.s S010,S010\nvscl.t C000,C000,S010\nusv.s S000,0 + %0\nusv.s S001,4 + %0\nusv.s		S002,	8 + %0\n":"+m"(v));return v;}
/**
 * ベクトルを行列で座標変換にかけます。
 *
 * @param v ベクトル
 * @param m 変換行列
 * @return 変換結果
*/
static inline VECTOR VTransform(VECTOR v,MATRIX m){__asm__ volatile("ulv.q C000,%0\nvone.s S003\nulv.q R100,0  + %1\nulv.q R101,16 + %1\nulv.q R102,32 + %1\nulv.q R103,48 + %1\nvtfm4.q C010,M100,C000\nsv.s S010,0 + %0\nsv.s S011,4 + %0\nsv.s S012,8 + %0\n":"+m"(v):"m"(m));return v;}
/**
 * ベクトルを行列で座標変換にかけます。ただし、平行移動を行いません
 *
 * @param v ベクトル
 * @param m 変換行列
 * @return 変換結果
*/
static inline VECTOR VTransformSR(VECTOR v,MATRIX m){__asm__ volatile("ulv.q C000,%0\nulv.q R100,0  + %1\nulv.q R101,16 + %1\nulv.q R102,32 + %1\nulv.q R103,48 + %1\nvtfm3.t C010,M100,C000\nsv.s S010,0 + %0\nsv.s S011,4 + %0\nsv.s S012,8 + %0\n":"+m"(v):"m"(m));return v;}
/**
 * 単位行列を取得します
 *
 * @return 単位行列
*/
static inline MATRIX MGetIdent(){MATRIX m;__asm__ volatile ("vmidt.q M000\nusv.q R000,0 + %0\nusv.q R001,16 + %0\nusv.q R002,32 + %0\nusv.q R003,48 + %0\n":"=m"(m));return m;}
/**
 * 拡大変換行列を取得します
 *
 * @param v XYZそれぞれの軸方向に対する拡大率を表すベクトル
 * @return 拡大変換行列
*/
static inline MATRIX MGetScale(VECTOR v){MATRIX m;__asm__ volatile ("ulv.q R100,%1\nvmov.q R000,R100[x,0,0,0]\nvmov.q R001,R100[0,y,0,0]\nvmov.q R002,R100[0,0,z,0]\nvmov.q R003,R100[0,0,0,1]\nusv.q R000,0  + %0\nusv.q R001,16 + %0\nusv.q R002,32 + %0\nusv.q R003,48 + %0\n":"=m"(m):"m"(v));return m;}
/**
 * 平行移動行列を取得します
 *
 * @param v XYZそれぞれの軸方向に対する移動距離を表すベクトル
 * @return 平行移動行列
*/
static inline MATRIX MGetTranslate(VECTOR v){MATRIX m;__asm__ volatile("ulv.q R100,%1\nvmidt.q M000\nvmov.q R003,R100[x,y,z,1]\nusv.q R000,0  + %0\nusv.q R001,16 + %0\nusv.q R002,32 + %0\nusv.q R003,48 + %0\n":"=m"(m):"m"(v));return m;}
/**
 * X軸回転行列を取得します
 *
 * @param angle X軸に対しての回転角度
 * @return 回転行列
*/
static inline MATRIX MGetRotX(float angle){MATRIX m;__asm__ volatile("mtv %1,S100\nvcst.s S110,VFPU_2_PI\nvmul.s S100,S100,S110\nvmidt.q M000\nvrot.q R001,S100,[0,c,s,0]\nvrot.q R002,S100,[0,-s,c,0]\nusv.q R000,0  + %0\nusv.q R001,16 + %0\nusv.q R002,32 + %0\nusv.q R003,48 + %0\n":"=m"(m):"r"(angle));return m;}
/**
 * Y軸回転行列を取得します
 *
 * @param angle Y軸に対しての回転角度
 * @return 回転行列
*/
static inline MATRIX MGetRotY(float angle){MATRIX m;__asm__ volatile("mtv %1,S100\nvcst.s S110,VFPU_2_PI\nvmul.s S100,S100,S110\nvmidt.q M000\nvrot.q R000,S100,[c,0,-s,0]\nvrot.q R002,S100,[s,0,c,0]\nusv.q R000,0  + %0\nusv.q R001,16 + %0\nusv.q R002,32 + %0\nusv.q R003,48 + %0\n":"=m"(m):"r"(angle));return m;}
/**
 * Z軸回転行列を取得します
 *
 * @param angle Z軸に対しての回転角度
 * @return 回転行列
*/
static inline MATRIX MGetRotZ(float angle){MATRIX m;__asm__ volatile("mtv %1,S100\nvcst.s S110,VFPU_2_PI\nvmul.s S100,S100,S110\nvmidt.q M000\nvrot.q R000,S100,[c,s,0,0]\nvrot.q R001,S100,[-s,c,0,0]\nusv.q R000,0  + %0\nusv.q R001,16 + %0\nusv.q R002,32 + %0\nusv.q R003,48 + %0\n":"=m"(m):"r"(angle));return m;}
/**
 * 任意軸回転行列を取得します
 *
 * @param v 回転軸の方向を指定するベクトル
 * @param angle 指定した軸に対しての回転角度
 * @return 回転行列
*/
static inline MATRIX MGetRotAxis(VECTOR v,float angle){MATRIX m;__asm__ volatile("ulv.q R100,%2\nvdot.t S103,R100,R100\nvrsq.s S103,S103\nvscl.t R100,R100,S103\nmtv %1,S130\nvcst.s S103,VFPU_2_PI\nvmul.s S130,S130,S103\nvrot.p R101,S130,[s,c]\nvocp.s S121,S111\nvscl.t R102,R100,S121\nvmov.q R000,R100[x,y,z,0]\nvmov.q R001,R100[x,y,z,0]\nvmov.q R002,R100[x,y,z,0]\nvmov.q R003,R100[0,0,0,1]\nvscl.t R000,R000,S102\nvscl.t R001,R001,S112\nvscl.t R002,R002,S122\nvmul.t R102,R101[y,x,-x],R100[1,z,y]\nvadd.t R000,R000,R102\nvmul.t R102,R101[-x,y,x],R100[z,1,x]\nvadd.t R001,R001,R102\nvmul.t R102,R101[x,-x,y],R100[y,x,1]\nvadd.t R002,R002,R102\nusv.q R000,0  + %0\nusv.q R001,16 + %0\nusv.q R002,32 + %0\nusv.q R003,48 + %0\n":"=m"(m):"r"(angle),"m"(v));return m;}
/**
 * あるベクトルの方向から別のベクトルの方向に回転する回転行列を取得します
 *
 * ベクトルのなす角が90度を超えていると正しく値を取得できないので注意してください。
 * @param v1 変換元方向のベクトル
 * @param v2 変換先方向のベクトル
 * @return 回転行列
*/
static inline MATRIX MGetRotVec2(VECTOR v1,VECTOR v2){MATRIX m;__asm__ volatile ("ulv.q R000,%1\nulv.q R001,%2\nvdot.t S002,R000,R000\nvdot.t S012,R001,R001\nvrsq.p R002,R002\nvscl.t R000,R000,S002\nvscl.t R001,R001,S012\nvdot.t S002,R000,R001\nvmul.s S012,S002,S002\nvocp.p R022,R002\nvsqrt.s S012,S032\nvcrsp.t R003,R000,R001\nvdot.t S032,R003,R003\nvrsq.s S032,S032\nvscl.t R003,R003,S032\nvscl.t R000,R003,S022\nvmov.q R100,R003[x,y,z,0]\nvmov.q R101,R003[x,y,z,0]\nvmov.q R102,R003[x,y,z,0]\nvmov.q R103,R003[0,0,0,1]\nvscl.t R100,R100,S000\nvscl.t R101,R101,S010\nvscl.t R102,R102,S020\nvmul.t R000,R002[x,y,-y],R003[1,z,y]\nvadd.t R100,R100,R000\nvmul.t R000,R002[-y,x,y],R003[z,1,x]\nvadd.t R101,R101,R000\nvmul.t R000,R002[y,-y,x],R003[y,x,1]\nvadd.t R102,R102,R000\nusv.q R100,0  + %0\nusv.q R101,16 + %0\nusv.q R102,32 + %0\nusv.q R103,48 + %0\n":"=m"(m):"m"(v1),"m"(v2));return m;}
/**
 * 指定の座標系のベクトルを基本座標系上のベクトルに直す変換行列を取得します
 *
 * @param xAxis 変換元座標系のX軸方向を表すベクトル
 * @param yAxis 変換元座標系のY軸方向を表すベクトル
 * @param zAxis 変換元座標系のZ軸方向を表すベクトル
 * @param pos 変換元座標系の原点の基本座標系での位置
 * @return 変換行列
*/
static inline MATRIX MGetAxis1(VECTOR xAxis,VECTOR yAxis,VECTOR zAxis,VECTOR pos){MATRIX m;m.m[0][0] = xAxis.x;m.m[0][1] = xAxis.y;m.m[0][2] = xAxis.z;m.m[0][3] = 0.0f;m.m[1][0] = yAxis.x;m.m[1][1] = yAxis.y;m.m[1][2] = yAxis.z;m.m[1][3] = 0.0f;m.m[2][0] = zAxis.x;m.m[2][1] = zAxis.y;m.m[2][2] = zAxis.z;m.m[2][3] = 0.0f;m.m[3][0] = pos.x;m.m[3][1] = pos.y;m.m[3][2] = pos.z;m.m[3][3] = 1.0f;return m;}
/**
 * 基本座標系のベクトルを指定の座標系上のベクトルに直す変換行列を取得します
 *
 * @param xAxis 変換先座標系のX軸方向を表すベクトル
 * @param yAxis 変換先座標系のY軸方向を表すベクトル
 * @param zAxis 変換先座標系のZ軸方向を表すベクトル
 * @param pos 変換先座標系の原点の基本座標系での位置
 * @return 変換行列
*/
static inline MATRIX MGetAxis2(VECTOR xAxis,VECTOR yAxis,VECTOR zAxis,VECTOR pos){MATRIX m;__asm__ volatile ("ulv.q C010,%1\nulv.q C020,%2\nulv.q C030,%3\nulv.q C040,%4\nvdot.t S003,C010,C040[-x,-y,-z]\nvdot.t S013,C020,C040[-x,-y,-z]\nvdot.t S023,C030,C040[-x,-y,-z]\nvmov.q C040,C040[0,0,0,1]\nusv.q R000,0  + %0\nusv.q R001,16 + %0\nusv.q R002,32 + %0\nusv.q R003,48 + %0\n":"=m"(m):"m"(xAxis),"m"(yAxis),"m"(zAxis),"m"(pos));return m;}
/**
 * 行列同士を足し算します
 *
 * @param m1 足されるベクトル
 * @param m2 足すベクトル
 * @return 結果の行列
*/
static inline MATRIX MAdd(MATRIX m1,MATRIX m2){MATRIX m;__asm__ volatile ("ulv.q R000,0  + %1\nulv.q R001,16 + %1\nulv.q R002,32 + %1\nulv.q R003,48 + %1\nulv.q R100,0  + %2\nulv.q R101,16 + %2\nulv.q R102,32 + %2\nulv.q R103,48 + %2\nvadd.q R200,R000,R100\nvadd.q R201,R001,R101\nvadd.q R202,R002,R102\nvadd.q R203,R003,R103\nusv.q R200,0  + %0\nusv.q R201,16 + %0\nusv.q R202,32 + %0\nusv.q R203,48 + %0\n":"=m"(m):"m"(m1),"m"(m2));return m;}
/**
 * 行列同士を乗算します
 *
 * @param m1 掛けられるベクトル
 * @param m2 掛けるベクトル
 * @return 結果の行列
*/
static inline MATRIX MMult(MATRIX m1,MATRIX m2){MATRIX m;__asm__ volatile ("ulv.q R000,0  + %1\nulv.q R001,16 + %1\nulv.q R002,32 + %1\nulv.q R003,48 + %1\nulv.q R100,0  + %2\nulv.q R101,16 + %2\nulv.q R102,32 + %2\nulv.q R103,48 + %2\nvmmul.q M200,M000,M100\nusv.q R200,0  + %0\nusv.q R201,16 + %0\nusv.q R202,32 + %0\nusv.q R203,48 + %0\n":"=m"(m):"m"(m1),"m"(m2));return m;}
/**
 * 行列を拡大します
 *
 * @param m 変換元行列
 * @param scale 拡大率
 * @return 結果の行列
*/

static inline MATRIX MScale(MATRIX m,float scale){__asm__ volatile ("ulv.q R000,0 + %0\nulv.q R001,16 + %0\nulv.q R002,32 + %0\nulv.q R003,48 + %0\nmtv %1,S100\nvmscl.q M000,M000,S100\nusv.q R000,0 + %0\nusv.q R001,16 + %0\nusv.q R002,32 + %0\nusv.q R003,48 + %0\n":"=m"(m):"r"(scale));return m;}

/**
 * 転置行列を取得します
 *
 * @param m 転置したい行列
 * @return 転置行列
*/
static inline MATRIX MTranspose(MATRIX m){__asm__ volatile ("ulv.q R000,0  + %0\nulv.q R001,16 + %0\nulv.q R002,32 + %0\nulv.q R003,48 + %0\nusv.q C000,0  + %0\nusv.q C010,16 + %0\nusv.q C020,32 + %0\nusv.q C030,48 + %0\n":"=m"(m));return m;}
/**
 * 逆行列を取得します
 *
 * 行列式が0となるような行列には逆行列が存在しないので、単位行列を返します
 * @param m 逆にしたい行列
 * @return 逆行列
*/
static inline MATRIX MInverse(MATRIX m){register float d;__asm__ volatile ("ulv.q R200,0  + %1\nulv.q R201,16 + %1\nulv.q R202,32 + %1\nulv.q R203,48 + %1\nvmul.q R100,R201[y,x,x,x],R202[z,z,y,y]\nvmul.q R100,R203[w,w,w,z],R100\nvmul.q R101,R201[z,z,y,y],R202[w,w,w,z]\nvmul.q R101,R203[y,x,x,x],R101\nvadd.q R100,R100,R101\nvmul.q R101,R201[w,w,w,z],R202[y,x,x,x]\nvmul.q R101,R203[z,z,y,y],R101\nvadd.q R100,R100,R101\nvmul.q R101,R203[y,x,x,x],R202[z,z,y,y]\nvmul.q R101,R201[w,w,w,z],R101\nvsub.q R100,R100,R101\nvmul.q R101,R203[z,z,y,y],R202[w,w,w,z]\nvmul.q R101,R201[y,x,x,x],R101\nvsub.q R100,R100,R101\nvmul.q R101,R203[w,w,w,z],R202[y,x,x,x]\nvmul.q R101,R201[z,z,y,y],R101\nvsub.q R100,R100,R101\nvdot.q S101,R100,R200[x,-y,z,-w]\nvabs.s S102,S101\nmfv %0,S102\n":"=r"(d):"m"(m));if(d < 0.00001f){__asm__ volatile("vmidt.q M000\nusv.q R000,0  + %0\nusv.q R001,16 + %0\nusv.q R002,32 + %0\nusv.q R003,48 + %0\n":"=m"(m));return m;}__asm__ volatile("vrcp.s S101,S101\nvscl.q C000,R100[x,-y,z,-w],S101\nvmul.q R102,R200[y,x,x,x],R203[w,w,w,z]\nvmul.q R103,R203[y,x,x,x],R200[w,w,w,z]\nvsub.q R102,R102,R103\nvmul.q C010,R102,R202[z,z,y,y]\nvmul.q R102,R200[z,z,y,y],R203[y,x,x,x]\nvmul.q R103,R203[z,z,y,y],R200[y,x,x,x]\nvsub.q R102,R102,R103\nvmul.q R102,R102,R202[w,w,w,z]\nvadd.q C010,C010,R102\nvmul.q R102,R200[w,w,w,z],R203[z,z,y,y]\nvmul.q R103,R203[w,w,w,z],R200[z,z,y,y]\nvsub.q R102,R102,R103\nvmul.q R102,R102,R202[y,x,x,x]\nvadd.q C010,C010,R102\nvscl.q C010,C010[-x,y,-z,w],S101\nvmul.q R102,R200[y,x,x,x],R203[w,w,w,z]\nvmul.q R103,R203[y,x,x,x],R200[w,w,w,z]\nvsub.q R102,R102,R103\nvmul.q C020,R102,R201[z,z,y,y]\nvmul.q R102,R200[z,z,y,y],R203[y,x,x,x]\nvmul.q R103,R203[z,z,y,y],R200[y,x,x,x]\nvsub.q R102,R102,R103\nvmul.q R102,R102,R201[w,w,w,z]\nvadd.q C020,C020,R102\nvmul.q R102,R200[w,w,w,z],R203[z,z,y,y]\nvmul.q R103,R203[w,w,w,z],R200[z,z,y,y]\nvsub.q R102,R102,R103\nvmul.q R102,R102,R201[y,x,x,x]\nvadd.q C020,C020,R102\nvscl.q C020,C020[x,-y,z,-w],S101\nvmul.q R102,R200[y,x,x,x],R202[w,w,w,z]\nvmul.q R103,R202[y,x,x,x],R200[w,w,w,z]\nvsub.q R102,R102,R103\nvmul.q C030,R102,R201[z,z,y,y]\nvmul.q R102,R200[z,z,y,y],R202[y,x,x,x]\nvmul.q R103,R202[z,z,y,y],R200[y,x,x,x]\nvsub.q R102,R102,R103\nvmul.q R102,R102,R201[w,w,w,z]\nvadd.q C030,C030,R102\nvmul.q R102,R200[w,w,w,z],R202[z,z,y,y]\nvmul.q R103,R202[w,w,w,z],R200[z,z,y,y]\nvsub.q R102,R102,R103\nvmul.q R102,R102,R201[y,x,x,x]\nvadd.q C030,C030,R102\nvscl.q C030,C030[-x,y,-z,w],S101\nusv.q R000,0  + %0\nusv.q R001,16 + %0\nusv.q R002,32 + %0\nusv.q R003,48 + %0\n":"=m"(m));return m;}

/*@}*/

/** @defgroup 入力関連*/
/*@{*/
/**
 * PSPのボタン入力情報を直接受け取る
 * 
 * @code
 * if(GetInputState() & DXP_INPUT_CIRCLE)printfDx("○ボタンが押されました");
 * @endcode
 * @return ボタンの入力状態
*/
int GetInputState(void);
/**
 * ジョイパッドが接続されている数を取得する。(本家互換)
 * 
 * DXPではこの関数は必ず1を返します。PSPのボタン入力はGetJoypadInputStateにより、PCのジョイパッド入力として受け取ることができます。詳細は本家のヘルプを参照してください。
*/
int GetJoypadNum(void);
/**
 * ジョイパッドの入力状況を得る。(本家互換)
 * 
 * DX_INPUT_PAD1が指定されているとPSPのボタン入力がジョイパッド入力として変換された結果が返されます。そうでなければ0が返されます。
 * @param inputtype 入力状態を取得するパッドの識別子
 * @return ジョイパッド形式に変換された入力状況
*/
int GetJoypadInputState(int inputtype) ;
/**
 * ジョイパッドのアナログ的なレバー入力情報を得る(本家互換)
 * 
 * DX_INPUT_KEY1が指定されていると-1000〜+1000の範囲でアナログ入力が返されます。そうでなければ結果は0となります。
 * @param xbuf パッドレバーの左右の入力状態を格納する int 型変数のアドレス
 * @param ybuf パッドレバーの上下の入力状態を格納する int 型変数のアドレス
 * @param inputtype 入力状態を取得するパッドの識別子。
 * @retval 0 成功
 * @retval -1 失敗
*/
int GetJoypadAnalogInput(int *xbuf,int *ybuf,int inputtype);
/**
 * ジョイパッドのアナログ的なレバー入力情報を得る（右スティック用）(本家互換)
 * 
 * PSPには右スティックが存在しないので、呼び出しても意味がありません。
*/
int GetJoypadAnalogInputRight(int *xbuf,int* ybuf,int inputtype);
/**
 * ジョイパッドの入力に対応したキーボードの入力を設定する。(本家互換)
 * 
 * ジョイパッドの入力をキーボードの入力に変換する為の対応させます。
 *
*/
int SetJoypadInputToKeyInput(int inputtype,int padinput,int keyinput1,int keyinput2,int keyinput3,int keyinput4);
/**
 * ジョイパッドの振動を開始する(本家互換)
 * 
 * PSPには振動機能なんて無いので働きません。常に0が返されます
*/
int StartJoypadVibration(int inputtype,int power,int time);
/**
 * ジョイパッドの振動を停止する(本家互換)
 * 
 * PSPには振動機能なんて無いので働きません。常に0が返されます
*/
int StopJoypadVibration(int inputtype);
/**
 * PSPのボタン入力に対応したキーボードの入力を設定する。
 * 
 * キーボードのキー１つにPSPのボタン（複数可）を割り当てる。SetJoypadInputToKeyInput関数に似せている。
 * @param key - KEY_INPUT_　から始まる定数をひとつだけ。
 * @param pspbutton - PSP_INPUT_　から始まる定数をひとつ、又は複数を|演算子で組み合わせたもの
 * @retval 0 成功
 * @retval -1 失敗
 * @par サンプルコード
 * ○ボタン入力をXキーとして扱わせる。
 * @code
 * SetKeyInputToPspInput(KEY_INPUT_X,DXP_INPUT_CIRCLE);
 * @endcode
**/
int SetKeyInputToPspInput(int key,int pspbutton);
/**
 * すべてのキーの押下状態を取得する(キーの特定はできない)(本家互換)
 * 
 * @retval 1 どれかのキーが押された
 * @retval 0 どのキーも押されていない
*/
int CheckHitKeyAll(void);												/**<本家互換関数*/
/**
 * 特定のキーの入力状態を得る(本家互換)
 * 
 * @param keycode 入力状態を取得するキーコード(KEY_INPUTで始まる定数)
 * @retval 1 キーが押された
 * @retval 0 キーが押されていない
*/
int CheckHitKey(int keycode);										/**<本家互換関数*/
/**
 * キーボードのすべてのキーの押下状態を取得する(本家互換)
 * 
 * 本家のヘルプを参照してください。
 * @param keystatebuf すべてのキーの押下状態を格納するバッファのポインタ(256要素のchar型配列)
 * @retval 0 成功
 * @retval -1 失敗
*/
int GetHitKeyStateAll(char* keystatebuf);							/**<本家互換関数*/
/**
 * PSPのオンスクリーンキーボード（OSK）を利用して文字列入力を受け付ける
 * 
 * OSKを利用して文字列入力を受け付けます。ユーザーが入力を終えてこの関数が終了するまで他の処理は一切できないので注意してください。
 * modeには以下の値が使えます。|演算子によって必要なものを組み合わせるか、DXP_OSK_ALLでどんな入力も受け付けられるようにしてください。
 * - DXP_OSK_ALL		全て
 * - DXP_OSK_DIGIT		半角数字
 * - DXP_OSK_SYMBOL		半角記号
 * - DXP_OSK_SMALL		半角小文字
 * - DXP_OSK_LARGE		半角大文字
 * - DXP_OSK_DIGIT2		全角数字
 * - DXP_OSK_SYMBOL2	全角記号
 * - DXP_OSK_SMALL2		全角小文字
 * - DXP_OSK_LARGE2		全角大文字
 * - DXP_OSK_HIRAGANA	ひらがな
 * - DXP_OSK_KATAKANA_H	半角カタカナ
 * - DXP_OSK_KATAKANA	全角カタカナ
 * - DXP_OSK_KANJI		漢字
 * - DXP_OSK_URL		URL入力支援
 * 
 * @param buf ユーザーが入力した文字列を格納するためのバッファ
 * @param buflen バッファのバイト数
 * @param mode どのような文字を受け付けるか指定する
 * @param title OSKの右下に表示される文字列
 * @param init OSKの入力エリアに最初から入力されている文字列
 * @retval 0 成功
 * @retval -1 失敗
*/
int GetTextOSK(char *buf,int buflen,int mode,const char *title,const char *init,int lllang);
/*@}*/

/** @defgroup ファイル読み込み関連*/
/*@{*/
int	FileRead_open(const char *filename,int async DXPDEFARG(0));		/**<本家互換関数　ただし、現在アーカイブには未対応*/
int	FileRead_size(const char *filename);							/**<本家互換関数*/
int	FileRead_close(int filehandle);									/**<本家互換関数*/
int	FileRead_tell(int filehandle);									/**<本家互換関数*/
int	FileRead_seek(int filehandle,int offset,int origin);			/**<本家互換関数*/
int	FileRead_read(void *buffer,int readsize,int filehandle);		/**<本家互換関数*/
int	FileRead_idle_chk( int filehandle);								/**<本家互換関数*/
int	FileRead_eof(int filehandle);									/**<本家互換関数*/
int	FileRead_gets(char *buffer,int buffersize,int filehandle);		/**<本家互換関数*/
int	FileRead_getc(int filehandle);									/**<本家互換関数*/
//int	FileRead_scanf(int filehandle,const char *format, ...);	//この関数の対応予定はありません。
/*@}*/


/** @defgroup グラフィックス関連 */
/*@{*/
/**
 * 線分を描画します(本家互換)
 * 
 * @param x1 線分の始点のX座標
 * @param y1 線分の始点のY座標
 * @param x2 線分の終点のX座標
 * @param y2 線分の終点のY座標
 * @param color 線分の色
 * @retval 0 成功
 * @retval -1 失敗
*/
int DrawLine(int x1,int y1,int x2,int y2,int color);
/**
 * 矩形を描画します(本家互換)
 * 
 * @param x1,y1 矩形の左上の座標
 * @param x2,y2 矩形の右下の座標
 * @param color 矩形の色
 * @param fillflag 塗りつぶしフラグ
 * @retval 0 成功
 * @retval -1 失敗
*/
int DrawBox(int x1,int y1,int x2,int y2,int color,int fillflag);
/** 
 * 円を描画します(本家互換)
 * 
 * @param x,y 円の中心座標
 * @param r 円の半径
 * @param color 円の色
 * @param fillflag 塗りつぶしフラグ
 * @retval 0 成功
 * @retval -1 失敗
*/
int DrawCircle(int x,int y,int r,int color,int fillflag);
/** 
 * 楕円を描画します(本家互換)
 * 
 * @param x,y 楕円の中心座標
 * @param rx 楕円のX方向半径
 * @param ry 楕円のY方向半径
 * @param color 楕円の色
 * @param fillflag 塗りつぶしフラグ
 * @retval 0 成功
 * @retval -1 失敗
*/
int DrawOval(int x,int y,int rx,int ry,int color,int fillflag);
/**
 * 三角形を描画します(本家互換)
 * 
 * @param x1,y1 頂点座標1
 * @param x2,y2 頂点座標2
 * @param x3,y3 頂点座標3
 * @param color 三角形の色
 * @param fillflag 塗りつぶしフラグ
 * @retval 0 成功
 * @retval -1 失敗
*/
int DrawTriangle(int x1,int y1,int x2,int y2,int x3,int y3,int color,int fillflag);
/**
 * 点を描画する(本家互換)
 * 
 * @param x,y 点の座標
 * @param color 点の色
 * @retval 0 成功
 * @retval -1 失敗
 * 
*/
int DrawPixel(int x,int y,int color);
/**
 * 指定点の色コードを取得する(本家互換)
 * 
 * @param x,y 点の座標
 * @return 点の色コード
*/
int GetPixel(int x,int y);
/**
 * 画像を読み込んで画面に表示する(本家互換)
 * 
 * @param x ロードした画像を描画する矩形の左上頂点のX座標
 * @param y ロードした画像を描画する矩形の左上頂点のY座標
 * @param filename ロードする画像パスの文字列があるポインタ
 * @param trans 透過色を入れるか、のフラグ。TRUEで透過色有効になる
 * @retval 0 成功
 * @retval -1 失敗
*/
int LoadGraphScreen(int x,int y,const char* filename,int trans);
/**
 * 画像を読み込みます(ほぼ本家互換)
 * 
 * サイズが512x512までのPNG画像を読み込むことが出来ます
 * 戻り値はDrawGraph等の関数で画像を描画する際必要になるので、変数に保存してください
 * @param FileName ファイル名
 * @return グラフィックスハンドル
 * @retval -1 失敗
*/
int LoadGraph(const char *FileName);
/**
 * 一枚の画像から複数のグラフィックスハンドルを作ります(ほぼ本家互換)
 * 
 * 画像全体のサイズは512x512までです。PNG画像しか読み込めないのもLoadGraphと同様です。
 * @param filename 分割読み込みする画像ファイル文字列のポインタ
 * @param allnum 画像の分割総数
 * @param xnum 画像の横向きに対する分割数
 * @param ynum 画像の縦向きに対する分割数
 * @param xsize 分割された画像一つの横幅
 * @param ysize 分割された画像一つの縦幅
 * @param handlebuf 分割読み込みして得たグラフィックハンドルを保存するint型の配列へのポインタ
*/
int LoadDivGraph(const char *filename,int allnum,int xnum,int ynum,int xsize,int ysize,int *handlebuf);
/**
 * 空のグラフィックスハンドルを生成する(本家互換)
 * 
 * 512x512より大きなグラフィックは作れないので注意してください
 * @param xsize 作成するグラフィックスハンドルの幅
 * @param ysize 作成するグラフィックスハンドルの高さ
 * @return グラフィックスハンドル
 * @retval -1 失敗
*/
int MakeGraph(int xsize,int ysize);
/**
 * 画像の描画を行います。(本家互換)
 * 
 * @param x 描画基点のX座標
 * @param y 描画基点のY座標
 * @param gh 描画するグラフィックスのハンドル
 * @param trans 透過フラグ
 * @retval 0 成功
 * @retval -1 失敗
*/
int DrawGraph(int x,int y,int gh,int trans);
/**
 * 画像の左右反転描画を行います。(本家互換)
 * 
 * @param x 描画基点のX座標
 * @param y 描画基点のY座標
 * @param gh 描画するグラフィックスのハンドル
 * @param trans 透過フラグ
 * @retval 0 成功
 * @retval -1 失敗
*/
int DrawTurnGraph(int x,int y,int gh,int trans);
/**
 * 画像の拡大縮小描画を行います。(本家互換)
 * 
 * @param x1 左上のX座標
 * @param y1 左上のY座標
 * @param x2 右下のX座標
 * @param y2 右下のY座標
 * @param gh 描画するグラフィックスのハンドル
 * @param trans 透過フラグ
 * @retval 0 成功
 * @retval -1 失敗
*/
int DrawExtendGraph(int x1,int y1,int x2,int y2,int gh,int trans);
/**
 * 画像の回転描画を行います。(本家互換)
 * 
 * @param x 画像中心位置のX座標
 * @param y 画像中心位置のY座標
 * @param scale 拡大率　1.0fで等倍
 * @param angle 回転角度
 * @param gh 描画するグラフィックスのハンドル
 * @param trans 透過フラグ
 * @param turn 画像反転フラグ
 * @retval 0 成功
 * @retval -1 失敗
*/
int DrawRotaGraph(int x,int y,float scale,float angle,int gh,int trans,int turn DXPDEFARG(0));
/**
 * 画像の回転描画を行います。(本家互換)
 * 
 * float型で座標指定できるDrawRotaGraphです。
 * @param x 画像中心位置のX座標
 * @param y 画像中心位置のY座標
 * @param scale 拡大率　1.0fで等倍
 * @param angle 回転角度
 * @param gh 描画するグラフィックスのハンドル
 * @param trans 透過フラグ
 * @param turn 画像反転フラグ
 * @retval 0 成功
 * @retval -1 失敗
*/
int DrawRotaGraphF(float x,float y,float scale,float angle,int gh,int trans,int turn DXPDEFARG(0));
/**
 * 回転中心座標指定可能な画像の回転描画を行います。(本家互換)
 * 
 * @param x,y スクリーン上の回転中心位置の座標
 * @param cx,cy 画像上の回転中心位置の座標
 * @param scale 拡大率　1.0fで等倍
 * @param angle 回転角度
 * @param gh 描画するグラフィックスのハンドル
 * @param trans 透過フラグ
 * @param turn 画像反転フラグ
 * @retval 0 成功
 * @retval -1 失敗
*/
int DrawRotaGraph2(int x,int y,int cx,int cy,float scale,float angle,int gh,int trans,int turn DXPDEFARG(0));
/**
 * 回転中心座標指定可能な画像の回転描画を行います。(本家互換)
 * 
 * float型で座標指定できるDrawRotaGraph2です。
 * @param x,y スクリーン上の回転中心位置の座標
 * @param cx,cy 画像上の回転中心位置の座標
 * @param scale 拡大率　1.0fで等倍
 * @param angle 回転角度
 * @param gh 描画するグラフィックスのハンドル
 * @param trans 透過フラグ
 * @param turn 画像反転フラグ
 * @retval 0 成功
 * @retval -1 失敗
*/
int DrawRotaGraph2F(float x,float y,float cx,float cy,float scale,float angle,int gh,int trans,int turn DXPDEFARG(0));
/**
 * 画像の自由変形描画を行います。(本家互換)
 * 
 * @param x1 左上のX座標
 * @param y1 左上のY座標
 * @param x2 右上のX座標
 * @param y2 右上のY座標
 * @param x3 右下のX座標
 * @param y3 右下のY座標
 * @param x4 左下のX座標
 * @param y4 左下のY座標
 * @param gh 描画するグラフィックスのハンドル
 * @param trans 透過フラグ
 * @retval 0 成功
 * @retval -1 失敗
*/
int DrawModiGraph(int x1,int y1,int x2,int y2,int x3,int y3,int x4,int y4,int gh,int trans);
/**
 * 画像の自由変形描画を行います。(本家互換)
 * float型で座標指定できるDrawModiGraphです。
 * 
 * @param x1 左上のX座標
 * @param y1 左上のY座標
 * @param x2 右上のX座標
 * @param y2 右上のY座標
 * @param x3 右下のX座標
 * @param y3 右下のY座標
 * @param x4 左下のX座標
 * @param y4 左下のY座標
 * @param gh 描画するグラフィックスのハンドル
 * @param trans 透過フラグ
 * @retval 0 成功
 * @retval -1 失敗
*/
int DrawModiGraphF(float x1,float y1,float x2,float y2,float x3,float y3,float x4,float y4, int gh, int trans );
/**
 * 画像の指定矩形部分の描画を行います。(本家互換)
 * 
 * @param destx 描画先の描画基点X座標
 * @param desty 描画先の描画基点Y座標
 * @param srcx 描画元の描画基点X座標
 * @param srcy 描画元の描画基点Y座標
 * @param width 描画する部分のX方向の大きさ
 * @param height 描画する部分のY方向の大きさ
 * @param gh 描画するグラフィックスのハンドル
 * @param trans 画像透過フラグ
 * @param turn 画像反転フラグ
 * @retval 0 成功
 * @retval -1 失敗
*/
int DrawRectGraph(int destx,int desty,int srcx,int srcy,int width,int height,int gh,int trans,int turn);
/**
 * 指定のグラフィックスハンドルの指定の部分だけを範囲とするグラフィックスハンドルを作る(本家互換)
 * 
 * @param srcx,srcy グラフィック中の抜き出したい矩形の左上座標
 * @param width,height 抜き出すグラフィックのサイズ
 * @param gh 抜き出したいグラフィックのハンドル
 * @return グラフィックスハンドル
 * @retval -1 失敗
*/
int DerivationGraph(int srcx,int srcy,int width,int height,int gh);
/**
 * 描画先に設定されているグラフィックから指定領域を別のグラフィックへ読みこむ(本家互換)
 * 
 * 読込先のグラフィックはVRAM上にあり、Swizzleされておらず、パレット画像でない必要があります。
 * なお、この関数で読み込んだグラフィックは透過色の機能が正常に働かないので注意してください。
 * @param x1 取得するグラフィック領域（矩形）の左上頂点のX座標
 * @param y1 取得するグラフィック領域（矩形）の左上頂点のY座標
 * @param x2 取得するグラフィック領域の右下頂点＋１のX座標
 * @param y2 取得するグラフィック領域の右下頂点＋１のY座標
 * @param gh 読込先のグラフィックスハンドル
 * @retval 0 成功
 * @retval -1 失敗
*/
int GetDrawScreenGraph(int x1,int y1,int x2,int y2,int gh);
/**
 * グラフィックの大きさを得る(本家互換)
 * 
 * @param gh グラフィックスハンドル
 * @param xbuf グラフィックの横幅を格納するint型変数へのポインタ
 * @param ybuf グラフィックの縦幅を格納するint型変数へのポインタ
 * @retval 0 成功
 * @retval -1 失敗
 */
int GetGraphSize(int gh,int *xbuf,int *ybuf);
/**
 * 全てのグラフィックスハンドルを削除します(本家互換)
 * 
 * @retval 0 成功
 * @retval -1 失敗
*/
int InitGraph(void);
/**
 * グラフィックスハンドルを削除します(本家互換)
 * 
 * @param gh グラフィックスハンドル
 * @retval 0 成功
 * @retval -1 失敗
*/
int DeleteGraph(int gh);
/**
 * 描画モードをセットする(本家互換)
 *
 * - DX_DRAWMODE_NEAREST ネアレストネイバー法で描画する(既定値)
 * - DX_DRAWMODE_BILINEAR バイリニア法で描画する
 *
 * @param mode 描画モード
 * @retval 0 成功
 * @retval -1 失敗
*/
int SetDrawMode(int mode);
/**
 * ブレンドモードをセットする(本家互換)
 *
 * 描画先の画像に対してどのように色を混ぜるか指定できます。
 * 詳しくは本家のリファレンスを一読してください。
 * なお、一部のブレンドモードはPSPのハードウェアの制約で実装できていません。以下のどれかを使ってください。
 * - DX_BLENDMODE_NOBLEND
 * - DX_BLENDMODE_ALPHA
 * - DX_BLENDMODE_ADD
 * - DX_BLENDMODE_SUB
 * - DX_BLENDMODE_MUL
 * - DX_BLENDMODE_DESTCOLOR
 * - DX_BLENDMODE_INVDESTCOLOR
 * - DX_BLENDMODE_INVSRC
 * @param blendmode ブレンドモード
 * @param param パラメータ
 * @retval 0 成功
 * @retval -1 失敗
*/
int SetDrawBlendMode(int blendmode,int param);
/**
 * 描画輝度をセットする(本家互換)
 *
 * 0-255の範囲で値を指定してください
 * @param red 赤の描画輝度
 * @param green 緑の描画輝度
 * @param blue 青の描画輝度
 * @retval 0 成功
 * @retval -1 失敗
*/
int SetDrawBright(int red,int green,int blue);
/**
 * 画像に設定する透過色を設定します(本家互換)
 * 
 * 画像の読み込み時に画像に設定される透過色を設定します。画像がアルファ情報を持たず、透過フラグがONの場合この値に近い色のエリアは描画されません。
 * @param color 透過色
 * @retval 0 成功
 * @retval -1 失敗
*/
int SetTransColor(int color);
/**
 * 画面モードを設定します(本家互換)
 * 
 * 画面サイズは480x272以外指定できません。それ以外を指定するとエラーになります。
 * bppには1ピクセルあたりのビット数を指定します。指定可能な値は以下の通りです。
 * - 16 DXP_FMT_5551と同じです
 * - 32 DXP_FMT_8888と同じです
 * - DXP_FMT_4444 各色に4bitが割り当てられます
 * - DXP_FMT_5650 赤と青に5bit、緑に6bitが割り当てられます
 * - DXP_FMT_5551 各色に5bitが割り当てられます
 * - DXP_FMT_8888 各色に8bitが割り当てられます
 * @retval 0 成功
 * @retval -1 失敗
*/
int SetGraphMode(int xsize,int ysize,int bpp);
/**
 * 現在の画面の大きさとカラービット数を得る(本家互換)
 * 
 * @param xsize,ysize 画面の幅と高さを格納するint型変数へのポインタ
 * @param bpp １ピクセルあたり何ビット使われているかを格納するint型変数へのポインタ
 * @retval 0 成功
 * @retval -1 失敗
*/
int GetScreenState(int *xsize,int *ysize,int *bpp);
/**
 * 描画可能領域のセット(本家互換)
 * 
 * @param x1,y1 描画可能領域を示す矩形の左上の座標
 * @param x2,y2 描画可能領域を示す矩形の右下の座標
 * @retval 0 成功
 * @retval -1 失敗
*/
int SetDrawArea(int x1,int y1,int x2,int y2);
/**
 * 描画先のグラフィックスをクリアします。(本家互換)
 * 
 * @retval 0 成功
 * @retval -1 失敗
*/
int ClearDrawScreen(void);
/**
 * 色コードを返します(本家互換)
 * 
 * @param Red 赤成分
 * @param Green 緑成分
 * @param Blue 青成分
 * @return 色コード
*/
int GetColor(int Red,int Green,int Blue);
/**
 * 描画先を変更します
 * 
 * VRAM上にあるSwizzleされていないグラフィックスハンドルを渡すと、描画先として設定されます
 * LoadDivGraphやDerivationGraph関数を使って作ったような、一枚のテクスチャを複数のグラフィックスが共有するような
 * グラフィックスハンドルを指定すると予期しない結果になる可能性があります
 * @param ghandle 描画先にするグラフィックスハンドル
 * @retval 0 成功
 * @retval -1 失敗
*/
int SetDrawScreen(int ghandle);
/**
 * 裏画面と表画面を交換します(本家互換)
 * 
 * @retval 0 成功
 * @retval -1 失敗
*/
int ScreenFlip(void);
/**
 * 裏画面の内容を表画面にコピーし、ScreenFlipを実行します。(本家互換)
 * 
 * @retval 0 成功
 * @retval -1 失敗
*/
int ScreenCopy(void);
/**
 * ScreenFlip、ScreenCopy関数実行時に垂直同期待ちをするかのフラグをセット(本家互換)
 * 
 * 垂直同期を待つ場合、ゲームの負荷が大きいといきなり60→30→20と60の約数のfpsに切り替わって遊びにくいことがあります。
 * 垂直同期を待たない場合、ゲームの負荷が大きいとfpsが連続的に変動します。ただし、画面が若干ちらつくことがあります。
 * @param flag 垂直同期待ちフラグ
 * @retval 0 成功
 * @retval -1 失敗
*/
int SetWaitVSyncFlag(int flag);
/**
 * 可能ならVRAM上にテクスチャのコピーを置き、それを使うようにする
 * 
 * 0.5.0以降ではメインメモリー上のテクスチャを保持するようになりました。
 * @retval 0 成功
 * @retval -1 失敗
*/
int MoveGraphToVRAM(int gh);
/**
 * VRAM上にテクスチャのデータがあれば、それをメインメモリーのテクスチャにコピーしてからVRAM上の領域を開放する
 * 
 * @retval 0 成功
 * @retval -1 失敗
*/
int MoveGraphToDDR(int gh);
/**
 * 可能ならグラフィックをSwizzleする
 * 
 * 空きメモリが足りないと失敗することがあります。
 * @retval 0 成功
 * @retval -1 失敗
*/
int SwizzleGraph(int gh);
/**
 * 可能ならグラフィックのSwizzleを解除する
 * 
 * 空きメモリが足りないと失敗することがあります。
 * @retval 0 成功
 * @retval -1 失敗
*/
int UnswizzleGraph(int gh);
/**
 * グラフィックのフォーマットを変更する。
 * 
 * グラフィックのフォーマットを変更できます。
 * 以下のフォーマットのみ入出力対応です。パレット画像には適用できません。
 * - DXP_FMT_4444
 * - DXP_FMT_5650
 * - DXP_FMT_5551
 * - DXP_FMT_8888
 * @param gh 対象のグラフィックスハンドル
 * @param psm ピクセルフォーマット
 * @retval 0 成功
 * @retval -1 失敗
*/
int ConvertGraphFormat(int gh,int psm);
/**
 * 画像を読み込む際にSwizzle処理を行うかどうか設定します
 * 
 * @param flag 画像読み込み時Swizzle処理実行フラグ
 * @retval 0 成功
 * @retval -1 エラー発生
*/
int SetCreateSwizzledGraphFlag(int flag);
/**
 * GPUが処理を終えるのを待ちます
 * 
 * @retval 0 成功
 * @retval -1 エラー発生
*/
int WaitGPUSync(void);
/**
 * 画面のピクセルフォーマットを得る
 * 
 * 戻り値は次のうちどれかです
 * - DXP_FMT_4444
 * - DXP_FMT_5551
 * - DXP_FMT_5650
 * - DXP_FMT_8888
 * @return ピクセルフォーマット
 * @retval -1 失敗
*/
int GetDisplayFormat(void);
/**
 * 画面のピクセルフォーマットを変更する
 * 
 * 指定可能な値は次のうちどれかです
 * - DXP_FMT_4444
 * - DXP_FMT_5551
 * - DXP_FMT_5650
 * - DXP_FMT_8888
 * @return ピクセルフォーマット
 * @retval -1 失敗
*/
int SetDisplayFormat(int psm);
/**
 * フレームバッファ（裏画面）へのポインタを返します
 * 
 * @return フレームバッファのポインタ
*/
void *GetFramebufferAddress(void);
/**
 * ディスプレイバッファ（表画面）へのポインタを返します
 * 
 * @return ディスプレイバッファへのポインタ
*/
void *GetDisplaybufferAddress(void);
/*@}*/

/**@defgroup サウンド関連*/
/*@{*/

/**
 * 音楽データを読み込みます(本家互換)
 * 
 * MP3形式の音楽ファイルのみ読み込めます。なお、読み込み作業は別スレッドで行われます。
 * 
 * @param filename ファイル名
 * @return サウンドハンドル
 * @retval -1 失敗
*/
int LoadSoundMem(const char *filename);
/**
 * サウンドハンドルから再生します(本家互換)
 * 
 * LoadSoundMemで読み込んだ音楽ファイルを再生することができます
 * 指定可能な再生タイプは以下の通り
 * - DX_PLAYTYPE_NORMAL 再生が終わるまで待ちます
 * - DX_PLAYTYPE_BACK バックグラウンドで再生します。音楽の終わりまで再生したら停止します
 * - DX_PLAYTYPE_LOOP バックグラウンドで再生します。ループ再生になります
 * 
 * @param handle サウンドハンドル
 * @param playtype 再生タイプ
 * @param rewindflag 最初から再生させるかどうか
 * @retval -1 失敗
*/
int PlaySoundMem(int handle,int playtype,int rewindflag DXPDEFARG(1));
/**
 * サウンドハンドルが再生中かチェックします(本家互換)
 * 
 * @param handle サウンドハンドル
 * @retval 1 再生中
 * @retval 0 停止
 * @retval -1 失敗
*/
int CheckSoundMem(int handle);
/**
 * サウンドハンドルの再生を止めます(本家互換)
 * 
 * @param handle サウンドハンドル
 * @retval 0 成功
 * @retval -1 失敗
*/
int StopSoundMem(int handle);
/**
 * サウンドハンドルを削除します(本家互換)
 * 
 * @param handle サウンドハンドル
 * @retval 0 成功
 * @retval -1 失敗
*/
int DeleteSoundMem(int handle);
/**
 * 全てのサウンドハンドルを削除します。(本家互換)
 * 
 * @retval 0 成功
 * @retval -1 失敗
*/
int InitSoundMem(void);
/**
 * サウンドハンドルにパンを設定する(本家互換)
 * 
 * 正の値を設定すると左の音量が下がり、負の値を設定すると右の音量が下がります。0なら左右の音量が等しくなります。
 * @param handle サウンドハンドル
 * @param pan パンの値。-10000〜+10000の範囲
 * @retval 0 成功
 * @retval -1 失敗
*/
int SetPanSoundMem(int pan,int handle);
/**
 * サウンドハンドルの音量を変更する(本家互換)
 * 
 * @param handle サウンドハンドル
 * @param volume 音量。0〜255の範囲
 * @retval 0 成功
 * @retval -1 失敗
*/
int ChangeVolumeSoundMem(int volume,int handle);
/**
 * ループ位置を設定する(本家互換)
 * 
 * ループ再生時に、指定した場所から再生再開できるようにします。
 * @param looppos_s ループ再開位置（ミリ秒単位）
 * @param handle サウンドハンドル
 * @retval 0 成功
 * @retval -1 失敗
*/
int SetLoopPosSoundMem(int looppos_s,int handle);
/**
 * ループ位置を設定する(本家互換)
 * 
 * ループ再生時に、指定した場所から再生再開できるようにします。サンプル数で指定します。
 * @param looppos ループ再開位置（サンプル数単位）
 * @param handle サウンドハンドル
 * @retval 0 成功
 * @retval -1 失敗
*/
int SetLoopSamplePosSoundMem(int looppos,int handle);
/** 
 * LoadSoundMemの挙動を変更します。(本家互換)
 * 
 * LoadSoundMemはメモリ上に音楽データを展開し、それを再生します。
 * この関数でその時の挙動を変更できます。
 * 指定可能な値は以下の通り
 * - DX_SOUNDDATATYPE_MEMNOPRESS	メモリ上にデータを展開し、それを再生します。
 * - DX_SOUNDDATATYPE_FILE ストリーミング再生をします。
 * 
 * 以下の値は現在使えません。
 * - DX_SOUNDDATATYPE_MEMPRESS
 * - DX_SOUNDDATATYPE_MEMPRESS_PLUS
 * @retval 0 成功
 * @retval -1 失敗
*/
int SetCreateSoundDataType(int type);
/*@}*/

/**@defgroup 文字列描画関連*/
/*@{*/
/**
 * 文字列を描画する(本家互換)
 * 
 * @param x,y 文字列の左上の座標
 * @param String 描画する文字列
 * @param color 文字列の色
 * @param EdgeColor 文字列のエッジの色
 * @retval 0 成功
 * @retval -1 失敗
*/
int DrawString(int x,int y,const char *String,int color, int EdgeColor DXPDEFARG(0));
/**
 * 書式付き文字列を描画する(本家互換)
 * 
 * @param x,y 文字列の左上の座標
 * @param color 文字列の色
 * @param String 書式付き文字列
 * @retval 0 成功
 * @retval -1 失敗
*/
int DrawFormatString(int x,int y,int color,const char *String,...);
/**
 * 文字列を描画した時の横幅を取得する(本家互換)
 * 
 * @param str 文字列
 * @param len 文字列の長さ
 * @return 文字列を描画した時の長さ
 * @retval -1 失敗
*/
int GetDrawStringWidth(const char *str,int len);
/**
 * 書式付き文字列を描画した時の横幅を取得する(本家互換)
 * 
 * @param format 書式付き文字列
 * @param ... 書式付き文字列に付随するデータ
 * @return 文字列を描画した時の長さ
 * @retval -1 失敗
*/
int GetDrawFormatStringWidth(const char *format, ... );
/**
 * フォントサイズを設定する(本家互換)
 * 
 * @param size フォントサイズ
 * @retval 0 成功
 * @retval -1 失敗
*/
int SetFontSize(int size);
/**
 * フォントの文字の太さを設定する
 * 
 * この関数は動きません。0を返すだけです。
 * @param thickness フォントの太さ（無視されます）
 * @retval 0 成功
 * @retval -1 失敗
*/
int SetFontThickness(int thickness);
/**
 * フォントを変更する(本家互換)
 * 
 * pgfフォントのみ読み込めます。
 * @param fontname フォント名
 * @param charset 文字コード
 * @retval 0 成功
 * @retval -1 失敗
*/
int ChangeFont(const char *fontname,int charset);
/**
 * フォントタイプを変更する(本家互換)
 * 
 * 以下の値が指定可能ですが、アンチエイリアシングの有無は描画に反映されません。
 * - -1（DX_FONTTYPE_NORMALとして扱われます）
 * - DX_FONTTYPE_NORMAL
 * - DX_FONTTYPE_EDGE
 * - DX_FONTTYPE_ANTIALIASING　
 * - DX_FONTTYPE_ANTIALIASING_EDGE
 * @param type フォントタイプ
 * @retval 0 成功
 * @retval -1 失敗
*/
int ChangeFontType(int type);

/**
 * フォントを読み込み、ハンドルを作成する
 * 
 * @param fontname フォント名
 * @param size フォントサイズ
 * @param thick フォントの太さ（無視されます）
 * @param fonttype フォントタイプ 詳しくはSetFontTypeを参照してください。
 * @param charset 文字セット　DXP_CP_が頭についているものを指定する必要があります
 * @return フォントハンドル
 * @retval -1 失敗
*/
int CreateFontToHandle(const char *fontname,int size,int thick,int fonttype,int charset DXPDEFARG(DXP_CP_SJIS));
/**
 * フォントハンドルを削除する(本家互換)
 *
 * @param handle 削除したいフォントハンドル
 * @retval 0 成功
 * @retval -1 失敗
 *
*/
int DeleteFontToHandle(int handle);
/**
 * フォントハンドルを指定して文字列を描画する(本家互換)
 * 
 * @param x,y 文字列の左上の座標
 * @param str 描画する文字列
 * @param color 文字列の色
 * @param handle フォントハンドル
 * @param edgecolor 文字列のエッジの色
 * @retval 0 成功
 * @retval -1 失敗
*/
int DrawStringToHandle(int x,int y,const char *str,int color,int handle,int edgecolor DXPDEFARG(0));
/**
 * フォントハンドルを指定して書式付き文字列を描画する(本家互換)
 * 
 * @param x,y 文字列の左上の座標
 * @param color 文字列の色
 * @param handle フォントハンドル
 * @param format 書式付き文字列
 * @retval 0 成功
 * @retval -1 失敗
*/
int	DrawFormatStringToHandle(int x,int y,int color,int handle,const char *format,...);
/**
 * フォントハンドルを指定して文字列を描画した時の横幅を取得する(本家互換)
 * 
 * @param str 文字列
 * @param len 文字列の長さ
 * @param handle フォントハンドル
 * @return 文字列を描画した時の長さ
 * @retval -1 失敗
*/
int GetDrawStringWidthToHandle(const char *str,int len,int handle);
/**
 * フォントハンドルを指定して書式付き文字列を描画した時の横幅を取得する(本家互換)
 * 
 * @param handle フォントハンドル
 * @param format 書式付き文字列
 * @param ... 書式付き文字列に付随するデータ
 * @return 文字列を描画した時の長さ
 * @retval -1 失敗
*/
int GetDrawFormatStringWidthToHandle(int handle,const char *format, ... );
/**
 * フォントハンドルを全て開放する(本家互換)
 * 
 * @retval 0 成功
 * @retval -1 失敗
*/
int InitFontToHandle(void);
/*@}*/

/**@defgroup デバッグ関連*/
/*@{*/
/** 
 * ログファイルに出力します
 * printfのように使うとログファイルに書き込まれます。
*/
int AppLogAdd(const char *format,...);
/**
 * 簡易文字列出力
 * 
 * DOS窓のように文字列を出力します。
 * 非常に低速な上、実行ファイルサイズが一気に膨れるのでゲームには不向きです。
 * なお、ScreenFlip関数かScreenCopy関数が呼ばれるまで描画されませんので注意してください。
 * @retval 0 成功
 * @retval -1 失敗
*/
int printfDx(const char *format,...);
/**
 * 簡易文字列出力の履歴を削除します
 * 
 * @retval 0 成功
 * @retval -1 失敗
*/
int clsDx(void);
/*@}*/

int DrawLine3D(VECTOR pos1,VECTOR pos2,int color);
int DrawTriangle3D(VECTOR pos1,VECTOR pos2,VECTOR pos3,int color,int fillflag);
int DrawPolygon3D( VERTEX3D *Vertex, int PolygonNum, int GrHandle, int TransFlag );

int SetCameraPositionAndTargetAndUpVec( VECTOR Position, VECTOR Target, VECTOR Up );
int SetupCamera_ProjectionMatrix( MATRIX ProjectionMatrix );
int SetupCamera_Perspective( float Fov );
int SetCameraNearFar( float Near, float Far );
int SetCameraDotAspect(float Aspect);

int SetUseZBufferFlag(int flag);
int SetUseZBuffer3D(int flag);
int SetWriteZBufferFlag(int flag);
int SetWriteZBuffer3D(int flag);

int SetTransformToWorld( MATRIX *Matrix );

static inline COLOR_U8 GetColorU8(int red,int green,int blue,int alpha)
{
	COLOR_U8 c;
	c.a = alpha & 0xff;
	c.b = blue & 0xff;
	c.g = green & 0xff;
	c.r = red & 0xff;
	return c;
}

#ifdef __cplusplus
}
#endif
#endif//DXLIBP_H__
