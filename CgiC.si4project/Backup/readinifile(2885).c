#include "common.h"

char html[] = "<html>\
<head>\
    <meta charset=\"utf-8\">\
    <title>中石油配置文件修改</title>\
    <style>\
        #b{\
            width: 30%%;\
			float:left;\
			line-height:25px;\
			padding:5px;\
        }\
		#c{			\
            width: 35%%;\
        }\
		#d{			\
            width: 25%%;\
        }\
		#e{\
            width: 30%%;\
			//text-align:right;\
        }\
		#footer {\
			width: 79%%;\
			height:100px;\
			text-align:right;\
			position:relative;\
			bottom:0;\
		}\
		\
		#button_read{\
			margin:10px;\
		}\
		#button_submit{\
			margin:0px;\
		}\
		#b,#c,#d,#e,#footer,#button_read,#button_submit{\
			display: inline-block;\
		}\
    </style>\
</head>\
<body onload=\"checkboxOnclick()\">	\
    <script type=\"text/javascript\"> \
	function myFunction(){\
	   alert(document.getElementById(\"IFSF_Node\").value);\
	}\
	function checkboxOnclick(){	/*检查是否选中，若没有选中，则不显示相关信息*/	\
		if(document.getElementById(\"Gun_Info2\").checked==true){\
			document.getElementById(\"Gun_Info2_display\").style.display = \"block\";\
		}else{\
			document.getElementById(\"Gun_Info2_display\").style.display = \"none\";\
		}	\
	\
		if(document.getElementById(\"Gun_Info3\").checked==true){\
			document.getElementById(\"Gun_Info3_display\").style.display = \"block\";\
		}else{\
			document.getElementById(\"Gun_Info3_display\").style.display = \"none\";\
		}\
	\
		if(document.getElementById(\"Gun_Info4\").checked==true){\
			document.getElementById(\"Gun_Info4_display\").style.display = \"block\";\
		}else{\
			document.getElementById(\"Gun_Info4_display\").style.display = \"none\";\
		}\
	}\
	function checkForm(){/*submit时被调用，没选中的CheckBox则让其失效*/\
		if(document.getElementById(\"Gun_Info2\").checked==true){\
			document.getElementById(\"Gun_Info2\").disabled=false;\
			document.getElementById(\"Gun_num2\").disabled=false;\
			document.getElementById(\"My_Node2\").disabled=false;\
			document.getElementById(\"Pri_Ver2\").disabled=false;\
			document.getElementById(\"price2\").disabled=false;\
			document.getElementById(\"oilcode2\").disabled=false;\
			document.getElementById(\"Uart_NO2\").disabled=false;\
			document.getElementById(\"Uart_Speed2\").disabled=false;\
			document.getElementById(\"Uart_Data_Bits2\").disabled=false;\
			document.getElementById(\"Uart_Stop_Bits2\").disabled=false;\
			document.getElementById(\"Uart_Parity2\").disabled=false;\
		}else{			\
			document.getElementById(\"Gun_Info2\").disabled=true;\
			document.getElementById(\"Gun_num2\").disabled=true;\
			document.getElementById(\"My_Node2\").disabled=true;\
			document.getElementById(\"Pri_Ver2\").disabled=true;\
			document.getElementById(\"price2\").disabled=true;\
			document.getElementById(\"oilcode2\").disabled=true;\
			document.getElementById(\"Uart_NO2\").disabled=true;\
			document.getElementById(\"Uart_Speed2\").disabled=true;\
			document.getElementById(\"Uart_Data_Bits2\").disabled=true;\
			document.getElementById(\"Uart_Stop_Bits2\").disabled=true;\
			document.getElementById(\"Uart_Parity2\").disabled=true;	\
		}	\
	\
		if(document.getElementById(\"Gun_Info3\").checked==true){\
			document.getElementById(\"Gun_Info3\").disabled=false;\
			document.getElementById(\"Gun_num3\").disabled=false;\
			document.getElementById(\"My_Node3\").disabled=false;\
			document.getElementById(\"Pri_Ver3\").disabled=false;\
			document.getElementById(\"price3\").disabled=false;\
			document.getElementById(\"oilcode3\").disabled=false;\
			document.getElementById(\"Uart_NO3\").disabled=false;\
			document.getElementById(\"Uart_Speed3\").disabled=false;\
			document.getElementById(\"Uart_Data_Bits3\").disabled=false;\
			document.getElementById(\"Uart_Stop_Bits3\").disabled=false;\
			document.getElementById(\"Uart_Parity3\").disabled=false;	\
		}else{			\
			document.getElementById(\"Gun_Info3\").disabled=true;\
			document.getElementById(\"Gun_num3\").disabled=true;\
			document.getElementById(\"My_Node3\").disabled=true;\
			document.getElementById(\"Pri_Ver3\").disabled=true;\
			document.getElementById(\"price3\").disabled=true;\
			document.getElementById(\"oilcode3\").disabled=true;\
			document.getElementById(\"Uart_NO3\").disabled=true;\
			document.getElementById(\"Uart_Speed3\").disabled=true;\
			document.getElementById(\"Uart_Data_Bits3\").disabled=true;\
			document.getElementById(\"Uart_Stop_Bits3\").disabled=true;\
			document.getElementById(\"Uart_Parity3\").disabled=true;	\
		}\
	\
		if(document.getElementById(\"Gun_Info4\").checked==true){\
			document.getElementById(\"Gun_Info4\").disabled=false;\
			document.getElementById(\"Gun_num4\").disabled=false;\
			document.getElementById(\"My_Node4\").disabled=false;\
			document.getElementById(\"Pri_Ver4\").disabled=false;\
			document.getElementById(\"price4\").disabled=false;\
			document.getElementById(\"oilcode4\").disabled=false;\
			document.getElementById(\"Uart_NO4\").disabled=false;\
			document.getElementById(\"Uart_Speed4\").disabled=false;\
			document.getElementById(\"Uart_Data_Bits4\").disabled=false;\
			document.getElementById(\"Uart_Stop_Bits4\").disabled=false;\
			document.getElementById(\"Uart_Parity4\").disabled=false;	\
		}else{			\
			document.getElementById(\"Gun_Info4\").disabled=true;\
			document.getElementById(\"Gun_num4\").disabled=true;\
			document.getElementById(\"My_Node4\").disabled=true;\
			document.getElementById(\"Pri_Ver4\").disabled=true;\
			document.getElementById(\"price4\").disabled=true;\
			document.getElementById(\"oilcode4\").disabled=true;\
			document.getElementById(\"Uart_NO4\").disabled=true;\
			document.getElementById(\"Uart_Speed4\").disabled=true;\
			document.getElementById(\"Uart_Data_Bits4\").disabled=true;\
			document.getElementById(\"Uart_Stop_Bits4\").disabled=true;\
			document.getElementById(\"Uart_Parity4\").disabled=true;\
		}\
	}\
	</script>\
	<noscript>抱歉，你的浏览器不支持 JavaScript!</noscript>\
	<form action=\"/cgi-bin/writeinifile.cgi\" onsubmit=\"checkForm()\" method=\"post\">\
			<div id=\"b\">	\
				<b>[FS_EPS]设置:</b><br>\
				<div id=\"e\">FS 节点:</div><input type=\"text\" name=\"IFSF_Node\" value=\"%s\"><br>\
				<div id=\"e\">FS IP:</div><input type=\"text\" name=\"FS_IP\"   value=\"%s\"><br>	\
				<div id=\"e\">FS TCP端口号:</div><input type=\"text\" name=\"FS_Port\"   value=\"%s\"><br>\
				<div id=\"e\">FS UDP端口号:</div><input type=\"text\" name=\"FS_Udp_Port\"   value=\"%s\"><br>\
				<div id=\"e\">EPS IP:</div><input type=\"text\" name=\"EPS_IP\"   value=\"%s\"><br>\
				<div id=\"e\">EPS 端口号:</div><input type=\"text\" name=\"EPS_Port\"   value=\"%s\"><br>\
				<div id=\"e\">FS 心跳间隔:</div><input type=\"text\" name=\"Time_Out\"   value=\"%s\"><br>\
				<div id=\"e\">FS 重连间隔:</div><input type=\"text\" name=\"Time_Reconnect\"   value=\"%s\"><br>\
				<div id=\"e\">OPT超时时间:</div><input type=\"text\" name=\"OPT_IS_Online\"   value=\"%s\"><br>\
			</div>\
			<div id=\"b\">\
				<b>[Board_Info]设置:</b><br>\
				<div id=\"c\">本机IP:</div><input type=\"text\" name=\"My_IP\" value=\"%s\"><br>\
				<div id=\"c\">本机TCP服务端口 :</div><input type=\"text\" name=\"My_FS_Port\"   value=\"%s\"><br>\
				<div id=\"c\">本机EPS服务端口:</div><input type=\"text\" name=\"My_EPS_Port\"   value=\"%s\"><br>\
				<div id=\"c\">本机掩码:</div><input type=\"text\" name=\"My_Mask\"   value=\"%s\"><br>\
				<div id=\"c\">本机网关:</div><input type=\"text\" name=\"My_Gateway\"   value=\"%s\"><br>\
				<div id=\"c\">本机广播地址:</div><input type=\"text\" name=\"My_Broadcast_IP\"   value=\"%s\"><br>\
				<div id=\"c\">本机广播端口:</div><input type=\"text\" name=\"My_Broadcast_Port\"   value=\"%s\"><br>\
				<div id=\"c\">心跳灯使能:</div><input type=\"text\" name=\"Led_ON\"   value=\"%s\"><br>\
			</div>\
			<div id=\"b\">\
				<b>[Gun_Info1]设置:</b><br>\
				<div id=\"d\">枪号:</div><input type=\"text\" name=\"Gun_num\"   value=\"%s\"><br>\
				<div id=\"d\">节点号:</div><input type=\"text\" name=\"My_Node\"   value=\"%s\"><br>\
				<div id=\"d\">单价版本号:</div><input type=\"text\" name=\"Pri_Ver\"   value=\"%s\"><br>\
				<div id=\"d\">单价:</div><input type=\"text\" name=\"price\"   value=\"%s\"><br>\
				<div id=\"d\">油品代码:</div><input type=\"text\" name=\"oilcode\"   value=\"%s\"><br>\
				<div id=\"d\">串口号:</div><input type=\"text\" name=\"Uart_NO\"   value=\"%s\"><br>\
				<div id=\"d\">波特率:</div><input type=\"text\" name=\"Uart_Speed\"   value=\"%s\"><br>\
				<div id=\"d\">数据位:</div><input type=\"text\" name=\"Uart_Data_Bits\"   value=\"%s\"><br>\
				<div id=\"d\">停止位:</div><input type=\"text\" name=\"Uart_Stop_Bits\"   value=\"%s\"><br>\
				<div id=\"d\">校验位:</div><input type=\"text\" name=\"Uart_Parity\"   value=\"%s\"><br><br>\
			</div>	\
			<div id=\"b\">\
			<b><input type=\"checkbox\" name=\"Gun_Info2\" value=\"[Gun_Info2]\" id=\"Gun_Info2\" onclick=\"checkboxOnclick()\" %s/>[Gun_Info2]设置:</b><br>\
				<label id=\"Gun_Info2_display\" style=\"display:block;\">\
					<div id=\"e\">枪号:</div><input type=\"text\" name=\"Gun_num2\"  id=\"Gun_num2\" value=\"%s\"><br>\
					<div id=\"e\">节点号:</div><input type=\"text\" name=\"My_Node2\"  id=\"My_Node2\" value=\"%s\"><br>\
					<div id=\"e\">单价版本号:</div><input type=\"text\" name=\"Pri_Ver2\"  id=\"Pri_Ver2\"  value=\"%s\"><br>\
					<div id=\"e\">单价:</div><input type=\"text\" name=\"price2\"  id=\"price2\"  value=\"%s\"><br>\
					<div id=\"e\">油品代码:</div><input type=\"text\" name=\"oilcode2\"  id=\"oilcode2\" value=\"%s\"><br>\
					<div id=\"e\">串口号:</div><input type=\"text\" name=\"Uart_NO2\"  id=\"Uart_NO2\" value=\"%s\"><br>\
					<div id=\"e\">波特率:</div><input type=\"text\" name=\"Uart_Speed2\"  id=\"Uart_Speed2\" value=\"%s\"><br>\
					<div id=\"e\">数据位:</div><input type=\"text\" name=\"Uart_Data_Bits2\"  id=\"Uart_Data_Bits2\" value=\"%s\"><br>\
					<div id=\"e\">停止位:</div><input type=\"text\" name=\"Uart_Stop_Bits2\"  id=\"Uart_Stop_Bits2\" value=\"%s\"><br>\
					<div id=\"e\">校验位:</div><input type=\"text\" name=\"Uart_Parity2\"  id=\"Uart_Parity2\" value=\"%s\"><br><br>\
				</label>\
			</div>\
			<div id=\"b\">\
			<b><input type=\"checkbox\" name=\"Gun_Info3\" value=\"[Gun_Info3]\" id=\"Gun_Info3\" onclick=\"checkboxOnclick()\" %s/>[Gun_Info3]设置:</b><br>\
				<label id=\"Gun_Info3_display\" style=\"display:block;\">\
					<div id=\"c\">枪号:</div><input type=\"text\" name=\"Gun_num3\"  id=\"Gun_num3\" value=\"%s\"><br>\
					<div id=\"c\">节点号:</div><input type=\"text\" name=\"My_Node3\"  id=\"My_Node3\" value=\"%s\"><br>\
					<div id=\"c\">单价版本号:</div><input type=\"text\" name=\"Pri_Ver3\"  id=\"Pri_Ver3\" value=\"%s\"><br>\
					<div id=\"c\">单价:</div><input type=\"text\" name=\"price3\"  id=\"price3\" value=\"%s\"><br>\
					<div id=\"c\">油品代码:</div><input type=\"text\" name=\"oilcode3\"  id=\"oilcode3\"  value=\"%s\"><br>\
					<div id=\"c\">串口号:</div><input type=\"text\" name=\"Uart_NO3\"  id=\"Uart_NO3\" value=\"%s\"><br>									\
					<div id=\"c\">波特率:</div><input type=\"text\" name=\"Uart_Speed3\"  id=\"Uart_Speed3\" value=\"%s\"><br>\
					<div id=\"c\">数据位:</div><input type=\"text\" name=\"Uart_Data_Bits3\"  id=\"Uart_Data_Bits3\" value=\"%s\"><br>\
					<div id=\"c\">停止位:</div><input type=\"text\" name=\"Uart_Stop_Bits3\"  id=\"Uart_Stop_Bits3\" value=\"%s\"><br>\
					<div id=\"c\">校验位:</div><input type=\"text\" name=\"Uart_Parity3\"  id=\"Uart_Parity3\" value=\"%s\"><br><br>\
				</label>\
			</div>\
			<div id=\"b\">\
			<b><input type=\"checkbox\" name=\"Gun_Info4\" value=\"[Gun_Info4]\" id=\"Gun_Info4\" onclick=\"checkboxOnclick()\" %s/>[Gun_Info4]设置:</b><br>\
				<label id=\"Gun_Info4_display\" style=\"display:block;\">\
					<div id=\"d\">枪号:</div><input type=\"text\" name=\"Gun_num4\"  id=\"Gun_num4\" value=\"%s\"><br>\
					<div id=\"d\">节点号:</div><input type=\"text\" name=\"My_Node4\"  id=\"My_Node4\" value=\"%s\"><br>\
					<div id=\"d\">单价版本号:</div><input type=\"text\" name=\"Pri_Ver4\"  id=\"Pri_Ver4\" value=\"%s\"><br>\
					<div id=\"d\">单价:</div><input type=\"text\" name=\"price4\"  id=\"price4\" value=\"%s\"><br>\
					<div id=\"d\">油品代码:</div><input type=\"text\" name=\"oilcode4\"  id=\"oilcode4\" value=\"%s\"><br>\
					<div id=\"d\">串口号:</div><input type=\"text\" name=\"Uart_NO4\"  id=\"Uart_NO4\" value=\"%s\"><br>\
					<div id=\"d\">波特率:</div><input type=\"text\" name=\"Uart_Speed4\"  id=\"Uart_Speed4\" value=\"%s\"><br>\
					<div id=\"d\">数据位:</div><input type=\"text\" name=\"Uart_Data_Bits4\"  id=\"Uart_Data_Bits4\" value=\"%s\"><br>\
					<div id=\"d\">停止位:</div><input type=\"text\" name=\"Uart_Stop_Bits4\"  id=\"Uart_Stop_Bits4\" value=\"%s\"><br>\
					<div id=\"d\">校验位:</div><input type=\"text\" name=\"Uart_Parity4\"  id=\"Uart_Parity4\" value=\"%s\"><br><br>\
				</label>\
			</div>\
		<div id=\"footer\">\
			<!--button type=\"button\" onclick=\"myFunction()\">读取</button--> \
			<div id=\"button_read\">\
				<button type=\"button\" style=\"background:#1E90FF;font-size:16px\" onclick=\"window.location.href='./readinifile.cgi'\">读取</button>\
			</div>\
			<div id=\"button_submit\">\
				<input type=\"submit\" style=\"background:#1E90FF;font-size:16px\" value=\"提交\" /> \
			</div>\
		</div>		\
	</form>   \
</body>\
</html>\
";

