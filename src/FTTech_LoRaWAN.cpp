/***********************************************************************
 * Includes
 ***********************************************************************/
#include "FTTech_SAMD51Clicks.h"
#include "FTTech_LoRaWAN.h"


/***********************************************************************
 * Class contructors
 ***********************************************************************/	

FT_RAK811::FT_RAK811(String dev_eui, String app_eui, String app_key, String method, String region){
    _dev_eui = dev_eui;
    _app_eui = app_eui;
    _app_key = app_key;
    _method  = method;
    _region  = region;
}


/***********************************************************************
 * Public Methods of the Class
 ***********************************************************************/

void FT_RAK811::turnLoRaON(void){
    Serial.begin(9600);
    while (!Serial);    
    _LORAWANSERIAL.begin(115200);
    while(!_LORAWANSERIAL);
    FTClicks.turnON(_LORACLICK);
    SendCommand("at+version\r\n");
    delay(5000);
    ShowDebug();
    return;
}

void FT_RAK811::begin(void){
    SetKeys();
    SetRegion();
    SendJoinReq();
    Serial.println("");
    Sleep();
    return;
}

void FT_RAK811::send(String port, String data){
    WakeUp();
    SendCommand("at+send=0,"+ port +","+ data +"\r\n");
    ShowDebug();
    Sleep();
    return;
}

/***********************************************************************
 * Private Methods of the Class
 ***********************************************************************/

void FT_RAK811::ShowDebug(void){
    String response = "";
    while(_LORAWANSERIAL.available()){ 
        char ch = _LORAWANSERIAL.read(); 
        response += ch; 
    } 
    Serial.println(response);
    delay(1000);
    return;
}

void FT_RAK811::SendCommand(String atComm){
    _LORAWANSERIAL.print(atComm);
    delay(1000);
    return;
}

void FT_RAK811::Sleep(void){
    SendCommand("at+set_config=device:sleep:1\r\n");
    ShowDebug();
    return;
}

void FT_RAK811::WakeUp(void){
    SendCommand("at+set_config=device:sleep:0\r\n");
    ShowDebug();
    return;
}

void FT_RAK811::SendJoinReq(void){
    uint8_t methodid;
    if(_method=="OTAA"){
        methodid=0;
    } else if (_method=="ABP"){
        methodid=1;
    } else {
        Serial.print("Invalid join method.");
        return;
    }
    SendCommand("at+set_config=lora:join_mode:" + (String)methodid + "\r\n");
    ShowDebug();
    SendCommand("at+join\r\n");
    delay(5000);
    ShowDebug();
    return;
}

void FT_RAK811::SetDR(String dr){
    Serial.print("DR set to "+ dr +":");
    SendCommand("at+set_config=lora:dr:"+ dr +"\r\n");
    ShowDebug();
}

void FT_RAK811::SetADR(String adr){
    Serial.print("ADR set to "+ adr +":");
    SendCommand("at+set_config=lora:adr:"+ adr +"\r\n");
    ShowDebug();
}

void FT_RAK811::SetRegion(){
    Serial.print("Setting region to "+ _region + ":");
    SendCommand("at+set_config=lora:region:"+ _region +"\r\n");
    ShowDebug();
}

void FT_RAK811::SetKeys(void){
    Serial.print("DEV EUI ("+ _dev_eui +") configuration:");
    SendCommand("at+set_config=lora:dev_eui:" + _dev_eui + "\r\n");
    ShowDebug();
    Serial.print("APP EUI ("+ _app_eui +") configuration:");
    SendCommand("at+set_config=lora:app_eui:" + _app_eui + "\r\n");
    ShowDebug();
    Serial.print("APP KEY ("+ _app_key +") configuration:");
    SendCommand("at+set_config=lora:app_key:" + _app_key + "\r\n");
    ShowDebug();
    SetADR("0"); // Disable SetADR
    SetDR("0"); // Minimum payload, maximum coverage
    return;
}
