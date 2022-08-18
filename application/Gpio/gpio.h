#pragma once

#include "driver/gpio.h"

namespace GPIO
{

    class GpioBase
    {
    public:
    }; // GpioBase

    class GpioOutput
    {
        bool _state = false;
        const bool _inverted_logic = false;
        const gpio_num_t _pin;

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
        bool state(void) { return _state; }
    }

    gpio_pin_t _pin; //memory
    const bool _inverter_logic = false;
        
    class GpioInput
    {
        eps_err_t init(void);
        
        public:
            bool state(void);
    };

} // namespace GPIO