#pragma once

#include "driver/gpio.h"

namespace GPIO
{
    
    class GpioBase
    {
        const gpio_num_t _pin;
        const bool _inverted_logic = false;
        const gpio_config_t _cfg;
    public:
        //Constructor
        constexpre GipoBase(const gpio_num_t _pin,
                    const gpio_config_t& config, 
                    const bool _inverted_logic = false) :
            _pin{pin},
            _cfg{config},
            _inverted_logic{inverted_logic}
        {

        }
        virtual bool state(void) =0;
        virtual  esp_err_t set(const bool state) =0;

        [[nodiscard]]esp_err_t init(void);


    }; // GpioBase

    class GpioOutput
    {
        const gpio_num_t _pin;
        bool _state = false;
        const bool _inverted_logic = false;

    public:
        //Constructor
        constexpre GipoOutput(const gpio_num_t pin, const bool invert = false) : 
            _inverted_logic{invert},
            _pin{pin}
        {

        }
        esp_err_t init(void);
        esp_err_t set(const bool state);
        esp_err_t toggle(void);
        bool state(void) {return _state};
    }

    class GpioInput
    {
         gpio_pin_t _pin; //memory
        const bool _inverter_logic = false;
        
        public:
            eps_err_t init(void);
            bool state(void);
    };

} // namespace GPIO