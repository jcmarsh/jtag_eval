CFLAGS = -Wall -O0 -g3
INC = -I../../../basic_bsp/ps7_cortexa9_0/include -I../../common
LD_SRCS += ../../common/lscript.ld
LIB = -L../../../basic_bsp/ps7_cortexa9_0/lib
SPEC = -specs=../../common/Xilinx.spec
LIBS := -Wl,--start-group,-lxil,-lgcc,-lc,--end-group

RM := rm -rf


# Add inputs and outputs from these tool invocations to the build variables 
ELFSIZE += \
tambara.elf.size \

# All Target
all: pre-build main-build

# Main-build Target
main-build: tambara.elf secondary-outputs

C_SRCS += ../../common/platform.c  \
../src/test_mm.c

OBJS += ../../common/platform.o \
../src/test_mm.o

C_DEPS += ../../common/platform.d \
../src/test_mm.d


%.o: %.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM v7 gcc compiler'
	arm-none-eabi-gcc $(CFLAGS) -c -fmessage-length=0 -MT"$@" -mcpu=cortex-a9 -mfpu=vfpv3 -mfloat-abi=hard $(INC) -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

# Tool invocations
tambara.elf: $(OBJS) $(LD_SRCS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: ARM v7 gcc linker'
	arm-none-eabi-gcc -mcpu=cortex-a9 -mfpu=vfpv3 -mfloat-abi=hard -Wl,-build-id=none $(SPEC) -Wl,-T -Wl,$(LD_SRCS) $(LIB) -o "tambara.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

tambara.elf.size: tambara.elf
	@echo 'Invoking: ARM v7 Print Size'
	arm-none-eabi-size tambara.elf  |tee "tambara.elf.size"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(EXECUTABLES) $(OBJS) $(S_UPPER_DEPS) $(C_DEPS) $(ELFSIZE) tambara.elf Xilinx.spec
	-@echo ' '

pre-build:
	-a9-linaro-pre-build-step
	-@echo ' '

secondary-outputs: $(ELFSIZE)

.PHONY: all clean dependents
.SECONDARY: main-build pre-build

-include ../makefile.targets