//读取FS_EPS下的值
void ReadInifileFS_EPS()
{
	iniFileLoad(inifile_Name);
	iniGetString("FS_EPS", "IFSF_Node", conf.IFSF_Node,sizeof(conf.IFSF_Node), "null");
    iniGetString("FS_EPS", "FS_IP", conf.FS_IP,sizeof(conf.FS_IP), "null");
    iniGetString("FS_EPS", "FS_Port", conf.FS_Port,sizeof(conf.FS_Port), "null");
    iniGetString("FS_EPS", "FS_Udp_Port", conf.FS_Udp_Port,sizeof(conf.FS_Udp_Port), "null");    
    iniGetString("FS_EPS", "EPS_IP", conf.EPS_IP,sizeof(conf.EPS_IP), "null");
    iniGetString("FS_EPS", "EPS_Port", conf.EPS_Port,sizeof(conf.EPS_Port), "null");
    iniGetString("FS_EPS", "Time_Out", conf.Time_Out,sizeof(conf.Time_Out), "null");
    iniGetString("FS_EPS", "Time_Reconnect", conf.Time_Reconnect,sizeof(conf.Time_Reconnect), "null");
	iniGetString("FS_EPS", "OPT_IS_Online", conf.OPT_IS_Online,sizeof(conf.OPT_IS_Online), "null");
}

