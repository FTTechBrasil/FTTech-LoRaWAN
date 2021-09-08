/**! -----------------------------------------
 * The MIT License (MIT)
 * 
 * Copyright (c) 2021 FTTech
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 * 
 * -----------------------------------------
 *
 * Send Message OTAA
 * 
 * This examples show how to send a message using RAK811 click through LoRaWAN. 
 * This library uses FTTech SAMD51 Clicks library and a RAK811 click.
 * 
 * 
 * Itens needed:
 *  - FTTech SmartNode Board (This also works with arduino boards)
 *  - RAK811 click
 *
 * -----------------------------------------
*/
#include <FTTech_LoRaWAN.h>

#define DEV_EUI   "XXXXXXXXXXXXXXXX" // Use your device EUI
#define APP_EUI   "XXXXXXXXXXXXXXXX" // Use your application EUI configured on your TTN gateway registration
#define APP_KEY   "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX" // Use your application key configured on your TTN gateway registration 
#define CON_MET   "XXXX" // Connection method, OTAA (default) or ABP
#define REG_COD   "XXXXX" // Region code, US915 is the default
#define POR_SEN   "XX" // Gateway port to send the message to, recommended to use 8-15 if you don't actuallly know what you are doing
#define MESSAGE   "XXXXXXXX" // The message to be sent, for testing porpuses use a reconizable pattern

FT_RAK811 fttechlora(DEV_EUI,APP_EUI,APP_KEY,CON_MET,REG_COD); // Create a object with all parameters

void setup() {
  
  fttechlora.turnLoRaON(); // Turn on alll the clicks, remember to ensure that the Monitor serial is on
  fttechlora.begin(); // Configures the RAK811 click and joins the gateway network
  fttechlora.send(POR_SEN,MESSAGE); // Send a message to the port selected
  
}

void loop() {

}
