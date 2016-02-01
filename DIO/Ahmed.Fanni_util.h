#define GetBit(Reg,no) ((Reg>>no)&0x01)
#define ClrBit(Reg,no) (~(0x01<<no)&Reg)
#define SetBit(Reg,no) ((0x01<<no)|Reg)
#define ToggleBit(Reg,no) ((0x01<<no)^Reg)

#define SetReg(Reg) Reg=0xFF
#define ClrReg(Reg) Reg=0
#define Toggle(Reg) Reg^0xFF
#define Assign(Reg,x) Reg=x

#define GetLowNib(Reg) Reg&0x0F
#define ClrLowNib(Reg) Reg&0xF0
#define SetLowNib(Reg) Reg|0x0F
#define ToggleLowNib(Reg) Reg^0x0F
#define AssignLowNib(Reg,x) ((Reg&0xF0)|(x & 0x0F))

#define GetHighNib(Reg) Reg&0xF0
#define ClrHighNib(Reg) Reg&0x0F
#define SetHighNib(Reg) Reg|0xF0
#define ToggleHighNib(Reg) Reg^0xF0
#define AssignHighNib(Reg,x) ((Reg&0x0F)|( x & 0xF0))
