#define REG_NOP 0x00
#define REG_DEVTYPE 0x01
#define REG_MFGR 0x02
#define REG_MODEL 0x03
#define REG_SERNO 0x04
#define REG_MFGDATE 0x05
#define REG_RELEASE 0x06
#define REG_RELBACK 0x07
#define REG_GENCFG 0x08
#define REG_AEAEAC 0x09
#define REG_AEAEA 0x0A
#define REG_AEAEAR 0x0B
#define REG_IOCAP 0x0D
#define REG_EAC 0x0E
#define REG_EA 0x0F
#define REG_EAR 0x10
#define REG_DLCONFIG 0x14
#define REG_DLSTATUS 0x15
#define REG_STATUSF 0x20
#define REG_STATUSW 0x21
#define REG_FPOWTH 0x22
#define REG_WPOWTH 0x23
#define REG_FFREQTH 0x24
#define REG_WFREQTH 0x25
#define REG_FTHERMTH 0x26
#define REG_WTHERMTH 0x27
#define REG_SRQT 0x28
#define REG_FATALT 0x29
#define REG_ALMT 0x2A
#define REG_CHANNEL 0x30
#define REG_PWR 0x31
#define REG_RESENA 0x32
#define REG_MCB 0x33
#define REG_GRID 0x34
#define REG_FCF1 0x35
#define REG_FCF2 0x36
#define REG_LF1 0x40
#define REG_LF2 0x41
#define REG_OOP 0x42
#define REG_CTEMP 0x43
#define REG_FTFR 0x4F
#define REG_OPSL 0x50
#define REG_OPSH 0x51
#define REG_LFL1 0x52
#define REG_LFL2 0x53
#define REG_LFH1 0x54
#define REG_LFH2 0x55
#define REG_LGRID 0x56
#define REG_CURRENTS 0x57
#define REG_TEMPS 0x58
#define REG_DITHERE 0x59
#define REG_DITHERR 0x5A
#define REG_DITHERF 0x5B
#define REG_DITHERA 0x5C
#define REG_TBTFL 0x5D
#define REG_TBTFH 0x5E
#define REG_FAGETH 0x5F
#define REG_WAGETH 0x60
#define REG_AGE 0x61
#define REG_FTF 0x62
#define REG_LOWNOISEMODE 0x90
#define REG_PASSWORD 0xE0
#define REG_CLEANSWEEPRANGE 0xE4
#define REG_CLEANSWEEPSTART 0xE5
#define REG_CLEANSWEEPOFFSET 0xE6
#define REG_CALF1SLOPE 0xF0
#define REG_CALF2SLOPE 0xF1
#define REG_CALSLEDSLOPE 0xF2
#define REG_CALTECUP 0xF3
#define REG_CALTECDOWN 0xF4
#define REG_CALOFFSETUP 0xF5
#define REG_CALOFFSETDOWN 0xF6
#define REG_CALDELAYUP 0xF7
#define REG_CALDELAYDOWN 0xF8

unsigned char calcBIP4(unsigned char* data);
//void ITLACommand(int reg, int data, int RW, int port);
unsigned char* ITLACommand(int reg, int data, int RW, int port);
unsigned char* ITLACommand2(int reg, double data, int RW, int port);
int ITLALastValue();
unsigned char* ITLAAea(int reg, int data, int RW, int port);
unsigned char* AEA(int port, int bytes);
//unsigned char* Rs232_read(int port);
System::String^ ITLAshow(int reg, int data, int RW, int port);
int main();
//double ITLAvalue(int reg, int data, int RW, int port);
double Round_off(double N, double n);
double ThzToNm(double thz);
double NmtoThz(double nm);
bool openPort(void);
bool closePort(void);