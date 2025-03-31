#pragma once
/*
 * This class represents the interface to a Flash Memory Device. The hardware has only two methods - 'read' and 'write'
 * However, the interface for using the device is a lot more complex than that. It is outlined in the top-level README file.
 */
class FlashMemoryDevice
{
public:
    unsigned char read(long address) {
        return mem[address];
    }
    void write(long address, unsigned char data) {
        mem[address] = data;
        return;
    }
private:
    unsigned char mem[1024];
};

