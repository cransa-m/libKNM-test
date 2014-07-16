#!/bin/bash

RD="/home/jp/Projects/libKNM"

g++ \
	main.cpp \
	$RD/KError/KError.cpp \
	-I $RD/KTree \
	-I $RD/KError 