#pragma once

// ###################################################################################
// Include libraries:

#include <iostream>                 // Input and output stream library

// ###################################################################################

namespace AntennaTracker_VariablesManager
{

/**
     * @ingroup public_general_structures
     * @enum ErrorCode
     * @brief Enum for error code.
     *  */ 
    enum ErrorCode 
    {
        ERROR_GENERAL = 0,               // General error code.
        ERROR_HMI_INIT,
        ERROR_HMI_INPUT,
        ERROR_RESTAPI_INIT,
        ERROR_RESTAPI_INPUT,
        ERROR_ETHERCAT_UPDATE_PEOCESS,
        ERROR_ETHERCAT_INIT,
        ERROR_ETHERNET_INIT,
        ERROR_DRIVER_ALARM,
        ERROR_DRIVER_INIT,
        ERROR_ENCODER_ALARM,
        ERROR_ENCODER_INIT,
        ERROR_GPS_INIT,
        ERROR_TLE_INIT,
        ERROR_WINDSENSOR_INIT,
        ERROR_CONTROLLER_INIT,
        ERROR_CONNECTION,
        ERROR_CALIBRATION
    };

    /**
     * @ingroup public_general_structures
     * @struct TimeVarData
     * @brief Structure for time variables
     *  */ 
    struct TimeVarData
    {
        /// @brief Timer value in the main loop. [us]
        uint64_t T = 0;     

        /// @brief Duration of the loop process. [us]
        uint64_t T_dur = 0;                        
    };

    /**
     * @ingroup public_general_structures
     * @struct MotorVarData
     * @brief Structure for Motor Variables
     *  */ 
    struct MotorVarData
    {
        /// @brief Motor current. [amp]. “If the system has an amper sensor, this variable can be used.
        float amp = 0;     

        /// @brief Primary value of the motor. This value usually comes from controller signals.
        float primaryValue = 0;  

        /// @brief Secondary value of the motor. This value usually comes from controller signals.            
        float secondaryValue = 0;                       
    };

    /**
     * @ingroup public_general_structures
     * @struct EncoderVarData
     * @brief Structure for Encoders variables
     *  */ 
    struct EncoderVarData
    {
        /// @brief The raw descereted value of encoder. [Step]
        uint32_t posRawStep = 0;     

        /// @brief The raw position value of encoder. [deg]            
        double posRawDeg = 0;      

        /// @brief Encoder shaft velocity. [deg/s]                 
        double rate = 0;   
        
        /// @brief The position output value of encoder. [deg] 
        double posDeg = 0;
    };

    /**
     * @ingroup public_general_structures
     * @struct GpsVarData
     * @brief Structure for GPS variables
     *  */ 
    struct GpsVarData
    {
        /// @brief GPS UTC time. [year, month, day, hours, minutes, seconds]
        uint utcTime[6] = {0};   

        /// @brief GPS fix mode. 0: no fixed, 1: 3D fixed. [-]                
        bool fixStatus = false;   
        
        /// @brief GPS connection status. true: connected, false: disconnected.
        bool connectStatus = false;

        /// @brief GPS latitude. [deg]            
        double latitude = 0;     

        /// @brief GPS longitude. [deg]              
        double longitude = 0;  

        /// @brief GPS altitude. [m]                
        double altitude = 0;  
        
        bool syncFlag = false;
    };

    /**
     * @ingroup public_general_structures
     * @struct LimitSwitchVarData
     * @brief Structure for limitswitch variables
     *  */ 
    struct LimitSwitchVarData
    {
        /**
         * @brief Positive limit switch value. 
         * @note The value is a 3-bit number. Bit 0 is for the software limit, Bit 1 is for the pre limit, and Bit 2 is for the main limit.
         *  */ 
        uint8_t positive = 0;   

        /**
         * @brief Negative limit switch value.
         * @note The value is a 3-bit number. Bit 0 is for the software limit, Bit 1 is for the pre limit, and Bit 2 is for the main limit.
         *  */             
        uint8_t negative = 0;
    };

    /**
     * @ingroup public_general_structures
     * @struct AtitiudeVarData
     * @brief Structure for atitude variables
     *  */ 
    struct AtitiudeVarData
    {
        /// @brief Angle. [deg]
        double angle = 0;      

        /// @brief Rate. [deg/s]              
        double rate = 0;       

        /// @brief Desired angle. [deg]              
        double angleDes = 0;   

        /// @brief Desired rate. [deg/s]              
        double rateDes = 0;  

        /**
         * @brief The value that just used in direct control mode.
         * @note Direct control mode transfer "direct" value to primary output of motor without active controller.
         *  */ 
        double direct = 0;                 
    };

    /**
     * @ingroup public_general_structures
     * @struct TempVarData
     * @brief Structure for temperature variables
     *  */ 
    struct TempVarData
    {
        /// @brief CPU temperature. [degree]
        float cpuTemp = 0;     

        /// @brief LM35 sensor temperature. [degree]                
        float lm35Temp = 0;                     
    };

    /**
     * @ingroup public_general_structures
     * @struct TleVarData
     * @brief Structure for TLE states and variables
     *  */ 
    struct TleVarData
    {
        
    };

    /**
     * @ingroup public_general_structures
     * @struct CalibratorVarData
     * @brief Structure for calibration variables.
     *  */ 
    struct CalibratorVarData
    {
        /**
         * @brief The calibration flag. 
         */
        bool calFlag = false;

        /**
         * @brief The calibration type. 0:offline, 1:online
         */
        uint8_t calType = 0;

        uint8_t freedomMode = 0;