//读取Board_Info下的值
void ReadInifileBoard_Info()
{
	iniGetString("Board_Info", "My_IP", conf.My_IP,sizeof(conf.My_IP), "null");
	iniGetString("FS_EPS", "My_FS_Port", conf.My_FS_Port,sizeof(conf.My_FS_Port), "null");
    iniGetString("Board_Info", "My_EPS_Port", conf.My_EPS_Port,sizeof(conf.My_EPS_Port), "null");
    iniGetString("Board_Info", "My_Mask", conf.My_Mask,sizeof(conf.My_Mask), "null");
    iniGetString("Board_Info", "My_Gateway", conf.My_Gateway,sizeof(conf.My_Gateway), "null");
    iniGetString("Board_Info", "My_Broadcast_IP", conf.My_Broadcast_IP,sizeof(conf.My_Broadcast_IP), "null");
    iniGetString("Board_Info", "My_Broadcast_Port", conf.My_Broadcast_Port,sizeof(conf.My_Broadcast_Port), "null");
    iniGetString("Board_Info", "Led_ON", conf.Led_ON,sizeof(conf.Led_ON), "null");    
}


//读取Gun_Info下的值
void ReadInifileGun_Info(char *section)
{
	char gunnum=0;	
	gunnum = section[strlen(section)-1]-'0';
	if(gunnum<1 || gunnum>4 ) return;
	iniGetString(section, "Gun_num", conf.Gun_num[gunnum-1],sizeof(conf.Gun_num[gunnum-1]), "null");
    iniGetString(section, "My_Node", conf.My_Node[gunnum-1],sizeof(conf.My_Node[gunnum-1]), "null");
    iniGetString(section, "Pri_Ver", conf.Pri_Ver[gunnum-1],sizeof(conf.Pri_Ver[gunnum-1]), "null");
    iniGetString(section, "price", conf.price[gunnum-1],sizeof(conf.price[gunnum-1]), "null");    
    iniGetString(section, "oilcode", conf.oilcode[gunnum-1],sizeof(conf.oilcode[gunnum-1]), "null");
    iniGetString(section, "Uart_NO", conf.Uart_NO[gunnum-1],sizeof(conf.Uart_NO[gunnum-1]), "null");
    iniGetString(section, "Uart_Speed", conf.Uart_Speed[gunnum-1],sizeof(conf.Uart_Speed[gunnum-1]), "null");
    iniGetString(section, "Uart_Data_Bits", conf.Uart_Data_Bits[gunnum-1],sizeof(conf.Uart_Data_Bits[gunnum-1]), "null");
	iniGetString(section, "Uart_Stop_Bits", conf.Uart_Stop_Bits[gunnum-1],sizeof(conf.Uart_Stop_Bits[gunnum-1]), "null");
	iniGetString(section, "Uart_Parity", conf.Uart_Parity[gunnum-1],sizeof(conf.Uart_Parity[gunnum-1]), "null");
}


