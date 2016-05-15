# ��� �������
#-------------------------------------------------------------------------------
TARGET = USBDEV

# ������������ ������ ���������� ���������
#-------------------------------------------------------------------------------
# PERIPHDRIVERS += stm32f10x_adc
# PERIPHDRIVERS += stm32f10x_bkp
# PERIPHDRIVERS += stm32f10x_can
# PERIPHDRIVERS += stm32f10x_cec
# PERIPHDRIVERS += stm32f10x_crc
# PERIPHDRIVERS += stm32f10x_dbgmcu
 PERIPHDRIVERS += stm32f10x_exti
# PERIPHDRIVERS += stm32f10x_flash
# PERIPHDRIVERS += stm32f10x_fsmc
 PERIPHDRIVERS += stm32f10x_gpio
# PERIPHDRIVERS += stm32f10x_i2c
# PERIPHDRIVERS += stm32f10x_iwdg
# PERIPHDRIVERS += stm32f10x_pwr
 PERIPHDRIVERS += stm32f10x_rcc
# PERIPHDRIVERS += stm32f10x_rtc
# PERIPHDRIVERS += stm32f10x_sdio
# PERIPHDRIVERS += stm32f10x_spi
# PERIPHDRIVERS += stm32f10x_tim
# PERIPHDRIVERS += stm32f10x_usart
# PERIPHDRIVERS += stm32f10x_wwdg
 PERIPHDRIVERS += misc.c

# �������
#-------------------------------------------------------------------------------
#DEFINES += USE_STDPERIPH_DRIVER
DEFINES += STM32F10X_MD
#
DEFINES += ARM_MATH_CM3
#DEFINES += VECT_TAB_FLASH

# �����������
#-------------------------------------------------------------------------------
AS = arm-none-eabi-gcc
CC = arm-none-eabi-gcc
LD = arm-none-eabi-gcc
CP = arm-none-eabi-objcopy
SZ = arm-none-eabi-size
RM = rm

# ���� � CMSIS, StdPeriph Lib
#-------------------------------------------------------------------------------
CMSIS_PATH         = system/src/cmsis
STDPERIPH_INC_PATH = system/include/stm32f1-stdperiph
STDPERIPH_SRC_PATH = system/src/stm32f1-stdperiph

# startup ����
#-------------------------------------------------------------------------------
#STARTUP = startup/startup_stm32f10x_md_vl.s

# ���� ������ �������� ������
#-------------------------------------------------------------------------------
SOURCEDIRS := src
SOURCEDIRS += $(CMSIS_PATH)
SOURCEDIRS += system/src/src
SOURCEDIRS += system/src/cortexm
SOURCEDIRS += system/src/diag
SOURCEDIRS += system/src/newlib
SOURCEDIRS += system/src/usb

# ���� ������ �������
#-------------------------------------------------------------------------------
INCLUDES += .
INCLUDES += $(SOURCEDIRS) 
INCLUDES += $(CMSIS_PATH)
INCLUDES += $(STDPERIPH_INC_PATH)
INCLUDES += include/
INCLUDES += system/include/arm
INCLUDES += system/include/cmsis
INCLUDES += system/include/cortexm
INCLUDES += system/include/diag
INCLUDES += system/include/inc
INCLUDES += system/include/stm32f1-stdperiph
INCLUDES += system/include/usb
INCLUDES += system/include/xprintf

# ����������
#-------------------------------------------------------------------------------
LIBPATH +=
LIBS    +=

# ��������� �����������
#-------------------------------------------------------------------------------
CFLAGS += -mthumb -mcpu=cortex-m3 # ����������� � ������� �������
CFLAGS += -std=gnu99              # �������� ����� �
CFLAGS += -Wall -pedantic         # �������� ��� ��������������
CFLAGS += -Os                     # �����������
CFLAGS += -ggdb                   # ������������ ���������� ���������� ��� gdb
CFLAGS += -fno-builtin

CFLAGS += $(addprefix -I , $(INCLUDES))
CFLAGS += $(addprefix -D , $(DEFINES))

# ������ �������
#-------------------------------------------------------------------------------
LDSCR_PATH = ldscripts
LDSCRIPT   = sections.ld

# ��������� �������
#-------------------------------------------------------------------------------
LDFLAGS += -nostartfiles
LDFLAGS += -L$(LDSCR_PATH)
LDFLAGS += -T$(LDSCR_PATH)/$(LDSCRIPT)
LDFLAGS += $(addprefix -L, $(LIBPATH))
LDFLAGS += $(LIBS)

# ��������� ����������
#-------------------------------------------------------------------------------
AFLAGS += -ahls -mapcs-32

# ������ ��������� ������
#-------------------------------------------------------------------------------
OBJS += $(patsubst %.c, %.o, $(wildcard  $(addsuffix /*.c, $(SOURCEDIRS))))
OBJS += $(addprefix $(STDPERIPH_SRC_PATH)/, $(addsuffix .o, $(PERIPHDRIVERS)))
OBJS += $(patsubst %.s, %.o, $(STARTUP))

# ���� ������ make
#-------------------------------------------------------------------------------
VPATH := $(SOURCEDIRS)

# ������ ������ � �������� �������� "make clean"
#-------------------------------------------------------------------------------
TOREMOVE += *.elf *.hex
TOREMOVE += $(addsuffix /*.o, $(SOURCEDIRS))
TOREMOVE += $(addsuffix /*.d, $(SOURCEDIRS))
TOREMOVE += $(STDPERIPH_SRC_PATH)/*.o
TOREMOVE += $(patsubst %.s, %.o, $(STARTUP))
TOREMOVE += $(TARGET)

# ������� ���
#-------------------------------------------------------------------------------
all: $(TARGET).hex size 

# �������
#-------------------------------------------------------------------------------
clean:
	@$(RM) -f $(TOREMOVE)  

# �������� .hex �����
#-------------------------------------------------------------------------------
$(TARGET).hex: $(TARGET).elf
	@$(CP) -Oihex $(TARGET).elf $(TARGET).hex
        
# ���������� ������
#-------------------------------------------------------------------------------
size:
	@echo "---------------------------------------------------"
	@$(SZ) $(TARGET).elf

# ��������
#------------------------------------------------------------------------------- 
$(TARGET).elf: $(OBJS)
	@$(LD) $(LDFLAGS) $^ -o $@
        
# ����������
#------------------------------------------------------------------------------- 
%.o: %.c
	@echo "Compilling C source =>" $<
	$(CC) $(CFLAGS) -MD -c $< -o $@
        
%.o: %.s
	@$(AS) $(AFLAGS) -c $< -o $@

# ��������������� gcc �����������
#-------------------------------------------------------------------------------
include $(wildcart *.d)