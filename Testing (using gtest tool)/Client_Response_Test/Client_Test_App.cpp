// UDS_Diag.cpp
#include <gtest/gtest.h>
#include <gmock/gmock.h>
extern "C"
{
    // #include "example.h"
    #include "APP_UDS_Diag.h"
    #include "APP_UDS_Diag_CFG.h"
    #include "funcMock.h"

/*************************************************************************************************************************************/
/* serviceNotSupported  -  securityAccessDenied  -  subFunctionNotSupported  -  serviceNotSupportedInActiveSession  -  invalidKey    */
/* OilTemperature_Read  -  OilPressure_Read      -  VIN_number_Read                                                                  */
/* OilTemperature_Write -  OilPressure_Write     -  VIN_number_Write                                                                 */
/* DefaultSession       -  ExtendedSession       -  SecuritySeed             - SecurityKey    -    TesterPresent   -  ALL_TEST_CASES */
/*************************************************************************************************************************************/
    #define          Response           ALL_TEST_CASES

    
    volatile uint8_t  Test_Case  = 0;


    extern PduInfoTRx *GlobalRxPduInfoPtr;
    extern volatile uint32_t GlobalRxPduId;
    extern volatile uint8_t UDS_Tx_Confirm;

    /*************************************************************************************/
    /********************************** Test Flags ***************************************/
    /*************************************************************************************/

    // Negative Response Flags
    extern volatile uint8_t serviceNotSupported_Flag;
    extern volatile uint8_t securityAccessDenied_Flag;
    extern volatile uint8_t subFunctionNotSupported_Flag;
    extern volatile uint8_t serviceNotSupportedInActiveSession_Flag;
    extern volatile uint8_t invalidKey_Flag;

    // Read Flags
    extern volatile uint8_t OilTemperature_ReadFlag;
    extern volatile uint8_t OilPressure_ReadFlag;
    extern volatile uint8_t VIN_number_ReadFlag;

    // Write Flags
    extern volatile uint8_t OilTemperature_WriteFlag;
    extern volatile uint8_t OilPressure_WriteFlag;
    extern volatile uint8_t VIN_number_WriteFlag;

    // Control Session Flags
    extern volatile uint8_t DefaultSession_Flag;
    extern volatile uint8_t ExtendedSession_Flag;

    // Security Flags
    extern volatile uint8_t SecuritySeed_Flag;
    extern volatile uint8_t SecurityKey_Flag;

    // Tester presenter Flags
    extern volatile uint8_t TesterPresent_Flag;

    /*************************************************************************************/
    /*************************************************************************************/
}




/***************************************************************************************************************/
/*************************************** Negative Response test cases ******************************************/
/***************************************************************************************************************/
TEST(UDS_Client_NR, ServiceNotSupported_Test)
{
    Test_Case = serviceNotSupported;
    CanTP_Stub(Test_Case);
    // EXPECT_EQ(UDS_Tx_Confirm, 1);
    UDS_MainFunction();

    // Check the return value
    EXPECT_EQ(serviceNotSupported_Flag, 1);
}


TEST(UDS_Client_NR, securityAccessDenied_Test)
{
    Test_Case = securityAccessDenied;
    CanTP_Stub(Test_Case);
    // EXPECT_EQ(UDS_Tx_Confirm, 1);

    UDS_MainFunction();

    // Check the return value
    EXPECT_EQ(securityAccessDenied_Flag, 1);
}


TEST(UDS_Client_NR, subFunctionNotSupported_Test)
{
    Test_Case = subFunctionNotSupported;
    CanTP_Stub(Test_Case);
    // EXPECT_EQ(UDS_Tx_Confirm, 1);

    UDS_MainFunction();

    // Check the return value
    EXPECT_EQ(subFunctionNotSupported_Flag, 1);
}


TEST(UDS_Client_NR, serviceNotSupportedInActiveSession_Test)
{
    Test_Case = serviceNotSupportedInActiveSession;
    CanTP_Stub(Test_Case);
    // EXPECT_EQ(UDS_Tx_Confirm, 1);

    UDS_MainFunction();

    // Check the return value
    EXPECT_EQ(serviceNotSupportedInActiveSession_Flag, 1);
}


