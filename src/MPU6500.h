  /* 
   MPU6500.h: Class declaration for MPU6500

   Copyright (C) 2018 Simon D. Levy

   This file is part of MPU.

   MPU is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   MPU is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   You should have received a copy of the GNU General Public License
   along with MPU.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "MPU.h"

class MPU6500 : public MPUIMU {

    public:

        MPU6500(Ascale_t ascale, Gscale_t gscale);

        MPU_Error_t begin(void);

        bool checkNewData(void);

        void readGyrometer(float & gx, float & gy, float & gz);

    protected:

        // Register map
        const uint8_t SELF_TEST_X_GYRO  = 0x00;                  
        const uint8_t SELF_TEST_Y_GYRO  = 0x01;
        const uint8_t SELF_TEST_Z_GYRO  = 0x02;

        virtual void writeMPURegister(uint8_t subAddress, uint8_t data) override;

        virtual void readMPURegisters(uint8_t subAddress, uint8_t count, uint8_t * dest) override;
}; 