int cgiMain()
{
	cgiHeaderContentType("text/html");
	ReadInifileFS_EPS();
	ReadInifileBoard_Info();
    ReadInifileGun_Info("Gun_Info1");
	ReadInifileGun_Info("Gun_Info2");
	ReadInifileGun_Info("Gun_Info3");
	ReadInifileGun_Info("Gun_Info4");
    fprintf(cgiOut, html,
    	//FS_EPS
    	conf.IFSF_Node,
		conf.FS_IP,
		conf.FS_Port,
		conf.FS_Udp_Port,
		conf.EPS_IP,
		conf.EPS_Port,
		conf.Time_Out,
		conf.Time_Reconnect,
		conf.OPT_IS_Online,

		//Board_Info
		conf.My_IP,
		conf.My_FS_Port,
		conf.My_EPS_Port,
		conf.My_Mask,
		conf.My_Gateway,
		conf.My_Broadcast_IP,
		conf.My_Broadcast_Port,
		conf.Led_ON,

		//Gun_Info1
		conf.Gun_num[0],
		conf.My_Node[0],
		conf.Pri_Ver[0],
		conf.price[0],
		conf.oilcode[0],
		conf.Uart_NO[0],
		conf.Uart_Speed[0],
		conf.Uart_Data_Bits[0],
		conf.Uart_Stop_Bits[0],
		conf.Uart_Parity[0],

		//Gun_Info2
		(conf.Gun_num[1][0]!='n')?"checked":"",
		conf.Gun_num[1],
		conf.My_Node[1],
		conf.Pri_Ver[1],
		conf.price[1],
		conf.oilcode[1],
		conf.Uart_NO[1],
		conf.Uart_Speed[1],
		conf.Uart_Data_Bits[1],
		conf.Uart_Stop_Bits[1],
		conf.Uart_Parity[1],

		//Gun_Info3
		(conf.Gun_num[2][0]!='n')?"checked":"",
		conf.Gun_num[2],
		conf.My_Node[2],
		conf.Pri_Ver[2],
		conf.price[2],
		conf.oilcode[2],
		conf.Uart_NO[2],
		conf.Uart_Speed[2],
		conf.Uart_Data_Bits[2],
		conf.Uart_Stop_Bits[2],
		conf.Uart_Parity[2],

		//Gun_Info4
		(conf.Gun_num[3][0]!='n')?"checked":"",
		conf.Gun_num[3],
		conf.My_Node[3],
		conf.Pri_Ver[3],
		conf.price[3],
		conf.oilcode[3],
		conf.Uart_NO[3],
		conf.Uart_Speed[3],
		conf.Uart_Data_Bits[3],
		conf.Uart_Stop_Bits[3],
		conf.Uart_Parity[3]
    	);
    return 0;
}

