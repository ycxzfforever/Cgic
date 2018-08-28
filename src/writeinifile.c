#include "common.h"

char debug[] = "<html>\
<head>\
	<meta charset=\"utf-8\">\
	<title>Modify Info</title>\
</head>\
<body>\
</body>\
</html>\
";

void ReadInifileFS_EPS()
{
	iniFileLoad(inifile_Name);
	iniGetString("FS_EPS", "IFSF_Node", conf.IFSF_Node,sizeof(conf.IFSF_Node), NULL);
    iniGetString("FS_EPS", "FS_IP", conf.FS_IP,sizeof(conf.FS_IP), NULL);
    iniGetString("FS_EPS", "FS_Port", conf.FS_Port,sizeof(conf.FS_Port), NULL);
    iniGetString("FS_EPS", "FS_Udp_Port", conf.FS_Udp_Port,sizeof(conf.FS_Udp_Port), NULL);    
    iniGetString("FS_EPS", "EPS_IP", conf.EPS_IP,sizeof(conf.EPS_IP), NULL);
    iniGetString("FS_EPS", "EPS_Port", conf.EPS_Port,sizeof(conf.EPS_Port), NULL);
    iniGetString("FS_EPS", "Time_Out", conf.Time_Out,sizeof(conf.Time_Out), NULL);
    iniGetString("FS_EPS", "Time_Reconnect", conf.Time_Reconnect,sizeof(conf.Time_Reconnect), NULL);
	iniGetString("FS_EPS", "OPT_IS_Online", conf.OPT_IS_Online,sizeof(conf.OPT_IS_Online), NULL);
}


void ReadInifileBoard_Info()
{
	iniGetString("Board_Info", "My_IP", conf.My_IP,sizeof(conf.My_IP), NULL);
	iniGetString("FS_EPS", "My_FS_Port", conf.My_FS_Port,sizeof(conf.My_FS_Port), NULL);
    iniGetString("Board_Info", "My_EPS_Port", conf.My_EPS_Port,sizeof(conf.My_EPS_Port), NULL);
    iniGetString("Board_Info", "My_Mask", conf.My_Mask,sizeof(conf.My_Mask), NULL);
    iniGetString("Board_Info", "My_Gateway", conf.My_Gateway,sizeof(conf.My_Gateway), NULL);
    iniGetString("Board_Info", "My_Broadcast_IP", conf.My_Broadcast_IP,sizeof(conf.My_Broadcast_IP), NULL);
    iniGetString("Board_Info", "My_Broadcast_Port", conf.My_Broadcast_Port,sizeof(conf.My_Broadcast_Port), NULL);
    iniGetString("Board_Info", "Led_ON", conf.Led_ON,sizeof(conf.Led_ON), NULL);    
}



void ReadInifileGun_Info(char *section)
{
	char gunnum=0;	
	gunnum = section[strlen(section)-1]-'0';
	if(gunnum<1 || gunnum>4 ) return;
	iniGetString(section, "Gun_num", conf.Gun_num[gunnum-1],sizeof(conf.Gun_num[gunnum-1]), NULL);
    iniGetString(section, "My_Node", conf.My_Node[gunnum-1],sizeof(conf.My_Node[gunnum-1]), NULL);
    iniGetString(section, "Pri_Ver", conf.Pri_Ver[gunnum-1],sizeof(conf.Pri_Ver[gunnum-1]), NULL);
    iniGetString(section, "price", conf.price[gunnum-1],sizeof(conf.price[gunnum-1]), NULL);    
    iniGetString(section, "oilcode", conf.oilcode[gunnum-1],sizeof(conf.oilcode[gunnum-1]), NULL);
    iniGetString(section, "Uart_NO", conf.Uart_NO[gunnum-1],sizeof(conf.Uart_NO[gunnum-1]), NULL);
    iniGetString(section, "Uart_Speed", conf.Uart_Speed[gunnum-1],sizeof(conf.Uart_Speed[gunnum-1]), NULL);
    iniGetString(section, "Uart_Data_Bits", conf.Uart_Data_Bits[gunnum-1],sizeof(conf.Uart_Data_Bits[gunnum-1]), NULL);
	iniGetString(section, "Uart_Stop_Bits", conf.Uart_Stop_Bits[gunnum-1],sizeof(conf.Uart_Stop_Bits[gunnum-1]), NULL);
	iniGetString(section, "Uart_Parity", conf.Uart_Parity[gunnum-1],sizeof(conf.Uart_Parity[gunnum-1]), NULL);
}

Conf form;
char update;//是否有更新数据

void ModifyValueFromForm(char *section,char *key,char *confvalue,char *formvalue,int max)
{	
	char tmpkey[16];
	if(!strcmp(section,"Gun_Info2")|| !strcmp(section,"Gun_Info3") || !strcmp(section,"Gun_Info4"))
	{
		sprintf(tmpkey,"%s%d",key,section[8]-'0');
	}
	else
	{
		strcpy(tmpkey,key);			
	}

	cgiFormString(tmpkey, formvalue, max);
	
	if(strcmp(formvalue, confvalue))//!=
	{

		iniSetString(section,key, formvalue);
		fprintf(cgiOut,"<lable style=\"display:inline-block;width:6%%;\">%s</lable> -> <lable style=\"display:inline-block;width:9%%;\">%s</lable> ==> old value:<lable style=\"display:inline-block;width:10%%;\"><font size=5 color=\"blue\">%s</lable></font>new value:",section,key,confvalue);
		fprintf(cgiOut,"<font size=5 color=\"red\">%s</font><br>",formvalue);	
		update=1;
	}
	else//==
	{
		//fprintf(cgiOut,"<lable style=\"display:inline-block;width:6%%;\">%s</lable> -> <lable style=\"display:inline-block;width:9%%;\">%s</lable> ==> old value == new value(%s)<br>",section,key,confvalue);
	}

}

