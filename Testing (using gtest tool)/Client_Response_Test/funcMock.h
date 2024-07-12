#ifndef _FUNCMOCK_H 
#define _FUNCMOCK_H 


    #define 	serviceNotSupported 					1
	#define 	securityAccessDenied 					2
	#define 	subFunctionNotSupported 				3
    #define 	serviceNotSupportedInActiveSession 		4
    #define 	invalidKey							 	5
    #define 	OilTemperature_Read					 	6
    #define 	OilPressure_Read					 	7
    #define 	VIN_number_Read						 	8
    #define 	OilTemperature_Write				 	9
    #define 	OilPressure_Write 					 	10
    #define 	VIN_number_Write					 	11
    #define 	DefaultSession						 	12
    #define 	ExtendedSession						 	13
    #define 	SecuritySeed						 	14
    #define 	SecurityKey 						 	15
    #define 	TesterPresent						 	16
    #define 	ALL_TEST_CASES						 	17


	void CanTP_Stub(uint8_t Response);
#endif //_FUNCMOCK_H 