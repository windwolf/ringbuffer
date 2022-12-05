#ifndef __WWDEVICE_PERIPHERAL_PIN_HPP__
#define __WWDEVICE_PERIPHERAL_PIN_HPP__

#include "base.hpp"
#include "peripheral.hpp"

namespace wibot::peripheral
{

PIN_PER_DECL
enum class PinStatus : uint32_t
{
    Reset = 0U,
    Set = 1U,
};

enum class PinMode : uint8_t
{
    Input = 0U,
    Output = 1U,
};
union PinConfig {
    struct
    {
        bool inverse : 1;
        uint32_t : 31;
    };
    uint32_t value;
};

class Pin : public Initializable, public Configurable<PinConfig>
{
  public:
    Pin(PIN_CTOR_ARG, uint16_t pinMask);
    Result _init() override;
    void _deinit() override;

    Result read(PinStatus &value);
    Result write(PinStatus value);

    Result toggle();
    Result mode_set(PinMode mode);

  private:
    PIN_FIELD_DECL;
    uint16_t _pinMask;
};
} // namespace wibot::peripheral

#endif // __WWDEVICE_PERIPHERAL_PIN_HPP__