int cgiMain()
{
	int i=0;
	cgiHeaderContentType("text/html");
	fprintf(cgiOut,debug);	
	ReadInifileFS_EPS();
	ReadInifileBoard_Info();
    ReadInifileGun_Info("Gun_Info1");
	ReadInifileGun_Info("Gun_Info2");
	ReadInifileGun_Info("Gun_Info3");
	ReadInifileGun_Info("Gun_Info4");
	ModifyValueFromForm("FS_EPS","IFSF_Node",conf.IFSF_Node,form.IFSF_Node,sizeof(form.IFSF_Node));
	ModifyValueFromForm("FS_EPS","FS_IP",conf.FS_IP,form.FS_IP,sizeof(form.FS_IP));
	ModifyValueFromForm("FS_EPS","FS_Port",conf.FS_Port,form.FS_Port,sizeof(form.FS_Port));
	ModifyValueFromForm("FS_EPS","FS_Udp_Port",conf.FS_Udp_Port,form.FS_Udp_Port,sizeof(form.FS_Udp_Port));
	ModifyValueFromForm("FS_EPS","EPS_IP",conf.EPS_IP,form.EPS_IP,sizeof(form.EPS_IP));
	ModifyValueFromForm("FS_EPS","EPS_Port",conf.EPS_Port,form.EPS_Port,sizeof(form.EPS_Port));
	ModifyValueFromForm("FS_EPS","Time_Out",conf.Time_Out,form.Time_Out,sizeof(form.Time_Out));
	ModifyValueFromForm("FS_EPS","Time_Reconnect",conf.Time_Reconnect,form.Time_Reconnect,sizeof(form.Time_Reconnect));
	ModifyValueFromForm("FS_EPS","OPT_IS_Online",conf.OPT_IS_Online,form.OPT_IS_Online,sizeof(form.OPT_IS_Online));
	ModifyValueFromForm("FS_EPS","My_FS_Port",conf.My_FS_Port,form.My_FS_Port,sizeof(form.My_FS_Port));

	ModifyValueFromForm("Board_Info","My_IP",conf.My_IP,form.My_IP,sizeof(form.My_IP));
	ModifyValueFromForm("Board_Info","My_EPS_Port",conf.My_EPS_Port,form.My_EPS_Port,sizeof(form.My_EPS_Port));
	ModifyValueFromForm("Board_Info","My_Mask",conf.My_Mask,form.My_Mask,sizeof(form.My_Mask));
	ModifyValueFromForm("Board_Info","My_Gateway",conf.My_Gateway,form.My_Gateway,sizeof(form.My_Gateway));
	ModifyValueFromForm("Board_Info","My_Broadcast_IP",conf.My_Broadcast_IP,form.My_Broadcast_IP,sizeof(form.My_Broadcast_IP));
	ModifyValueFromForm("Board_Info","My_Broadcast_Port",conf.My_Broadcast_Port,form.My_Broadcast_Port,sizeof(form.My_Broadcast_Port));
	ModifyValueFromForm("Board_Info","Led_ON",conf.Led_ON,form.Led_ON,sizeof(form.Led_ON));

	for(i=0;i<4;i++)
	{
		char section[10];
		sprintf(section,"Gun_Info%d",i+1);
		ModifyValueFromForm(section,"Gun_num",conf.Gun_num[i],form.Gun_num[i],sizeof(form.Gun_num[i]));
		ModifyValueFromForm(section,"My_Node",conf.My_Node[i],form.My_Node[i],sizeof(form.My_Node[i]));
		ModifyValueFromForm(section,"price",conf.price[i],form.price[i],sizeof(form.price[i]));
		ModifyValueFromForm(section,"Pri_Ver",conf.Pri_Ver[i],form.Pri_Ver[i],sizeof(form.Pri_Ver[i]));
		ModifyValueFromForm(section,"oilcode",conf.oilcode[i],form.oilcode[i],sizeof(form.oilcode[i]));
		ModifyValueFromForm(section,"Uart_NO",conf.Uart_NO[i],form.Uart_NO[i],sizeof(form.Uart_NO[i]));
		ModifyValueFromForm(section,"Uart_Speed",conf.Uart_Speed[i],form.Uart_Speed[i],sizeof(form.Uart_Speed[i]));
		ModifyValueFromForm(section,"Uart_Data_Bits",conf.Uart_Data_Bits[i],form.Uart_Data_Bits[i],sizeof(form.Uart_Data_Bits[i]));
		ModifyValueFromForm(section,"Uart_Stop_Bits",conf.Uart_Stop_Bits[i],form.Uart_Stop_Bits[i],sizeof(form.Uart_Stop_Bits[i]));
		ModifyValueFromForm(section,"Uart_Parity",conf.Uart_Parity[i],form.Uart_Parity[i],sizeof(form.Uart_Parity[i]));
	}

	if(update==0)
	{		
		fprintf(cgiOut,"All old and new values are equal, nothing to be done!!!");		
	}
	fflush(cgiOut);

	return 0;
}