TEST(UDS_Client_NR, invalidKey_Test)
{
    Test_Case = invalidKey;
    CanTP_Stub(Test_Case);
    // EXPECT_EQ(UDS_Tx_Confirm, 1);

    UDS_MainFunction();
    
    // Check the return value
    EXPECT_EQ(invalidKey_Flag, 1);
}

/***************************************************************************************************************/
/***************************************************************************************************************/



/***************************************************************************************************************/
/********************************************** Read test cases ************************************************/
/***************************************************************************************************************/

TEST(UDS_Client_PR_Read, OilTemperature_Test)
{
    Test_Case = OilTemperature_Read;
    CanTP_Stub(Test_Case);
    // EXPECT_EQ(UDS_Tx_Confirm, 1);

    UDS_MainFunction();
    
    // Check the return value
    EXPECT_EQ(OilTemperature_ReadFlag, 1);
}


TEST(UDS_Client_PR_Read, OilPressure_Test)
{
    Test_Case = OilPressure_Read;
    CanTP_Stub(Test_Case);
    // EXPECT_EQ(UDS_Tx_Confirm, 1);

    UDS_MainFunction();
    
    // Check the return value
    EXPECT_EQ(OilPressure_ReadFlag, 1);
}


TEST(UDS_Client_PR_Read, VIN_number_Test)
{
    Test_Case = VIN_number_Read;
    CanTP_Stub(Test_Case);
    // EXPECT_EQ(UDS_Tx_Confirm, 1);

    UDS_MainFunction();
    
    // Check the return value
    EXPECT_EQ(VIN_number_ReadFlag, 1);
}
/***************************************************************************************************************/
/***************************************************************************************************************/





/***************************************************************************************************************/
/********************************************** Write test cases ************************************************/
/***************************************************************************************************************/

TEST(UDS_Client_PR_Write, OilTemperature_Test)
{
    Test_Case = OilTemperature_Write;
    CanTP_Stub(Test_Case);
    // EXPECT_EQ(UDS_Tx_Confirm, 1);

    UDS_MainFunction();
    
    // Check the return value
    EXPECT_EQ(OilTemperature_WriteFlag, 1);
}


TEST(UDS_Client_PR_Write, OilPressure_Test)
{
    Test_Case = OilPressure_Write;
    CanTP_Stub(Test_Case);
    // EXPECT_EQ(UDS_Tx_Confirm, 1);

    UDS_MainFunction();
    
    // Check the return value
    EXPECT_EQ(OilPressure_WriteFlag, 1);
}


TEST(UDS_Client_PR_Write, VIN_number_Test)
{
    Test_Case = VIN_number_Write;
    CanTP_Stub(Test_Case);
    // EXPECT_EQ(UDS_Tx_Confirm, 1);

    UDS_MainFunction();
    
    // Check the return value
    EXPECT_EQ(VIN_number_WriteFlag, 1);
}
/***************************************************************************************************************/
/***************************************************************************************************************/





/***************************************************************************************************************/
/**************************************** Control Session test cases *******************************************/
/***************************************************************************************************************/

TEST(UDS_Client_PR_ControlSession, DefaultSession_Test)
{
    Test_Case = DefaultSession;
    CanTP_Stub(Test_Case);
    // EXPECT_EQ(UDS_Tx_Confirm, 1);

    UDS_MainFunction();
    
    // Check the return value
    EXPECT_EQ(DefaultSession_Flag, 1);
}


TEST(UDS_Client_PR_ControlSession, ExtendedSession_Test)
{
    Test_Case = ExtendedSession;
    CanTP_Stub(Test_Case);
    // EXPECT_EQ(UDS_Tx_Confirm, 1);

    UDS_MainFunction();
    
    // Check the return value
    EXPECT_EQ(ExtendedSession_Flag, 1);
}

/***************************************************************************************************************/
/***************************************************************************************************************/





/***************************************************************************************************************/
/**************************************** Security test cases *******************************************/
/***************************************************************************************************************/

