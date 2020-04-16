################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/AFIO_Prog.c \
../src/DIO_Prog.c \
../src/DMA_Prog.c \
../src/FLASH_Prog.c \
../src/NVIC_Prog.c \
../src/NVIC_program.c \
../src/RCC_Prog.c \
../src/SYSTICK_Prog.c \
../src/USART_Prog.c \
../src/_write.c \
../src/flash_usart.c \
../src/main.c 

OBJS += \
./src/AFIO_Prog.o \
./src/DIO_Prog.o \
./src/DMA_Prog.o \
./src/FLASH_Prog.o \
./src/NVIC_Prog.o \
./src/NVIC_program.o \
./src/RCC_Prog.o \
./src/SYSTICK_Prog.o \
./src/USART_Prog.o \
./src/_write.o \
./src/flash_usart.o \
./src/main.o 

C_DEPS += \
./src/AFIO_Prog.d \
./src/DIO_Prog.d \
./src/DMA_Prog.d \
./src/FLASH_Prog.d \
./src/NVIC_Prog.d \
./src/NVIC_program.d \
./src/RCC_Prog.d \
./src/SYSTICK_Prog.d \
./src/USART_Prog.d \
./src/_write.d \
./src/flash_usart.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM GNU C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -ffreestanding -fno-move-loop-invariants -Wall -Wextra  -g3 -DDEBUG -DUSE_FULL_ASSERT -DTRACE -DOS_USE_TRACE_SEMIHOSTING_DEBUG -DSTM32F10X_MD -DUSE_STDPERIPH_DRIVER -DHSE_VALUE=8000000 -I"../include" -I"../system/include" -I"../system/include/cmsis" -I"../system/include/stm32f1-stdperiph" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


