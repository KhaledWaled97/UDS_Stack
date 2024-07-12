/*
 * UDS_APP_Diag.c
 *
 *  Created on: Jun 4, 2024
 *      Author: Omnia
 */

#include "APP_UDS_Diag.h"

// there are many ser. has sub,  this var indecate for which sub servise
#define sub_func_control  	1
#define Num_of_Services 	5

Std_ReturnType CanTp_Transmit(uint32_t TxPduId, PduInfoType* PduInfoPtr);


PduInfoType Read_Data_Client;
PduInfoType Write_Data_Client;
PduInfoType Control_Session_Default;
PduInfoType Send_Security_Seed;
PduInfoType Control_Session_Extended;
PduInfoType PduInfoTypePtr;
volatile uint8_t global_sec_flag = 0;
volatile uint8_t global_session = DefaultSession;

volatile uint8_t Security_Service_Availability_Flag = Not_Available;
//uint8_t seed =50 ; // for example
/*Security Variables */
volatile uint32_t Sec_u32SeedValue = 0 ;
Security_Access_State Sec_State = Un_Secure ;
volatile uint32_t Oil_Pressure_var = 0x778899AA;
volatile uint32_t Oil_Temp_var = 0x5566;
volatile uint8_t VIN_number_var[17]= { 0x11, 0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11};
//volatile uint32_t VIN_number_var;

/*************************************************************************************/
/********************************** Test flags ***************************************/
/*************************************************************************************/

// Control Session flags
volatile uint8_t Control_Session_Menu_Flag = 0;
volatile uint8_t Default_Session_Flag = 0;
volatile uint8_t Extended_Session_Flag = 0;


/*************************************************************************************/
/*************************************************************************************/

ServiceInfo pos_Response;

ServiceInfo Control;
PduInfoType msg;
// extern TIM_HandleTypeDef htim6;
volatile uint8_t flag_sub_fun;
volatile uint8_t UDS_Tx_Confirm = 0;
PduInfoType* UDS_Struct;
PduInfoType* PduDataPTR;

uint8_t* seed = NULL;
uint8_t* key = NULL;


uint8_t SupressedPosRes_CLient = 1;
uint8_t SupressedPosRes_Server = 1;

uint8_t Source_Address = Client_Address;
uint8_t Target_Address = Tempreture_Address;


/***************************************************************Init**********************************************************************/





// SA  TA  PCI  SID  DID1  DID2   D a t a
// 03  01   8    22   F1    3D     54 32


// void UDS_Client_Callback(uint32_t TxPduId,PduInfoType *PduInfoPtr)
// PduInfoPtr.data = 03  01   8    22   F1    3D     54 32
// PduInfoPtr.length = 8



// cllient 01
// oil pressure 02
// oil temp 03
// pci = 8 for temp









//For Menus
ClientMenu Menu = Target_Selection_Menu;
uint8_t Menu_Letter = {0};
extern uint8_t SupressedPosRes_CLient;
extern uint8_t Source_Address;
extern uint8_t Target_Address;












void mockUartDriver(const char* data) 
{
    while (*data) 
	{
        uartHandleChar(*data++);
    }
}

