#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=clang
CCC=clang++
CXX=clang++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=CLang-MacOSX
CND_DLIB_EXT=dylib
CND_CONF=Mac_Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/cpuid_c.o \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/modules/ArchInfo.o \
	${OBJECTDIR}/modules/CpuInfo.o \
	${OBJECTDIR}/modules/PDInfo.o \
	${OBJECTDIR}/modules/TsxCheck.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=-Waddress-of-temporary
CXXFLAGS=-Waddress-of-temporary

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/cppapplication_1

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/cppapplication_1: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/cppapplication_1 ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/cpuid_c.o: cpuid_c.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/cpuid_c.o cpuid_c.cpp

${OBJECTDIR}/cpuid_c.h.gch: cpuid_c.h
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o "$@" cpuid_c.h

${OBJECTDIR}/main.o: main.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

${OBJECTDIR}/modules/ArchInfo.o: modules/ArchInfo.cpp
	${MKDIR} -p ${OBJECTDIR}/modules
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/modules/ArchInfo.o modules/ArchInfo.cpp

${OBJECTDIR}/modules/CpuInfo.o: modules/CpuInfo.cpp
	${MKDIR} -p ${OBJECTDIR}/modules
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/modules/CpuInfo.o modules/CpuInfo.cpp

${OBJECTDIR}/modules/PDInfo.o: modules/PDInfo.cpp
	${MKDIR} -p ${OBJECTDIR}/modules
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/modules/PDInfo.o modules/PDInfo.cpp

${OBJECTDIR}/modules/TsxCheck.o: modules/TsxCheck.cpp
	${MKDIR} -p ${OBJECTDIR}/modules
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/modules/TsxCheck.o modules/TsxCheck.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