TEST(UDS_Client_PR_ControlSession, SecuritySeed_Test)
{
    Test_Case = SecuritySeed;
    CanTP_Stub(Test_Case);
    // EXPECT_EQ(UDS_Tx_Confirm, 1);

    UDS_MainFunction();
    
    // Check the return value
    EXPECT_EQ(SecuritySeed_Flag, 1);
}


TEST(UDS_Client_PR_ControlSession, SecurityKey_Test)
{
    Test_Case = SecurityKey;
    CanTP_Stub(Test_Case);
    // EXPECT_EQ(UDS_Tx_Confirm, 1);

    UDS_MainFunction();
    
    // Check the return value
    EXPECT_EQ(SecurityKey_Flag, 1);
}

/***************************************************************************************************************/
/***************************************************************************************************************/




/***************************************************************************************************************/
/**************************************** Tester Presenter test cases *******************************************/
/***************************************************************************************************************/

TEST(UDS_Client_PR_ControlSession, TesterPresent_Test)
{
    Test_Case = TesterPresent;
    CanTP_Stub(Test_Case);
    // EXPECT_EQ(UDS_Tx_Confirm, 1);

    UDS_MainFunction();
    
    // Check the return value
    EXPECT_EQ(TesterPresent_Flag, 1);
}


/***************************************************************************************************************/
/***************************************************************************************************************/
