void uartHandleChar(uint8_t Menu_Letter) 
{
	//A --> Control Session.
	//B --> Read Data.
	//C --> Write Data.
	//D --> Security Access.
	//E --> Tester Representer.

	//F --> Default Session.
	//G --> Extended Session.

	//H --> Read Oil Temperature.
	//I --> Read Oil Pressure.

	//J --> Seed.
	//K --> Key.

	//M --> Return to Main Menu

	//O --> Write Oil Temperature.
	//P --> Write Oil Pressure.

	//Q --> Yes
	//R --> No.

	//N--> Back to Response Permission

	//T --> Oil Temperature
	//U --> Oil Pressure
	//W --> Broadcast
	//V --> Back To Target Selection Menu

	//X --> Read VIN Number.
	//Y --> Write VIN Number.



	//Switch on User Menus
	switch(Menu_Letter)
	{
	case 'A':
		Menu = Control_Session_Menu;
		break;

	case 'B':
		Menu = Read_Data_Menu;
		break;

	case 'C':
		Menu = Write_Data_Menu;
		break;

	case 'D':
		Menu = Security_Access_Menu;
		break;

	case 'N':
		Menu = Response_Permission_Menu;
		break;

	case 'V':
		Menu = Target_Selection_Menu;
		break;

	case 'T':
		Target_Address = Tempreture_Address;
		Menu = Response_Permission_Menu;
		break;

	case 'U':
		Target_Address = Pressure_Address;
		Menu = Response_Permission_Menu;
		break;

	case 'W':
		Target_Address = Functional_Address;
		Menu = Response_Permission_Menu;
		break;
		
		
		
		
		

	case 'E':
		// UDS_Tester_Presenter_Client();
		
		break;

	case 'F':
		// UDS_Control_Session_Default();
		Default_Session_Flag = 1;
		break;

	case 'G':
		// UDS_Control_Session_Extended();
		Extended_Session_Flag = 1;
		break;


	case 'H':
		DID Read_Oil_Temp = Oil_Temp;
		// UDS_Read_Data_Client(Read_Oil_Temp);
		break;


	case 'I':
		DID Read_Oil_Pressure = Oil_Pressure;
		// UDS_Read_Data_Client(Read_Oil_Pressure);

		break;

	case 'X':
		DID Read_VIN_number = VIN_number;
		// UDS_Read_Data_Client(Read_VIN_number);

		break;


	case 'O':
		DID Write_Oil_Temp = Oil_Temp;
		uint32_t Write_Oil_Temp_data = 0x5432;
		// UDS_Write_Data_Client(Write_Oil_Temp, Write_Oil_Temp_data);
		break;


	case 'P':
		DID Write_Oil_Pressure = Oil_Pressure;
		uint32_t Write_Oil_Pressure_data = 0x54321044;
		// UDS_Write_Data_Client(Write_Oil_Pressure, Write_Oil_Pressure_data);
		break;

	case 'Y':
		DID Write_VIN_number = VIN_number;
		uint32_t Write_VIN_number_data = 0x00;
		// UDS_Write_Data_Client(Write_VIN_number, Write_VIN_number_data);
		break;


	case 'J':
		Sub_Fun sub_fun_seed = Seed;
		// UDS_Send_Security_Client(sub_fun_seed);
		break;


	case 'K':
		Sub_Fun sub_fun_key = Key;
		// A Temporary example for a seed (Accessed in CallBack)
		// UDS_Send_Security_Client(sub_fun_key);
		break;


	case 'M':
		Menu = Main_Menu;
		break;

	case 'Q':
		SupressedPosRes_CLient = 1;
		Menu = Main_Menu;
		break;

	case 'R':
		SupressedPosRes_CLient = 0;
		Menu = Main_Menu;
		break;


	default:
		Menu = Main_Menu;
	}

	Display_Menu();

}




