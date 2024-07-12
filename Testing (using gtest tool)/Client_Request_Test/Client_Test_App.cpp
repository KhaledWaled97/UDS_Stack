// UDS_Diag.cpp
#include <gtest/gtest.h>
#include <gmock/gmock.h>
extern "C"
{
    // #include "example.h"
    #include "APP_UDS_Diag.h"
    #include "APP_UDS_Diag_CFG.h"

    extern PduInfoTRx *GlobalRxPduInfoPtr;
    extern volatile uint32_t GlobalRxPduId;
    extern volatile uint8_t UDS_Tx_Confirm;

    /*************************************************************************************/
    /********************************** Test flags ***************************************/
    /*************************************************************************************/

    // Control Session flags
    extern volatile uint8_t Control_Session_Menu_Flag;
    extern volatile uint8_t Default_Session_Flag;
    extern volatile uint8_t Extended_Session_Flag;

    /*************************************************************************************/
    /*************************************************************************************/
 
    #define     CONTROL_DEFAULT_SESSION          "AF"
    #define     CONTROL_EXTENDED_SESSION         "AG"

}

/***************************************************************************************************************/
/***************************************** Control Session test cases ******************************************/
/***************************************************************************************************************/

TEST(UDS_Client_Request, Default_Session_Test)
{

    mockUartDriver(CONTROL_DEFAULT_SESSION);

    // Check the return value
    EXPECT_EQ(Control_Session_Menu_Flag, 1);
    EXPECT_EQ(Default_Session_Flag, 1);
}


TEST(UDS_Client_Request, Extended_Session_Test)
{

    mockUartDriver(CONTROL_EXTENDED_SESSION);

    // Check the return value
    EXPECT_EQ(Control_Session_Menu_Flag, 1);
    EXPECT_EQ(Extended_Session_Flag, 1);
}

/***************************************************************************************************************/
/***************************************************************************************************************/






// /***************************************************************************************************************/
// /********************************************** Read test cases ************************************************/
// /***************************************************************************************************************/

// TEST(UDS_Client_PR_Read, OilTemperature_Test)
// {
//     uint32_t testRxPduId = 0;
//     PduInfoType testPduInfo;
//     testPduInfo.Length = 8;
//     testPduInfo.Data[0] = 0x08;  // PCI
//     testPduInfo.Data[1] = 0x3D;  // Source Addressing "Temperature node" 
//     testPduInfo.Data[2] = 0xF1;  // Target Addressing "Client node" 
//     testPduInfo.Data[3] = 0x62;  // SID + 0x40
//     testPduInfo.Data[4] = 0xF1;  // DID_1
//     testPduInfo.Data[5] = 0x3D;  // DID_2
//     testPduInfo.Data[6] = 0x54;  // Data
//     testPduInfo.Data[7] = 0x32;  // Data

//     UDS_Client_Callback(testRxPduId, &testPduInfo);
//     // EXPECT_EQ(UDS_Tx_Confirm, 1);

//     UDS_MainFunction();
    
//     // Check the return value
//     EXPECT_EQ(OilTemperature_ReadFlag, 1);
// }


// TEST(UDS_Client_PR_Read, OilPressure_Test)
// {
//     uint32_t testRxPduId = 0;
//     PduInfoType testPduInfo;
//     testPduInfo.Length = 10;
//     testPduInfo.Data[0] = 0x10;  // PCI
//     testPduInfo.Data[1] = 0x4D;  // Source Addressing "Pressure node" 
//     testPduInfo.Data[2] = 0xF1;  // Target Addressing "Client node" 
//     testPduInfo.Data[3] = 0x62;  // SID + 0x40
//     testPduInfo.Data[4] = 0xF5;  // DID_1
//     testPduInfo.Data[5] = 0x3D;  // DID_2
//     testPduInfo.Data[6] = 0x54;  // Data
//     testPduInfo.Data[7] = 0x32;  // Data
//     testPduInfo.Data[8] = 0x88;  // Data
//     testPduInfo.Data[9] = 0x77;  // Data
//     UDS_Client_Callback(testRxPduId, &testPduInfo);
//     // EXPECT_EQ(UDS_Tx_Confirm, 1);

//     UDS_MainFunction();
    
//     // Check the return value
//     EXPECT_EQ(OilPressure_ReadFlag, 1);
// }


