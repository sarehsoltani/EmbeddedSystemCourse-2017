#include <MKL25Z4.H>
struct State {
  uint32_t Out; 
  uint32_t Time;  // 1 ms units
  uint32_t Next[4]; // list of next states
}; 
typedef const struct State STyp;
uint32_t CS;  // index of current state
uint32_t Input; 
  
#define goN   0
#define waitN 1
#define goE   2
#define waitE 3
STyp FSM[4] = {
 {0x401,30000,{goN,waitN,goN,waitN}}, 
 {0x402, 5000,{goE,goE,goE,goE}},
 {0x104,30000,{goE,goE,waitE,waitE}},
 {0x204, 5000,{goN,goN,goN,goN}}
};

void delay(unsigned int length_ms)
{
   SIM_SCGC5 |= SIM_SCGC5_LPTMR_MASK;  // Make sure clock is enabled
   LPTMR0_CSR = 0;                     // Reset LPTMR settings
   LPTMR0_CMR = length_ms;             // Set compare value (in ms)
   // Use 1kHz LPO with no prescaler
   LPTMR0_PSR = LPTMR_PSR_PCS(1) | LPTMR_PSR_PBYP_MASK;
    // Start the timer and wait for it to reach the compare value
   LPTMR0_CSR = LPTMR_CSR_TEN_MASK;
   while (!(LPTMR0_CSR & LPTMR_CSR_TCF_MASK));
   LPTMR0_CSR = 0;                     
 }

void init_switch(void){
	//enable clk A , D
	SIM->SCGC5 |= 0x1200; 
	//set pinA1 , A2 , D0 , D1 to GPIO(MUX=001 IN PCREG),IRQC(19:16)=1010I=>Interrupt on falling edge, PE=1 &PS=0 
	PORTD -> PCR[0] |= 0xA0102;
	PORTD -> PCR[1] |= 0xA0102;
	PORTA -> PCR[1] |= 0x100;
	PORTA -> PCR[2] |= 0x100;
	//input
	PTA ->PDDR |= (0<<1);
	PTA ->PDDR |= (0<<2);	
	PTD ->PDDR |= (0<<0);
	PTD ->PDDR |= (0<<1);
	//set
	PTA ->PDOR |= (0<<1);
	PTA ->PDOR |= (0<<2);
	PTD ->PDOR |= (0<<0);
	PTD ->PDOR |= (0<<1);
	
	PORTD_ISFR = PORT_ISFR_ISF(0x01);
	NVIC_SetPriority(PORTD_IRQn,128);
	NVIC_EnableIRQ(PORTD_IRQn);
}

void init_RGB_LEDs(void){
	//GPIO
	PORTB ->PCR[0] |= 0x0100;
	PORTB-> PCR[1] |= 0x0100;
	PORTB-> PCR[2] |= 0x0100;
	PORTB-> PCR[8] |= 0x0100;
	PORTB-> PCR[9] |= 0x0100;
	PORTB-> PCR[10] |= 0x0100;
	// OUTPUT : B18:REDLED B19:GREENLED D1:BLUELED
	PTB->PDDR |= (1<<0);
	PTB->PDDR |= (1<<1);
	PTB->PDDR |= (1<<2);
	PTB->PDDR |= (1<<8);
	PTB->PDDR |= (1<<9);
	PTB->PDDR |= (1<<10);
	//SET 
	PTB->PDOR |= (0<<0);
	PTB->PDOR |= (0<<1);
	PTB->PDOR |= (0<<2);
	PTB->PDOR |= (0<<8);
	PTB->PDOR |= (0<<9);
	PTB->PDOR |= (0<<10);
}


void PORTD_IRQHandler(void)
{
	if(PORTD_ISFR & 0x01){
		// interrupt from north
		//PTB->PDOR
		if(CS == goN){
		}
		else if (CS == waitN){
			PTB->PDOR = 0x021;
			delay(5000);
			PTB->PDOR |= FSM[CS].Out;
		}
		else if (CS == goE){
			PTB->PDOR = 0x021;
			delay(5000);
			PTB->PDOR |= FSM[CS].Out;
		}
		else if (CS == waitE){
			PTB->PDOR = 0x021;
			delay(5000);
			PTB->PDOR |= FSM[CS].Out;
		}
	}
	
	if(PORTD_ISFR & 0x02){
		// interrupt from east
		if(CS == goN){
			PTB->PDOR = 0x00C;
			delay(5000);
			PTB->PDOR |= FSM[CS].Out;
		}
		else if (CS == waitN){
			PTB->PDOR = 0x00C;
			delay(5000);
			PTB->PDOR |= FSM[CS].Out;
		}
		else if (CS == goE){
		}
		else if (CS == waitE){
			PTB->PDOR = 0x00C;
			delay(5000);
			PTB->PDOR |= FSM[CS].Out;
		}
	}
}

int main(){
	
  init_switch();
	init_RGB_LEDs();

  CS = goN; // start state
  while(1) {
    PTB->PDOR |= FSM[CS].Out;  // set lights
    delay(FSM[CS].Time);
    Input =(PTA->PDIR & 0x06) >> 1;  // read sensors
    CS = FSM[CS].Next[Input];  
  }

}
