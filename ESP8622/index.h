String str_html;

void SetHtml(){
 str_html+="<!DOCTYPE html>";
 str_html+="<html>";
 
 str_html+="<head>";
 str_html+="<meta charset=\"utf-8\"><meta http-equiv=\"content-type\" content=\"text/html; charset=UTF-8\">";
 str_html+="<meta name=\"viewport\" content=\"width=device-width\">";
 str_html+="<title>[ProjectionBall]</title>";
 str_html+="<style>";
 str_html+="body { font-size:12pt; color:#666666; }";
 str_html+="h1 { font-size:16pt; background-color:#AABBFF; }";
 str_html+="h2 { font-size:16pt; background-color:#AFFFFF; }";
 str_html+="pre { background-color:#EEEEEE; }";
 str_html+="</style>";
 str_html+="</head>";
 
 str_html+="<body>";
 str_html+="<script>";
 str_html+="function sendRemote(){";
 str_html+="send(\"/remote/\");";
 str_html+="document.getElementById(\"NOWstatus\").innerHTML=\"[Remote]\";";
 str_html+="}";
 str_html+="function sendLocal(){";
 str_html+="send(\"/local/\");";
 str_html+="document.getElementById(\"NOWstatus\").innerHTML=\"[Local]\";";
 str_html+="}";
 str_html+="function sendInternal(){";
 str_html+="send(\"/internal/\");";
 str_html+="document.getElementById(\"Datastatus\").innerHTML=\"[Internal Data]\";";
 str_html+="}";
 str_html+="function sendMemory(){";
 str_html+="send(\"/memory/\");";
 str_html+="document.getElementById(\"Datastatus\").innerHTML=\"[Memory Data]\";";
 str_html+="}";
 str_html+="function sendMode0(){";
 str_html+="send(\"/mode0/\");";
 str_html+="document.getElementById(\"MODEstatus\").innerHTML=\"[Animation]\";";
 str_html+="}";
 str_html+="function sendMode1(){";
 str_html+="send(\"/mode1/\");";
 str_html+="document.getElementById(\"MODEstatus\").innerHTML=\"[Rotation]\";";
 str_html+="}";
 str_html+="function sendMode2(){";
 str_html+="send(\"/mode2/\");";
 str_html+="document.getElementById(\"MODEstatus\").innerHTML=\"[One-stroke]\";";
 str_html+="}";
 str_html+="function sendMode3(){";
 str_html+="send(\"/mode3/\");";
 str_html+="document.getElementById(\"MODEstatus\").innerHTML=\"[Always-ON]\";";
 str_html+="}";
 str_html+="function sendPattern0(){";
 str_html+="send(\"/pattern0/\");";
 str_html+="document.getElementById(\"PATTERNstatus\").innerHTML=\"[Star/Data0]\";";
 str_html+="}";
 str_html+="function sendPattern1(){";
 str_html+="send(\"/pattern1/\");";
 str_html+="document.getElementById(\"PATTERNstatus\").innerHTML=\"[Arrow/Data1]\";";
 str_html+="}";
 str_html+="function sendPattern2(){";
 str_html+="send(\"/pattern2/\");";
 str_html+="document.getElementById(\"PATTERNstatus\").innerHTML=\"[Mail/Data2]\";";
 str_html+="}";
 str_html+="function sendPattern3(){";
 str_html+="send(\"/pattern3/\");";
 str_html+="document.getElementById(\"PATTERNstatus\").innerHTML=\"[Smile/Data3]\";";
 str_html+="}";
 str_html+="function send(url){";
 str_html+="var xhr = new XMLHttpRequest();";
 str_html+="xhr.open(\"GET\", url, true);";
 str_html+="xhr.send();";
 str_html+="}";
 str_html+="</script>";
 
 str_html+="<div>";
 str_html+="<h2 >ProjectionBall Remote</h2>";
 str_html+="</div>";
 
 str_html+="<div onclick=\"obj=document.getElementById('open0').style; obj.display=(obj.display=='none')?'block':'none';\">";
 str_html+="<h1 style=\"cursor:pointer;\">▼ Local/Remote</h1>";
 str_html+="</div>";
 str_html+="<div id=\"open0\" style=\"display:none;clear:both;\">";
 str_html+="</br>";
 str_html+="<button id=\"remote\" onClick=sendRemote() style=\"WIDTH:200px; HEIGHT: 30px\">Remote Mode</button>";
 str_html+="</br>";
 str_html+="<button id=\"local\" onClick=sendLocal() style=\"WIDTH:200px; HEIGHT: 30px\">Local Mode</button>";
 str_html+="<p id=\"NOWstatus\"></p>";
 str_html+="</div>";
 
 str_html+="<div onclick=\"obj=document.getElementById('open1').style; obj.display=(obj.display=='none')?'block':'none';\">";
 str_html+="<h1 style=\"cursor:pointer;\">▼ Data</h1>";
 str_html+="</div>";
 str_html+="<div id=\"open1\" style=\"display:none;clear:both;\">";
 str_html+="</br>";
 str_html+="<button id=\"internal\" onClick=sendInternal() style=\"WIDTH:200px; HEIGHT: 30px\">Internal Data</button>";
 str_html+="</br>";
 str_html+="<button id=\"memory\" onClick=sendMemory() style=\"WIDTH:200px; HEIGHT: 30px\">Memory Data</button>";
 str_html+="<p id=\"Datastatus\"></p>";
 str_html+="</div>";
 
 str_html+="<div onclick=\"obj=document.getElementById('open2').style; obj.display=(obj.display=='none')?'block':'none';\">";
 str_html+="<h1 style=\"cursor:pointer;\">▼ Mode</h1>";
 str_html+="</div>";
 str_html+="<div id=\"open2\" style=\"display:none;clear:both;\">";
 str_html+="</br>";
 str_html+="<button id=\"mode0\" onClick=sendMode0() style=\"WIDTH:200px; HEIGHT: 30px\">Animation</button>";
 str_html+="</br>";
 str_html+="<button id=\"mode1\" onClick=sendMode1() style=\"WIDTH:200px; HEIGHT: 30px\">Rotation</button>";
 str_html+="</br>";
 str_html+="<button id=\"mode2\" onClick=sendMode2() style=\"WIDTH:200px; HEIGHT: 30px\">One-stroke</button>";
 str_html+="</br>";
 str_html+="<button id=\"mode3\" onClick=sendMode3() style=\"WIDTH:200px; HEIGHT: 30px\">Always-ON</button>";
 str_html+="<p id=\"MODEstatus\"></p>";
 str_html+="</div>";
 
 str_html+="<div onclick=\"obj=document.getElementById('open3').style; obj.display=(obj.display=='none')?'block':'none';\">";
 str_html+="<h1 style=\"cursor:pointer;\">▼ Pattern</h1>";
 str_html+="</div>";
 str_html+="<div id=\"open3\" style=\"display:none;clear:both;\">";
 str_html+="</br>";
 str_html+="<button id=\"pattern0\" onClick=sendPattern0() style=\"WIDTH:200px; HEIGHT: 30px\">Star/Data0</button>";
 str_html+="</br>";
 str_html+="<button id=\"pattern1\" onClick=sendPattern1() style=\"WIDTH:200px; HEIGHT: 30px\">Arrow/Data1</button>";
 str_html+="</br>";
 str_html+="<button id=\"pattern2\" onClick=sendPattern2() style=\"WIDTH:200px; HEIGHT: 30px\">Mail/Data2</button>";
 str_html+="</br>";
 str_html+="<button id=\"pattern3\" onClick=sendPattern3() style=\"WIDTH:200px; HEIGHT: 30px\">Smile/Data3</button>";
 str_html+="<p id=\"PATTERNstatus\"></p>";
 str_html+="</div>";
 
 str_html+="<div onclick=\"obj=document.getElementById('open4').style; obj.display=(obj.display=='none')?'block':'none';\">";
 str_html+="<h1 style=\"cursor:pointer;\">▼ Wifi</h1>";
 str_html+="</div>";
 str_html+="<div id=\"open4\" style=\"display:none;clear:both;\">";
 str_html+="<form method='post'>";
 str_html+="<input type='text' name='SSID' placeholder='SSID'></br>";
 str_html+="<input type='text' name='PASS' placeholder='PASS'></br></br>";
 str_html+="<input type='submit' value='Save'></br>";
 str_html+="</form>";
 str_html+="</div>";
 
 str_html+="<div onclick=\"obj=document.getElementById('open9').style; obj.display=(obj.display=='none')?'block':'none';\">";
 str_html+="<h1 style=\"cursor:pointer;\">▼ INFO</h1>";
 str_html+="</div>";
 str_html+="<div id=\"open9\" style=\"display:none;clear:both;\">";
 str_html+="<p >Version : 1.0.0</p>";
 str_html+="<p >Release : 16/12/28</p>";
 str_html+="<a href=\"http://projectionball.jp/\">Official Web Site</a>";
 str_html+="</br></br>";
 str_html+="<a href=\"https://www.facebook.com/projectionball\">Official Facebook</a>";
 str_html+="</div>";
 str_html+="<p style =\"font-size:10pt\">Copyright&copy; Crescent All Rights Reserved.</p>";
 
 
 str_html+="</body>";
 str_html+="</html>";

}