        /**
         * @brief The calibration data. {AZM, ELM, AZA, ELA} [deg]
         */
        double data[4] = {0, 0, 0, 0};

        /**
         * @brief The number of data set in the data base buffer.
         */
        uint32_t DataNumber = 0;

        /**
         * @brief The flag for reset the data base buffer.
         */
        bool resetDataFlag = false;

        /**
         * @brief The add data flag.
         */
        bool addDataFlag = false;
    };

    /**
     * @ingroup public_general_structures
     * @struct SystemVarData
     * @brief Structure for system state variables.
     *  */ 
    struct SystemVarData
    {
        /**
         * @brief Admin flag that is used for admin access advanced level. 
         * @note A value of true means user can access to admin level.
         * */ 
        bool adminFlag = false;

        /**
         * @brief The admin password for admin level access.
        */
        std::string adminPass = "";

        /**
         * @brief The system identification string value.
        */
        std::string ID = "";

        /**
         * @brief Controller state for TLE/STAR/SUN/OBJECT tracking state.
         * @note A value of true means the controller status is in tracking mode.
         * */  
        bool trackStatus = false;  

        /// @brief The tracking data azimuth angle offset. [deg]
        double azOffset = 0;

        /// @brief The tracking data elevation angle offset. [deg]
        double elOffset = 0;

        /// @brief The flag for calibration of azimuth angle.
        bool azimuthCalFlag = false;

        /// @brief The flag for calibration of elevation angle.
        bool elevationCalFlag = false;

        /// @brief The value for correct azimuth angle at current time. [deg]
        double azimuthPresetValue = false;
        
        /// @brief The value for correct elevation angle at current time. [deg]
        double elevationPresetValue = false;

        /**
         * @brief Arm status. false: disarm, true: arm
         * @note A value of false means all motion devices stop/off and be in safe mode.
         * */ 
        bool armStatus = false;    

        /**
         * @brief Stop flag. false: normal operation. true: stop command.
         * @note - A value of true means all movements stop but is not in safe mode.
         * @note - This flag not affect on arm status.
         * */ 
        bool stopFlag = false;  

        /**
         * @brief Emergency push buttons state that store in binary format.
         * @note The value is a 2-bit number. Bit 0 is for the center/main/cabin emergency push button state, Bit 1 is for the pedestal push button state. 
         */
        uint8_t emergencyStop = 0;

        bool clearErrorFlag = false;

        /**
         * @brief The flag for critical situations.  
         * @note - The alarm falg be true at these situations:  
         * @note 1 - Motor overload(currect/torque)
         * @note 2 - Over speed for azimuth/elevation.
         * @note 3 - Over speed detection for wind speed.
         * @note 4 - Pre/Main limit switches touched.
         *    
        */
        bool alarmFlag = false;

        /// @brief The alarm message string.
        std::string alarmMessage = "";

        /**
         * @brief The flag for process-specific failures.
         * @note - A value of true means system normal operation is failed and stop.  
         * @note - For true values, the user must eliminate the error cause and reset the system.  
         * @note - The error flag be true at these situations:
         * @note 1 - The system could not init correctly at startup.
         * @note 2 - Some critical modules became disconnected due to wiring.
         * @note 3 - The system process crashed and can not continue.
        */
        bool fatalErrorFlag = false;

        /// @brief The error message string.  
        std::string errorMessage = "";

        /// @brief The error code.
        ErrorCode errorCode = ERROR_GENERAL;

        /**
         * @brief Power status. 0: on, 1: reset, 2: shutdown
         * @note - A value of 1:reset means system will reset.
         * @note - A value of 2:shutdown means system will shutdown.
         * */                
        uint8_t powerStatus = 0; 

        /// @brief Controller mode. “The value is a string between these: NONE, DIR, VEL, POS, TLE, STAR, SUN, STP.              
        std::string controlMode = "NONE"; 

        /// @brief Save parameters flag.
        bool saveParamFlag = false;

        /// @brief Load parameters flag.
        bool loadParamFlag = false;

        /// @brief Reset to default parameters flag.
        bool resetToDefaultFlag = false;
    };

    /**
     * @ingroup public_utility_classes
     * @class VarData
     * @brief A class for access and management HmiCom variables.
     *  */ 
    class VarData
    {   
        public:
        
            TimeVarData TIM;                ///! @brief time
            MotorVarData MOT_AZ_MASTER;     ///! @brief Azimuth motor master
            MotorVarData MOT_AZ_SLAVE;      ///! @brief Azimuth motor slave
            MotorVarData MOT_EL_MASTER;     ///! @brief Elevation motor master
            MotorVarData MOT_EL_SLAVE;      ///! @brief Elevation motor slave
            EncoderVarData ENC_AZ;          ///! @brief Azimuth encoder
            EncoderVarData ENC_EL;          ///! @brief Elevation encoder
            GpsVarData GPS;                 ///! @brief GPS
            LimitSwitchVarData LIM_AZ;      ///! @brief Azimuth limit switch
            LimitSwitchVarData LIM_EL;      ///! @brief Elevation limit switch
            AtitiudeVarData ATT_AZ;         ///! @brief Azimuth attitude:{angle, desired angle, rate, desired rate}
            AtitiudeVarData ATT_EL;         ///! @brief Elevation attitude:{angle, desired angle, rate, desired rate}
            TempVarData TMP;                ///! @brief Temperature {CPU + LM35 sensor}
            TleVarData TLE;                 ///! @brief TLE data
            SystemVarData SYS;              ///! @brief System variables.  
            CalibratorVarData calibrator;   ///! @brief The calibration variables.

        private:

    };

}




