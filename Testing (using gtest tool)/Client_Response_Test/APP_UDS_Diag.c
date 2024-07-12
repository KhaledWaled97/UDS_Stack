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

// Negative response flags
volatile uint8_t serviceNotSupported_Flag = 0;
volatile uint8_t securityAccessDenied_Flag = 0;
volatile uint8_t subFunctionNotSupported_Flag = 0;
volatile uint8_t serviceNotSupportedInActiveSession_Flag = 0;
volatile uint8_t invalidKey_Flag = 0;

// Read flags
volatile uint8_t OilTemperature_ReadFlag = 0;
volatile uint8_t OilPressure_ReadFlag = 0;
volatile uint8_t VIN_number_ReadFlag = 0;

// Write flags
volatile uint8_t OilTemperature_WriteFlag = 0;
volatile uint8_t OilPressure_WriteFlag = 0;
volatile uint8_t VIN_number_WriteFlag = 0;

// Control Session flags
volatile uint8_t DefaultSession_Flag = 0;
volatile uint8_t ExtendedSession_Flag = 0;

// Security flags
volatile uint8_t SecuritySeed_Flag = 0;
volatile uint8_t SecurityKey_Flag = 0;

// Tester presenter flags
volatile uint8_t TesterPresent_Flag = 0;

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


void UDS_Init(void)
{

}


/***************************************************************Read**********************************************************************/


/***************************************************************Shared Functions**********************************************************************/




/***************************************************************Server**********************************************************************/


/***************************************************************************************************/