void Display_Menu(void)
{

	switch(Menu)
	{
	case Main_Menu:

		//Default Session Menu
		// HAL_UART_Transmit(&huart2, Menu_Msg_Arr[0], strlen((char*)Menu_Msg_Arr[0]), HAL_MAX_DELAY);    //{"\r\nMain Menu.\r\n"
		// HAL_UART_Transmit(&huart2, Menu_Msg_Arr[1], strlen((char*)Menu_Msg_Arr[1]), HAL_MAX_DELAY);    //"\r\n please Choose Your Service.\r\n",
		// HAL_UART_Transmit(&huart2, Menu_Msg_Arr[2], strlen((char*)Menu_Msg_Arr[2]), HAL_MAX_DELAY);    //"\r\nA --> Control Session.\r\n",
		// HAL_UART_Transmit(&huart2, Menu_Msg_Arr[3], strlen((char*)Menu_Msg_Arr[3]), HAL_MAX_DELAY);    //"\r\nB --> Read Data.\r\n",
		// HAL_UART_Transmit(&huart2, Menu_Msg_Arr[4], strlen((char*)Menu_Msg_Arr[4]), HAL_MAX_DELAY);    //"\r\nC --> Write Data.\r\n",
		// HAL_UART_Transmit(&huart2, Menu_Msg_Arr[5], strlen((char*)Menu_Msg_Arr[5]), HAL_MAX_DELAY);    //"\r\nD --> Security Access.\r\n",
		// HAL_UART_Transmit(&huart2, Menu_Msg_Arr[6], strlen((char*)Menu_Msg_Arr[6]), HAL_MAX_DELAY);    //"\r\nE --> Tester Representer.\r\n"};
		// HAL_UART_Transmit(&huart2, Menu_Msg_Arr[24], strlen((char*)Menu_Msg_Arr[24]), HAL_MAX_DELAY);    //"\r\nN --> Back to Response Permission.\r\n"};
		// HAL_UART_Transmit(&huart2, Menu_Msg_Arr[28], strlen((char*)Menu_Msg_Arr[28]), HAL_MAX_DELAY);    //"\r\nV --> Back To Target Selection Menu.\r\n"
		// HAL_UART_Transmit(&huart2, Menu_Msg_Arr[17], strlen((char*)Menu_Msg_Arr[17]), HAL_MAX_DELAY);    //"\r\n=========================================.\r\n"};
		break;

	case Control_Session_Menu:
		// HAL_UART_Transmit(&huart2, Menu_Msg_Arr[7], strlen((char*)Menu_Msg_Arr[7]), HAL_MAX_DELAY);    //"\r\nChoose Your Session.\r\n"
		// HAL_UART_Transmit(&huart2, Menu_Msg_Arr[8], strlen((char*)Menu_Msg_Arr[8]), HAL_MAX_DELAY);    //"\r\nF --> Default Session.\r\n"
		// HAL_UART_Transmit(&huart2, Menu_Msg_Arr[9], strlen((char*)Menu_Msg_Arr[9]), HAL_MAX_DELAY);    //"\r\nG --> Extended Session.\r\n"
		// HAL_UART_Transmit(&huart2, Menu_Msg_Arr[16], strlen((char*)Menu_Msg_Arr[16]), HAL_MAX_DELAY);    //"\r\nM --> Return to Main Menu.\r\n"
		// HAL_UART_Transmit(&huart2, Menu_Msg_Arr[17], strlen((char*)Menu_Msg_Arr[17]), HAL_MAX_DELAY);    //"\r\n=========================================.\r\n"};
		Control_Session_Menu_Flag = 1;
		break;


	// case Read_Data_Menu:
	// 	// HAL_UART_Transmit(&huart2, Menu_Msg_Arr[10], strlen((char*)Menu_Msg_Arr[10]), HAL_MAX_DELAY);    //"\r\nChoose Your Data.\r\n"

	// 	if(Target_Address == Tempreture_Address || Target_Address == Functional_Address )
	// 	{
	// 		HAL_UART_Transmit(&huart2, Menu_Msg_Arr[11], strlen((char*)Menu_Msg_Arr[11]), HAL_MAX_DELAY);    //"\r\nH --> Read Oil Temperature.\r\n"

	// 	}
	// 	else if (Target_Address == Pressure_Address || Target_Address == Functional_Address)
	// 	{
	// 		HAL_UART_Transmit(&huart2, Menu_Msg_Arr[12], strlen((char*)Menu_Msg_Arr[12]), HAL_MAX_DELAY);    //"\r\nI --> Read Oil Pressure.\r\n"

	// 	}
	// 	else
	// 	{
	// 		//Nothing
	// 	}
	// 	HAL_UART_Transmit(&huart2, Menu_Msg_Arr[31], strlen((char*)Menu_Msg_Arr[31]), HAL_MAX_DELAY);    //"\r\nX --> Read VIN Number.\r\n"
	// 	HAL_UART_Transmit(&huart2, Menu_Msg_Arr[16], strlen((char*)Menu_Msg_Arr[16]), HAL_MAX_DELAY);    //"\r\nM --> Return to Main Menu.\r\n"
	// 	HAL_UART_Transmit(&huart2, Menu_Msg_Arr[17], strlen((char*)Menu_Msg_Arr[17]), HAL_MAX_DELAY);    //"\r\n=========================================.\r\n"};
	// 	break;


	// case Security_Access_Menu:
	// 	HAL_UART_Transmit(&huart2, Menu_Msg_Arr[13], strlen((char*)Menu_Msg_Arr[13]), HAL_MAX_DELAY);    //"\r\nChoose Your Option.\r\n"
	// 	HAL_UART_Transmit(&huart2, Menu_Msg_Arr[14], strlen((char*)Menu_Msg_Arr[14]), HAL_MAX_DELAY);    //"\r\nJ --> Seed.\r\n"
	// 	HAL_UART_Transmit(&huart2, Menu_Msg_Arr[15], strlen((char*)Menu_Msg_Arr[15]), HAL_MAX_DELAY);    //"\r\nK --> Key.\r\n"
	// 	HAL_UART_Transmit(&huart2, Menu_Msg_Arr[16], strlen((char*)Menu_Msg_Arr[16]), HAL_MAX_DELAY);    //"\r\nM --> Return to Main Menu.\r\n"
	// 	HAL_UART_Transmit(&huart2, Menu_Msg_Arr[17], strlen((char*)Menu_Msg_Arr[17]), HAL_MAX_DELAY);    //"\r\n=========================================.\r\n"};
	// 	break;

	// case Write_Data_Menu:
	// 	HAL_UART_Transmit(&huart2, Menu_Msg_Arr[10], strlen((char*)Menu_Msg_Arr[10]), HAL_MAX_DELAY);    //"\r\nChoose Your Data.\r\n"

	// 	if(Target_Address == Tempreture_Address || Target_Address == Functional_Address)
	// 	{
	// 		HAL_UART_Transmit(&huart2, Menu_Msg_Arr[18], strlen((char*)Menu_Msg_Arr[18]), HAL_MAX_DELAY);    //"\r\nO --> Write Oil Temperature.\r\n"

	// 	}
	// 	else if (Target_Address == Pressure_Address || Target_Address == Functional_Address)
	// 	{
	// 		HAL_UART_Transmit(&huart2, Menu_Msg_Arr[19], strlen((char*)Menu_Msg_Arr[19]), HAL_MAX_DELAY);    //"\r\nP --> Write Oil Pressure.\r\n"

	// 	}
	// 	else
	// 	{
	// 		//Nothing
	// 	}
	// 	HAL_UART_Transmit(&huart2, Menu_Msg_Arr[32], strlen((char*)Menu_Msg_Arr[32]), HAL_MAX_DELAY);    //"\r\nY --> Write VIN Number.\r\n"
	// 	HAL_UART_Transmit(&huart2, Menu_Msg_Arr[16], strlen((char*)Menu_Msg_Arr[16]), HAL_MAX_DELAY);    //"\r\nM --> Return to Main Menu.\r\n"
	// 	HAL_UART_Transmit(&huart2, Menu_Msg_Arr[17], strlen((char*)Menu_Msg_Arr[17]), HAL_MAX_DELAY);    //"\r\n=========================================.\r\n"};
	// 	break;

	// case Response_Permission_Menu:
	// 	HAL_UART_Transmit(&huart2, Menu_Msg_Arr[20], strlen((char*)Menu_Msg_Arr[20]), HAL_MAX_DELAY);    //"\r\nDo You want a Response in case of it's Positive?.\r\n"
	// 	HAL_UART_Transmit(&huart2, Menu_Msg_Arr[22], strlen((char*)Menu_Msg_Arr[22]), HAL_MAX_DELAY);    //"\r\nQ --> Yes.\r\n"
	// 	HAL_UART_Transmit(&huart2, Menu_Msg_Arr[21], strlen((char*)Menu_Msg_Arr[21]), HAL_MAX_DELAY);    //"\r\nR --> No.\r\n"
	// 	HAL_UART_Transmit(&huart2, Menu_Msg_Arr[23], strlen((char*)Menu_Msg_Arr[23]), HAL_MAX_DELAY);    //"\r\nM --> Go to Main Menu.\r\n"
	// 	HAL_UART_Transmit(&huart2, Menu_Msg_Arr[28], strlen((char*)Menu_Msg_Arr[28]), HAL_MAX_DELAY);    //"\r\nT --> Oil Temperature.\r\n"
	// 	HAL_UART_Transmit(&huart2, Menu_Msg_Arr[17], strlen((char*)Menu_Msg_Arr[17]), HAL_MAX_DELAY);    //"\r\nU --> Oil Pressure.\r=========================================.\r\n"};
	// 	break;

	// case Target_Selection_Menu:
	// 	HAL_UART_Transmit(&huart2, Menu_Msg_Arr[25], strlen((char*)Menu_Msg_Arr[25]), HAL_MAX_DELAY);    //"\r\nChoose Your Target:.\r\n"
	// 	HAL_UART_Transmit(&huart2, Menu_Msg_Arr[26], strlen((char*)Menu_Msg_Arr[26]), HAL_MAX_DELAY);    //"\r\nT --> Oil Temperature.\r\n"
	// 	HAL_UART_Transmit(&huart2, Menu_Msg_Arr[27], strlen((char*)Menu_Msg_Arr[27]), HAL_MAX_DELAY);    //"\r\nU --> Oil Pressure.\r\n"
	// 	HAL_UART_Transmit(&huart2, Menu_Msg_Arr[30], strlen((char*)Menu_Msg_Arr[30]), HAL_MAX_DELAY);    //"\r\nW --> Broadcast.\r\n"
	// 	HAL_UART_Transmit(&huart2, Menu_Msg_Arr[29], strlen((char*)Menu_Msg_Arr[29]), HAL_MAX_DELAY);    //"\r\nN --> Go to Response Permission.\r\n"};
	// 	HAL_UART_Transmit(&huart2, Menu_Msg_Arr[23], strlen((char*)Menu_Msg_Arr[23]), HAL_MAX_DELAY);    //"\r\nM --> Go to Main Menu.\r\n"
	// 	HAL_UART_Transmit(&huart2, Menu_Msg_Arr[17], strlen((char*)Menu_Msg_Arr[17]), HAL_MAX_DELAY);    //"\r\n=========================================.\r\n"};
	// 	break;

	default:
	// 	HAL_UART_Transmit(&huart2, Menu_Msg_Arr[25], strlen((char*)Menu_Msg_Arr[25]), HAL_MAX_DELAY);    //"\r\nChoose Your Target:.\r\n"
	// 	HAL_UART_Transmit(&huart2, Menu_Msg_Arr[26], strlen((char*)Menu_Msg_Arr[26]), HAL_MAX_DELAY);    //"\r\nT --> Oil Temperature.\r\n"
	// 	HAL_UART_Transmit(&huart2, Menu_Msg_Arr[27], strlen((char*)Menu_Msg_Arr[27]), HAL_MAX_DELAY);    //"\r\nU --> Oil Pressure.\r\n"
	// 	HAL_UART_Transmit(&huart2, Menu_Msg_Arr[30], strlen((char*)Menu_Msg_Arr[30]), HAL_MAX_DELAY);    //"\r\nW --> Broadcast.\r\n"
	// 	HAL_UART_Transmit(&huart2, Menu_Msg_Arr[23], strlen((char*)Menu_Msg_Arr[23]), HAL_MAX_DELAY);    //"\r\nM --> Go to Main Menu.\r\n"
	// 	HAL_UART_Transmit(&huart2, Menu_Msg_Arr[17], strlen((char*)Menu_Msg_Arr[17]), HAL_MAX_DELAY);    //"\r\n=========================================.\r\n"};
		break;

		//Nothing
	}

}
