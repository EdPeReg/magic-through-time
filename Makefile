# _____     ___ ____     ___ ____
#  ____|   |    ____|   |        | |____|
# |     ___|   |____ ___|    ____| |    \    PS2DEV Open Source Project.
#-----------------------------------------------------------------------
# Copyright 2005, ps2dev - http://www.ps2dev.org
# Licenced under Academic Free License version 2.0
# Review ps2sdk README & LICENSE files for further details.
#
# $Id: makefile por retropanda junio 2021 $

EE_DIR_BIN  = bin/
EE_DIR_SRC  = source/
EE_DIR_OBJS = obj/


EE_BIN = $(EE_DIR_BIN)SLES_529.89

EE_SRC = $(wildcard $(EE_DIR_SRC)*.cpp)
EE_OBJS = $(subst .cpp,.o,$(EE_SRC))

EE_INCS = -I../../ -I$(PS2SDK)/ports/include
EE_INCS += -I./include/
EE_LDFLAGS = -L../../lib/ -L$(PS2SDK)/ports/lib -L$(PS2DEV)/gsKit/lib
EE_LIBS = -lc -L$(PS2DEV)/gsKit/lib -L../lib -lGRAPHIC -lsdlmixer -lSDL_image -lpng -ljpeg -lsdl -lgskit -ldmakit -laudsrv -lmass -lc -lm -lm2


all:$(EE_BIN)
	


%.o:%.cpp
	$(EE_CXX) -o $@ -c $^ $(EE_INCS)

clean:
	rm -f $(EE_BIN) $(EE_OBJS)

emu: $(EE_BIN)
	$(PSXEMU)/pcsx2 --elf $(PS2DEV)/test/bin/test.elf

run: $(EE_BIN) 
	 ps2client execee host:$(EE_BIN)


reset:
	ps2client reset


line:et
	ee-addr2line -e $(EE_BIN)

include $(PS2SDK)/samples/Makefile.pref
include $(PS2SDK)/samples/Makefile.eeglobal_cpp
