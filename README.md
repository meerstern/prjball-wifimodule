# prjball-wifimodule
ESP-WROOM-02 for ProjectionBall.  
This code enables to control in remote area through wifi.  

ProjectionBallとESP-WROOM-02を接続して遠隔で操作ができます。  
アクセスポイント経由(クライアントモード)と直接接続(サーバモード)の両方に対応しています。  
市販のESP-WROOM-02に本コードをArduinoIDEを経由して書き込んで使用してください。  
ESP-WROOM-02の書き込み方等についてはGoogle先生にお尋ねください。  


スマートフォンやPC、タブレット等と接続して下記の操作が遠隔で可能です。  
  * 操作切替
  * 描画データ切替
  * 描画モード切替
  * アクセスポイント経由時のSSID、PASS設定
  
![PBR](http://meerstern.up.seesaa.net/image/iphone.PNG "PBR")
  
  
## ハードウェア設定
  * ここでは最低限の配線について説明します。
  * 既にESP-WROOM-02へ本コードが書き込み済みの状態から説明します。
  * ESP-WROOM-02へ書き込み済み方法はGoogle先生にお尋ねください。  
  * ESP-WROOM-02の電源はProjectionBallの基板上の3.3Vから配線します。
  * ESP-WROOM-02のGNDはProjectionBallの基板上のGNDから配線します。
  * ESP-WROOM-02のTXをProjectionBallの基板上のRXへ接続します。
  * ESP-WROOM-02のIO15ををProjectionBallの基板上のGNDへ接続します。
  
![power](http://meerstern.up.seesaa.net/image/power.png "power")
![uart](http://meerstern.up.seesaa.net/image/uart.png "uart")
  
  
  
## 接続方法
  初回使用時及び設定済みアクセスポイントが見つからない場合は自動的に直接接続(サーバモード)となります。  
  設定済みのアクセスポイントが見つかった場合は自動的にアクセスポイント経由(クライアントモード)となります。　　


### サーバモード接続方法    
  * ESP-WROOM-02接続済みのProjectionBallの電源を入れます。
  * 数十秒後に自動的にサーバモードとなります。
  * スマートフォンやPC等からアクセスポイント名「prjballXX」へ接続してください。
  * ブラウザ等のアドレス画面へ「192.168.4.1」を打ち込んで「Enter」キーを押してください。
  * 「ProjectionBall Remote」画面が表示されたら、接続完了です。
  
  
### クライアントモード接続方法　　  
  * 予め上記のサーバモードで接続し、「ProjectionBall Remote」画面が表示させてください。
  * アクセスポイント経由で接続する場合は「Wifi」タブの「SSID」「PASS」を設定してください。
  * アクセスポイント設定完了後、次回の起動でアクセスポイント経由で接続されます。
  * アクセスポイント経由で接続するため、ProjectionBallの電源を一度切ってから再度入れてください。
  * 数十秒後に自動的に先ほど設定したアクセスポイントへ接続を試行します。
  * 接続が成功した場合、同一のアクセスポイントへ接続されたスマートフォンやPC等のブラウザから操作ができます。
  * スマートフォンやPC等のブラウザのアドレス画面で「prjball.local」と打ち込んで「Enter」キーを押してください。
  * 「ProjectionBall Remote」画面が表示されたら、接続完了です。
  * 再びサーバモードで接続したい場合は「Wifi」タブの「SSID」「PASS」で適当な文字を設定してください。
  
## ProjectionBall Remote使用方法　　
  * ProjectionBall電源入れた直後は本体のスイッチの設定が優先されます。
  * Wifiの設定を優先するため、最初に「Local/Remote」タブの「Remote」を押してください。  
  * 描画データの読み込み先を切り替える際には「Data」タブから設定してください。
  * 描画データの描画方法を切り替える際には「Mode」タブから設定してください。
  * 描画データの描画パターンを切り替える際には「Pattern」タブから設定してください。

 
License -MIT
