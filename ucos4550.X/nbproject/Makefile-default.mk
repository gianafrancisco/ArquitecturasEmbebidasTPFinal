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
MKDIR=mkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=cof
DEBUGGABLE_SUFFIX=cof
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/ucos4550.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=cof
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/ucos4550.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=../OS_CPU_C.c ../VECTORS.c ../UCOS_II.c ../TEST.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/1472/OS_CPU_C.o ${OBJECTDIR}/_ext/1472/VECTORS.o ${OBJECTDIR}/_ext/1472/UCOS_II.o ${OBJECTDIR}/_ext/1472/TEST.o
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/1472/OS_CPU_C.o.d ${OBJECTDIR}/_ext/1472/VECTORS.o.d ${OBJECTDIR}/_ext/1472/UCOS_II.o.d ${OBJECTDIR}/_ext/1472/TEST.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/1472/OS_CPU_C.o ${OBJECTDIR}/_ext/1472/VECTORS.o ${OBJECTDIR}/_ext/1472/UCOS_II.o ${OBJECTDIR}/_ext/1472/TEST.o

# Source Files
SOURCEFILES=../OS_CPU_C.c ../VECTORS.c ../UCOS_II.c ../TEST.c


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
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/ucos4550.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=18F4550
MP_PROCESSOR_OPTION_LD=18f4550
MP_LINKER_DEBUG_OPTION=-r=ROM@0x7DC0:0x7FFF -r=RAM@GPR:0x3F4:0x3FF -u_DEBUGSTACK
# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/1472/OS_CPU_C.o: ../OS_CPU_C.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/OS_CPU_C.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/OS_CPU_C.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -p$(MP_PROCESSOR_OPTION) -I"/home/francisco/SOFTWARE_PIC/uCOS-II/PIC18/Practico_4x" -I"/home/francisco/SOFTWARE_PIC/uCOS-II/SOURCE" -I"/opt/microchip/mplabc18/v3.47/h" -I".." -I"." -ml -oa- -Ls -o-  -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/_ext/1472/OS_CPU_C.o   ../OS_CPU_C.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1472/OS_CPU_C.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/OS_CPU_C.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1472/VECTORS.o: ../VECTORS.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/VECTORS.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/VECTORS.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -p$(MP_PROCESSOR_OPTION) -I"/home/francisco/SOFTWARE_PIC/uCOS-II/PIC18/Practico_4x" -I"/home/francisco/SOFTWARE_PIC/uCOS-II/SOURCE" -I"/opt/microchip/mplabc18/v3.47/h" -I".." -I"." -ml -oa- -Ls -o-  -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/_ext/1472/VECTORS.o   ../VECTORS.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1472/VECTORS.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/VECTORS.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1472/UCOS_II.o: ../UCOS_II.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/UCOS_II.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/UCOS_II.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -p$(MP_PROCESSOR_OPTION) -I"/home/francisco/SOFTWARE_PIC/uCOS-II/PIC18/Practico_4x" -I"/home/francisco/SOFTWARE_PIC/uCOS-II/SOURCE" -I"/opt/microchip/mplabc18/v3.47/h" -I".." -I"." -ml -oa- -Ls -o-  -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/_ext/1472/UCOS_II.o   ../UCOS_II.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1472/UCOS_II.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/UCOS_II.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1472/TEST.o: ../TEST.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/TEST.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/TEST.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -p$(MP_PROCESSOR_OPTION) -I"/home/francisco/SOFTWARE_PIC/uCOS-II/PIC18/Practico_4x" -I"/home/francisco/SOFTWARE_PIC/uCOS-II/SOURCE" -I"/opt/microchip/mplabc18/v3.47/h" -I".." -I"." -ml -oa- -Ls -o-  -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/_ext/1472/TEST.o   ../TEST.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1472/TEST.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/TEST.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
else
${OBJECTDIR}/_ext/1472/OS_CPU_C.o: ../OS_CPU_C.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/OS_CPU_C.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/OS_CPU_C.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -I"/home/francisco/SOFTWARE_PIC/uCOS-II/PIC18/Practico_4x" -I"/home/francisco/SOFTWARE_PIC/uCOS-II/SOURCE" -I"/opt/microchip/mplabc18/v3.47/h" -I".." -I"." -ml -oa- -Ls -o-  -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/_ext/1472/OS_CPU_C.o   ../OS_CPU_C.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1472/OS_CPU_C.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/OS_CPU_C.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1472/VECTORS.o: ../VECTORS.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/VECTORS.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/VECTORS.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -I"/home/francisco/SOFTWARE_PIC/uCOS-II/PIC18/Practico_4x" -I"/home/francisco/SOFTWARE_PIC/uCOS-II/SOURCE" -I"/opt/microchip/mplabc18/v3.47/h" -I".." -I"." -ml -oa- -Ls -o-  -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/_ext/1472/VECTORS.o   ../VECTORS.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1472/VECTORS.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/VECTORS.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1472/UCOS_II.o: ../UCOS_II.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/UCOS_II.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/UCOS_II.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -I"/home/francisco/SOFTWARE_PIC/uCOS-II/PIC18/Practico_4x" -I"/home/francisco/SOFTWARE_PIC/uCOS-II/SOURCE" -I"/opt/microchip/mplabc18/v3.47/h" -I".." -I"." -ml -oa- -Ls -o-  -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/_ext/1472/UCOS_II.o   ../UCOS_II.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1472/UCOS_II.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/UCOS_II.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1472/TEST.o: ../TEST.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/TEST.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/TEST.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -I"/home/francisco/SOFTWARE_PIC/uCOS-II/PIC18/Practico_4x" -I"/home/francisco/SOFTWARE_PIC/uCOS-II/SOURCE" -I"/opt/microchip/mplabc18/v3.47/h" -I".." -I"." -ml -oa- -Ls -o-  -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/_ext/1472/TEST.o   ../TEST.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1472/TEST.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/TEST.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/ucos4550.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    /home/francisco/SOFTWARE_PIC/uCOS-II/PIC18/Practico_4x/18f45k20.lkr
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_LD} $(MP_EXTRA_LD_PRE) "/home/francisco/SOFTWARE_PIC/uCOS-II/PIC18/Practico_4x/18f45k20.lkr"  -p$(MP_PROCESSOR_OPTION_LD)  -w -x -u_DEBUG -m"$(BINDIR_)$(TARGETBASE).map" -l"../../../../../../../opt/microchip/mplabc18/v3.47/lib" -l"."  -z__MPLAB_BUILD=1  -u_CRUNTIME -z__MPLAB_DEBUG=1 -z__MPLAB_DEBUGGER_PK3=1 $(MP_LINKER_DEBUG_OPTION) -l ${MP_CC_DIR}/../lib  -o dist/${CND_CONF}/${IMAGE_TYPE}/ucos4550.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}   
else
dist/${CND_CONF}/${IMAGE_TYPE}/ucos4550.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   /home/francisco/SOFTWARE_PIC/uCOS-II/PIC18/Practico_4x/18f45k20.lkr
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_LD} $(MP_EXTRA_LD_PRE) "/home/francisco/SOFTWARE_PIC/uCOS-II/PIC18/Practico_4x/18f45k20.lkr"  -p$(MP_PROCESSOR_OPTION_LD)  -w  -m"$(BINDIR_)$(TARGETBASE).map" -l"../../../../../../../opt/microchip/mplabc18/v3.47/lib" -l"."  -z__MPLAB_BUILD=1  -u_CRUNTIME -l ${MP_CC_DIR}/../lib  -o dist/${CND_CONF}/${IMAGE_TYPE}/ucos4550.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}   
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell "${PATH_TO_IDE_BIN}"mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
