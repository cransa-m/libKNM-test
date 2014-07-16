#!/bin/bash

RD="/home/jp/Projects/libKNM"

g++ \
	main.cpp 					\
	$RD/KConfig/KConfig.cpp		\
	$RD/KParser/KParser.cpp 	\
	$RD/KParser/KParser_cfg.cpp \
	$RD/KError/KError.cpp		\
	$RD/KUtils/KUtils.cpp		\
	-I $RD/KConfig				\
	-I $RD/KParser 				\
	-I $RD/KError				\
	-I $RD/KUtils				\
	-I $RD/KTree