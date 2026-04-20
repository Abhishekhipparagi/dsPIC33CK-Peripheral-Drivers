#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/dsPIC33CK-Bare-Metal-Drivers-Power-Electronics-BSP.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/dsPIC33CK-Bare-Metal-Drivers-Power-Electronics-BSP.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS
SUB_IMAGE_ADDRESS_COMMAND=--image-address $(SUB_IMAGE_ADDRESS)
else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=main.c drv_clock.c drv_gpio.c drv_uart.c drv_adc.c drv_pwm.c drv_timer.c drv_capture.c drv_utils.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/main.o ${OBJECTDIR}/drv_clock.o ${OBJECTDIR}/drv_gpio.o ${OBJECTDIR}/drv_uart.o ${OBJECTDIR}/drv_adc.o ${OBJECTDIR}/drv_pwm.o ${OBJECTDIR}/drv_timer.o ${OBJECTDIR}/drv_capture.o ${OBJECTDIR}/drv_utils.o
POSSIBLE_DEPFILES=${OBJECTDIR}/main.o.d ${OBJECTDIR}/drv_clock.o.d ${OBJECTDIR}/drv_gpio.o.d ${OBJECTDIR}/drv_uart.o.d ${OBJECTDIR}/drv_adc.o.d ${OBJECTDIR}/drv_pwm.o.d ${OBJECTDIR}/drv_timer.o.d ${OBJECTDIR}/drv_capture.o.d ${OBJECTDIR}/drv_utils.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/main.o ${OBJECTDIR}/drv_clock.o ${OBJECTDIR}/drv_gpio.o ${OBJECTDIR}/drv_uart.o ${OBJECTDIR}/drv_adc.o ${OBJECTDIR}/drv_pwm.o ${OBJECTDIR}/drv_timer.o ${OBJECTDIR}/drv_capture.o ${OBJECTDIR}/drv_utils.o

# Source Files
SOURCEFILES=main.c drv_clock.c drv_gpio.c drv_uart.c drv_adc.c drv_pwm.c drv_timer.c drv_capture.c drv_utils.c



CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk ${DISTDIR}/dsPIC33CK-Bare-Metal-Drivers-Power-Electronics-BSP.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=33CK256MP508
MP_LINKER_FILE_OPTION=,--script=p33CK256MP508.gld
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/main.o: main.c  .generated_files/flags/default/ecc4444075a61853ce8cd79f7701e4ca27ac7cdb .generated_files/flags/default/c0d3be8c26ba84d29e572b159668201f8b46bf63
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  main.c  -o ${OBJECTDIR}/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/main.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/drv_clock.o: drv_clock.c  .generated_files/flags/default/9af080bafda98552fcde1b03b51fa82cf8863779 .generated_files/flags/default/c0d3be8c26ba84d29e572b159668201f8b46bf63
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/drv_clock.o.d 
	@${RM} ${OBJECTDIR}/drv_clock.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  drv_clock.c  -o ${OBJECTDIR}/drv_clock.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/drv_clock.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/drv_gpio.o: drv_gpio.c  .generated_files/flags/default/cd95b88069eb56463ce2ee0f461fb98940a52c5e .generated_files/flags/default/c0d3be8c26ba84d29e572b159668201f8b46bf63
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/drv_gpio.o.d 
	@${RM} ${OBJECTDIR}/drv_gpio.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  drv_gpio.c  -o ${OBJECTDIR}/drv_gpio.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/drv_gpio.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/drv_uart.o: drv_uart.c  .generated_files/flags/default/5a90dbdd281e7921285fd8d252b6da6e33628a5b .generated_files/flags/default/c0d3be8c26ba84d29e572b159668201f8b46bf63
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/drv_uart.o.d 
	@${RM} ${OBJECTDIR}/drv_uart.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  drv_uart.c  -o ${OBJECTDIR}/drv_uart.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/drv_uart.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/drv_adc.o: drv_adc.c  .generated_files/flags/default/a5b5b9db0d83cd35ec82f1fc7886d155e5c1c996 .generated_files/flags/default/c0d3be8c26ba84d29e572b159668201f8b46bf63
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/drv_adc.o.d 
	@${RM} ${OBJECTDIR}/drv_adc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  drv_adc.c  -o ${OBJECTDIR}/drv_adc.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/drv_adc.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/drv_pwm.o: drv_pwm.c  .generated_files/flags/default/5e60bc89e6009c9a46fc5161215b602e1094a5fa .generated_files/flags/default/c0d3be8c26ba84d29e572b159668201f8b46bf63
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/drv_pwm.o.d 
	@${RM} ${OBJECTDIR}/drv_pwm.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  drv_pwm.c  -o ${OBJECTDIR}/drv_pwm.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/drv_pwm.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/drv_timer.o: drv_timer.c  .generated_files/flags/default/c9f2b16d0aa3b833f32ebe81ac6049c20faa09e9 .generated_files/flags/default/c0d3be8c26ba84d29e572b159668201f8b46bf63
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/drv_timer.o.d 
	@${RM} ${OBJECTDIR}/drv_timer.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  drv_timer.c  -o ${OBJECTDIR}/drv_timer.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/drv_timer.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/drv_capture.o: drv_capture.c  .generated_files/flags/default/affac357b409baade56e13d8e96e16feec1cbe80 .generated_files/flags/default/c0d3be8c26ba84d29e572b159668201f8b46bf63
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/drv_capture.o.d 
	@${RM} ${OBJECTDIR}/drv_capture.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  drv_capture.c  -o ${OBJECTDIR}/drv_capture.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/drv_capture.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/drv_utils.o: drv_utils.c  .generated_files/flags/default/47688b800e0672988f5e824083161f0e0c2a8f15 .generated_files/flags/default/c0d3be8c26ba84d29e572b159668201f8b46bf63
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/drv_utils.o.d 
	@${RM} ${OBJECTDIR}/drv_utils.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  drv_utils.c  -o ${OBJECTDIR}/drv_utils.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/drv_utils.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