void UDS_MainFunction()
{
	// while(1)
	{
		if(UDS_Tx_Confirm)
		{
			UDS_Tx_Confirm = 0;
			if ( UDS_Struct ->Data[Neg_Res_INDEX] == 0x7f)
			{
				switch(UDS_Struct ->Data[NRC_INDEX])
				{
				case serviceNotSupported :
					// HAL_UART_Transmit(&huart2, (uint8_t*) "\r\nThis Service is not Available.\r\n",strlen("\r\nThis Service is not Available.\r\n"), HAL_MAX_DELAY);
					serviceNotSupported_Flag = 1;
					break ;

				case securityAccessDenied :
					// HAL_UART_Transmit(&huart2, (uint8_t*) "\r\nNot Secured, Please Enter a Key.\r\n",strlen("\r\nNot Secured, Please Enter a Key.\r\n"), HAL_MAX_DELAY);
					securityAccessDenied_Flag = 1;
					break ;

				case subFunctionNotSupported :
					// HAL_UART_Transmit(&huart2, (uint8_t*) "\r\nWrong Session, Please Enter Extended Session.\r\n",strlen("\r\nWrong Session, Please Enter Extended Session.\r\n"), HAL_MAX_DELAY);
					subFunctionNotSupported_Flag = 1;
					break ;

				case serviceNotSupportedInActiveSession :
					// HAL_UART_Transmit(&huart2, (uint8_t*) "\r\nWrong Session, Please Enter Extended Session.\r\n",strlen("\r\nWrong Session, Please Enter Extended Session.\r\n"), HAL_MAX_DELAY);
					serviceNotSupportedInActiveSession_Flag = 1;
					break ;

				case invalidKey :
					// HAL_UART_Transmit(&huart2, (uint8_t*) "\r\nWrong Key.\r\n",strlen("\r\nWrong Key.\r\n"), HAL_MAX_DELAY);
					invalidKey_Flag = 1;
					break ;

				default:
					//Nothing
				}
			}

			else {
				UDS_Struct->Data[SID] = UDS_Struct->Data[SID] - 0x40;
				if (UDS_Struct->Data[SID] == Read_Service)

				{
					if  ( UDS_Struct->Data[DID_1] == Oil_Temp_First_byte &&  UDS_Struct->Data[DID_2] == Oil_Temp_Second_byte )
					{
						OilTemperature_ReadFlag = 1;
						// HAL_UART_Transmit(&huart2, (uint8_t*) "\r\nOil Temp:\r\n", strlen("\r\nOil Temp:\r\n"), HAL_MAX_DELAY);
						// sendHexArrayAsASCII((uint8_t*)&UDS_Struct->Data[Data_DID],2);

					}

					else if  ( UDS_Struct->Data[DID_1] == Oil_Pressure_First_byte &&  UDS_Struct->Data[DID_2] == Oil_Pressure_Second_byte  )
					{
						OilPressure_ReadFlag = 1;
						// HAL_UART_Transmit(&huart2, (uint8_t*) "\r\nOil Pressure:\r\n", strlen("\r\nOil Pressure:\r\n"), HAL_MAX_DELAY);
						// sendHexArrayAsASCII((uint8_t*)&UDS_Struct->Data[Data_DID],4);

					}

					else if  ( UDS_Struct->Data[DID_1] == VIN_number_First_byte &&  UDS_Struct->Data[DID_2] == VIN_number_Second_byte  )
					{
						VIN_number_ReadFlag = 1;
						// HAL_UART_Transmit(&huart2, (uint8_t*) "\r\nVIN Number:\r\n", strlen("\r\nVIN Number:\r\n"), HAL_MAX_DELAY);
						// sendHexArrayAsASCII((uint8_t*)&UDS_Struct->Data[Data_DID],17);
						//sendHexArrayAsASCII((uint8_t*)&UDS_Struct->Data[Data_DID],17);

					}
				}

				/*  Write IDS Message */
				else if (UDS_Struct->Data[SID] == Write_Service)

				{

					if ( UDS_Struct->Data[DID_1] == Oil_Temp_First_byte &&  UDS_Struct->Data[DID_2] == Oil_Temp_Second_byte )
					{
						// HAL_UART_Transmit(&huart2, (uint8_t*) "\r\nOil Temperature Written successfully.\r\n", strlen("\r\nOil Temperature Written successfully .\r\n"), HAL_MAX_DELAY);
						OilTemperature_WriteFlag = 1;
					}

					else if  ( UDS_Struct->Data[DID_1] == Oil_Pressure_First_byte &&  UDS_Struct->Data[DID_2] == Oil_Pressure_Second_byte  )
					{
						// HAL_UART_Transmit(&huart2, (uint8_t*) "\r\nOil Pressure Written successfully.\r\n", strlen("\r\nOil Pressure Written successfully .\r\n"), HAL_MAX_DELAY);
						OilPressure_WriteFlag = 1;
					}

					else if  ( UDS_Struct->Data[DID_1] == VIN_number_First_byte &&  UDS_Struct->Data[DID_2] == VIN_number_Second_byte   )
					{
						// HAL_UART_Transmit(&huart2, (uint8_t*) "\r\nVIN Number Written successfully.\r\n", strlen("\r\nVIN Number Written successfully .\r\n"), HAL_MAX_DELAY);
						VIN_number_WriteFlag = 1;
					}
				}
				/*  Control Service  Session */

				else if (UDS_Struct->Data[SID] == Control_Service)

				{

					switch ( UDS_Struct->Data[Sub_F] )
					{

					case DefaultSession :
						// HAL_UART_Transmit(&huart2, (uint8_t*) "\r\nIt's Default Session!\r\n", strlen("\r\nIt's Default Session!\r\n"), HAL_MAX_DELAY);
						//UDS_Read_Data_Client(Frame_Info.DID);
						DefaultSession_Flag = 1;
						break ;

					case ExtendedSession :
						// HAL_UART_Transmit(&huart2,(uint8_t*) "\r\nIt's Extended Session!\r\n", strlen("\r\nIt's Extended Session!\r\n"), HAL_MAX_DELAY);
						//UDS_Read_Data_Client(Frame_Info.DID);
						ExtendedSession_Flag = 1;
						break ;
					}
				}
				/*  Security Service  */

				else if (UDS_Struct->Data[SID] == Security_Service)

				{

					switch ( UDS_Struct->Data[Sub_F] )
					{

					case Seed :
						// HAL_UART_Transmit(&huart2, (uint8_t*) "\r\nSeed is:\r\n", strlen ("\r\nSeed is:\r\n"), HAL_MAX_DELAY);
						// sendHexArrayAsASCII((uint8_t*)&UDS_Struct->Data[Data_Sub_Fun],4);
						SecuritySeed_Flag = 1;
						break ;

					case Key :
						// HAL_UART_Transmit(&huart2, (uint8_t*) "\r\nKey is Compatible!\r\n", strlen ( "\r\nKey is Compatible!\r\n"), HAL_MAX_DELAY);
						SecurityKey_Flag = 1;
						break ;

					}
				}
				/*  Tester_Representer_Service  */

				else if (UDS_Struct->Data[SID] == Tester_Representer_Service)

				{

					// HAL_UART_Transmit(&huart2,(uint8_t*) "\r\nECU Reseted!\r\n", strlen("\r\n ECU Reseted!\r\n"), HAL_MAX_DELAY);
					TesterPresent_Flag = 1;
				}

				else { /* no thing  */	}

			}

		}

		// vTaskDelay(50);
	}
}

void UDS_Client_Callback(uint32_t TxPduId,PduInfoType *PduInfoPtr)
{
	UDS_Tx_Confirm = 1;
	UDS_Struct = PduInfoPtr;

}



// SA  TA  PCI  SID  DID1  DID2   D a t a
// 03  01   8    22   F1    3D     54 32


// void UDS_Client_Callback(uint32_t TxPduId,PduInfoType *PduInfoPtr)
// PduInfoPtr.data = 03  01   8    22   F1    3D     54 32
// PduInfoPtr.length = 8



// cllient 01
// oil pressure 02
// oil temp 03
// pci = 8 for temp