void CanTP_Stub(uint8_t Test_Case)
{
    uint32_t testRxPduId = 0;
    PduInfoType testPduInfo;

#if Response == serviceNotSupported
    testPduInfo.Length = 6;
    testPduInfo.Data[0] = 0x06;  // PCI
    testPduInfo.Data[1] = 0x7F;  // negative Response
    testPduInfo.Data[2] = 0x3D;  // Source Addressing "Server node" 3D or 4D
    testPduInfo.Data[3] = 0xF1;  // Target Addressing "Client node" 
    testPduInfo.Data[4] = 0x99;  // SID_NR_INDEX ... may be any SID
    testPduInfo.Data[5] = 0x11;  // NRC_INDEX for invalidKey

    UDS_Client_Callback(testRxPduId, &testPduInfo);


#elif Response == securityAccessDenied
    testPduInfo.Length = 6;
    testPduInfo.Data[0] = 0x06;  // PCI
    testPduInfo.Data[1] = 0x7F;  // negative Response
    testPduInfo.Data[2] = 0x3D;  // Source Addressing "Server node" 3D or 4D
    testPduInfo.Data[3] = 0xF1;  // Target Addressing "Client node" 
    testPduInfo.Data[4] = 0x99;  // SID_NR_INDEX may be any SID
    testPduInfo.Data[5] = 0x33;  // NRC_INDEX for securityAccessDenied

    UDS_Client_Callback(testRxPduId, &testPduInfo);


#elif Response == subFunctionNotSupported
    testPduInfo.Length = 6;
    testPduInfo.Data[0] = 0x06;  // PCI
    testPduInfo.Data[1] = 0x7F;  // negative Response
    testPduInfo.Data[2] = 0x3D;  // Source Addressing "Server node" 3D or 4D
    testPduInfo.Data[3] = 0xF1;  // Target Addressing "Client node" 
    testPduInfo.Data[4] = 0x99;  // SID_NR_INDEX may be any SID
    testPduInfo.Data[5] = 0x12;  // NRC_INDEX for invalidKey

    UDS_Client_Callback(testRxPduId, &testPduInfo);


#elif Response == serviceNotSupportedInActiveSession
    testPduInfo.Length = 6;
    testPduInfo.Data[0] = 0x06;  // PCI
    testPduInfo.Data[1] = 0x7F;  // negative Response
    testPduInfo.Data[2] = 0x3D;  // Source Addressing "Server node" 3D or 4D
    testPduInfo.Data[3] = 0xF1;  // Target Addressing "Client node" 
    testPduInfo.Data[4] = 0x99;  // SID_NR_INDEX may be any SID
    testPduInfo.Data[5] = 0x7F;  // NRC_INDEX for invalidKey

    UDS_Client_Callback(testRxPduId, &testPduInfo);


#elif Response == invalidKey
    testPduInfo.Length = 6;
    testPduInfo.Data[0] = 0x06;  // PCI
    testPduInfo.Data[1] = 0x7F;  // negative Response
    testPduInfo.Data[2] = 0x3D;  // Source Addressing "Server node" 3D or 4D
    testPduInfo.Data[3] = 0xF1;  // Target Addressing "Client node" 
    testPduInfo.Data[4] = 0x99;  // SID_NR_INDEX
    testPduInfo.Data[5] = 0x35;  // NRC_INDEX for invalidKey

    UDS_Client_Callback(testRxPduId, &testPduInfo);


/********************************************** Read test cases ************************************************/
#elif Response == OilTemperature_Read
    testPduInfo.Length = 8;
    testPduInfo.Data[0] = 0x08;  // PCI
    testPduInfo.Data[1] = 0x3D;  // Source Addressing "Temperature node" 
    testPduInfo.Data[2] = 0xF1;  // Target Addressing "Client node" 
    testPduInfo.Data[3] = 0x62;  // SID + 0x40
    testPduInfo.Data[4] = 0xF1;  // DID_1
    testPduInfo.Data[5] = 0x3D;  // DID_2
    testPduInfo.Data[6] = 0x54;  // Data
    testPduInfo.Data[7] = 0x32;  // Data

    UDS_Client_Callback(testRxPduId, &testPduInfo);


#elif Response == OilPressure_Read
    testPduInfo.Length = 10;
    testPduInfo.Data[0] = 0x10;  // PCI
    testPduInfo.Data[1] = 0x4D;  // Source Addressing "Pressure node" 
    testPduInfo.Data[2] = 0xF1;  // Target Addressing "Client node" 
    testPduInfo.Data[3] = 0x62;  // SID + 0x40
    testPduInfo.Data[4] = 0xF5;  // DID_1
    testPduInfo.Data[5] = 0x3D;  // DID_2
    testPduInfo.Data[6] = 0x54;  // Data
    testPduInfo.Data[7] = 0x32;  // Data
    testPduInfo.Data[8] = 0x88;  // Data
    testPduInfo.Data[9] = 0x77;  // Data
    UDS_Client_Callback(testRxPduId, &testPduInfo);


#elif Response == VIN_number_Read
    testPduInfo.Length = 23;
    testPduInfo.Data[0] = 0x23;  // PCI
    testPduInfo.Data[1] = 0x3D;  // Source Addressing "Server node" maybe 0x3D or 0x4D 
    testPduInfo.Data[2] = 0xF1;  // Target Addressing "Client node" 
    testPduInfo.Data[3] = 0x62;  // SID + 0x40
    testPduInfo.Data[4] = 0xF2;  // DID_1
    testPduInfo.Data[5] = 0x3D;  // DID_2
    testPduInfo.Data[6] = 0x54;  // Data
    testPduInfo.Data[7] = 0x32;  // Data
    testPduInfo.Data[8] = 0x88;  // Data
    testPduInfo.Data[9] = 0x77;  // Data
    testPduInfo.Data[10] = 0x54;  // Data
    testPduInfo.Data[11] = 0x32;  // Data
    testPduInfo.Data[12] = 0x88;  // Data
    testPduInfo.Data[13] = 0x77;  // Data
    testPduInfo.Data[14] = 0x54;  // Data
    testPduInfo.Data[15] = 0x32;  // Data
    testPduInfo.Data[16] = 0x88;  // Data
    testPduInfo.Data[17] = 0x77;  // Data
    testPduInfo.Data[18] = 0x54;  // Data
    testPduInfo.Data[19] = 0x32;  // Data
    testPduInfo.Data[20] = 0x88;  // Data
    testPduInfo.Data[21] = 0x77;  // Data
    testPduInfo.Data[22] = 0x54;  // Data

    UDS_Client_Callback(testRxPduId, &testPduInfo);
 

/********************************************** Write test cases ************************************************/

#elif Response == OilTemperature_Write
    testPduInfo.Length = 6;
    testPduInfo.Data[0] = 0x06;  // PCI
    testPduInfo.Data[1] = 0x3D;  // Source Addressing "Temperature node" 
    testPduInfo.Data[2] = 0xF1;  // Target Addressing "Client node" 
    testPduInfo.Data[3] = 0x6E;  // SID + 0x40
    testPduInfo.Data[4] = 0xF1;  // DID_1
    testPduInfo.Data[5] = 0x3D;  // DID_2

    UDS_Client_Callback(testRxPduId, &testPduInfo);


#elif Response == OilPressure_Write
    testPduInfo.Length = 6;
    testPduInfo.Data[0] = 0x06;  // PCI
    testPduInfo.Data[1] = 0x4D;  // Source Addressing "Pressure node" 
    testPduInfo.Data[2] = 0xF1;  // Target Addressing "Client node" 
    testPduInfo.Data[3] = 0x6E;  // SID + 0x40
    testPduInfo.Data[4] = 0xF5;  // DID_1
    testPduInfo.Data[5] = 0x3D;  // DID_2

    UDS_Client_Callback(testRxPduId, &testPduInfo);


#elif Response == VIN_number_Write
    testPduInfo.Length = 6;
    testPduInfo.Data[0] = 0x06;  // PCI
    testPduInfo.Data[1] = 0x3D;  // Source Addressing "Server node" maybe 0x3D or 0x4D 
    testPduInfo.Data[2] = 0xF1;  // Target Addressing "Client node" 
    testPduInfo.Data[3] = 0x6E;  // SID + 0x40
    testPduInfo.Data[4] = 0xF2;  // DID_1
    testPduInfo.Data[5] = 0x3D;  // DID_2

    UDS_Client_Callback(testRxPduId, &testPduInfo);


/**************************************** Control Session test cases *******************************************/

#elif Response == DefaultSession
    testPduInfo.Length = 5;
    testPduInfo.Data[0] = 0x05;  // PCI
    testPduInfo.Data[1] = 0x3D;  // Source Addressing "Server node" 0x3D or 0x4D
    testPduInfo.Data[2] = 0xF1;  // Target Addressing "Client node" 
    testPduInfo.Data[3] = 0x50;  // SID + 0x40
    testPduInfo.Data[4] = 0x01;  // Sub_F

    UDS_Client_Callback(testRxPduId, &testPduInfo);


#elif Response == ExtendedSession
    testPduInfo.Length = 5;
    testPduInfo.Data[0] = 0x05;  // PCI
    testPduInfo.Data[1] = 0x3D;  // Source Addressing "Server node" 0x3D or 0x4D
    testPduInfo.Data[2] = 0xF1;  // Target Addressing "Client node" 
    testPduInfo.Data[3] = 0x50;  // SID + 0x40
    testPduInfo.Data[4] = 0x03;  // Sub_F

    UDS_Client_Callback(testRxPduId, &testPduInfo);


/**************************************** Security test cases *******************************************/

#elif Response == SecuritySeed
    testPduInfo.Length = 9;
    testPduInfo.Data[0] = 0x09;  // PCI
    testPduInfo.Data[1] = 0x3D;  // Source Addressing "Server node" 0x3D or 0x4D
    testPduInfo.Data[2] = 0xF1;  // Target Addressing "Client node" 
    testPduInfo.Data[3] = 0x67;  // SID + 0x40
    testPduInfo.Data[4] = 0x01;  // Sub_F
    testPduInfo.Data[5] = 0x11;  // Data
    testPduInfo.Data[6] = 0x11;  // Data
    testPduInfo.Data[7] = 0x11;  // Data
    testPduInfo.Data[8] = 0x11;  // Data

    UDS_Client_Callback(testRxPduId, &testPduInfo);


#elif Response == SecurityKey
    testPduInfo.Length = 5;
    testPduInfo.Data[0] = 0x05;  // PCI
    testPduInfo.Data[1] = 0x3D;  // Source Addressing "Server node" 0x3D or 0x4D
    testPduInfo.Data[2] = 0xF1;  // Target Addressing "Client node" 
    testPduInfo.Data[3] = 0x67;  // SID + 0x40
    testPduInfo.Data[4] = 0x02;  // Sub_F

    UDS_Client_Callback(testRxPduId, &testPduInfo);


/**************************************** Tester Presenter test cases *******************************************/

#elif Response == TesterPresent
    testPduInfo.Length = 4;
    testPduInfo.Data[0] = 0x04;  // PCI
    testPduInfo.Data[1] = 0x3D;  // Source Addressing "Server node" 0x3D or 0x4D
    testPduInfo.Data[2] = 0xF1;  // Target Addressing "Client node" 
    testPduInfo.Data[3] = 0x7E;  // SID + 0x40

    UDS_Client_Callback(testRxPduId, &testPduInfo);

#elif Response == ALL_TEST_CASES
    if (Test_Case == serviceNotSupported)
    {
        testPduInfo.Length = 6;
        testPduInfo.Data[0] = 0x06;  // PCI
        testPduInfo.Data[1] = 0x7F;  // negative Response
        testPduInfo.Data[2] = 0x3D;  // Source Addressing "Server node" 3D or 4D
        testPduInfo.Data[3] = 0xF1;  // Target Addressing "Client node" 
        testPduInfo.Data[4] = 0x99;  // SID_NR_INDEX ... may be any SID
        testPduInfo.Data[5] = 0x11;  // NRC_INDEX for invalidKey

        UDS_Client_Callback(testRxPduId, &testPduInfo);
    }

    else if (Test_Case == securityAccessDenied)
    {
        testPduInfo.Length = 6;
        testPduInfo.Data[0] = 0x06;  // PCI
        testPduInfo.Data[1] = 0x7F;  // negative Response
        testPduInfo.Data[2] = 0x3D;  // Source Addressing "Server node" 3D or 4D
        testPduInfo.Data[3] = 0xF1;  // Target Addressing "Client node" 
        testPduInfo.Data[4] = 0x99;  // SID_NR_INDEX may be any SID
        testPduInfo.Data[5] = 0x33;  // NRC_INDEX for securityAccessDenied

        UDS_Client_Callback(testRxPduId, &testPduInfo);
    }

    else if (Test_Case == subFunctionNotSupported)
    {
        testPduInfo.Length = 6;
        testPduInfo.Data[0] = 0x06;  // PCI
        testPduInfo.Data[1] = 0x7F;  // negative Response
        testPduInfo.Data[2] = 0x3D;  // Source Addressing "Server node" 3D or 4D
        testPduInfo.Data[3] = 0xF1;  // Target Addressing "Client node" 
        testPduInfo.Data[4] = 0x99;  // SID_NR_INDEX may be any SID
        testPduInfo.Data[5] = 0x12;  // NRC_INDEX for invalidKey

        UDS_Client_Callback(testRxPduId, &testPduInfo);
    }

    else if (Test_Case == serviceNotSupportedInActiveSession)
    {
        testPduInfo.Length = 6;
        testPduInfo.Data[0] = 0x06;  // PCI
        testPduInfo.Data[1] = 0x7F;  // negative Response
        testPduInfo.Data[2] = 0x3D;  // Source Addressing "Server node" 3D or 4D
        testPduInfo.Data[3] = 0xF1;  // Target Addressing "Client node" 
        testPduInfo.Data[4] = 0x99;  // SID_NR_INDEX may be any SID
        testPduInfo.Data[5] = 0x7F;  // NRC_INDEX for invalidKey

        UDS_Client_Callback(testRxPduId, &testPduInfo);
    }

    else if (Test_Case == invalidKey)
    {
        testPduInfo.Length = 6;
        testPduInfo.Data[0] = 0x06;  // PCI
        testPduInfo.Data[1] = 0x7F;  // negative Response
        testPduInfo.Data[2] = 0x3D;  // Source Addressing "Server node" 3D or 4D
        testPduInfo.Data[3] = 0xF1;  // Target Addressing "Client node" 
        testPduInfo.Data[4] = 0x99;  // SID_NR_INDEX
        testPduInfo.Data[5] = 0x35;  // NRC_INDEX for invalidKey

        UDS_Client_Callback(testRxPduId, &testPduInfo);
    }

    /********************************************** Read test cases ************************************************/
    else if (Test_Case == OilTemperature_Read)
    {
        testPduInfo.Length = 8;
        testPduInfo.Data[0] = 0x08;  // PCI
        testPduInfo.Data[1] = 0x3D;  // Source Addressing "Temperature node" 
        testPduInfo.Data[2] = 0xF1;  // Target Addressing "Client node" 
        testPduInfo.Data[3] = 0x62;  // SID + 0x40
        testPduInfo.Data[4] = 0xF1;  // DID_1
        testPduInfo.Data[5] = 0x3D;  // DID_2
        testPduInfo.Data[6] = 0x54;  // Data
        testPduInfo.Data[7] = 0x32;  // Data

        UDS_Client_Callback(testRxPduId, &testPduInfo);
    }   

    else if (Test_Case == OilPressure_Read)
    {
        testPduInfo.Length = 10;
        testPduInfo.Data[0] = 0x10;  // PCI
        testPduInfo.Data[1] = 0x4D;  // Source Addressing "Pressure node" 
        testPduInfo.Data[2] = 0xF1;  // Target Addressing "Client node" 
        testPduInfo.Data[3] = 0x62;  // SID + 0x40
        testPduInfo.Data[4] = 0xF5;  // DID_1
        testPduInfo.Data[5] = 0x3D;  // DID_2
        testPduInfo.Data[6] = 0x54;  // Data
        testPduInfo.Data[7] = 0x32;  // Data
        testPduInfo.Data[8] = 0x88;  // Data
        testPduInfo.Data[9] = 0x77;  // Data
        UDS_Client_Callback(testRxPduId, &testPduInfo);
    }

    else if (Test_Case == VIN_number_Read)
    {
        testPduInfo.Length = 23;
        testPduInfo.Data[0] = 0x23;  // PCI
        testPduInfo.Data[1] = 0x3D;  // Source Addressing "Server node" maybe 0x3D or 0x4D 
        testPduInfo.Data[2] = 0xF1;  // Target Addressing "Client node" 
        testPduInfo.Data[3] = 0x62;  // SID + 0x40
        testPduInfo.Data[4] = 0xF2;  // DID_1
        testPduInfo.Data[5] = 0x3D;  // DID_2
        testPduInfo.Data[6] = 0x54;  // Data
        testPduInfo.Data[7] = 0x32;  // Data
        testPduInfo.Data[8] = 0x88;  // Data
        testPduInfo.Data[9] = 0x77;  // Data
        testPduInfo.Data[10] = 0x54;  // Data
        testPduInfo.Data[11] = 0x32;  // Data
        testPduInfo.Data[12] = 0x88;  // Data
        testPduInfo.Data[13] = 0x77;  // Data
        testPduInfo.Data[14] = 0x54;  // Data
        testPduInfo.Data[15] = 0x32;  // Data
        testPduInfo.Data[16] = 0x88;  // Data
        testPduInfo.Data[17] = 0x77;  // Data
        testPduInfo.Data[18] = 0x54;  // Data
        testPduInfo.Data[19] = 0x32;  // Data
        testPduInfo.Data[20] = 0x88;  // Data
        testPduInfo.Data[21] = 0x77;  // Data
        testPduInfo.Data[22] = 0x54;  // Data

        UDS_Client_Callback(testRxPduId, &testPduInfo);
    }

    /********************************************** Write test cases ************************************************/

    else if (Test_Case == OilTemperature_Write)
    {
        testPduInfo.Length = 6;
        testPduInfo.Data[0] = 0x06;  // PCI
        testPduInfo.Data[1] = 0x3D;  // Source Addressing "Temperature node" 
        testPduInfo.Data[2] = 0xF1;  // Target Addressing "Client node" 
        testPduInfo.Data[3] = 0x6E;  // SID + 0x40
        testPduInfo.Data[4] = 0xF1;  // DID_1
        testPduInfo.Data[5] = 0x3D;  // DID_2

        UDS_Client_Callback(testRxPduId, &testPduInfo);
    }

    else if (Test_Case == OilPressure_Write)
    {
        testPduInfo.Length = 6;
        testPduInfo.Data[0] = 0x06;  // PCI
        testPduInfo.Data[1] = 0x4D;  // Source Addressing "Pressure node" 
        testPduInfo.Data[2] = 0xF1;  // Target Addressing "Client node" 
        testPduInfo.Data[3] = 0x6E;  // SID + 0x40
        testPduInfo.Data[4] = 0xF5;  // DID_1
        testPduInfo.Data[5] = 0x3D;  // DID_2

        UDS_Client_Callback(testRxPduId, &testPduInfo);
    }

    else if (Test_Case == VIN_number_Write)
    {
        testPduInfo.Length = 6;
        testPduInfo.Data[0] = 0x06;  // PCI
        testPduInfo.Data[1] = 0x3D;  // Source Addressing "Server node" maybe 0x3D or 0x4D 
        testPduInfo.Data[2] = 0xF1;  // Target Addressing "Client node" 
        testPduInfo.Data[3] = 0x6E;  // SID + 0x40
        testPduInfo.Data[4] = 0xF2;  // DID_1
        testPduInfo.Data[5] = 0x3D;  // DID_2

        UDS_Client_Callback(testRxPduId, &testPduInfo);
    }

    /**************************************** Control Session test cases *******************************************/

    else if (Test_Case == DefaultSession)
    {
        testPduInfo.Length = 5;
        testPduInfo.Data[0] = 0x05;  // PCI
        testPduInfo.Data[1] = 0x3D;  // Source Addressing "Server node" 0x3D or 0x4D
        testPduInfo.Data[2] = 0xF1;  // Target Addressing "Client node" 
        testPduInfo.Data[3] = 0x50;  // SID + 0x40
        testPduInfo.Data[4] = 0x01;  // Sub_F

        UDS_Client_Callback(testRxPduId, &testPduInfo);
    }

    else if (Test_Case == ExtendedSession)
    {
        testPduInfo.Length = 5;
        testPduInfo.Data[0] = 0x05;  // PCI
        testPduInfo.Data[1] = 0x3D;  // Source Addressing "Server node" 0x3D or 0x4D
        testPduInfo.Data[2] = 0xF1;  // Target Addressing "Client node" 
        testPduInfo.Data[3] = 0x50;  // SID + 0x40
        testPduInfo.Data[4] = 0x03;  // Sub_F

        UDS_Client_Callback(testRxPduId, &testPduInfo);
    }

    /**************************************** Security test cases *******************************************/

    else if (Test_Case == SecuritySeed)
    {
        testPduInfo.Length = 9;
        testPduInfo.Data[0] = 0x09;  // PCI
        testPduInfo.Data[1] = 0x3D;  // Source Addressing "Server node" 0x3D or 0x4D
        testPduInfo.Data[2] = 0xF1;  // Target Addressing "Client node" 
        testPduInfo.Data[3] = 0x67;  // SID + 0x40
        testPduInfo.Data[4] = 0x01;  // Sub_F
        testPduInfo.Data[5] = 0x11;  // Data
        testPduInfo.Data[6] = 0x11;  // Data
        testPduInfo.Data[7] = 0x11;  // Data
        testPduInfo.Data[8] = 0x11;  // Data

        UDS_Client_Callback(testRxPduId, &testPduInfo);
    }

    else if (Test_Case == SecurityKey)
    {
        testPduInfo.Length = 5;
        testPduInfo.Data[0] = 0x05;  // PCI
        testPduInfo.Data[1] = 0x3D;  // Source Addressing "Server node" 0x3D or 0x4D
        testPduInfo.Data[2] = 0xF1;  // Target Addressing "Client node" 
        testPduInfo.Data[3] = 0x67;  // SID + 0x40
        testPduInfo.Data[4] = 0x02;  // Sub_F

        UDS_Client_Callback(testRxPduId, &testPduInfo);
    }

    /**************************************** Tester Presenter test cases *******************************************/

    else if (Test_Case == TesterPresent)
    {
        testPduInfo.Length = 4;
        testPduInfo.Data[0] = 0x04;  // PCI
        testPduInfo.Data[1] = 0x3D;  // Source Addressing "Server node" 0x3D or 0x4D
        testPduInfo.Data[2] = 0xF1;  // Target Addressing "Client node" 
        testPduInfo.Data[3] = 0x7E;  // SID + 0x40

        UDS_Client_Callback(testRxPduId, &testPduInfo);
    }

#else
#endif

}













int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