// TEST(UDS_Client_PR_Read, VIN_number_Test)
// {
//     uint32_t testRxPduId = 0;
//     PduInfoType testPduInfo;
//     testPduInfo.Length = 23;
//     testPduInfo.Data[0] = 0x23;  // PCI
//     testPduInfo.Data[1] = 0x3D;  // Source Addressing "Server node" maybe 0x3D or 0x4D 
//     testPduInfo.Data[2] = 0xF1;  // Target Addressing "Client node" 
//     testPduInfo.Data[3] = 0x62;  // SID + 0x40
//     testPduInfo.Data[4] = 0xF2;  // DID_1
//     testPduInfo.Data[5] = 0x3D;  // DID_2
//     testPduInfo.Data[6] = 0x54;  // Data
//     testPduInfo.Data[7] = 0x32;  // Data
//     testPduInfo.Data[8] = 0x88;  // Data
//     testPduInfo.Data[9] = 0x77;  // Data
//     testPduInfo.Data[10] = 0x54;  // Data
//     testPduInfo.Data[11] = 0x32;  // Data
//     testPduInfo.Data[12] = 0x88;  // Data
//     testPduInfo.Data[13] = 0x77;  // Data
//     testPduInfo.Data[14] = 0x54;  // Data
//     testPduInfo.Data[15] = 0x32;  // Data
//     testPduInfo.Data[16] = 0x88;  // Data
//     testPduInfo.Data[17] = 0x77;  // Data
//     testPduInfo.Data[18] = 0x54;  // Data
//     testPduInfo.Data[19] = 0x32;  // Data
//     testPduInfo.Data[20] = 0x88;  // Data
//     testPduInfo.Data[21] = 0x77;  // Data
//     testPduInfo.Data[22] = 0x54;  // Data

//     UDS_Client_Callback(testRxPduId, &testPduInfo);
//     // EXPECT_EQ(UDS_Tx_Confirm, 1);

//     UDS_MainFunction();
    
//     // Check the return value
//     EXPECT_EQ(VIN_number_ReadFlag, 1);
// }
// /***************************************************************************************************************/
// /***************************************************************************************************************/





// /***************************************************************************************************************/
// /********************************************** Write test cases ************************************************/
// /***************************************************************************************************************/

// TEST(UDS_Client_PR_Write, OilTemperature_Test)
// {
//     uint32_t testRxPduId = 0;
//     PduInfoType testPduInfo;
//     testPduInfo.Length = 6;
//     testPduInfo.Data[0] = 0x06;  // PCI
//     testPduInfo.Data[1] = 0x3D;  // Source Addressing "Temperature node" 
//     testPduInfo.Data[2] = 0xF1;  // Target Addressing "Client node" 
//     testPduInfo.Data[3] = 0x6E;  // SID + 0x40
//     testPduInfo.Data[4] = 0xF1;  // DID_1
//     testPduInfo.Data[5] = 0x3D;  // DID_2

//     UDS_Client_Callback(testRxPduId, &testPduInfo);
//     // EXPECT_EQ(UDS_Tx_Confirm, 1);

//     UDS_MainFunction();
    
//     // Check the return value
//     EXPECT_EQ(OilTemperature_WriteFlag, 1);
// }


// TEST(UDS_Client_PR_Write, OilPressure_Test)
// {
//     uint32_t testRxPduId = 0;
//     PduInfoType testPduInfo;
//     testPduInfo.Length = 6;
//     testPduInfo.Data[0] = 0x06;  // PCI
//     testPduInfo.Data[1] = 0x4D;  // Source Addressing "Pressure node" 
//     testPduInfo.Data[2] = 0xF1;  // Target Addressing "Client node" 
//     testPduInfo.Data[3] = 0x6E;  // SID + 0x40
//     testPduInfo.Data[4] = 0xF5;  // DID_1
//     testPduInfo.Data[5] = 0x3D;  // DID_2

//     UDS_Client_Callback(testRxPduId, &testPduInfo);
//     // EXPECT_EQ(UDS_Tx_Confirm, 1);

//     UDS_MainFunction();
    
//     // Check the return value
//     EXPECT_EQ(OilPressure_WriteFlag, 1);
// }


// TEST(UDS_Client_PR_Write, VIN_number_Test)
// {
//     uint32_t testRxPduId = 0;
//     PduInfoType testPduInfo;
//     testPduInfo.Length = 6;
//     testPduInfo.Data[0] = 0x06;  // PCI
//     testPduInfo.Data[1] = 0x3D;  // Source Addressing "Server node" maybe 0x3D or 0x4D 
//     testPduInfo.Data[2] = 0xF1;  // Target Addressing "Client node" 
//     testPduInfo.Data[3] = 0x6E;  // SID + 0x40
//     testPduInfo.Data[4] = 0xF2;  // DID_1
//     testPduInfo.Data[5] = 0x3D;  // DID_2

//     UDS_Client_Callback(testRxPduId, &testPduInfo);
//     // EXPECT_EQ(UDS_Tx_Confirm, 1);

//     UDS_MainFunction();
    
//     // Check the return value
//     EXPECT_EQ(VIN_number_WriteFlag, 1);
// }
// /***************************************************************************************************************/
// /***************************************************************************************************************/





// /***************************************************************************************************************/
// /**************************************** Control Session test cases *******************************************/
// /***************************************************************************************************************/

