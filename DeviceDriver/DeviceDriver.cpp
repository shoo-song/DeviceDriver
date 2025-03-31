#include "DeviceDriver.h"
#include <stdexcept>
DeviceDriver::DeviceDriver(FlashMemoryDevice* hardware) : m_hardware(hardware)
{
}
int DeviceDriver::read(long address)
{
    // TODO: implement this method properly
    unsigned char result = m_hardware->read(address);
    for (int i = 0; i < 4; i++) {
        if (result != m_hardware->read(address)) {
            //exception
            throw std::exception("ReadFailException");
        }
    }
    return (int)result;
}

void DeviceDriver::write(long address, int data)
{
    // TODO: implement this method
    unsigned char cur_data = m_hardware->read(address);
    if (cur_data != 0xFF) {
        throw std::exception("WriteFailException");
    }
    else {
        m_hardware->write(address, (unsigned char)data);
    }
}