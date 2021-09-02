#ifndef FTTech_RAK811
#define FTTech_RAK811

/**************************************************************************!
    @brief  LoRa WAN 20 pins click class
    Currently Supports: 
        RAK811;

***************************************************************************/

#include "FTTech_SAMD51Clicks.h"

#ifdef _VARIANT_SAMD51_1S
    #define _LORAWANSERIAL Serial2
    #define _LORACLICK 2
#endif

#ifdef _VARIANT_SAMD51_3S
    #define _LORAWANSERIAL Serial4
    #define _LORACLICK 4
#endif

class FT_RAK811{
	public:
        //Constructor
        FT_RAK811(String dev_eui, String app_eui, String app_key, String method);

        // Methods
        void turnLoRaON(void);
        void begin(void);
        void send(String port, String data);

    private:
        String _dev_eui;
        String _app_eui;
        String _app_key;
        String _method;

        // Methods
        void ShowDebug(void);
        void SendCommand(String atComm);
        void Sleep(void);
        void WakeUp(void);
        void SendJoinReq(void);
        void SetKeys(void);
        
};

#endif