// TEST(UDS_Client_PR_ControlSession, DefaultSession_Test)
// {
//     uint32_t testRxPduId = 0;
//     PduInfoType testPduInfo;
//     testPduInfo.Length = 5;
//     testPduInfo.Data[0] = 0x05;  // PCI
//     testPduInfo.Data[1] = 0x3D;  // Source Addressing "Server node" 0x3D or 0x4D
//     testPduInfo.Data[2] = 0xF1;  // Target Addressing "Client node" 
//     testPduInfo.Data[3] = 0x50;  // SID + 0x40
//     testPduInfo.Data[4] = 0x01;  // Sub_F

//     UDS_Client_Callback(testRxPduId, &testPduInfo);
//     // EXPECT_EQ(UDS_Tx_Confirm, 1);

//     UDS_MainFunction();
    
//     // Check the return value
//     EXPECT_EQ(DefaultSession_Flag, 1);
// }


// TEST(UDS_Client_PR_ControlSession, ExtendedSession_Test)
// {
//     uint32_t testRxPduId = 0;
//     PduInfoType testPduInfo;
//     testPduInfo.Length = 5;
//     testPduInfo.Data[0] = 0x05;  // PCI
//     testPduInfo.Data[1] = 0x3D;  // Source Addressing "Server node" 0x3D or 0x4D
//     testPduInfo.Data[2] = 0xF1;  // Target Addressing "Client node" 
//     testPduInfo.Data[3] = 0x50;  // SID + 0x40
//     testPduInfo.Data[4] = 0x03;  // Sub_F

//     UDS_Client_Callback(testRxPduId, &testPduInfo);
//     // EXPECT_EQ(UDS_Tx_Confirm, 1);

//     UDS_MainFunction();
    
//     // Check the return value
//     EXPECT_EQ(ExtendedSession_Flag, 1);
// }

// /***************************************************************************************************************/
// /***************************************************************************************************************/





// /***************************************************************************************************************/
// /**************************************** Security test cases *******************************************/
// /***************************************************************************************************************/

// TEST(UDS_Client_PR_ControlSession, SecuritySeed_Test)
// {
//     uint32_t testRxPduId = 0;
//     PduInfoType testPduInfo;
//     testPduInfo.Length = 9;
//     testPduInfo.Data[0] = 0x09;  // PCI
//     testPduInfo.Data[1] = 0x3D;  // Source Addressing "Server node" 0x3D or 0x4D
//     testPduInfo.Data[2] = 0xF1;  // Target Addressing "Client node" 
//     testPduInfo.Data[3] = 0x67;  // SID + 0x40
//     testPduInfo.Data[4] = 0x01;  // Sub_F
//     testPduInfo.Data[5] = 0x11;  // Data
//     testPduInfo.Data[6] = 0x11;  // Data
//     testPduInfo.Data[7] = 0x11;  // Data
//     testPduInfo.Data[8] = 0x11;  // Data

//     UDS_Client_Callback(testRxPduId, &testPduInfo);
//     // EXPECT_EQ(UDS_Tx_Confirm, 1);

//     UDS_MainFunction();
    
//     // Check the return value
//     EXPECT_EQ(SecuritySeed_Flag, 1);
// }


// TEST(UDS_Client_PR_ControlSession, SecurityKey_Test)
// {
//     uint32_t testRxPduId = 0;
//     PduInfoType testPduInfo;
//     testPduInfo.Length = 5;
//     testPduInfo.Data[0] = 0x05;  // PCI
//     testPduInfo.Data[1] = 0x3D;  // Source Addressing "Server node" 0x3D or 0x4D
//     testPduInfo.Data[2] = 0xF1;  // Target Addressing "Client node" 
//     testPduInfo.Data[3] = 0x67;  // SID + 0x40
//     testPduInfo.Data[4] = 0x02;  // Sub_F

//     UDS_Client_Callback(testRxPduId, &testPduInfo);
//     // EXPECT_EQ(UDS_Tx_Confirm, 1);

//     UDS_MainFunction();
    
//     // Check the return value
//     EXPECT_EQ(SecurityKey_Flag, 1);
// }

// /***************************************************************************************************************/
// /***************************************************************************************************************/




// /***************************************************************************************************************/
// /**************************************** Security test cases *******************************************/
// /***************************************************************************************************************/

// TEST(UDS_Client_PR_ControlSession, TesterPresent_Test)
// {
//     uint32_t testRxPduId = 0;
//     PduInfoType testPduInfo;
//     testPduInfo.Length = 4;
//     testPduInfo.Data[0] = 0x04;  // PCI
//     testPduInfo.Data[1] = 0x3D;  // Source Addressing "Server node" 0x3D or 0x4D
//     testPduInfo.Data[2] = 0xF1;  // Target Addressing "Client node" 
//     testPduInfo.Data[3] = 0x7E;  // SID + 0x40


//     UDS_Client_Callback(testRxPduId, &testPduInfo);
//     // EXPECT_EQ(UDS_Tx_Confirm, 1);

//     UDS_MainFunction();
    
//     // Check the return value
//     EXPECT_EQ(TesterPresent_Flag, 1);
// }


// /***************************************************************************************************************/
// /***************************************************************************************************************/


















int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
