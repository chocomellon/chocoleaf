//
// アプリ雛形
// ※ファイル分割対応版
//

#include "lib/defines.hpp"
// ↑これは必ず最初にincludeする

#include "lib/appEnv.hpp"
// ↑必要なヘッダファイルは適時インクルードする

#include"leaf.h"

// アプリのウインドウサイズ
enum Window {
	WIDTH = 1320,
	HEIGHT = 720
};


// 
// メインプログラム
// 

int main() {
	// アプリウインドウの準備
	AppEnv app_env(Window::WIDTH, Window::HEIGHT,
		false, false);

	//leaf Leaf(app_env);
	leaf* Leaf[200];

	for (int i =0; i < 200; i++){
		Leaf[i] = new leaf(app_env);
	}

	int j = 0;
	bool frag = false;

	while (1) {
		// アプリウインドウが閉じられたらプログラムを終了
		if (!app_env.isOpen()) return 0;

		// 描画準備
		app_env.setupDraw();

		//
		// 描画処理はここでおこなう
		// 
		for (int i=0; i < 200; i++){
			Leaf[i]->Update();
			if (frag == true){
				Leaf[i]->Move(app_env);
			}
			Leaf[i]->Draw(app_env);
		}

		if (app_env.isPressKey('T')){
			frag = true;
		}
		else frag = false;

		j++;


	// 画面更新
	app_env.update();
}

	for (int i = 0; i < 200;i++)delete Leaf[i];
// アプリ終了
}
