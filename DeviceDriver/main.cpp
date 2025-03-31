#include "gmock/gmock.h"
#include "DeviceDriver.h"
#include "FlashMemoryDevice.h"
class FlashMock : public FlashMemoryDevice {
public:
	MOCK_METHOD(unsigned char, read, (long address));
	MOCK_METHOD(void, write, (long address, unsigned char data));
};
TEST(DDTest, ReadTC1) {
	FlashMock M;
	DeviceDriver DD(&M);
	int result = DD.read(0);
	EXPECT_EQ(result, 0);
}
TEST(DDTest, WriteTC1) {
	FlashMock M;
	DeviceDriver DD(&M);
	EXPECT_THROW(DD.write(0, 0), std::exception);
}
int  main() {
	::testing::InitGoogleMock();
	return RUN_ALL_TESTS();
}