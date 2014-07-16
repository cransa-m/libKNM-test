#!/bin/bash

RD="/home/jp/Projects/libKNM"

g++ \
	$RD/KParser/KParser.cpp \
	$RD/KParser/KParser_cfg.cpp \
	$RD/KError/KError.cpp \
	$RD/KUtils/KUtils.cpp \
	-I $RD/KParser \
	-I $RD/KError \
	-I $RD/KTree \
	-I $RD/KUtils \
	main.cpp