else
${OBJECTDIR}/main.o: main.c  .generated_files/flags/default/13199ddab269953e45d74041fca41fc1ed3ceab2 .generated_files/flags/default/c0d3be8c26ba84d29e572b159668201f8b46bf63
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  main.c  -o ${OBJECTDIR}/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/main.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/drv_clock.o: drv_clock.c  .generated_files/flags/default/5ce0ef96a1bae024ee6518a8a12cd4fd047cc319 .generated_files/flags/default/c0d3be8c26ba84d29e572b159668201f8b46bf63
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/drv_clock.o.d 
	@${RM} ${OBJECTDIR}/drv_clock.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  drv_clock.c  -o ${OBJECTDIR}/drv_clock.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/drv_clock.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/drv_gpio.o: drv_gpio.c  .generated_files/flags/default/6e1971ab78fd454a30306d12b249467f71cff669 .generated_files/flags/default/c0d3be8c26ba84d29e572b159668201f8b46bf63
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/drv_gpio.o.d 
	@${RM} ${OBJECTDIR}/drv_gpio.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  drv_gpio.c  -o ${OBJECTDIR}/drv_gpio.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/drv_gpio.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/drv_uart.o: drv_uart.c  .generated_files/flags/default/3480ce29834c457354a802a4430d9e48277cf83 .generated_files/flags/default/c0d3be8c26ba84d29e572b159668201f8b46bf63
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/drv_uart.o.d 
	@${RM} ${OBJECTDIR}/drv_uart.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  drv_uart.c  -o ${OBJECTDIR}/drv_uart.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/drv_uart.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/drv_adc.o: drv_adc.c  .generated_files/flags/default/32a5c7a1dd8d87805f0a2b2706c8c798576dbf46 .generated_files/flags/default/c0d3be8c26ba84d29e572b159668201f8b46bf63
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/drv_adc.o.d 
	@${RM} ${OBJECTDIR}/drv_adc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  drv_adc.c  -o ${OBJECTDIR}/drv_adc.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/drv_adc.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/drv_pwm.o: drv_pwm.c  .generated_files/flags/default/d9f0701eba00a82f5e5ff45d3779ada496f1a6b1 .generated_files/flags/default/c0d3be8c26ba84d29e572b159668201f8b46bf63
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/drv_pwm.o.d 
	@${RM} ${OBJECTDIR}/drv_pwm.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  drv_pwm.c  -o ${OBJECTDIR}/drv_pwm.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/drv_pwm.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/drv_timer.o: drv_timer.c  .generated_files/flags/default/2768208771dbbc3a4faec03e30f51d9c4dacaf85 .generated_files/flags/default/c0d3be8c26ba84d29e572b159668201f8b46bf63
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/drv_timer.o.d 
	@${RM} ${OBJECTDIR}/drv_timer.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  drv_timer.c  -o ${OBJECTDIR}/drv_timer.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/drv_timer.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/drv_capture.o: drv_capture.c  .generated_files/flags/default/2d1a47ea83922f07f1b47496d183a698217074f .generated_files/flags/default/c0d3be8c26ba84d29e572b159668201f8b46bf63
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/drv_capture.o.d 
	@${RM} ${OBJECTDIR}/drv_capture.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  drv_capture.c  -o ${OBJECTDIR}/drv_capture.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/drv_capture.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/drv_utils.o: drv_utils.c  .generated_files/flags/default/6784d81eeb0f318c555970611ef35f0ce69aea60 .generated_files/flags/default/c0d3be8c26ba84d29e572b159668201f8b46bf63
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/drv_utils.o.d 
	@${RM} ${OBJECTDIR}/drv_utils.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  drv_utils.c  -o ${OBJECTDIR}/drv_utils.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/drv_utils.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemblePreproc
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${DISTDIR}/dsPIC33CK-Bare-Metal-Drivers-Power-Electronics-BSP.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o ${DISTDIR}/dsPIC33CK-Bare-Metal-Drivers-Power-Electronics-BSP.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -D__DEBUG=__DEBUG   -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)   -mreserve=data@0x1000:0x101B -mreserve=data@0x101C:0x101D -mreserve=data@0x101E:0x101F -mreserve=data@0x1020:0x1021 -mreserve=data@0x1022:0x1023 -mreserve=data@0x1024:0x1027 -mreserve=data@0x1028:0x104F   -Wl,--local-stack,,--defsym=__MPLAB_BUILD=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D__DEBUG=__DEBUG,,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,${DISTDIR}/memoryfile.xml$(MP_EXTRA_LD_POST)  -mdfp="${DFP_DIR}/xc16" 
	
else
${DISTDIR}/dsPIC33CK-Bare-Metal-Drivers-Power-Electronics-BSP.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o ${DISTDIR}/dsPIC33CK-Bare-Metal-Drivers-Power-Electronics-BSP.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -Wl,--local-stack,,--defsym=__MPLAB_BUILD=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,${DISTDIR}/memoryfile.xml$(MP_EXTRA_LD_POST)  -mdfp="${DFP_DIR}/xc16" 
	${MP_CC_DIR}\\xc16-bin2hex ${DISTDIR}/dsPIC33CK-Bare-Metal-Drivers-Power-Electronics-BSP.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} -a  -omf=elf   -mdfp="${DFP_DIR}/xc16" 
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${OBJECTDIR}
	${RM} -r ${DISTDIR}

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
