#include "common.h"

char debug[] = "<html>\
<head>\
	<meta charset=\"utf-8\">\
	<title>Modify Info</title>\
</head>\
<body>%s\n\
</body>\
</html>\
";

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

Conf form;


void ModifyValueFromForm(char *section,char *key,char *confvalue,char *formvalue)
{
	cgiFormString(key, formvalue, sizeof(formvalue));
	if(strcmp(formvalue, confvalue))//!=
	{
		iniSetString(section,key, formvalue);
		fprintf(cgiOut,"<lable> size = "30" %s</lable> -> %s ==> old value:<font size=5 color=\"blue\">%s</font> new value:",section,key,confvalue);
		fprintf(cgiOut,"<font size=5 color=\"red\">%s</font><br>",formvalue);
	}
	else//==
	{
		fprintf(cgiOut,"%s -> %s ==> old value == new value %s<br>",section,key,confvalue);
	}
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
	ModifyValueFromForm("FS_EPS","IFSF_Node",conf.IFSF_Node,form.IFSF_Node);
	ModifyValueFromForm("FS_EPS","FS_IP",conf.FS_IP,form.FS_IP);
	return 0;
}

