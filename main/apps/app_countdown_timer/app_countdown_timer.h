/**
 * @file app_timer.h
 * @author Forairaaaaa
 * @brief 
 * @version 0.1
 * @date 2023-09-20
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#pragma once
#include <mooncake.h>
#include "../../hal/hal.h"
#include "../utils/theme/theme_define.h"
#include "../utils/anim/anim_define.h"
#include "../utils/icon/icon_define.h"

#include "assets/countdown_timer_big.h"
#include "assets/countdown_timer_small.h"


namespace MOONCAKE
{
    namespace APPS
    {
        class AppCountdownTimer : public APP_BASE
        {
            private:
                struct Data_t
                {
                    HAL::Hal* hal = nullptr;
                    char string_buffer[100];
                };
                Data_t _data;

            public:
                void onCreate() override;
                void onResume() override;
                void onRunning() override;
        };

        class AppCountdownTimer_Packer : public APP_PACKER_BASE
        {
            std::string getAppName() override { return "Countdown"; }
            void* getAppIcon() override { return (void*)(new AppIcon_t(image_data_countdown_timer_big, image_data_countdown_timer_small)); }
            void* newApp() override { return new AppCountdownTimer; }
            void deleteApp(void *app) override { delete (AppCountdownTimer*)app; }
        };
    }
}
